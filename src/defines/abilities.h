#ifndef ABILITY_IDS
#define ABILITY_IDS

enum poke_abilities
{
        ABILITY_NO_ABILITY	,//0x0000
        ABILITY_STENCH	,//0x0001
        ABILITY_DRIZZLE	,//0x0002
        ABILITY_SPEED_BOOST	,//0x0003
        ABILITY_BATTLE_ARMOR	,//0x0004
        ABILITY_STURDY	,//0x0005
        ABILITY_DAMP	,//0x0006
        ABILITY_LIMBER	,//0x0007
        ABILITY_SAND_VEIL	,//0x0008
        ABILITY_STATIC	,//0x0009
        ABILITY_VOLT_ABSORB	,//0x000A
        ABILITY_WATER_ABSORB	,//0x000B
        ABILITY_OBLIVIOUS	,//0x000C
        ABILITY_CLOUD_NINE	,//0x000D
        ABILITY_COMPOUND_EYES	,//0x000E
        ABILITY_INSOMNIA	,//0x000F
        ABILITY_COLOR_CHANGE	,//0x0010
        ABILITY_IMMUNITY	,//0x0011
        ABILITY_FLASH_FIRE	,//0x0012
        ABILITY_SHIELD_DUST	,//0x0013
        ABILITY_OWN_TEMPO	,//0x0014
        ABILITY_SUCTION_CUPS	,//0x0015
        ABILITY_INTIMIDATE	,//0x0016
        ABILITY_SHADOW_TAG	,//0x0017
        ABILITY_ROUGH_SKIN	,//0x0018
        ABILITY_WONDER_GUARD	,//0x0019
        ABILITY_LEVITATE	,//0x001A
        ABILITY_EFFECT_SPORE	,//0x001B
        ABILITY_SYNCHRONIZE	,//0x001C
        ABILITY_CLEAR_BODY	,//0x001D
        ABILITY_NATURAL_CURE	,//0x001E
        ABILITY_LIGHTNING_ROD	,//0x001F
        ABILITY_SERENE_GRACE	,//0x0020
        ABILITY_SWIFT_SWIM	,//0x0021
        ABILITY_CHLOROPHYLL	,//0x0022
        ABILITY_ILLUMINATE	,//0x0023
        ABILITY_TRACE	,//0x0024
        ABILITY_HUGE_POWER	,//0x0025
        ABILITY_POISON_POINT	,//0x0026
        ABILITY_INNER_FOCUS	,//0x0027
        ABILITY_MAGMA_ARMOR	,//0x0028
        ABILITY_WATER_VEIL	,//0x0029
        ABILITY_MAGNET_PULL	,//0x002A
        ABILITY_SOUNDPROOF	,//0x002B
        ABILITY_RAIN_DISH	,//0x002C
        ABILITY_SAND_STREAM	,//0x002D
        ABILITY_PRESSURE	,//0x002E
        ABILITY_THICK_FAT	,//0x002F
        ABILITY_EARLY_BIRD	,//0x0030
        ABILITY_FLAME_BODY	,//0x0031
        ABILITY_RUN_AWAY	,//0x0032
        ABILITY_KEEN_EYE	,//0x0033
        ABILITY_HYPER_CUTTER	,//0x0034
        ABILITY_PICKUP	,//0x0035
        ABILITY_TRUANT	,//0x0036
        ABILITY_HUSTLE	,//0x0037
        ABILITY_CUTE_CHARM	,//0x0038
        ABILITY_PLUS	,//0x0039
        ABILITY_MINUS	,//0x003A
        ABILITY_FORECAST	,//0x003B
        ABILITY_STICKY_HOLD	,//0x003C
        ABILITY_SHED_SKIN	,//0x003D
        ABILITY_GUTS	,//0x003E
        ABILITY_MARVEL_SCALE	,//0x003F
        ABILITY_LIQUID_OOZE	,//0x0040
        ABILITY_OVERGROW	,//0x0041
        ABILITY_BLAZE	,//0x0042
        ABILITY_TORRENT	,//0x0043
        ABILITY_SWARM	,//0x0044
        ABILITY_ROCK_HEAD	,//0x0045
        ABILITY_DROUGHT	,//0x0046
        ABILITY_ARENA_TRAP	,//0x0047
        ABILITY_VITAL_SPIRIT	,//0x0048
        ABILITY_DAUNTLESS_SHIELD	,//0x0049
        ABILITY_MISTY_SURGE	,//0x004A
        ABILITY_GRASSY_SURGE	,//0x004B
        ABILITY_PSYCHIC_SURGE	,//0x004C
        ABILITY_FILTER	,//0x004D
        ABILITY_MOXIE	,//0x004E
        ABILITY_TURBOBLAZE	,//0x004F
        ABILITY_PROTEAN	,//0x0050
        ABILITY_GOOEY	,//0x0051
        ABILITY_WIMP_OUT	,//0x0052
        ABILITY_RECEIVER	,//0x0053
        ABILITY_PROPELLER_TAIL	,//0x0054
        ABILITY_HEATPROOF	,//0x0055
        ABILITY_SIMPLE	,//0x0056
        ABILITY_DRY_SKIN	,//0x0057
        ABILITY_DOWNLOAD	,//0x0058
        ABILITY_IRON_FIST	,//0x0059
        ABILITY_POISON_HEAL	,//0x005A
        ABILITY_ADAPTABILITY	,//0x005B
        ABILITY_SKILL_LINK	,//0x005C
        ABILITY_HYDRATION	,//0x005D
        ABILITY_SOLAR_POWER	,//0x005E
        ABILITY_QUICK_FEET	,//0x005F
        ABILITY_NORMALIZE	,//0x0060
        ABILITY_SNIPER	,//0x0061
        ABILITY_MAGIC_GUARD	,//0x0062
        ABILITY_NO_GUARD	,//0x0063
        ABILITY_STALL	,//0x0064
        ABILITY_TECHNICIAN	,//0x0065
        ABILITY_LEAF_GUARD	,//0x0066
        ABILITY_KLUTZ	,//0x0067
        ABILITY_MOLD_BREAKER	,//0x0068
        ABILITY_SUPER_LUCK	,//0x0069
        ABILITY_AFTERMATH	,//0x006A
        ABILITY_ANTICIPATION	,//0x006B
        ABILITY_FOREWARN	,//0x006C
        ABILITY_UNAWARE	,//0x006D
        ABILITY_TINTED_LENS	,//0x006E
        ABILITY_TANGLED_FEET	,//0x006F
        ABILITY_SLOW_START	,//0x0070
        ABILITY_SCRAPPY	,//0x0071
        ABILITY_STORM_DRAIN	,//0x0072
        ABILITY_ICE_BODY	,//0x0073
        ABILITY_INTREPID_SWORD	,//0x0074
        ABILITY_SNOW_WARNING	,//0x0075
        ABILITY_HONEY_GATHER	,//0x0076
        ABILITY_FRISK	,//0x0077
        ABILITY_RECKLESS	,//0x0078
        ABILITY_MULTITYPE	,//0x0079
        ABILITY_FLOWER_GIFT	,//0x007A
        ABILITY_BAD_DREAMS	,//0x007B
        ABILITY_PICKPOCKET	,//0x007C
        ABILITY_SHEER_FORCE	,//0x007D
        ABILITY_CONTRARY	,//0x007E
        ABILITY_UNNERVE	,//0x007F
        ABILITY_DEFIANT	,//0x0080
        ABILITY_DEFEATIST	,//0x0081
        ABILITY_CURSED_BODY	,//0x0082
        ABILITY_HEALER	,//0x0083
        ABILITY_FRIEND_GUARD	,//0x0084
        ABILITY_WEAK_ARMOR	,//0x0085
        ABILITY_HEAVY_METAL	,//0x0086
        ABILITY_LIGHT_METAL	,//0x0087
        ABILITY_MULTISCALE	,//0x0088
        ABILITY_TOXIC_BOOST	,//0x0089
        ABILITY_FLARE_BOOST	,//0x008A
        ABILITY_HARVEST	,//0x008B
        ABILITY_TELEPATHY	,//0x008C
        ABILITY_MOODY	,//0x008D
        ABILITY_OVERCOAT	,//0x008E
        ABILITY_POISON_TOUCH	,//0x008F
        ABILITY_REGENERATOR	,//0x0090
        ABILITY_BIG_PECKS	,//0x0091
        ABILITY_SAND_RUSH	,//0x0092
        ABILITY_WONDER_SKIN	,//0x0093
        ABILITY_ANALYTIC	,//0x0094
        ABILITY_ILLUSION	,//0x0095
        ABILITY_IMPOSTER	,//0x0096
        ABILITY_INFILTRATOR	,//0x0097
        ABILITY_MUMMY	,//0x0098
        ABILITY_MOTOR_DRIVE	,//0x0099
        ABILITY_JUSTIFIED	,//0x009A
        ABILITY_RATTLED	,//0x009B
        ABILITY_MAGIC_BOUNCE	,//0x009C
        ABILITY_SAP_SIPPER	,//0x009D
        ABILITY_PRANKSTER	,//0x009E
        ABILITY_SAND_FORCE	,//0x009F
        ABILITY_IRON_BARBS	,//0x00A0
        ABILITY_ZEN_MODE	,//0x00A1
        ABILITY_VICTORY_STAR	,//0x00A2
        ABILITY_RIVALRY	,//0x00A3
        ABILITY_ELECTRIC_SURGE	,//0x00A4
        ABILITY_AROMA_VEIL	,//0x00A5
        ABILITY_FLOWER_VEIL	,//0x00A6
        ABILITY_CHEEK_POUCH	,//0x00A7
        ABILITY_STEADFAST	,//0x00A8
        ABILITY_FUR_COAT	,//0x00A9
        ABILITY_MAGICIAN	,//0x00AA
        ABILITY_BULLETPROOF	,//0x00AB
        ABILITY_COMPETITIVE	,//0x00AC
        ABILITY_STRONG_JAW	,//0x00AD
        ABILITY_REFRIGERATE	,//0x00AE
        ABILITY_SWEET_VEIL	,//0x00AF
        ABILITY_STANCE_CHANGE	,//0x00B0
        ABILITY_GALE_WINGS	,//0x00B1
        ABILITY_MEGA_LAUNCHER	,//0x00B2
        ABILITY_GRASS_PELT	,//0x00B3
        ABILITY_SYMBIOSIS	,//0x00B4
        ABILITY_TOUGH_CLAWS	,//0x00B5
        ABILITY_PIXILATE	,//0x00B6
        ABILITY_SNOW_CLOAK	,//0x00B7
        ABILITY_AERILATE	,//0x00B8
        ABILITY_PARENTAL_BOND	,//0x00B9
        ABILITY_DARK_AURA	,//0x00BA
        ABILITY_FAIRY_AURA	,//0x00BB
        ABILITY_AURA_BREAK	,//0x00BC
        ABILITY_PRIMORDIAL_SEA	,//0x00BD
        ABILITY_DESOLATE_LAND	,//0x00BE
        ABILITY_DELTA_STREAM	,//0x00BF
        ABILITY_STAMINA	,//0x00C0
        ABILITY_GLUTTONY	,//0x00C1
        ABILITY_DRAGONS_MAW	,//0x00C2
        ABILITY_WATER_COMPACTION	,//0x00C3
        ABILITY_MERCILESS	,//0x00C4
        ABILITY_SHIELDS_DOWN	,//0x00C5
        ABILITY_STAKEOUT	,//0x00C6
        ABILITY_WATER_BUBBLE	,//0x00C7
        ABILITY_STEELWORKER	,//0x00C8
        ABILITY_BERSERK	,//0x00C9
        ABILITY_SLUSH_RUSH	,//0x00CA
        ABILITY_LONG_REACH	,//0x00CB
        ABILITY_LIQUID_VOICE	,//0x00CC
        ABILITY_TRIAGE	,//0x00CD
        ABILITY_GALVANIZE	,//0x00CE
        ABILITY_SURGE_SURFER	,//0x00CF
        ABILITY_SCHOOLING	,//0x00D0
        ABILITY_DISGUISE	,//0x00D1
        ABILITY_BATTLE_BOND	,//0x00D2
        ABILITY_POWER_CONSTRUCT	,//0x00D3
        ABILITY_CORROSION	,//0x00D4
        ABILITY_COMATOSE	,//0x00D5
        ABILITY_QUEENLY_MAJESTY	,//0x00D6
        ABILITY_INNARDS_OUT	,//0x00D7
        ABILITY_DANCER	,//0x00D8
        ABILITY_BATTERY	,//0x00D9
        ABILITY_FLUFFY	,//0x00DA
        ABILITY_DAZZLING	,//0x00DB
        ABILITY_SOUL_HEART	,//0x00DC
        ABILITY_CURIOUS_MEDICINE	,//0x00DD
        ABILITY_ANGER_POINT	,//0x00DE
        ABILITY_AS_ONE	,//0x00DF
        ABILITY_BEAST_BOOST	,//0x00E0
        ABILITY_RKS_SYSTEM	,//0x00E1
        ABILITY_PASTEL_VEIL	,//0x00E2
        ABILITY_HUNGER_SWITCH	,//0x00E3
        ABILITY_QUICK_DRAW	,//0x00E4
        ABILITY_UNSEEN_FIST	,//0x00E5
        ABILITY_FULL_METAL_BODY	,//0x00E6
        ABILITY_SHADOW_SHIELD	,//0x00E7
        ABILITY_PRISM_ARMOR	,//0x00E8
        ABILITY_NEUROFORCE	,//0x00E9
        ABILITY_GORILLA_TACTICS	,//0x00EA
        ABILITY_NEUTRALIZING_GAS	,//0x00EB
        ABILITY_TRANSISTOR	,//0x00EC
        ABILITY_BALL_FETCH	,//0x00ED
        ABILITY_COTTON_DOWN	,//0x00EE
        ABILITY_UNBURDEN	,//0x00EF
        ABILITY_MIRROR_ARMOR	,//0x00F0
        ABILITY_GULP_MISSILE	,//0x00F1
        ABILITY_GRIM_NEIGH	,//0x00F2
        ABILITY_STEAM_ENGINE	,//0x00F3
        ABILITY_PUNK_ROCK	,//0x00F4
        ABILITY_SAND_SPIT	,//0x00F5
        ABILITY_ICE_SCALES	,//0x00F6
        ABILITY_RIPEN	,//0x00F7
        ABILITY_ICE_FACE	,//0x00F8
        ABILITY_POWER_SPOT	,//0x00F9
        ABILITY_MIMICRY	,//0x00FA
        ABILITY_SCREEN_ClEANER	,//0x00FB
        ABILITY_STEELY_SPIRIT	,//0x00FC
        ABILITY_PERISH_BODY	,//0x00FD
        ABILITY_WANDERING_SPIRIT	,//0x00FE
        ABILITY_NONAME	,//0x00FF
        ABILITY_NONE	,//0x0100
        ABILITY_SHELL_ARMOR	=0x0104,//0x0104
        ABILITY_AIR_LOCK	=0x010D,//0x010D
        ABILITY_WHITE_SMOKE	=0x011D,//0x011D
        ABILITY_PURE_POWER	=0x0125,//0x0125
        ABILITY_SOLID_ROCK	=0x014D,//0x014D
        ABILITY_CHILLING_NEIGH	=0x014E,//0x014E
        ABILITY_TERAVOLT	=0x014F,//0x014F
        ABILITY_LIBERO	=0x0150,//0x0150
        ABILITY_TANGLING_HAIR	=0x0151,//0x0151
        ABILITY_EMERGENCY_EXIT	=0x0152,//0x0152
        ABILITY_POWER_OF_ALCHEMY	=0x0153,//0x0153
        ABILITY_STALWART	=0x0154//0x0154

};

#endif /* ABILITY_IDS_H */

