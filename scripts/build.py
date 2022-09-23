#!/usr/bin/env python3

from glob import glob
from pathlib import Path
import os
import itertools
import hashlib
import subprocess
import sys

Paths = os.environ.get('Path').split(';')
PATH = ""
for candidatePath in Paths:
    if "devkitARM" in candidatePath:
        PATH = candidatePath
        break
if PATH == "":
    print('DevKit does not exist in your Path variable.\nChecking default location.')
    PATH = 'F:\\jiujilv\\devkitARM\\devkitARM\\bin'
    #PATH = 'F:\\jiujilv\\devkitARM\\devkitARM\\bin'
    if not os.path.isdir(PATH):
        print("...\nDevkit not found.")
        sys.exit(1)
    else:
        print("Devkit found.")

PREFIX = '/arm-none-eabi-'
AS = (PATH + PREFIX + 'as')
CC = (PATH + PREFIX + 'gcc')
CPP = (PATH + PREFIX + 'g++')
LD = (PATH + PREFIX + 'ld')
OBJCOPY = (PATH + PREFIX + 'objcopy')
SRC = './src'
BUILD = './build'
ASFLAGS = [AS, '-mthumb', '-I', SRC]
LDFLAGS = ['BPEE.ld', '-T', 'linker.ld']
LDFLAGS_next = ['BPEE.ld', '-T', 'linker_next.ld']
CFLAGS = [CC,'-mthumb', '-mno-thumb-interwork', '-mcpu=arm7tdmi', '-mtune=arm7tdmi',
          '-mno-long-calls', '-march=armv4t', '-Wall','-Wextra', '-Os', '-fira-loop-pressure', '-fipa-pta']

CPPFLAGS = CFLAGS + ['-fno-exceptions','-fno-unwind-tables','-fno-asynchronous-unwind-tables','-std=c++11']
CPPFLAGS[0] = CPP
def run_command(cmd):
    try:
        subprocess.check_output(cmd)
    except subprocess.CalledProcessError as e:
        print(e.output.decode(), file=sys.stderr)
        sys.exit(1)

def file_modifiled(in_file,out_file):
    #if os.path.exists(out_file):
    #    return os.path.getmtime(in_file) > os.path.getmtime(out_file)
    return True

def make_output_file(filename):
    """Return hash of filename to use as object filename"""
    m = hashlib.md5()
    m.update(filename.encode())
    return os.path.join(BUILD, m.hexdigest() + '.o')

def process(in_file,cmd,msg):
    out_file = make_output_file(in_file)
    if file_modifiled(in_file, out_file):
        print(msg % in_file)
        run_command(cmd+['-c', in_file, '-o', out_file])
    return out_file

def process_next(in_file,cmd,msg):
    out_file = make_output_file(in_file)
    if file_modifiled(in_file, out_file):
        print(msg % in_file)
        run_command(cmd+['-c', in_file, '-o', out_file])
    return out_file

def process_assembly(in_file):
    return process(in_file,ASFLAGS,'Assembling %s')


def process_c(in_file):
    return process(in_file,CFLAGS,'Compiling %s')

def process_c_next(in_file):
    return process_next(in_file,CFLAGS,'CompilingNext %s')

def process_cpp(in_file):
    return process(in_file,CPPFLAGS,'Compiling %s')

def link(objects):
    """Link objects into one binary"""
    linked = 'build/linked.o'
    cmd = [LD] + LDFLAGS + ['-o', linked] + list(objects)
    run_command(cmd)
    return linked

def link_next(objects):
    """Link objects into one binary"""
    linked = 'build/linked_next.o'
    cmd = [LD] + LDFLAGS_next + ['-o', linked] + list(objects)
    run_command(cmd)
    return linked

def objcopy(binary):
    cmd = [OBJCOPY, '-O', 'binary', binary, 'build/output.bin']
    run_command(cmd)

def objcopy_next(binary):
    cmd = [OBJCOPY, '-O', 'binary', binary, 'build/more_abilities_list.bin']
    run_command(cmd)

def run_glob(globstr, fn):
    """Glob recursively and run the processor function on each file in result"""
    if sys.version_info > (3, 4):
        files = glob(os.path.join(SRC, globstr), recursive=True)
        if './src\MoreAbilities\MoreAbilities.c' in files:
            # 重新指定MoreAbilities.c写入的位置
            files.remove('./src\MoreAbilities\MoreAbilities.c')
        return map(fn, files)
    else:
        files = Path(SRC).glob(globstr)
        return map(fn, map(str, files))

def run_glob_next(globstr, fn):
    files = glob(globstr)
    return map(fn, files)


def main():
    globs = [('**/*.s', process_assembly),('**/*.cpp',process_cpp), ('**/*.c', process_c)]
    # Create output directory
    try:
        os.makedirs(BUILD)
    except FileExistsError:
        pass

    # Gather source files and process them
    objects = itertools.starmap(run_glob, globs)

    # Link and extract raw binary
    linked = link(itertools.chain.from_iterable(objects))
    objcopy(linked)
	


if __name__ == '__main__':
    main()
