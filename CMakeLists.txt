cmake_minimum_required(VERSION 3.23)
project(POKEMON_EMERALD_G9_PROJECT C)

set(CMAKE_C_STANDARD 11)

include_directories(src)
include_directories(src/defines)
include_directories(src/megaimages)

add_executable(POKEMON_EMERALD_G9_PROJECT
        src/defines/abilities.h
        src/defines/battle_structs_cpp.h
        src/defines/flavours.h
        src/defines/get_attr.h
        src/defines/item_effects.h
        src/defines/items.h
        src/defines/moves.h
        src/defines/poke_types.h
        src/defines/pokes.h
        src/megaimages/indicators.h
        src/megaimages/mega_trigger.h
        src/MoreAbilities/Funcs.c
        src/abcd.c
        src/ability_effects.c
        src/accuracycalc.c
        src/allocnewstruct.c
        src/battle_animations.c
        src/battle_locations.h
        src/battle_strings.c
        src/battle_structs.h
        src/battle_system.c
        src/battle_system_part2.c
        src/battleorder_calc.c
        src/BattleRecording.c
        src/battlescripts.c
        src/bs_start_attack.c
        src/bscommands_updated.c
        src/config.h
        src/cppdefines.h
        src/critcalc.c
        src/custom_battles.c
        src/damagecalc.c
        src/defines.h
        src/display_mega_symbols.c
        src/double_wild_battles.c
        src/gen7_new_move_effect.c
        src/graphics_related.c
        src/helper_functions.c
        src/item_effects.c
        src/lastdamageadjustment.c
        src/learnset.c
        src/learnset.h
        src/mega_activation.c
        src/move_table.c
        src/new_battle_routine.c
        src/new_battle_struct.h
        src/primal_reversion.c
        src/statchange.c
        src/static_references.h
        src/trainer_msg_sliding.c
        src/TrainerAi.c
        src/types.h
        src/vanilla_functions.h)
