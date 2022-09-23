#ifndef ENGINE7_LEARNSETS_H
#define ENGINE7_LEARNSETS_H

#include "defines.h"

#define MOVE_BLANK 0xFFFF
#define END 0xFF
#define EGG_MOVESET 0x00000000
#define LEVEL_EVO 0x00


struct learnset{
	u16 move;
	u16 level;
};


extern const struct learnset* gLevelUpLearnsets[ALL_POKES];


#endif //ENGINE7_LEARNSETS_H
