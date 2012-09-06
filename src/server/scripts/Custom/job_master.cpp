#include "ScriptPCH.h"

enum Spells {
	SPELL_BS	= 29844,
	SPELL_JC	= 28897,
	SPELL_EN	= 28029,
	SPELL_AL	= 28596,
	SPELL_EG	= 30350,
	SPELL_IN	= 45361,
	SPELL_TA	= 26790,
	SPELL_MI	= 50310,
	SPELL_HE	= 50300,
	SPELL_LW	= 32549,
	SPELL_SK	= 50305,

	SKILL_BS	= 164,
	SKILL_JC	= 755,
	SKILL_EN	= 333,
	SKILL_AL	= 171,
	SKILL_EG	= 202,
	SKILL_IN	= 773,
	SKILL_TA	= 197,
	SKILL_MI	= 186,
	SKILL_HE	= 182,
	SKILL_LW	= 165,
	SKILL_SK	= 393 };

class job_master : public CreatureScript {
    public: job_master() : CreatureScript("job_master") {}

bool OnGossipHello(Player* player, Creature* creature) {
	player->ADD_GOSSIP_ITEM( 3, "Dépecage (collecte)" , GOSSIP_SENDER_MAIN, 1009);
	player->ADD_GOSSIP_ITEM( 3, "Herborisme" , GOSSIP_SENDER_MAIN, 1004);
	player->ADD_GOSSIP_ITEM( 3, "Minage" , GOSSIP_SENDER_MAIN, 1008);
	player->ADD_GOSSIP_ITEM( 3, "Alchimie (artisanat)" , GOSSIP_SENDER_MAIN, 1000);
	player->ADD_GOSSIP_ITEM( 3, "Calligraphie" , GOSSIP_SENDER_MAIN, 1005);
	player->ADD_GOSSIP_ITEM( 3, "Couture" , GOSSIP_SENDER_MAIN, 1010);
	player->ADD_GOSSIP_ITEM( 3, "Enchantement" , GOSSIP_SENDER_MAIN, 1002);
	player->ADD_GOSSIP_ITEM( 3, "Forge" , GOSSIP_SENDER_MAIN, 1001);
	player->ADD_GOSSIP_ITEM( 3, "Ingénierie" , GOSSIP_SENDER_MAIN, 1003);
	player->ADD_GOSSIP_ITEM( 3, "Joaillerie" , GOSSIP_SENDER_MAIN, 1006);
	player->ADD_GOSSIP_ITEM( 3, "Travail du cuir" , GOSSIP_SENDER_MAIN, 1007);
	player->SEND_GOSSIP_MENU(1000004, creature->GetGUID());
	return true; }

bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) {

	if (player->GetFreePrimaryProfessionPoints() >= 1) {
		switch (action) {	
		
	case 1000:
	    player->CLOSE_GOSSIP_MENU();
		player->learnSpell(SPELL_AL, false);
		player->UpdateSkill(SKILL_AL, 375);
	    break;
	case 1001:
	    player->CLOSE_GOSSIP_MENU();
		player->learnSpell(SPELL_BS, false);
		player->UpdateSkill(SKILL_BS, 375);
	    break;
	case 1002:
		player->CLOSE_GOSSIP_MENU();
		player->learnSpell(SPELL_EN, false);
		player->UpdateSkill(SKILL_EN, 375);
		break;
	case 1003:
		player->CLOSE_GOSSIP_MENU();
		player->learnSpell(SPELL_EG, false);
		player->UpdateSkill(SKILL_EG, 375);
		break;
	case 1004:
		player->CLOSE_GOSSIP_MENU();
		player->learnSpell(SPELL_HE, false);
		player->learnSpell(55503, false);
		player->UpdateSkill(SKILL_HE, 450);
		break;
	case 1005:
		player->CLOSE_GOSSIP_MENU();
		player->learnSpell(SPELL_IN, false);
		player->UpdateSkill(SKILL_IN, 375);
		break;
	case 1006:
		player->CLOSE_GOSSIP_MENU();
		player->learnSpell(SPELL_JC, false);
		player->UpdateSkill(SKILL_JC, 375);
		break;
	case 1007:
		player->CLOSE_GOSSIP_MENU();
		player->learnSpell(SPELL_LW, false);
		player->UpdateSkill(SKILL_LW, 375);
		break;
	case 1008:
		player->CLOSE_GOSSIP_MENU();
		player->learnSpell(SPELL_MI, false);
		player->learnSpell(53040, false);
		player->UpdateSkill(SKILL_MI, 450);
		break;
	case 1009:
		player->CLOSE_GOSSIP_MENU();
		player->learnSpell(SPELL_SK, false);
		player->learnSpell(53666, false);
		player->UpdateSkill(SKILL_SK, 450);
		break;
	case 1010:
		player->CLOSE_GOSSIP_MENU();
		player->learnSpell(SPELL_TA, false);
		player->UpdateSkill(SKILL_TA, 375);
		break;
		}
	}
	else {
		player->CLOSE_GOSSIP_MENU();
		creature->MonsterWhisper("Vous avez déjà deux métiers !", player->GetGUID(), false); }
		
    return true; }
};

void AddSc_job_master() {
    new job_master; }