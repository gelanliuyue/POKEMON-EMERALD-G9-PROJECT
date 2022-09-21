#include "defines.h"
#include "static_references.h"

u8 get_airborne_state(u8 bank, u8 mode, u8 check_levitate);
u8 can_lose_item(u8 bank, u8 stickyholdcheck, u8 sticky_message);
u8 is_item_a_plate(u16 item);
u16 get_battle_item_extra_param(u32 bank);
u8 ability_battle_effects(u8 switch_id, u8 bank, u16 ability_to_check, u8 special_cases_argument, u16 move);
u8 get_item_effect(u8 bank, u8 check_negating_effects);
u8 has_ability_effect(u8 bank, u8 mold_breaker);
s8 get_move_position(u8 bank, u16 move);
u8 weather_abilities_effect();
u8 is_of_type(u8 bank, u8 type);
bool check_ability(u8 bank, u16 ability);
bool check_ability_with_mold(u8 bank, u16 ability);
u8 is_bank_present(u8 bank);
void move_to_buff1(u16 move);
u8 get_bank_side(u8 bank);
void bs_push_current(void *now);
bool photon_geyser_special(u16 move); //JeremyZ
u32 get_item_extra_param(u32 bank);
u8 z_protect_affects(u16 move); //JeremyZ
u8 check_field_for_ability(enum poke_abilities ability, u8 side_to_ignore, u8 mold);

struct natural_gift {
    u8 move_power;
    u8 move_type;
};

const struct natural_gift natural_gift_table[] = {{0xFF, 0},
		//0x85-0xaf
        {80, TYPE_FIRE},
        {80, TYPE_WATER},
        {80, TYPE_ELECTRIC},
        {80, TYPE_GRASS},
        {80, TYPE_ICE},
        {80, TYPE_FIGHTING},
        {80, TYPE_POISON},
        {80, TYPE_GROUND},
        {80, TYPE_FLYING},
        {80, TYPE_PSYCHIC},
        {80, TYPE_BUG},
        {80, TYPE_ROCK},
        {80, TYPE_GHOST},
        {80, TYPE_DRAGON},
        {80, TYPE_DARK},
        {80, TYPE_STEEL},
        {90, TYPE_FIRE},
        {90, TYPE_WATER},
        {90, TYPE_ELECTRIC},
        {90, TYPE_GRASS},
        {90, TYPE_ICE},
        {90, TYPE_FIGHTING},
        {90, TYPE_POISON},
        {90, TYPE_GROUND},
        {90, TYPE_FLYING},
        {90, TYPE_PSYCHIC},
        {90, TYPE_BUG},
        {90, TYPE_ROCK},
        {90, TYPE_GHOST},
        {90, TYPE_DRAGON},
        {90, TYPE_DARK},
        {90, TYPE_STEEL},
        {100, TYPE_FIRE},
        {100, TYPE_WATER},
        {100, TYPE_ELECTRIC},
		{100, TYPE_GRASS},
		{100, TYPE_ICE},
        {100, TYPE_FIGHTING},
        {100, TYPE_POISON},
        {100, TYPE_GROUND},
        {100, TYPE_FLYING},
        {100, TYPE_PSYCHIC},
        {100, TYPE_BUG},
		//0x2c0-0x2d1 ReduxBerry
        {80, TYPE_FIRE},
        {80, TYPE_WATER},
        {80, TYPE_ELECTRIC},
        {80, TYPE_GRASS},
        {80, TYPE_ICE},
        {80, TYPE_FIGHTING},
        {80, TYPE_POISON},
        {80, TYPE_GROUND},
        {80, TYPE_FLYING},
        {80, TYPE_PSYCHIC},
        {80, TYPE_BUG},
        {80, TYPE_ROCK},
        {80, TYPE_GHOST},
        {80, TYPE_DRAGON},
        {80, TYPE_DARK},
        {80, TYPE_STEEL},
		{80, TYPE_NORMAL},
		{80, TYPE_FAIRY},
		{100, TYPE_ROCK},//Micle Berry
		{100, TYPE_GHOST},//Custap Berry
		{100, TYPE_DRAGON},//Jaboca Berry	
		{100, TYPE_DARK},//Rowap Berry
		{100, TYPE_FAIRY},//Kee Berry
		{100, TYPE_DARK}//Maranga Berry
		
};

struct fling {
    u16 item_id;
    u8 move_power;
    u16 move_effect;
};

const struct fling fling_table[] = {
		{ITEM_SEAINCENSE, 10, 0},
		{ITEM_LAXINCENSE, 10, 0},
		{ITEM_ODDINCENSE, 10, 0},
		{ITEM_ROCKINCENSE, 10, 0},
		{ITEM_FULLINCENSE, 10, 0},
		{ITEM_WAVEINCENSE, 10, 0},
		{ITEM_ROSEINCENSE, 10, 0},
		{ITEM_LUCKINCENSE, 10, 0},
		{ITEM_PUREINCENSE, 10, 0},
		{ITEM_AIRBALLOON, 10, 0},
		{ITEM_BIGROOT, 10, 0},
		{ITEM_BRIGHTPOWDER, 10, 0},
		{ITEM_CHOICEBAND, 10, 0},
		{ITEM_CHOICESCARF, 10, 0},
		{ITEM_CHOICESPECS, 10, 0},
		{ITEM_DESTINYKNOT, 10, 0},
		{ITEM_ELECTRICSEED, 10, 0},
		{ITEM_EXPERTBELT, 10, 0},
		{ITEM_FOCUSBAND, 10, 0},
		{ITEM_FOCUSSASH, 10, 0},
		{ITEM_GRASSYSEED, 10, 0},
		{ITEM_LAGGINGTAIL, 10, 0},
		{ITEM_LEFTOVERS, 10, 0},
		{ITEM_MENTALHERB, 10, 0},
		{ITEM_METALPOWDER, 10, 0},
		{ITEM_MISTYSEED, 10, 0},
		{ITEM_MUSCLEBAND, 10, 0},
		{ITEM_PINKNECTAR, 10, 0},
		{ITEM_POWERHERB, 10, 0},
		{ITEM_PSYCHICSEED, 10, 0},
		{ITEM_PURPLENECTAR, 10, 0},
		{ITEM_QUICKPOWDER, 10, 0},
		{ITEM_REAPERCLOTH, 10, 0},
		{ITEM_REDCARD, 10, 0},
		{ITEM_REDNECTAR, 10, 0},
		{ITEM_RINGTARGET, 10, 0},
		{ITEM_SHEDSHELL, 10, 0},
		{ITEM_SILKSCARF, 10, 0},
		{ITEM_SILVERPOWDER, 10, 0},
		{ITEM_SMOOTHROCK, 10, 0},
		{ITEM_SOFTSAND, 10, 0},
		{ITEM_SOOTHEBELL, 10, 0},
		{ITEM_WHITEHERB, 10, 0},
		{ITEM_WIDELENS, 10, 0},
		{ITEM_WISEGLASSES, 10, 0},
		{ITEM_YELLOWNECTAR, 10, 0},
		{ITEM_ZOOMLENS, 10, 0},
		
        {ITEM_ANTIDOTE, 30, 0},
        {ITEM_PARLYZHEAL, 30, 0},
        {ITEM_AWAKENING, 30, 0},
        {ITEM_BURNHEAL, 30, 0},
        {ITEM_ICEHEAL, 30, 0},
        {ITEM_FULLHEAL, 30, 0},
        {ITEM_FULLRESTORE, 30, 0},
        {ITEM_LAVACOOKIE, 30, 0},
        {ITEM_POTION, 30, 0},
        {ITEM_SUPERPOTION, 30, 0},
        {ITEM_HYPERPOTION, 30, 0},
        {ITEM_MAXPOTION, 30, 0},
        {ITEM_HEALPOWDER, 30, 0},
        {ITEM_ENERGYPOWDER, 30, 0},
        {ITEM_ENERGYROOT, 30, 0},
        {ITEM_REVIVALHERB, 30, 0},
        {ITEM_REVIVE, 30, 0},
        {ITEM_MAXREVIVE, 30, 0},
        {ITEM_SODAPOP, 30, 0},
        {ITEM_LEMONADE, 30, 0},
        {ITEM_SODAPOP, 30, 0},
        {ITEM_MOOMOOMILK, 30, 0},
        {ITEM_BERRYJUICE, 30, 0},
        {ITEM_ETHER, 30, 0},
        {ITEM_MAXETHER, 30, 0},
        {ITEM_ELIXIR, 30, 0},
        {ITEM_MAXELIXIR, 30, 0},
        {ITEM_REPEL, 30, 0},
        {ITEM_SUPERREPEL, 30, 0},
        {ITEM_MAXREPEL, 30, 0},
        {ITEM_PROTEIN, 30, 0},
        {ITEM_ZINC, 30, 0},
        {ITEM_CALCIUM, 30, 0},
        {ITEM_CARBOS, 30, 0},
        {ITEM_HPUP, 30, 0},
        {ITEM_PPUP, 30, 0},
        {ITEM_PPMAX, 30, 0},
        {ITEM_REDSHARD, 30, 0},
        {ITEM_BLUESHARD, 30, 0},
        {ITEM_YELLOWSHARD, 30, 0},
        {ITEM_GREENSHARD, 30, 0},
        {ITEM_XACCURACY, 30, 0},
        {ITEM_XDEFEND, 30, 0},
        {ITEM_XSPEED, 30, 0},
        {ITEM_XATTACK, 30, 0},
        {ITEM_XSPECIAL, 30, 0},
        {ITEM_YELLOWFLUTE, 30, 0},
        {ITEM_BLACKFLUTE, 30, 0},
        {ITEM_WHITEFLUTE, 30, 0},
        {ITEM_REDFLUTE, 30, 0},
        {ITEM_BLUEFLUTE, 30, 0},
		{ITEM_ABSORBBULB, 30, 0},
		{ITEM_ADRENALINEORB, 30, 0},
		{ITEM_AMULETCOIN, 30, 0},
		{ITEM_BIGMUSHROOM, 30, 0},
		{ITEM_BIGPEARL, 30, 0},
		{ITEM_BINDINGBAND, 30, 0},
		{ITEM_BLACKBELT, 30, 0},
		{ITEM_BLACKGLASSES, 30, 0},
		{ITEM_BLACKSLUDGE, 30, 0},
		{ITEM_BOTTLECAP, 30, 0},
		{ITEM_CELLBATTERY, 30, 0},
		{ITEM_CHARCOAL, 30, 0},
		{ITEM_CLEANSETAG, 30, 0},
		{ITEM_DEEPSEASCALE, 30, 0},
		{ITEM_DRAGONSCALE, 30, 0},
		{ITEM_EJECTBUTTON, 30, 0},
		{ITEM_ESCAPEROPE, 30, 0},
		{ITEM_EVERSTONE, 30, 0},
		{ITEM_EXPSHARE, 30, 0},
		{ITEM_FIRESTONE, 30, 0},
		{ITEM_FLAMEORB, 30, MOVEEFFECT_BRN},
		{ITEM_FLOATSTONE, 30, 0},
		{ITEM_FLUFFYTAIL, 30, 0},
		{ITEM_GOLDBOTTLECAP, 30, 0},
		{ITEM_HEARTSCALE, 30, 0},
		{ITEM_ICESTONE, 30, 0},
		{ITEM_KINGSROCK, 30, MOVEEFFECT_FLINCH},
		{ITEM_LAVACOOKIE, 30, 0},
		{ITEM_LEAFSTONE, 30, 0},
		{ITEM_LIFEORB, 30, 0},
		{ITEM_LIGHTBALL, 30, MOVEEFFECT_PRLZ},
		{ITEM_LIGHTCLAY, 30, 0},
		{ITEM_LUCKYEGG, 30, 0},
		{ITEM_LUMINOUSMOSS, 30, 0},
		{ITEM_MAGNET, 30, 0},
		{ITEM_METALCOAT, 30, 0},
		{ITEM_METRONOME, 30, 0},
		{ITEM_MIRACLESEED, 30, 0},
		{ITEM_MOONSTONE, 30, 0},
		{ITEM_MYSTICWATER, 30, 0},
		{ITEM_NEVERMELTICE, 30, 0},
		{ITEM_NUGGET, 30, 0},
		{ITEM_PEARL, 30, 0},
		{ITEM_POKEDOLL, 30, 0},
		{ITEM_PRISMSCALE, 30, 0},
		{ITEM_PROTECTIVEPADS, 30, 0},
		{ITEM_RAZORFANG, 30, MOVEEFFECT_FLINCH},
		{ITEM_SACREDASH, 30, 0},
		{ITEM_SCOPELENS, 30, 0},
		{ITEM_SHELLBELL, 30, 0},
		{ITEM_SHOALSALT, 30, 0},
		{ITEM_SHOALSHELL, 30, 0},
		{ITEM_SMOKEBALL, 30, 0},
		{ITEM_SNOWBALL, 30, 0},
		{ITEM_SOULDEW, 30, 0},
		{ITEM_SPELLTAG, 30, 0},
		{ITEM_STARPIECE, 30, 0},
		{ITEM_STARDUST, 30, 0},
		{ITEM_SUNSTONE, 30, 0},
		{ITEM_THUNDERSTONE, 30, 0},
		{ITEM_TINYMUSHROOM, 30, 0},
		{ITEM_TOXICORB, 30, MOVEEFFECT_TOXIC},
		{ITEM_TWISTEDSPOON, 30, 0},
		{ITEM_UPGRADE, 30, 0},
		{ITEM_WATERSTONE, 30, 0},
		
		{ITEM_EVIOLITE, 40, 0},
		{ITEM_ICYROCK, 40, 0},
        {ITEM_LUCKYPUNCH, 40, 0},
		
		{ITEM_FIGHTINGMEMORY, 50, 0},
		{ITEM_FLYINGMEMORY, 50, 0},
		{ITEM_POISONMEMORY, 50, 0},
		{ITEM_GROUNDMEMORY, 50, 0},
		{ITEM_ROCKMEMORY, 50, 0},
		{ITEM_BUGMEMORY, 50, 0},
		{ITEM_GHOSTMEMORY, 50, 0},
		{ITEM_STEELMEMORY, 50, 0},
		{ITEM_FIREMEMORY, 50, 0},
		{ITEM_WATERMEMORY, 50, 0},
		{ITEM_GRASSMEMORY, 50, 0},
		{ITEM_ELECTRICMEMORY, 50, 0},
		{ITEM_PSYCHICMEMORY, 50, 0},
		{ITEM_ICEMEMORY, 50, 0},
		{ITEM_DRAGONMEMORY, 50, 0},
		{ITEM_DARKMEMORY, 50, 0},
		{ITEM_FAIRYMEMORY, 50, 0},
		{ITEM_DUBIOUSDISC, 50, 0},
		{ITEM_SHARPBEAK, 50, 0},

		{ITEM_ADAMANTORB, 60, 0},
		{ITEM_DAMPROCK, 60, 0},
		{ITEM_GRISEOUSORB, 60, 0},
		{ITEM_HEATROCK, 60, 0},
		{ITEM_LUSTROUSORB, 60, 0},
		{ITEM_MACHOBRACE, 60, 0},
		{ITEM_ROCKYHELMET, 60, 0},
		{ITEM_STICK, 60, 0},
		{ITEM_TERRAINEXTENDER, 60, 0},

		{ITEM_DOUSEDRIVE, 70, 0},
		{ITEM_SHOCKDRIVE, 70, 0},
		{ITEM_BURNDRIVE, 70, 0},
		{ITEM_CHILLDRIVE, 70, 0},
		{ITEM_DRAGONFANG, 70, 0},
		{ITEM_POISONBARB, 70, MOVEEFFECT_PSN},

		{ITEM_ABOMASITE, 80, 0},
		{ITEM_ABSOLITE, 80, 0},
		{ITEM_AERODACTYLITE, 80, 0},
		{ITEM_AGGRONITE, 80, 0},
		{ITEM_ALAKAZITE, 80, 0},
		{ITEM_ALTARIANITE, 80, 0},
		{ITEM_AMPHAROSITE, 80, 0},
		{ITEM_AUDINITE, 80, 0},
		{ITEM_BANETTITE, 80, 0},
		{ITEM_BEEDRILLITE, 80, 0},
		{ITEM_BLASTOISINITE, 80, 0},
		{ITEM_BLAZIKENITE, 80, 0},
		{ITEM_CAMERUPTITE, 80, 0},
		{ITEM_CHARIZARDITEX, 80, 0},
		{ITEM_CHARIZARDITEY, 80, 0},
		{ITEM_DIANCITE, 80, 0},
		{ITEM_GALLADITE, 80, 0},
		{ITEM_GARCHOMPITE, 80, 0},
		{ITEM_GARDEVOIRITE, 80, 0},
		{ITEM_GENGARITE, 80, 0},
		{ITEM_GLALITITE, 80, 0},
		{ITEM_GYARADOSITE, 80, 0},
		{ITEM_HERACRONITE, 80, 0},
		{ITEM_HOUNDOOMINITE, 80, 0},
		{ITEM_KANGASKHANITE, 80, 0},
		{ITEM_LATIASITE, 80, 0},
		{ITEM_LATIOSITE, 80, 0},
		{ITEM_LOPUNNITE, 80, 0},
		{ITEM_LUCARIONITE, 80, 0},
		{ITEM_MANECTITE, 80, 0},
		{ITEM_MAWILITE, 80, 0},
		{ITEM_MEDICHAMITE, 80, 0},
		{ITEM_METAGROSSITE, 80, 0},
		{ITEM_MEWTWONITEX, 80, 0},
		{ITEM_MEWTWONITEY, 80, 0},
		{ITEM_PIDGEOTITE, 80, 0},
		{ITEM_PINSIRITE, 80, 0},
		{ITEM_SABLENITE, 80, 0},
		{ITEM_SALAMENCITE, 80, 0},
		{ITEM_SCEPTILITE, 80, 0},
		{ITEM_SCIZORITE, 80, 0},
		{ITEM_SHARPEDONITE, 80, 0},
		{ITEM_SLOWBRONITE, 80, 0},
		{ITEM_STEELIXITE, 80, 0},
		{ITEM_SWAMPERTITE, 80, 0},
		{ITEM_TYRANITARITE, 80, 0},
		{ITEM_VENUSAURITE, 80, 0},
		{ITEM_ASSAULTVEST, 80, 0},
		{ITEM_DAWNSTONE, 80, 0},
		{ITEM_DUSKSTONE, 80, 0},
		{ITEM_ELECTIRIZER, 80, 0},
		{ITEM_MAGMARIZER, 80, 0},
		{ITEM_OVALSTONE, 80, 0},
		{ITEM_PROTECTOR, 80, 0},
		{ITEM_QUICKCLAW, 80, 0},
		{ITEM_RAZORCLAW, 80, 0},
		{ITEM_SACHET, 80, 0},
		{ITEM_SAFETYGOGGLES, 80, 0},
		{ITEM_SHINYSTONE, 80, 0},
		{ITEM_STICKYBARB, 80, 0},
		{ITEM_WEAKNESSPOLICY, 80, 0},
		{ITEM_WHIPPEDDREAM, 80, 0},

		{ITEM_DEEPSEATOOTH, 90, 0},
		{ITEM_GRIPCLAW, 90, 0},
		{ITEM_THICKCLUB, 90, 0},

		{ITEM_DOMEFOSSIL, 100, 0},
		{ITEM_HELIXFOSSIL, 100, 0},
		{ITEM_OLDAMBER, 100, 0},
		{ITEM_ROOTFOSSIL, 100, 0},
		{ITEM_CLAWFOSSIL, 100, 0},
		{ITEM_SKULLFOSSIL, 100, 0},
		{ITEM_ARMORFOSSIL, 100, 0},
		{ITEM_COVERFOSSIL, 100, 0},
		{ITEM_PLUMEFOSSIL, 100, 0},
		{ITEM_JAWFOSSIL, 100, 0},
		{ITEM_SAILFOSSIL, 100, 0},
		{ITEM_HARDSTONE, 100, 0},
		
		{ITEM_IRONBALL, 130, 0},
        {0xFFFF, 0, 0}
};

bool can_evolve(u16 species) {
    const struct evolution_sub *evo = GET_EVO_TABLE(species);
    for (u8 i = 0; i < NUM_OF_EVOS; i++) {
        u8 method = evo[i].method;
        if (method != 0 && method < 0xFA)
            return true;
    }
    return false;
}

u32 percent_boost(u32 number, u16 percent) {
    return number * (100 + percent) / 100;
}

u32 percent_lose(u32 number, u16 percent) {
    return number * (100 - percent) / 100;
}

u16 chain_modifier(u16 curr_modifier, u16 new_modifier) {
    u16 updated_modifier;
    if (curr_modifier == 0) {
        updated_modifier = new_modifier;
    } else {
        u32 calculations = (curr_modifier * new_modifier + 0x800) >> 12;
        updated_modifier = calculations;
    }
    return updated_modifier;
}

u32 apply_modifier(u16 modifier, u32 value) {
    u32 multiplication = modifier * value;
    u32 anding_result = 0xFFF & multiplication;
    u32 new_value = multiplication >> 0xC;
    if (anding_result > 0x800) {
        new_value++;
    }
    return new_value;
}

u16 percent_to_modifier(u8 percent) //20 gives exactly 0x1333, 30 is short on 1
{
    return 0x1000 + (percent * 819 / 20);
}

u16 apply_statboost(u16 stat, u8 boost) {
    static const struct stat_fractions stat_buffs[13] = {{2, 8}, {2, 7}, {2, 6}, {2, 5}, {2, 4},
            {2, 3}, {2, 2}, {3, 2}, {4, 2}, {5, 2}, {6, 2}, {7, 2}, {8, 2}};
    return stat * stat_buffs[boost].dividend / stat_buffs[boost].divisor;
}

u16 get_poke_weight(u8 bank) {
    u16 poke_weight = get_height_or_weight(species_to_national_dex(battle_participants[bank].species), 1); //shupian
    if (has_ability_effect(bank, 1)) {
        switch (gBankAbilities[bank]) {
            case ABILITY_HEAVY_METAL:
                poke_weight *= 2;
                break;
            case ABILITY_LIGHT_METAL:
                poke_weight /= 2;
                break;
        }
    }
    if (get_item_effect(bank, 1) == ITEM_EFFECT_FLOATSTONE)
        poke_weight /= 2;

    s16 to_sub = 1000 * new_battlestruct->bank_affecting[bank].autonomize_uses;
    poke_weight -= to_sub;
    if (poke_weight < 1)
        poke_weight = 1;

    return poke_weight;
}

u8 count_stat_increases(u8 bank, u8 eva_acc) {
    u8 *atk_ptr = &battle_participants[bank].atk_buff;
    u8 increases = 0;
    for (u8 i = 0; i < 7; i++) {
        u8 *stat_ptr = atk_ptr + i;
        if (*stat_ptr > 6) {
            if (i <= 5 || (i > 5 && eva_acc))
                increases += (*stat_ptr - 6);
        }
    }
    return increases;
}

u16 get_speed(u8 bank) {
    u16 speed = battle_participants[bank].spd;
    bool is_umbrella = get_item_effect(bank, 1) == ITEM_EFFECT_UTILITYUMBRELLA;
    //take items into account
    switch (get_item_effect(bank, 1)) {
        case ITEM_EFFECT_IRONBALL:
            speed >>= 1;
            break;
        case ITEM_EFFECT_CHOICESCARF:
            speed = percent_boost(speed, 50);
            break;
        case ITEM_EFFECT_QUICKPOWDER:
            if (battle_participants[bank].species == POKE_DITTO && !battle_participants[bank].status2.transformed)
                speed <<= 1;
            break;
    }
    //take abilities into account
    if (has_ability_effect(bank, 0)) {
        u8 weather_effect = weather_abilities_effect();
        switch (gBankAbilities[bank]) {
            case ABILITY_CHLOROPHYLL:
                if (weather_effect && SUN_WEATHER && !is_umbrella)
                    speed *= 2;
                break;
            case ABILITY_SWIFT_SWIM:
                if (weather_effect && RAIN_WEATHER && !is_umbrella)
                    speed *= 2;
                break;
            case ABILITY_SAND_RUSH:
                if (weather_effect && SANDSTORM_WEATHER)
                    speed *= 2;
                break;
            case ABILITY_SLUSH_RUSH:
                if (weather_effect && HAIL_WEATHER)
                    speed *= 2;
                break;
            case ABILITY_SURGE_SURFER:
                if (new_battlestruct->field_affecting.electic_terrain)
                    speed *= 2;
                break;
            case ABILITY_QUICK_FEET:
                if (battle_participants[bank].status.flags.poison ||
                    battle_participants[bank].status.flags.toxic_poison ||
                    battle_participants[bank].status.flags.burn ||
                    battle_participants[bank].status.flags.paralysis ||
                    battle_participants[bank].status.flags.sleep ||
                    battle_participants[bank].status.flags.freeze)
                    speed = speed * 3 / 2;
                break;
            case ABILITY_SLOW_START:
                if (new_battlestruct->bank_affecting[bank].slowstart_duration) {
                    speed /= 2;
                }
                break;
        }
    }
    //tailwind
    if (new_battlestruct->side_affecting[get_bank_side(bank)].tailwind)
        speed *= 2;
    //unburden
    if (status3[bank].unburden)
        speed *= 2;
    //swamp
    if (new_battlestruct->side_affecting[get_bank_side(bank)].swamp_spd_reduce)
        speed /= 4;
    //paralysis
    if (battle_participants[bank].status.flags.paralysis && !check_ability(bank, ABILITY_QUICK_FEET))
        speed /= 2;
    speed = apply_statboost(speed, battle_participants[bank].spd_buff);

    return speed;
}

u8 z_moves_power[800];

s8 itemid_to_berryid_new(u16 item){//Hibiki
    if(item >= FIRST_REDUX_BERRY_INDEX && item <= LAST_REDUX_BERRY_INDEX){
        return ITEM_TO_REDUX_BERRY(item);
    }
    else {
        return itemid_to_berryid(item);
    }
}

u16 get_base_power(u16 move, u8 atk_bank, u8 def_bank) {
    u16 base_power = move_table[move].base_power;
    //u8 atk_ally_bank = atk_bank ^2;
    switch (move) {
        case MOVE_GRASS_PLEDGE:
        case MOVE_FIRE_PLEDGE:
        case MOVE_WATER_PLEDGE:
            if (new_battlestruct->side_affecting[atk_bank & 1].pledge_effect) {
                base_power = 150;
            }
            break;
        case MOVE_FLING: //make fling table; before calling damage calc should check if can use this, move effect is applied here
        {            //item deletion happens after damage calculation
            u8 *effect = &battle_communication_struct.move_effect;
            u16 item = battle_participants[atk_bank].held_item;
            //check if it's a berry or herb
		if (get_item_pocket_id(item) == 4 || item == ITEM_MENTALHERB || item == ITEM_WHITEHERB) {
                base_power = 10;
                *effect = 0x38; //target gets the berry or herb effect
            }
                //check if it's a plate
            else if (is_item_a_plate(item))
                base_power = 90;
            else {
                for (u16 i = 0; fling_table[i].item_id != 0xFFFF; i++) {
                    if (fling_table[i].item_id == item) {
                        base_power = fling_table[i].move_power;
                        new_battlestruct->move_effect.effect1 = fling_table[i].move_effect;
                        break;
                    }
                }
            }
            break;
        }
        case MOVE_DRAGON_ENERGY:
        case MOVE_ERUPTION:
        case MOVE_WATER_SPOUT:
            base_power = base_power * battle_participants[atk_bank].current_hp / battle_participants[atk_bank].max_hp;
            break;
        case MOVE_FLAIL:
        case MOVE_REVERSAL: {
            u32 P = 48 * battle_participants[atk_bank].current_hp / battle_participants[atk_bank].max_hp;
            if (P <= 1)
                base_power = 200;
            else if (P >= 2 && P <= 4)
                base_power = 150;
            else if (5 <= P && P <= 9)
                base_power = 100;
            else if (10 <= P && P <= 16)
                base_power = 80;
            else if (17 <= P && P <= 32)
                base_power = 40;
            else
                base_power = 20;
        }
            break;
        case MOVE_RETURN: 
        case MOVE_PIKA_PAPOW:
        case MOVE_VEEVEE_VOLLEY:
		{
            u32 return_damage = battle_participants[atk_bank].happiness * 10 / 25;
            if (return_damage == 0)
                return_damage = 1;
            base_power = return_damage;
        }
            break;
        case MOVE_FRUSTRATION: {
            u32 frustration_damage = (255 - battle_participants[atk_bank].happiness) * 10 / 25;
            if (frustration_damage == 0)
                frustration_damage = 1;
            base_power = frustration_damage;
        }
            break;
        case MOVE_FURY_CUTTER:
        case MOVE_ROLLOUT:
        case MOVE_MAGNITUDE:
        case MOVE_PRESENT:
        case MOVE_TRIPLE_KICK:
		case MOVE_TRIPLE_AXEL:
        case MOVE_POLLEN_PUFF: //JeremyZ
            if (dynamic_base_power) {
                base_power = dynamic_base_power;
            }
            break;
        case MOVE_SPIT_UP:
            //base_power = 100 * disable_structs[atk_bank].stockpile_counter;
            //disable_structs[atk_bank].stockpile_counter = 0;
			base_power = 100 * new_battlestruct->bank_affecting[atk_bank].stockpile_counter;
            break;
        case MOVE_REVENGE:
        case MOVE_AVALANCHE: {
            struct protect_struct *protect_str = &protect_structs[bank_attacker];
            if ((protect_str->physical_damage && protect_structs->counter_target == bank_target) ||
                (protect_str->special_damage && protect_structs->mirrorcoat_target == bank_target))
                base_power *= 2;
        }
            break;
        case MOVE_WEATHER_BALL:
        case MOVE_PURSUIT:
            if (battle_scripting.damage_multiplier)
                base_power *= battle_scripting.damage_multiplier;
            break;
        case MOVE_NATURAL_GIFT: //checking for held item and the capability of using an item should happen before damage calculation
        {                   //dynamic type will be set here
            s8 berryID = itemid_to_berryid_new(battle_participants[atk_bank].held_item);
            base_power = natural_gift_table[berryID].move_power;
            battle_stuff_ptr->dynamic_move_type = natural_gift_table[berryID].move_type + 0x80;
            if ((new_battlestruct->field_affecting.ion_deluge ||
                 new_battlestruct->bank_affecting[atk_bank].electrify) && battle_stuff_ptr->dynamic_move_type == 0x80)
                battle_stuff_ptr->dynamic_move_type = TYPE_ELECTRIC + 0x80;
        }
            break;
        case MOVE_WAKEUP_SLAP:
            if (battle_participants[def_bank].status.flags.sleep || check_ability(def_bank, ABILITY_COMATOSE)) {
                base_power *= 2;
            }
            break;
        case MOVE_SMELLING_SALTS:
            if (battle_participants[def_bank].status.flags.paralysis) {
                base_power *= 2;
            }
            break;
        case MOVE_WRING_OUT:
        case MOVE_CRUSH_GRIP:
            base_power = ATLEAST_ONE(
                    120 * battle_participants[def_bank].current_hp / battle_participants[def_bank].max_hp);
            break;
        case MOVE_HEX:
            if (battle_participants[def_bank].status.int_status) {
                base_power *= 2;
                anim_arguments[7] = 1;
            }
            break;
        case MOVE_ASSURANCE:
            if (new_battlestruct->bank_affecting[def_bank].battleturn_losthp) {
                base_power *= 2;
            }
            break;
        case MOVE_TRUMP_CARD: {
            s8 pp_slot = get_move_position(atk_bank, MOVE_TRUMP_CARD);
            u8 pp;
            if (pp_slot == -1) {
                pp = 4;
            } else {
                pp = battle_participants[atk_bank].current_pp[pp_slot];
            }
            switch (pp) {
                case 0:
                    base_power = 200;
                    break;
                case 1:
                    base_power = 80;
                    break;
                case 2:
                    base_power = 60;
                    break;
                case 3:
                    base_power = 50;
                    break;
                default:
                    base_power = 40;
                    break;
            }
            break;
        }
        case MOVE_ACROBATICS:
            if (!battle_participants[atk_bank].held_item) {
                base_power *= 2;
            }
            break;
        case MOVE_LOW_KICK:
        case MOVE_GRASS_KNOT: {
            u16 defender_weight = get_poke_weight(def_bank);
            if (defender_weight < 100)
                base_power = 20;
            else if (defender_weight < 250)
                base_power = 40;
            else if (defender_weight < 500)
                base_power = 60;
            else if (defender_weight < 1000)
                base_power = 80;
            else if (defender_weight < 2000)
                base_power = 100;
            else
                base_power = 120;
            break;
        }
        case MOVE_HEAT_CRASH:
        case MOVE_HEAVY_SLAM: {
            u16 weight_difference = get_poke_weight(atk_bank) / get_poke_weight(def_bank);

            if (weight_difference >= 5)
                base_power = 120;
            else if (weight_difference == 4)
                base_power = 100;
            else if (weight_difference == 3)
                base_power = 80;
            else if (weight_difference == 2)
                base_power = 60;
            else
                base_power = 40;
            break;
        }
        case MOVE_PUNISHMENT:
            base_power = 60 + 20 * count_stat_increases(def_bank, 0);
            if (base_power > 200)
                base_power = 200;
            break;
        case MOVE_STORED_POWER:
        case MOVE_POWER_TRIP: //JeremyZ
            base_power = base_power + 20 * count_stat_increases(atk_bank, 1);
            break;
        case MOVE_ELECTRO_BALL:
            switch (get_speed(atk_bank) / get_speed(def_bank)) {
                case 0:
                    base_power = 40;
                    break;
                case 1:
                    base_power = 60;
                    break;
                case 2:
                    base_power = 80;
                    break;
                case 3:
                    base_power = 120;
                    break;
                default:
                    base_power = 150;
                    break;
            }
            break;
        case MOVE_GYRO_BALL:
            base_power = (25 * get_speed(def_bank) / get_speed(atk_bank)) + 1;
            if (base_power > 150)
                base_power = 150;
            break;
        case MOVE_ECHOED_VOICE:
            base_power += 40 * new_battlestruct->field_affecting.echo_voice_counter;
            if (base_power > 200)
                base_power = 200;
            break;
        case MOVE_PAYBACK:
            if (turn_order[def_bank] < turn_order[atk_bank] && menu_choice_pbs[def_bank] != ACTION_SWITCH) {
                base_power *= 2;
            }
            break;
        case MOVE_GUST:
        case MOVE_TWISTER:
            if (new_battlestruct->bank_affecting[def_bank].sky_drop_attacker ||
                new_battlestruct->bank_affecting[def_bank].sky_drop_target || status3[def_bank].on_air) {
                base_power *= 2;
            }
            break;
        case MOVE_ROUND:
            if (current_move_turn && new_battlestruct->various.previous_move == MOVE_ROUND) {
                if((bank_attacker & 1) == (turn_order[current_move_turn - 1] & 1))base_power *= 2;
            }
            break;
        case MOVE_BEAT_UP: {
            struct pokemon *poke;
            if (get_bank_side(bank_attacker))
                poke = &party_opponent[0];
            else
                poke = &party_player[0];
            u8 poke_index = (u8) (0x02024480);
            if (get_attributes(&poke[poke_index], ATTR_CURRENT_HP, 0) == 0) {
                for (u8 i = 0; i < 6; i++) {
                    if (i > poke_index && get_attributes(&poke[i], ATTR_CURRENT_HP, 0))
                        poke_index = i;
                }
            }
            u16 species = get_attributes(&poke[poke_index], ATTR_SPECIES, 0);
            base_power = (*basestat_table)[species].base_atk / 10 + 5;
        }
            break;
        case MOVE_WATER_SHURIKEN:
            if (battle_participants[bank_attacker].species == POKE_ASH_GRENJA)
                base_power = 20;
            break;
        case MOVE_STOMPING_TANTRUM: //Stomping Tantrum, JeremyZ
            if (new_battlestruct->bank_affecting[bank_attacker].lastmove_fail
				&& (!battle_flags.double_battle || !new_battlestruct->bank_affecting[bank_attacker].move_worked_thisturn))
                base_power *= 2;
            break;
		case MOVE_BOLT_BEAK:  //Hibiki
		case MOVE_FISHIOUS_REND:
			if (get_bank_turn_order(atk_bank) < get_bank_turn_order(def_bank) || menu_choice_pbs[def_bank] == ACTION_SWITCH) {
				base_power *= 2;
			}
			break;
        case MOVE_GRAV_APPLE:
            if(new_battlestruct->field_affecting.gravity)
                base_power = base_power + base_power / 2;
            break;
        case MOVE_EXPANDING_FORCE:
            if(new_battlestruct->field_affecting.psychic_terrain && GROUNDED(atk_bank))
                base_power = base_power + base_power / 2;
            break;
		case MOVE_MISTY_EXPLOSION:
            if(new_battlestruct->field_affecting.misty_terrain && GROUNDED(atk_bank))
                base_power = base_power + base_power / 2;
            break;
		case MOVE_RISING_VOLTAGE:
            if(new_battlestruct->field_affecting.electic_terrain && GROUNDED(def_bank))
                base_power *= 2;
            break;
		case MOVE_TERRAIN_PULSE:
            if(new_battlestruct->field_affecting.electic_terrain || 
				new_battlestruct->field_affecting.grassy_terrain ||
				new_battlestruct->field_affecting.psychic_terrain ||
				new_battlestruct->field_affecting.misty_terrain)
                base_power *= 2;
            break;
		case MOVE_LASH_OUT:
			if(new_battlestruct->bank_affecting[atk_bank].stat_lowered_battle_turn)
				base_power *= 2;
			break;
    }
    if (move >= MOVE_Z_NORMAL_PHYS && move <= MOVE_Z_FAIRY_SPEC)
        base_power = z_moves_power[CURRENT_Z_MOVE];
    curr_move_BP = base_power;
    return base_power;
}

bool find_move_in_table(u16 move, const u16 *table_ptr) {
    for (u32 i = 0; table_ptr[i] != 0xFFFF; i++) {
        if (table_ptr[i] == move) { return true; }
    }
    return false;
}
bool find_poke_in_table(u16 species, const u16 *table_ptr) {
    return find_move_in_table(species, table_ptr);
}
bool does_move_make_contact(u16 move, u8 atk_bank) {
    if (move_table[move].move_flags.flags.makes_contact && !check_ability(atk_bank, ABILITY_LONG_REACH) &&
        get_item_effect(atk_bank, 1) != ITEM_EFFECT_PROTECTIVEPADS)
        return 1;
    return 0;
}

u16 apply_base_power_modifiers(u16 move, u8 move_type, u8 atk_bank, u8 def_bank, u16 base_power, bool setflag) {
    u16 modifier = 0x1000;
    u8 move_split = move_table[move].split & photon_geyser_special(move); //JeremyZ
    //u16 quality_atk_modifier = percent_to_modifier(get_item_quality(battle_participants[atk_bank].held_item));
    if (has_ability_effect(atk_bank, 0)) {
        switch (gBankAbilities[atk_bank]) {
            case ABILITY_TECHNICIAN:
                if (base_power <= 60) {
                    modifier = chain_modifier(modifier, 0x1800);
                }
                break;
            case ABILITY_FLARE_BOOST:
                if (battle_participants[atk_bank].status.flags.burn && move_split == MOVE_SPECIAL) {
                    modifier = chain_modifier(modifier, 0x1800);
                }
                break;
            case ABILITY_TOXIC_BOOST:
                if ((battle_participants[atk_bank].status.flags.toxic_poison ||
                     battle_participants[atk_bank].status.flags.poison) && move_split == MOVE_PHYSICAL) {
                    modifier = chain_modifier(modifier, 0x1800);
                }
                break;
            case ABILITY_RECKLESS:
                if (find_move_in_table(move, reckless_moves_table)) {
                    modifier = chain_modifier(modifier, 0x1333);
                }
                break;
            case ABILITY_IRON_FIST:
                if (find_move_in_table(move, &ironfist_moves_table[0])) {
                    modifier = chain_modifier(modifier, 0x1333);
                }
                break;
            case ABILITY_SHEER_FORCE:
                if (find_move_in_table(move, &sheerforce_moves_table[0])) {
                    modifier = chain_modifier(modifier, 0x14CD);
                    if(setflag) new_battlestruct->various.sheerforce_bonus = 1;
                }
                break;
            case ABILITY_SAND_FORCE:
                if (move_type == TYPE_STEEL || move_type == TYPE_ROCK || move_type == TYPE_GROUND) {
                    modifier = chain_modifier(modifier, 0x14CD);
                }
                break;
            case ABILITY_RIVALRY: {
                u8 attacker_gender = gender_from_pid(battle_participants[atk_bank].species,
                        battle_participants[atk_bank].pid);
                u8 target_gender = gender_from_pid(battle_participants[def_bank].species,
                        battle_participants[def_bank].pid);
                if (atk_bank != def_bank && attacker_gender != 0xFF && target_gender != 0xFF) {
                    if (attacker_gender == target_gender) {
                        modifier = chain_modifier(modifier, 0x1400);
                    } else {
                        modifier = chain_modifier(modifier, 0xC00);
                    }
                }
                break;
            }
            case ABILITY_ANALYTIC:
                if (get_bank_turn_order(def_bank) < turn_order[atk_bank] && move != MOVE_FUTURE_SIGHT &&
                    move != MOVE_DOOM_DESIRE) {
                    modifier = chain_modifier(modifier, 0x14CD);
                }
                break;
            case ABILITY_PUNK_ROCK:  //shupian
                if (find_move_in_table(move, &sound_moves[0])) {
                    modifier = chain_modifier(modifier, 0x14CD);
                }
                break;				
            case ABILITY_TOUGH_CLAWS:
                if (move_table[move].move_flags.flags.makes_contact) {
                    modifier = chain_modifier(modifier, 0x14CD);
                }
                break;
            case ABILITY_STRONG_JAW:
                if (find_move_in_table(move, &biting_moves_table[0])) {
                    modifier = chain_modifier(modifier, 0x1800);
                }
                break;
            case ABILITY_MEGA_LAUNCHER:
                if (find_move_in_table(move, &megalauncher_moves_table[0])) {
                    modifier = chain_modifier(modifier, 0x1800);
                }
                break;
            case ABILITY_WATER_BUBBLE:
                if (move_type == TYPE_WATER) {
                    modifier = chain_modifier(modifier, 0x2000);
                }
                break;
			case ABILITY_TRANSISTOR:
                if (move_type == TYPE_ELECTRIC) {
                    modifier = chain_modifier(modifier, 0x1800);
                }
                break;
			case ABILITY_DRAGONS_MAW:
                if (move_type == TYPE_DRAGON) {
                    modifier = chain_modifier(modifier, 0x1800);
                }
                break;
            case ABILITY_STEELWORKER:
                if (move_type == TYPE_STEEL) {
                    modifier = chain_modifier(modifier, 0x1800);
                }
                break;
			case ABILITY_STEELY_SPIRIT:
                if (move_type == TYPE_STEEL)			
                    modifier = chain_modifier(modifier, 0x1800);
                break;	
			case ABILITY_BATTERY:
                if (move_split == MOVE_SPECIAL)
                    modifier = chain_modifier(modifier, 0x14CD);
                break;	
        }
    }
	//aura
    if ((ability_battle_effects(19, 0, ABILITY_DARK_AURA, 0, 0) && move_type == TYPE_DARK) ||
        (ability_battle_effects(19, 0, ABILITY_FAIRY_AURA, 0, 0) && move_type == TYPE_FAIRY)) {
        if (ability_battle_effects(19, 0, ABILITY_AURA_BREAK, 0, 0)) {
            modifier = chain_modifier(modifier, 0xC00);
        } else {
            modifier = chain_modifier(modifier, 0x1547);
        }
    }
    //check partner abilities
    u8 atk_partner = atk_bank ^2;
    if (is_bank_present(atk_partner) && has_ability_effect(atk_partner, 0)) {
        switch (gBankAbilities[atk_partner]) {
            case ABILITY_POWER_SPOT:  //shupian
                    modifier = chain_modifier(modifier, 0x14CD);
                break;
            case ABILITY_STEELY_SPIRIT:  //shupian
                if (move_type == TYPE_STEEL)			
                    modifier = chain_modifier(modifier, 0x1800);
                break;				
            case ABILITY_BATTERY:
                if (move_split == MOVE_SPECIAL)
                    modifier = chain_modifier(modifier, 0x14CD);
                break;				
        }
    }

    //check target abilities
    if (has_ability_effect(def_bank, 1)) {
        switch (gBankAbilities[def_bank]) {
            case ABILITY_HEATPROOF:
            case ABILITY_WATER_BUBBLE:
                if (move_type == TYPE_FIRE)
                    modifier = chain_modifier(modifier, 0x800);
                break;
            case ABILITY_DRY_SKIN:
                if (move_type == TYPE_FIRE)
                    modifier = chain_modifier(modifier, 0x1400);
                break;
            case ABILITY_PUNK_ROCK: //shupian
                if (find_move_in_table(move, sound_moves))
                    modifier = chain_modifier(modifier, 0x800);
                break;	
            case ABILITY_ICE_SCALES:  //shupian
                if (move_split == MOVE_SPECIAL)
                    modifier = chain_modifier(modifier, 0x800);
                break;					
            case ABILITY_FLUFFY:
                if (does_move_make_contact(move, atk_bank))
                    modifier = chain_modifier(modifier, 0x800);
                if (move_type == TYPE_FIRE)
                    modifier = chain_modifier(modifier, 0x2000);
                break;
        }
    }
    switch (get_item_effect(atk_bank, 1)) {
        case ITEM_EFFECT_NOEFFECT:
            if (new_battlestruct->various.gem_boost) {
                if(setflag) new_battlestruct->various.gem_boost = 0;
                modifier = chain_modifier(modifier, 0x14CD);
            }
            break;
        case ITEM_EFFECT_MUSCLEBAND:
            if (move_split == MOVE_PHYSICAL) {
                modifier = chain_modifier(modifier, 0x1199);
            }
            break;
        case ITEM_EFFECT_WISEGLASSES:
            if (move_split == MOVE_SPECIAL) {
                modifier = chain_modifier(modifier, 0x1199);
            }
            break;
        case ITEM_EFFECT_LUSTROUSORB:
            if ((move_type == TYPE_WATER || move_type == TYPE_DRAGON) &&
                battle_participants[atk_bank].species == POKE_PALKIA) {
                modifier = chain_modifier(modifier, 0x1333);
            }
            break;
        case ITEM_EFFECT_ADAMANTORB:
            if ((move_type == TYPE_STEEL || move_type == TYPE_DRAGON) &&
                battle_participants[atk_bank].species == POKE_DIALGA) {
                modifier = chain_modifier(modifier, 0x1333);
            }
            break;
        case ITEM_EFFECT_GRISEOUSORB:
            if ((move_type == TYPE_GHOST || move_type == TYPE_DRAGON) &&
                (battle_participants[atk_bank].species == POKE_GIRATINA)) {
                modifier = chain_modifier(modifier, 0x1333);
            }
            break;
        case ITEM_EFFECT_PINKRIBBON:
            if (move_type == TYPE_FAIRY) {
                modifier = chain_modifier(modifier, 0x1333);
            }
            break;
        case ITEM_EFFECT_SILKSCARF:
            if (move_type == TYPE_NORMAL) {
                modifier = chain_modifier(modifier, 0x1333);
            }
            break;
        case ITEM_EFFECT_SHARPBEAK:
            if (move_type == TYPE_FLYING) {
                modifier = chain_modifier(modifier, 0x1333);
            }
            break;
        case ITEM_EFFECT_BLACKBELT:
            if (move_type == TYPE_FIGHTING) {
                modifier = chain_modifier(modifier, 0x1333);
            }
            break;
        case ITEM_EFFECT_SOFTSAND:
            if (move_type == TYPE_GROUND) {
                modifier = chain_modifier(modifier, 0x1333);
            }
            break;
        case ITEM_EFFECT_HARDSTONE:
            if (move_type == TYPE_ROCK) {
                modifier = chain_modifier(modifier, 0x1333);
            }
            break;
        case ITEM_EFFECT_MAGNET:
            if (move_type == TYPE_ELECTRIC) {
                modifier = chain_modifier(modifier, 0x1333);
            }
            break;
        case ITEM_EFFECT_NEVERMELTICE:
            if (move_type == TYPE_ICE) {
                modifier = chain_modifier(modifier, 0x1333);
            }
            break;
        case ITEM_EFFECT_BLACKGLASSES:
            if (move_type == TYPE_DARK) {
                modifier = chain_modifier(modifier, 0x1333);
            }
            break;
        case ITEM_EFFECT_SILVERPOWDER:
            if (move_type == TYPE_BUG) {
                modifier = chain_modifier(modifier, 0x1333);
            }
            break;
        case ITEM_EFFECT_SPELLTAG:
            if (move_type == TYPE_GHOST) {
                modifier = chain_modifier(modifier, 0x1333);
            }
            break;
        case ITEM_EFFECT_DRAGONFANG:
            if (move_type == TYPE_DRAGON) {
                modifier = chain_modifier(modifier, 0x1333);
            }
            break;
        case ITEM_EFFECT_MYSTICWATER:
            if (move_type == TYPE_WATER) {
                modifier = chain_modifier(modifier, 0x1333);
            }
            break;
        case ITEM_EFFECT_CHARCOAL:
            if (move_type == TYPE_FIRE) {
                modifier = chain_modifier(modifier, 0x1333);
            }
            break;
        case ITEM_EFFECT_MIRACLESEED:
            if (move_type == TYPE_GRASS) {
                modifier = chain_modifier(modifier, 0x1333);
            }
            break;
        case ITEM_EFFECT_TWISTEDSPOON:
            if (move_type == TYPE_PSYCHIC) {
                modifier = chain_modifier(modifier, 0x1333);
            }
            break;
        case ITEM_EFFECT_METALCOAT:
            if (move_type == TYPE_STEEL) {
                modifier = chain_modifier(modifier, 0x1333);
            }
            break;
        case ITEM_EFFECT_POISONBARB:
            if (move_type == TYPE_POISON) {
                modifier = chain_modifier(modifier, 0x1333);
            }
            break;
        case ITEM_EFFECT_PLATES:
            if (move_type == (u16) get_battle_item_extra_param(bank_attacker)) {
                modifier = chain_modifier(modifier, 0x1333);
            }
    }

    switch (move) {
        case MOVE_FACADE:
            if (battle_participants[atk_bank].status.flags.poison ||
                battle_participants[atk_bank].status.flags.toxic_poison ||
                battle_participants[atk_bank].status.flags.paralysis ||
                battle_participants[atk_bank].status.flags.burn) {
                modifier = chain_modifier(modifier, 0x2000);
            }
            break;
        case MOVE_BRINE:
            if (battle_participants[def_bank].current_hp < (battle_participants[def_bank].max_hp >> 1)) {
                modifier = chain_modifier(modifier, 0x2000);
            }
            break;
        case MOVE_VENOSHOCK:
            if (battle_participants[def_bank].status.flags.poison ||
                battle_participants[def_bank].status.flags.toxic_poison) {
                modifier = chain_modifier(modifier, 0x2000);
            }
            break;
        case MOVE_RETALIATE:
            if (new_battlestruct->side_affecting[get_bank_side(atk_bank)].ally_fainted_last_turn) {
                modifier = chain_modifier(modifier, 0x2000);
            }
            break;
        case MOVE_SOLAR_BEAM:
            if (!(SUN_WEATHER || battle_weather.int_bw == 0 || get_item_effect(def_bank, 1) == ITEM_EFFECT_UTILITYUMBRELLA)) {
                modifier = chain_modifier(modifier, 0x800);
            }
            break;
        case MOVE_EARTHQUAKE:
        case MOVE_MAGNITUDE:
        case MOVE_BULLDOZE:
            if (new_battlestruct->field_affecting.grassy_terrain) {
                modifier = chain_modifier(modifier, 0x800);
            }
            break;
        case MOVE_KNOCK_OFF:
            if (battle_participants[def_bank].held_item && can_lose_item(def_bank, 0, 0)) {
                modifier = chain_modifier(modifier, 0x1800);
            }
            break;
    }

    if (protect_structs[atk_bank].flag0_helpinghand) {
        modifier = chain_modifier(modifier, 0x1800);
    }

    if (status3[atk_bank].charged_up && move_type == TYPE_ELECTRIC) {
        modifier = chain_modifier(modifier, 0x2000);
    }
    if ((move_type == TYPE_ELECTRIC && new_battlestruct->field_affecting.mudsport) ||
        (move_type == TYPE_FIRE && new_battlestruct->field_affecting.watersport)) //mud and water sports
    {
        modifier = chain_modifier(modifier, 0x548);
    }
    if (new_battlestruct->bank_affecting[atk_bank].me_first) {
        modifier = chain_modifier(modifier, 0x1800);
    }
    if (new_battlestruct->field_affecting.grassy_terrain && GROUNDED(atk_bank) &&
        move_type == TYPE_GRASS) {
        modifier = chain_modifier(modifier, 0x14CD);
    }
    if (new_battlestruct->field_affecting.misty_terrain && GROUNDED(def_bank) &&
        move_type == TYPE_DRAGON) {
        modifier = chain_modifier(modifier, 0x800);
    }
    if (new_battlestruct->field_affecting.electic_terrain && GROUNDED(atk_bank) &&
        move_type == TYPE_ELECTRIC) {
        modifier = chain_modifier(modifier, 0x14CD);
    }
    if (new_battlestruct->field_affecting.psychic_terrain && GROUNDED(atk_bank) &&
        move_type == TYPE_PSYCHIC) {
        modifier = chain_modifier(modifier, 0x14CD);
    }

    return apply_modifier(modifier, base_power);
}

u16 get_attack_stat(u16 move, u8 move_type, u8 atk_bank, u8 def_bank) {
    u8 move_split = move_table[move].split & photon_geyser_special(move); //JeremyZ
    u8 stat_bank;
    bool is_umbrella = get_item_effect(atk_bank, 1) == ITEM_EFFECT_UTILITYUMBRELLA;
    if (move == MOVE_FOUL_PLAY) {
        stat_bank = def_bank;
    } else {
        stat_bank = atk_bank;
    }
    u16 attack_stat;
    u8 attack_boost;
    if (move_split == MOVE_PHYSICAL) {
        attack_stat = battle_participants[stat_bank].atk;
        attack_boost = battle_participants[stat_bank].atk_buff;
    } else {
        attack_stat = battle_participants[stat_bank].sp_atk;
        attack_boost = battle_participants[stat_bank].sp_atk_buff;
    }
    if (move == MOVE_BODY_PRESS) attack_stat = battle_participants[stat_bank].def;

    if (has_ability_effect(def_bank, 1) && gBankAbilities[def_bank] == ABILITY_UNAWARE) {
        attack_boost = 6;
    } else if (crit_loc == 2 && attack_boost < 6) {
        attack_boost = 6;
    }

    //apply stat boost to attack stat
    attack_stat = apply_statboost(attack_stat, attack_boost);

    //final modifications
    u16 modifier = 0x1000;
    if (has_ability_effect(atk_bank, 0)) {
        u8 pinch_abilities;
        if (battle_participants[atk_bank].current_hp >= (battle_participants[atk_bank].max_hp / 3))
            pinch_abilities = false;
        else
            pinch_abilities = true;

        switch (gBankAbilities[atk_bank]) {
            case ABILITY_PURE_POWER:
            case ABILITY_HUGE_POWER:
                if (move_split == MOVE_PHYSICAL) {
                    modifier = chain_modifier(modifier, 0x2000);
                }
                break;
			case ABILITY_GORILLA_TACTICS: //SHUPIAN
            if (move_split == MOVE_PHYSICAL) {
                modifier = chain_modifier(modifier, 0x1800);
            }
            break;				
            case ABILITY_SLOW_START:
                if (new_battlestruct->bank_affecting[atk_bank].slowstart_duration) {
                    modifier = chain_modifier(modifier, 0x800);
                }
                break;
            case ABILITY_SOLAR_POWER:
                if (move_split == MOVE_SPECIAL && SUN_WEATHER && !is_umbrella) {
                    modifier = chain_modifier(modifier, 0x1800);
                }
                break;
            case ABILITY_DEFEATIST:
                if (battle_participants[atk_bank].current_hp <= (battle_participants[atk_bank].max_hp >> 1)) {
                    modifier = chain_modifier(modifier, 0x800);
                }
                break;
            case ABILITY_FLASH_FIRE:
                if (move_type == TYPE_FIRE &&
                    battle_resources->ability_flags_ptr->flags_ability[atk_bank].flag1_flashfire) {
                    modifier = chain_modifier(modifier, 0x1800);
                }
                break;
            case ABILITY_SWARM:
                if (move_type == TYPE_BUG && pinch_abilities) {
                    modifier = chain_modifier(modifier, 0x1800);
                }
                break;
            case ABILITY_OVERGROW:
                if (move_type == TYPE_GRASS && pinch_abilities) {
                    modifier = chain_modifier(modifier, 0x1800);
                }
                break;
            case ABILITY_TORRENT:
                if (move_type == TYPE_GRASS && pinch_abilities) {
                    modifier = chain_modifier(modifier, 0x1800);
                }
                break;
            case ABILITY_BLAZE:
                if (move_type == TYPE_FIRE && pinch_abilities) {
                    modifier = chain_modifier(modifier, 0x1800);
                }
                break;
            case ABILITY_PLUS:
            case ABILITY_MINUS:
                if (move_split == MOVE_SPECIAL && (ability_battle_effects(20, atk_bank, ABILITY_PLUS, 0, 0) ||
                                                   ability_battle_effects(20, atk_bank, ABILITY_MINUS, 0, 0))) {
                    modifier = chain_modifier(modifier, 0x1800);
                }
                break;
            case ABILITY_HUSTLE:
                if (move_split == MOVE_PHYSICAL) {
                    attack_stat = apply_modifier(0x1800, attack_stat);
                }
                break;
			case ABILITY_GUTS:
				if (move_split == MOVE_PHYSICAL && (battle_participants[atk_bank].status.flags.poison ||
                    battle_participants[atk_bank].status.flags.toxic_poison || battle_participants[atk_bank].status.flags.burn ||
					battle_participants[atk_bank].status.flags.paralysis || battle_participants[atk_bank].status.flags.sleep ||
					battle_participants[atk_bank].status.flags.freeze)) {
					attack_stat = apply_modifier(0x1800, attack_stat);
				}
				break;
			case ABILITY_STAKEOUT:
				if (new_battlestruct->various.switch_in_cos_switch) {
					modifier = chain_modifier(modifier, 0x2000);
				}
				break;
        }
    }

    if (SUN_WEATHER) {
        u8 flower_gift_bank = ability_battle_effects(13, atk_bank, ABILITY_FLOWER_GIFT, 0, 0);
        if (flower_gift_bank && move_split == MOVE_PHYSICAL) {
            flower_gift_bank--;
            if (new_battlestruct->bank_affecting[flower_gift_bank].cherrim_form) {
                modifier = chain_modifier(modifier, 0x1800);
            }
        }
    }

    switch (get_item_effect(atk_bank, 1)) {
        case ITEM_EFFECT_THICKCLUB:
            if (move_split == MOVE_PHYSICAL) {
                u16 specie = battle_participants[atk_bank].species;
                if (specie == POKE_MAROWAK || specie == POKE_CUBONE || specie == 0x369)
                    modifier = chain_modifier(modifier, 0x2000);
            }
            break;
        case ITEM_EFFECT_DEEPSEATOOTH:
            if (move_split == MOVE_SPECIAL && (battle_participants[atk_bank].species == POKE_CLAMPERL)) {
                modifier = chain_modifier(modifier, 0x2000);
            }
            break;
		case ITEM_EFFECT_ZCRYSTAL: //Z-Crystals for Ash's Pikachu
			if (move_split == MOVE_SPECIAL && battle_participants[atk_bank].held_item == ITEM_PIKASHUNIUMZ &&
			((battle_participants[atk_bank].species >= 0X3DD && battle_participants[atk_bank].species <= 0X3E2) ||
			battle_participants[atk_bank].species == 0x434)) {
				modifier = chain_modifier(modifier, 0x2000);
			}
			break;
        case ITEM_EFFECT_LIGHTBALL:

            if (battle_participants[atk_bank].species == POKE_PIKACHU ||
                (battle_participants[atk_bank].species >= 0X3DD && battle_participants[atk_bank].species <= 0X3e2) ||
                (battle_participants[atk_bank].species >= 0x37B && battle_participants[atk_bank].species <= 0x380) ||
                battle_participants[atk_bank].species == 0x434) {
                modifier = chain_modifier(modifier, 0x2000);
            }
            break;
        case ITEM_EFFECT_SOULDEW:
            if (move_split == MOVE_SPECIAL && (battle_participants[atk_bank].species == POKE_LATIAS ||
                                               battle_participants[atk_bank].species == POKE_LATIOS)) {
                modifier = chain_modifier(modifier, 0x1800);
            }
            break;
        case ITEM_EFFECT_CHOICEBAND:
            if (move_split == MOVE_PHYSICAL) {
                modifier = chain_modifier(modifier, 0x1800);
            }
            break;
        case ITEM_EFFECT_CHOICESPECS:
            if (move_split == MOVE_SPECIAL) {
                modifier = chain_modifier(modifier, 0x1800);
            }
            break;
    }

    return apply_modifier(modifier, attack_stat);
}

u16 get_def_stat(u16 move, u8 atk_bank, u8 def_bank) {
    u8 chosen_def; //0 = def, 1 = sp.def
    u8 move_split = move_table[move].split & photon_geyser_special(move); //JeremyZ
    if (move_split == MOVE_PHYSICAL || move == MOVE_PSYSTRIKE || move == MOVE_PSYSHOCK || move == MOVE_SECRET_SWORD)
        chosen_def = 0;
    else
        chosen_def = 1;

    if (new_battlestruct->field_affecting.wonder_room)
        chosen_def ^= 1;

    u16 def_stat;
    u8 def_boost;

    if (chosen_def) // sp.def
    {
        def_stat = battle_participants[def_bank].sp_def;
        def_boost = battle_participants[def_bank].sp_def_buff;
    } else //def
    {
        def_stat = battle_participants[def_bank].def;
        def_boost = battle_participants[def_bank].def_buff;
    }

    if (check_ability(atk_bank, ABILITY_UNAWARE) || find_move_in_table(move, ignore_targetstats_moves))
        def_boost = 6;
    else if (crit_loc == 2 && def_boost > 6)
        def_boost = 6;

    //apply def boost to the stat
    def_stat = apply_statboost(def_stat, def_boost);

    u16 modifier = 0x1000;

    if (move_split == MOVE_SPECIAL) {
        if (SANDSTORM_WEATHER && is_of_type(def_bank, TYPE_ROCK) && weather_abilities_effect()) {
            modifier = chain_modifier(modifier, 0x1800);
        }
        u8 flowergift_bank = ability_battle_effects(13, def_bank, ABILITY_FLOWER_GIFT, 0, 0);
        if (flowergift_bank) {
            if (has_ability_effect(flowergift_bank - 1, 1))
                modifier = chain_modifier(modifier, 0x1800);
        }
    }

    if (check_ability_with_mold(def_bank, ABILITY_MARVEL_SCALE) && battle_participants[def_bank].status.int_status && chosen_def == 0) {
        modifier = chain_modifier(modifier, 0x1800);
    } else if (check_ability_with_mold(def_bank, ABILITY_FUR_COAT) && chosen_def == 0) {
        modifier = chain_modifier(modifier, 0x2000);
    } else if (check_ability_with_mold(def_bank, ABILITY_GRASS_PELT) && new_battlestruct->field_affecting.grassy_terrain && chosen_def == 0) {
        modifier = chain_modifier(modifier, 0x1800);
    }

    switch (get_item_effect(def_bank, 1)) {
        case ITEM_EFFECT_DEEPSEASCALE:
            if (move_split == MOVE_SPECIAL && battle_participants[def_bank].species == POKE_CLAMPERL) {
                modifier = chain_modifier(modifier, 0x1800);
            }
            break;
        case ITEM_EFFECT_SOULDEW:
            if (move_split == MOVE_SPECIAL && (battle_participants[def_bank].species == POKE_LATIAS ||
                                               battle_participants[def_bank].species == POKE_LATIOS)) {
                modifier = chain_modifier(modifier, 0x1800);
            }
            break;
        case ITEM_EFFECT_ASSAULTVEST:
            if (chosen_def == 1) {
                modifier = chain_modifier(modifier, 0x1800);
            }
            break;
        case ITEM_EFFECT_EVIOLITE:
            if (can_evolve(battle_participants[def_bank].species)) {
                modifier = chain_modifier(modifier, 0x1800);
            }
            break;
        case ITEM_EFFECT_METALPOWDER:
            if (battle_participants[def_bank].species == POKE_DITTO && move_split == MOVE_PHYSICAL &&
                !(battle_participants[def_bank].status2.transformed)) {
                modifier = chain_modifier(modifier, 0x2000);
            }
            break;
    }

    return apply_modifier(modifier, def_stat);
}

u16 type_effectiveness_calc(u16 move, u8 move_type, u8 atk_bank, u8 def_bank, u8 effects_handling_and_recording);
u8 does_move_target_multiple(void);
u8 count_alive_on_side(u8 bank);

u16 calc_reflect_modifier(u8 atk_bank, u8 def_bank, u16 final_modifier) {
    if (crit_loc != 2 && !((check_ability(atk_bank, ABILITY_INFILTRATOR)))) {
        if (count_alive_on_side(def_bank) == 2 && battle_flags.double_battle)
            final_modifier = chain_modifier(final_modifier, 0xA8F);
        else
            final_modifier = chain_modifier(final_modifier, 0x800);
    }
    return final_modifier;
}
u32 random_value(u32 limit);
void damage_calc(u16 move, u8 move_type, u8 atk_bank, u8 def_bank, u16 chained_effectiveness,bool setflag) {
    damage_loc = 0;
    if (chained_effectiveness == 0) { return; } // avoid wastage of time in case of non effective moves
    u8 move_split = move_table[move].split & photon_geyser_special(move); //JeremyZ
    u16 base_power = apply_base_power_modifiers(move, move_type, atk_bank, def_bank,
            get_base_power(move, atk_bank, def_bank),setflag);
    u16 atk_stat = get_attack_stat(move, move_type, atk_bank, def_bank);
    u16 def_stat = get_def_stat(move, atk_bank, def_bank);
    u32 damage = ((((2 * battle_participants[atk_bank].level) / 5 + 2) * base_power * atk_stat) / def_stat) / 50 + 2;

    //apply multi target modifier
    if (does_move_target_multiple()) {
        damage = apply_modifier(0xC00, damage);
    }
    //weather modifier
    if (weather_abilities_effect() && get_item_effect(def_bank, 1) != ITEM_EFFECT_UTILITYUMBRELLA) {
        if (RAIN_WEATHER) {
            if (move_type == TYPE_FIRE)
                damage = apply_modifier(0x800, damage);
            else if (move_type == TYPE_WATER)
                damage = apply_modifier(0x1800, damage);
        } else if (SUN_WEATHER) {
            if (move_type == TYPE_FIRE)
                damage = apply_modifier(0x1800, damage);
            else if (move_type == TYPE_WATER)
                damage = apply_modifier(0x800, damage);
        }
    }
    //crit modifier
    if (crit_loc == 2 && move != MOVE_CONFUSION_DMG) {
        damage = apply_modifier(0x1800, damage);
    }
    //rand modifier
    damage = (damage * (100 - (/*__umodsi3(rng(), 14)*/random_value(14) + 1))) / 100;

    u16 final_modifier = 0x1000;
    //stab modifier
    if (move_type != TYPE_EGG && is_of_type(atk_bank, move_type) && move != MOVE_STRUGGLE) {
        if (check_ability(atk_bank, ABILITY_ADAPTABILITY))
            damage = apply_modifier(0x2000, damage);
		else
			damage = apply_modifier(0x1800, damage);
    }
    //type effectiveness
    damage = (damage * chained_effectiveness) >> 6;

    //burn
    if (battle_participants[atk_bank].status.flags.burn && move_split == MOVE_PHYSICAL && move != MOVE_FACADE && !check_ability(atk_bank, ABILITY_GUTS))
    {
        damage /= 2;
    }
    //at least one check
    damage = ATLEAST_ONE(damage);
    //final modifiers
    //u8 move_split = move_table[move].split;
    //check reflect/light screen
    u8 def_side = get_bank_side(def_bank);
    if ((side_affecting_halfword[def_side].reflect_on && move_split == MOVE_PHYSICAL) ||
        (side_affecting_halfword[def_side].light_screen_on && move_split == MOVE_SPECIAL))
        final_modifier = calc_reflect_modifier(atk_bank, def_bank, final_modifier);

    //check aurora veil
    if (new_battlestruct->side_affecting[def_side].aurora_veil)
    {
        if (move == MOVE_BRICK_BREAK || move == MOVE_PSYCHIC_FANGS)
            new_battlestruct->side_affecting[def_side].aurora_veil = 0;
        else
            final_modifier = calc_reflect_modifier(atk_bank, def_bank, final_modifier);
    }

    u16 atk_ability = gBankAbilities[atk_bank];
    u16 def_ability = gBankAbilities[def_bank];
    //halve damage if full HP
    if (FULL_HP(def_bank) && (def_ability == ABILITY_SHADOW_SHIELD || def_ability == ABILITY_MULTISCALE) &&
        has_ability_effect(def_bank, 1)) {
        final_modifier = chain_modifier(final_modifier, 0x800);
    }
    if (atk_ability == ABILITY_TINTED_LENS && move_outcome.not_very_effective && has_ability_effect(atk_bank, 0)) {
        final_modifier = chain_modifier(final_modifier, 0x2000);
    }
    if (ability_battle_effects(20, def_bank, ABILITY_FRIEND_GUARD, 0, 1)) {
        if ((atk_ability != ABILITY_MOLD_BREAKER && atk_ability != ABILITY_TERAVOLT &&
             atk_ability != ABILITY_TURBOBLAZE) || !has_ability_effect(atk_bank, 0))
            final_modifier = chain_modifier(final_modifier, 0xC00);
    }
    if (atk_ability == ABILITY_SNIPER && crit_loc == 2 && has_ability_effect(atk_bank, 0)) {
        final_modifier = chain_modifier(final_modifier, 0x1800);
    }
	if (check_ability_with_mold(def_bank, ABILITY_THICK_FAT) && (move_type == TYPE_FIRE || move_type == TYPE_ICE)) {
		final_modifier = chain_modifier(final_modifier, 0x800);
	}
    //reduces power of super effective moves
    if (move_outcome.super_effective &&
        ((def_ability == ABILITY_FILTER || def_ability == ABILITY_SOLID_ROCK || def_ability == ABILITY_PRISM_ARMOR) &&
         has_ability_effect(def_bank, 1))) {
        final_modifier = chain_modifier(final_modifier, 0xC00);
    }
	if (move_outcome.super_effective && atk_ability == ABILITY_NEUROFORCE) {
		final_modifier = chain_modifier(final_modifier, 0x1400);
	}
    if (get_item_effect(atk_bank, 1) == ITEM_EFFECT_METRONOME) {
        if (new_battlestruct->bank_affecting[atk_bank].same_move_used > 4)
            final_modifier = chain_modifier(final_modifier, 0x2000);
        else
            final_modifier = chain_modifier(final_modifier,
                    0x1000 + new_battlestruct->bank_affecting[atk_bank].same_move_used * 0x333);
    } else if (get_item_effect(atk_bank, 1) == ITEM_EFFECT_EXPERTBELT && move_outcome.super_effective)
    {
        final_modifier = chain_modifier(final_modifier, 0x1333);
    } else if (get_item_effect(atk_bank, 1) == ITEM_EFFECT_LIFEORB) {
        final_modifier = chain_modifier(final_modifier, 0x14CD);
    }

    if (get_item_effect(def_bank, 1) == ITEM_EFFECT_DAM_REDUX_BERRY) {
        u8 type_to_resist = get_battle_item_extra_param(def_bank);
        if (type_to_resist == move_type && (move_outcome.super_effective || type_to_resist == TYPE_NORMAL)) {
            final_modifier = chain_modifier(final_modifier, 0x800);
            new_battlestruct->various.berry_damage_redux = 1;
        }
    }

    if (find_move_in_table(move, pressing_moves_table) && status3[def_bank].minimized) {
        final_modifier = chain_modifier(final_modifier, 0x2000);
    }
	else if ((move == MOVE_EARTHQUAKE || move == MOVE_MAGNITUDE) && status3[def_bank].underground) {
        final_modifier = chain_modifier(final_modifier, 0x2000);
    }
	else if ((move == MOVE_SURF || move == MOVE_WHIRLPOOL) && status3[def_bank].underwater) {
        final_modifier = chain_modifier(final_modifier, 0x2000);
    }
	else if ((move == MOVE_GUST || move == MOVE_TWISTER) && status3[def_bank].on_air) {
		final_modifier = chain_modifier(final_modifier, 0x2000);
	}

    //JeremyZ
    if (new_battlestruct->various.ate_bonus) {
        final_modifier = chain_modifier(final_modifier, 0x1333);
    }
	
	//JeremyZ
	if (z_protect_affects(move)) {
		final_modifier = chain_modifier(final_modifier, 0x400);
	}

    damage = apply_modifier(final_modifier, damage);
    damage_loc = ATLEAST_ONE(damage);
}

u8 get_attacking_move_type(void);

void atk05_dmg_calc(void) {
    u8 move_type = get_attacking_move_type();
    u16 item = battle_participants[bank_attacker].held_item;
    u16 chained_effectiveness = type_effectiveness_calc(current_move, move_type, bank_attacker, bank_target, 1);
    if (MOVE_WORKED && DAMAGING_MOVE(current_move) && item && get_item_effect(bank_attacker, 1) == ITEM_EFFECT_GEM &&
        get_item_extra_param(item) == move_type && current_move != MOVE_STRUGGLE && current_move != MOVE_WATER_PLEDGE &&
        current_move != MOVE_FIRE_PLEDGE && current_move != MOVE_GRASS_PLEDGE) {
        last_used_item = item;
        new_battlestruct->various.gem_boost = 1;
        move_to_buff1(current_move);
        bs_push_current(BS_GEM_MSG);
        return;
    }
    damage_calc(current_move, move_type, bank_attacker, bank_target, chained_effectiveness,1);
    if (new_battlestruct->various.parental_bond_mode == PBOND_CHILD)
        damage_loc /= 4;

    battlescripts_curr_instruction++;
}
