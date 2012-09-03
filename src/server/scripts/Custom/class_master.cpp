#include "ScriptPCH.h"

class class_master : public CreatureScript {
    public: class_master() : CreatureScript("class_master") {}

bool OnGossipHello(Player* player, Creature* creature) {
	MainMenu(player, creature);
	return true; }
		
void MainMenu(Player *player, Creature *creature) {
	player->ADD_GOSSIP_ITEM( 3, "Mise a niveau des sorts, stats et compétences" , GOSSIP_SENDER_MAIN, 1);
	player->ADD_GOSSIP_ITEM( 2, "Apprentissage de la double spécalisation" , GOSSIP_SENDER_MAIN, 2);
	player->ADD_GOSSIP_ITEM( 1, "Vendeur de glyphes." , GOSSIP_SENDER_MAIN, 3);
	player->ADD_GOSSIP_ITEM( 2, "Réinitialisation des talents" , GOSSIP_SENDER_MAIN, 4);
	player->SEND_GOSSIP_MENU(1000003, creature->GetGUID()); }

bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) {
	player->PlayerTalkClass->ClearMenus();

		switch (action) {

	case 1:
		MainMenu(player, creature);
		player->UpdateSkillsToMaxSkillsForLevel();
		if (player->HasSpell(17877)) {
		player->learnSpell(18867, false);
		player->learnSpell(18868, false);
		player->learnSpell(18869, false);
		player->learnSpell(18870, false); } // brulure de l'ombre
		if (player->HasSpell(11366)) {
		player->learnSpell(12505, false);
		player->learnSpell(12522, false);
		player->learnSpell(12523, false);
		player->learnSpell(12524, false);
		player->learnSpell(12525, false); } // explosion pyrotechnique
		if (player->HasSpell(11113)) {
		player->learnSpell(13018, false);
		player->learnSpell(13019, false); } // vague explosive
		if (player->HasSpell(5570)) {
		player->learnSpell(24974, false);
		player->learnSpell(24975, false); } // essaim d'insecte
		if (player->HasSpell(19434)) {
		player->learnSpell(20900, false);
		player->learnSpell(20901, false);
		player->learnSpell(20902, false); } // visée
		if (player->HasSpell(15407)) {
		player->learnSpell(17311, false);
		player->learnSpell(17312, false);
		player->learnSpell(17313, false); } // fouet mental
		if (player->HasSpell(19236)) {
		player->learnSpell(19238, false);
		player->learnSpell(19240, false);
		player->learnSpell(19241, false); } // prière du désespoir
		if (player->HasSpell(20473)) {
		player->learnSpell(20929, false); } // hotion sacre
		if (player->HasSpell(19306)) {
		player->learnSpell(20909, false); } // contre-attaque
		if (player->HasSpell(16511)) {
		player->learnSpell(17347, false); } // hemorragie
		if (player->HasSpell(11426)) {
		player->learnSpell(13031, false); } // barriere de glace
		player->UpdateSkill(185, 450); //cuisine
		player->UpdateSkill(129, 450); //secourisme
		player->learnSpell(33391, false);
		creature->CastSpell(player,38588,false);
		break;

	case 2:
		MainMenu(player, creature);
		if (player->GetSpecsCount() == 1) {
			player->CastSpell(player, 63680, true, NULL, NULL, player->GetGUID());
			player->CastSpell(player, 63624, true, NULL, NULL, player->GetGUID()); }
		break;
	
	case 3:
		player->GetSession()->SendListInventory(creature->GetGUID());
		break;

	case 30:
		if(player->getClass() == 1){    player->GetSession()->SendListInventory(999991); } // guerrier
		if(player->getClass() == 2){	player->GetSession()->SendListInventory(999992); } // paladin
		if(player->getClass() == 3){	player->GetSession()->SendListInventory(999993); } // chasseur
		if(player->getClass() == 4){	player->GetSession()->SendListInventory(999994); } // voleur
		if(player->getClass() == 5){	player->GetSession()->SendListInventory(999995); } // prêtre
		if(player->getClass() == 7){	player->GetSession()->SendListInventory(999996); } // chaman
		if(player->getClass() == 8){	player->GetSession()->SendListInventory(999997); } // mage
		if(player->getClass() == 9){	player->GetSession()->SendListInventory(999998); } // démoniste
		if(player->getClass() == 11){	player->GetSession()->SendListInventory(999999); } // druide
		break;
	
	case 4:
		MainMenu(player, creature);
		player->resetTalents(true);
 		player->SendTalentsInfoData(false);
		break;
	
		}
    return true; }
};

void AddSc_class_master() {
    new class_master; }