/*
 * (C) 2016 Fabian Beuke <mail@beuke.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
 
#include <map>

struct Cooldown 
{         
	int Last_Call[70];
}; 




char* configname = "./MadCoolDownConfig.txt";

const char* knight = "Knight";
const char* mage = "Mage";
const char* archer = "Archer";

const int knight_skills_count = 37;
const int mage_skills_count = 62;
const int archer_skills_count = 46;

int CoolDownTable[3][70];

map<int,Cooldown> CoolDown_Timer;

void parse(int class_id,const char* class_name, int skill_count,char* skills[])
{
	for (int i = 0;i < skill_count; i++)
	{
		CoolDownTable[class_id][i] = GetPrivateProfileInt(class_name, skills[i], -1, configname);
	}
}

void Read_Config()
{
	
	char* knight_skills[knight_skills_count] =
	{
		"run","behead","upgradeweapon","thunder","mock","Transcendental","upblockshield",
		"UpperSlash","Enrage","Edge","WildAccuracy","rest","upfatal","FatalWound","Protect",
		"ShieldSmash","UpperSmash","Infernal","RainforceDefense","ChantProtect","CUpParry",
		"CDash","CShieldAttack","ChantHealing","CBerserk","CPullSwing","CSacrifice",
		"CChantDefLightning","CChantDefIce","CChantDefFire","CUpReinforceVitality","CChantAccuracy",
		"CChantBattle","CChangeVitality","CShieldResilience","CReincarnate","upfatal"
	};

	char* mage_skills[mage_skills_count] =
	{
		"run","behead","firemagic","icemagic","litningmagic","ProtectRange","upIce2","upFire2",
		"selfheal","shockmagic","Anyheal","rest","uplitning","upIce","upFire","Meditation",
		"revival","stoneshield","stoneshield2","stoneshield3","stoneshield4","stoneshield5",
		"PlusAnyheal","Spark","MagicWideIce","MagicWideFire","Haste","FrostBlast","HealingParty",
		"HealingAnyQuick","CUpReinforceVitality","CCalllitning","IceLance","FireExplosion",
		"Resurrection","Restoration","Mesmerization","SnowField","InchantWeapon","AuraDefense",
		"SpiritBlast","ChainLitning","ThunderLitning","ThunderStorm","IceRequiem","IceStorm",
		"FireEruption","ExplosiveBurst","FireRain","StrenUpStr","StrenUpHth","StrenUpDex",
		"StrenUpInt","StrenUpFatal","Purge","HealingInstance","ReinforceSight","HealingPartyPlus",
		"HealingPartyIns","HealingGreatRe","ControlAppetite","CAmnegia"
	};

	char* archer_skills[archer_skills_count] = 
	{
		"run","behead","upgradebow","shot","negative","upgradeconcentration",
		"flameArrow","fatalchance","upevade","StunArrow","WildStrength","rest",
		"upfatal","PoisonArrow","Explosion","SilenceArrow","GetherShot","UpAttackRange",
		"VitalityDrain","Suffering","CUpRFEvade","CMysticArrow","CMeshSpeed","CDarknessVision",
		"CResistLightning","CResistIce","CResistFire","CSilenceShot","CResistCurse","CResistPalsy",
		"CUpReinforceVitality","CEmergencyEscape","upfatal2","CCloudSight","CManaBurn","CMeshChance",
		"CMeshStr","CMeshHth","CMeshDex","CMeshInt","CMeshWis","CMeshDefense","CPoisonCloud",
		"CVanishConfi","CDestroySight","CBenefitAblation"
	};

	parse(0,knight,knight_skills_count,knight_skills);
	parse(1,mage,mage_skills_count,mage_skills);
	parse(2,archer,archer_skills_count,archer_skills);
}

