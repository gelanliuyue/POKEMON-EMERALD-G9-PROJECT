#include "../defines.h"
#include "../static_references.h"

u16 GetAbilityBySpecies(u16 species, u8 slot);
void RecordAbilityBattle(u8 battlerId, u16 abilityId);
void ClearBattlerAbilityHistory(u8 battlerId);
void BtlController_EmitPrintString(u8 bufferId, u16 stringID);
void BtlController_EmitPrintSelectionString(u8 bufferId, u16 stringID);
void longcall battle_buffer_reset(u8 bufferId, u8 *data, u16 size);
extern u8 bbp_for_banks[0x100];
extern const struct move_info const move_table[];
struct string_inf
{
	u8 cmdID;
	u8 outcome;
	u16 stringID;
	u16 moves[2]; //curr move and last move
	u16 last_item;
	// u8 last_ability;
	u16 last_ability;
	u8 scr_active;
	u8 b_stuff_52;
	u8 b_stuff_hpbadscale;
	u8 another_act;
	u8 move_type;
	// u8 abilities[4];
	u16 abilities[4];
	u8 buffs[3][0x10];
};

/**
 * @用于获取精灵特性
 */
u16 GetAbilityBySpecies(u16 species, u8 slot)
{
    return (last_used_ability = glPokeAbilities[species][slot]);
}

/**
 * @支持0xFFFF个特性
 */
void RecordAbilityBattle(u8 battlerId, u16 abilityId)
{
	gRecordAbilities[battlerId] = abilityId;
}

/**
 * @支持0xFFFF个特性
 */
void ClearBattlerAbilityHistory(u8 battlerId)
{
	gRecordAbilities[battlerId] = 0;
}

/**
 * @支持0xFFFF个特性
 */
void BtlController_EmitPrintString(u8 bufferId, u16 stringID)
{
	struct string_inf *Strings = (struct string_inf *)bbp_for_banks;

	Strings->cmdID = 16;
	Strings->outcome = battle_outcome;
	Strings->stringID = stringID;
	Strings->moves[0] = current_move;
	Strings->moves[1] = last_used_move;
	Strings->last_item = last_used_item;
	Strings->last_ability = last_used_ability;
	Strings->scr_active = battle_scripting.active_bank;
	Strings->b_stuff_52 = battle_stuff_ptr->field_52;
	Strings->b_stuff_hpbadscale = battle_stuff_ptr->curr_hp_bad_scale;
	Strings->another_act = another_active_bank;
	Strings->move_type = move_table[current_move].type;
	
	for (u8 i = 0; i < 4; i++)
        Strings->abilities[i] = gBankAbilities[i];
    for (u8 i = 0; i < 0x10; i++)
    {
        Strings->buffs[0][i] = battle_text_buff1[i];
        Strings->buffs[1][i] = battle_text_buff2[i];
        Strings->buffs[2][i] = battle_text_buff3[i];
    }
    battle_buffer_reset(bufferId, bbp_for_banks, sizeof(struct string_inf) + 4);
}

/**
 * @支持0xFFFF个特性
 */
void BtlController_EmitPrintSelectionString(u8 bufferId, u16 stringID)
{
	struct string_inf *Strings = (struct string_inf *)bbp_for_banks;

	Strings->cmdID = 17;
	Strings->outcome = 17;
	Strings->stringID = stringID;
	Strings->moves[0] = current_move;
	Strings->moves[1] = last_used_move;
	Strings->last_item = last_used_item;
	Strings->last_ability = last_used_ability;
	Strings->scr_active = battle_scripting.active_bank;
	Strings->b_stuff_52 = battle_stuff_ptr->field_52;
	
	for (u8 i = 0; i < 4; i++)
        Strings->abilities[i] = gBankAbilities[i];
    for (u8 i = 0; i < 0x10; i++)
    {
        Strings->buffs[0][i] = battle_text_buff1[i];
        Strings->buffs[1][i] = battle_text_buff2[i];
        Strings->buffs[2][i] = battle_text_buff3[i];
    }
    battle_buffer_reset(bufferId, bbp_for_banks, sizeof(struct string_inf) + 4);
}