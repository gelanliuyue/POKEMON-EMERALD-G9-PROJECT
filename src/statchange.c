#include "defines.h"
#include "static_references.h"

u8 is_of_type(u8 bank, u8 type);
u8 protect_affecting_moves(u16 move);
u8 weather_abilities_effect(void);
u8 ability_battle_effects(u8 switch_id, u8 bank, u16 ability_to_check, u8 special_cases_argument, u16 move);
u8 has_ability_effect(u8 bank, u8 mold_breaker);
u8 get_bank_side(u8 bank);
void bs_push(void* to_return, void* now);
void bs_push_current(void* now);
static u8 unable_to_change(u8 bank, void* bs_ret, void* bs_string, u8 ability)
{
    bs_push(bs_ret, bs_string);
    if (ability)
    {
        last_used_ability = ability;
        record_usage_of_ability(bank, ability);
    }
    return STAT_UNABLE;
}
bool is_class_FOUR(u8 bank);
u8 change_stats(u8 bank, u8 bits, void* bs_unable) //returns 1 if unable to change stats, 0 otherwise
{

    u8* statchanger = &battle_scripting.stat_changer;
    u16 ability = gBankAbilities[bank];
    if (!has_ability_effect(bank, (bank == bank_target)))
        ability = 0;
    //set bank for strings
	battle_scripting.active_bank = bank;
    //check abilities that may change the stat
    if (ability == ABILITY_CONTRARY)
        *statchanger ^= STAT_NEGATIVE;
    else if (ability == ABILITY_SIMPLE)
    {
        u8 stage = *statchanger & STAT_STAGES;
        *statchanger = BIC(*statchanger, STAT_STAGES);
        *statchanger |= (stage * 2);
    }

    u8 statID = *statchanger & STAT_STATID;
    //prepare stat string
    battle_text_buff1[0] = 0xFD;
    battle_text_buff1[1] = 5; //stats
    battle_text_buff1[2] = statID;
    battle_text_buff1[3] = 0xFF;

    //check abilities that can prevent lowering stats and mist&similar
    bool lower = (*statchanger & STAT_NEGATIVE);

    if (lower && !(bits & STAT_SELFINFLICTED))
    {
        if (side_affecting_halfword[get_bank_side(bank)].mist_on)
        {
            if (bits & STAT_PRINTABILITY)
                return unable_to_change(bank, bs_unable, (void*)(0x082DAE03), 0);
            if (bs_unable)
                battlescripts_curr_instruction = bs_unable;
            return STAT_UNABLE;
        }
        void* bs_ability = NULL;
        switch (ability)
        {
        case ABILITY_FLOWER_VEIL:
            if (!is_of_type(bank, TYPE_GRASS)) {break;}
        case ABILITY_WHITE_SMOKE:	
        case ABILITY_CLEAR_BODY:	
        case ABILITY_FULL_METAL_BODY:
            bs_ability = (void*)(0x082DB5C7);
            break;
		case ABILITY_SCRAPPY:
		case ABILITY_INNER_FOCUS:
		case ABILITY_OBLIVIOUS:
		case ABILITY_OWN_TEMPO:
			if(new_battlestruct->various.intimidating){
				bs_ability = (void*)(0x082DB5C7);
				new_battlestruct->various.intimidating = 0;
			}
            break;
        case ABILITY_BIG_PECKS:
            if (statID == STAT_DEFENCE)
                bs_ability = (void*)(0x082DB62F);
            break;
        case ABILITY_KEEN_EYE:
            if (statID == STAT_ACCURACY)
                bs_ability = (void*)(0x082DB62F);
            break;
        case ABILITY_HYPER_CUTTER:
            if (statID == STAT_ATTACK)
                bs_ability = (void*)(0x082DB62F);
            break;
		case ABILITY_MIRROR_ARMOR:
			if (get_bank_side(bank_target) != get_bank_side(bank_attacker) && !new_battlestruct->various.mirror_armor_affecting){
				if(bank == bank_attacker)
					bs_ability = BS_MIRROR_ARMOR_ASATK;
				else if(bank == bank_target)
					bs_ability = BS_MIRROR_ARMOR_ASDEF;
				if (bs_ability){
					new_battlestruct->various.mirror_armor_affecting = 1;
					return unable_to_change(bank, bs_unable, bs_ability, 1);
				}
			}
			break;
        }
         if (bs_ability)
         {
            if (bits & STAT_PRINTABILITY)
                return unable_to_change(bank, bs_unable, bs_ability, 1);
            if (bs_unable)
                battlescripts_curr_instruction = bs_unable;
            return STAT_UNABLE;
         }	 
		if(is_class_FOUR(bank))
			return STAT_CANT_GO_DOWN;
		
    }

    //get stat ptr
    u8* stat = &battle_participants[bank].hp_buff + statID;
    u8* chooser = &battle_communication_struct.multistring_chooser;
    *chooser = 0;

    //we're lowering stats
    if (lower)
    {
		new_battlestruct->various.mirror_armor_affecting = 0;
        if (*stat == 0) //cant go any lower
        {   return STAT_CANT_GO_DOWN;}

        if (bits & STAT_CHANGE_VALUES)
        {
            //check if tries to lower by too many stages
            while ((*statchanger & STAT_STAGES) >> 4 > *stat)
            {   *statchanger -= 0x10;}

            //lower the stat in the data
            u8 stages = (*statchanger & STAT_STAGES) >> 4;
            *stat -= stages;
            new_battlestruct->bank_affecting[bank].stat_lowered_battle_turn = 1;
            if (!(bits & STAT_SELFINFLICTED))
                new_battlestruct->bank_affecting[bank].stat_lowered = 1;
        }
    }

    else
    {
        if (*stat == 0xC) //cant go any higher
        {   return STAT_CANT_GO_UP;}

        if (bits & STAT_CHANGE_VALUES)
        {
            //check if tries to raise by too many stages
            while (((*statchanger & STAT_STAGES) >> 4) + *stat > 0xC)
            {   *statchanger -= 0x10;}

            //lower the stat in the data
            u8 stages = (*statchanger & STAT_STAGES) >> 4;
            *stat += stages;
            new_battlestruct->bank_affecting[bank].stat_raised_battle_turn = 1;
        }
    }
	if(new_battlestruct->various.intimidating){
		new_battlestruct->various.intimidating = 0;
		new_battlestruct->bank_affecting[bank].be_intimidated = 1;
	}
    *chooser = 1;
    return STAT_CHANGED;
}
