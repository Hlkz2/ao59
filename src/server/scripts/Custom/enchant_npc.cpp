#include "ScriptPCH.h"

class enchant_npc : public CreatureScript {
public: enchant_npc() : CreatureScript("enchant_npc") {}

bool OnGossipHello(Player *player, Creature * creature) {
	MainMenu(player, creature);
    return true; }

void MainMenu(Player *player, Creature *creature) {
		player->SetClmSlty(0);
        player->ADD_GOSSIP_ITEM(0, "Dos", GOSSIP_SENDER_MAIN, 14);
        player->ADD_GOSSIP_ITEM(0, "Torse", GOSSIP_SENDER_MAIN, 4);
        player->ADD_GOSSIP_ITEM(0, "Poignets", GOSSIP_SENDER_MAIN, 8);
        player->ADD_GOSSIP_ITEM(0, "Mains", GOSSIP_SENDER_MAIN, 9);
        Item *item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, 6); if(item)
        player->ADD_GOSSIP_ITEM(0, "Jambes : Renfort d'armure épais", GOSSIP_SENDER_MAIN, 6);
        player->ADD_GOSSIP_ITEM(0, "Pieds", GOSSIP_SENDER_MAIN, 7);
        player->ADD_GOSSIP_ITEM(0, "Main droite", GOSSIP_SENDER_MAIN, 15);		
        item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, 16); if(item) {
		if(item->GetTemplate()->SubClass == 6)	player->ADD_GOSSIP_ITEM(0, "Bouclier", GOSSIP_SENDER_MAIN, 18);
        else { if(item->GetTemplate()->Class != 4) player->ADD_GOSSIP_ITEM(0, "Main gauche", GOSSIP_SENDER_MAIN, 16); } }
        item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, 17); if(item) {
		if((item->GetTemplate()->SubClass == 2) || (item->GetTemplate()->SubClass == 3) || (item->GetTemplate()->SubClass == 18))
			player->ADD_GOSSIP_ITEM(0, "A distance : lunette mortelle", GOSSIP_SENDER_MAIN, 17); }
		player->SEND_GOSSIP_MENU(20003, creature->GetGUID()); }

void Ench(Player *player, Creature *creature, uint32 slotid, uint32 enchid, uint32 twoha, uint32 requil, uint32 slty) {
	Item *item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slotid);
	
	if(!item) {
		creature->MonsterWhisper("Vous devez vous équiper de l'objet.", player->GetGUID());
		MainMenu(player, creature);
        return; }
    if (requil == 1 && item->GetTemplate()->ItemLevel <= 34) {
		creature->MonsterWhisper("L'objet n'est pas d'un niveau suffisant.", player->GetGUID());
		MainMenu(player, creature);
        return; }
    if (requil == 2 && item->GetTemplate()->ItemLevel <= 59) {
		creature->MonsterWhisper("L'objet n'est pas d'un niveau suffisant.", player->GetGUID());
		MainMenu(player, creature);
        return; }
    if (twoha == 2 && item->GetTemplate()->SubClass != 10) {
		creature->MonsterWhisper("Cet enchantement requiert un bâton.", player->GetGUID());
		MainMenu(player, creature);
        return; }
    if (twoha == 1 && item->GetTemplate()->InventoryType != 17) {
		creature->MonsterWhisper("Cet enchantement requiert une arme à deux mains.", player->GetGUID());
		MainMenu(player, creature);
        return; }
	if (slotid == 16) {
	if (item->GetTemplate()->Class == 4 && item->GetTemplate()->SubClass != 6) {
		creature->MonsterWhisper("Je n'enchante pas ce genre d'objets.", player->GetGUID());
		player->CLOSE_GOSSIP_MENU();
        return; }
	if(item->GetTemplate()->SubClass == 6 && player->GetClmSlty() == 1) {
		creature->MonsterWhisper("Un enchantement d'arme ne va pas sur un bouclier.", player->GetGUID());
		player->CLOSE_GOSSIP_MENU();
		return; }
	if(item->GetTemplate()->SubClass != 6 && player->GetClmSlty() == 0) {
		creature->MonsterWhisper("Un enchantement de bouclier ne va pas sur ce type d'arme.", player->GetGUID());
		player->CLOSE_GOSSIP_MENU();
		return; } }
	SpellItemEnchantmentEntry const* enchant_id = sSpellItemEnchantmentStore.LookupEntry(enchid);
	if (!enchant_id) {
		creature->MonsterWhisper("L'enchantement sélectionné n'est pas un enchantement, prévenez un administrateur.", player->GetGUID());
		player->CLOSE_GOSSIP_MENU();
        return; }
	player->ApplyEnchantment(item, PERM_ENCHANTMENT_SLOT, false);
	item->SetEnchantment(PERM_ENCHANTMENT_SLOT, enchid, 0, 0);
	player->ApplyEnchantment(item, PERM_ENCHANTMENT_SLOT, true);
	/*else {
	player->ADD_GOSSIP_ITEM(0, "<Retour>", GOSSIP_SENDER_MAIN, 100);
	player->SEND_GOSSIP_MENU(1000011, creature->GetGUID()); 
	return; }*/
	MainMenu(player, creature); }

bool OnGossipSelect(Player *player, Creature * creature, uint32 sender, uint32 action) {
    player->PlayerTalkClass->ClearMenus();

		switch (action) {
	
	case 100:	MainMenu(player, creature);	break;

// Dos
	case 14:
		player->ADD_GOSSIP_ITEM(3, "7 résistances", GOSSIP_SENDER_MAIN, 1408);
		player->ADD_GOSSIP_ITEM(3, "12 esquive", GOSSIP_SENDER_MAIN, 1406);
		player->ADD_GOSSIP_ITEM(3, "35 pénétration des sorts", GOSSIP_SENDER_MAIN, 1409);
		player->ADD_GOSSIP_ITEM(3, "20 résistance ombre", GOSSIP_SENDER_MAIN, 1419);
		player->ADD_GOSSIP_ITEM(3, "20 résistance feu", GOSSIP_SENDER_MAIN, 1405);
		player->ADD_GOSSIP_ITEM(3, "20 résistance givre", GOSSIP_SENDER_MAIN, 1418);
		player->ADD_GOSSIP_ITEM(3, "20 résistance arcane", GOSSIP_SENDER_MAIN, 1410);
		player->ADD_GOSSIP_ITEM(3, "20 résistance nature", GOSSIP_SENDER_MAIN, 1400);
		player->ADD_GOSSIP_ITEM(3, "Camouflage et 10 agilité", GOSSIP_SENDER_MAIN, 1402);
		player->ADD_GOSSIP_ITEM(3, "10 esprit et -2% menace", GOSSIP_SENDER_MAIN, 1414);
		player->ADD_GOSSIP_ITEM(3, "16 score de défense", GOSSIP_SENDER_MAIN, 1415);
		player->ADD_GOSSIP_ITEM(3, "225 armure", GOSSIP_SENDER_MAIN, 1416);
		player->ADD_GOSSIP_ITEM(3, "23 hâte", GOSSIP_SENDER_MAIN, 1417);
		player->ADD_GOSSIP_ITEM(3, "22 agilité", GOSSIP_SENDER_MAIN, 1403);
		player->ADD_GOSSIP_ITEM(0, "=> Retour", GOSSIP_SENDER_MAIN, 100);
		player->SEND_GOSSIP_MENU(20004, creature->GetGUID());
		break;
	case 1400:	Ench(player, creature, 14, 1400, 0, 2, 0);	break;
	case 1402:	Ench(player, creature, 14, 3256, 0, 2, 0);	break;
	case 1403:	Ench(player, creature, 14, 1099, 0, 2, 0);	break;
	case 1405:	Ench(player, creature, 14, 1354, 0, 2, 0);	break;
	case 1406:	Ench(player, creature, 14, 2078, 0, 0, 0);	break;
	case 1408:	Ench(player, creature, 14, 2663, 0, 1, 0);	break;
	case 1409:	Ench(player, creature, 14, 3243, 0, 2, 0);	break;
	case 1410:	Ench(player, creature, 14, 1262, 0, 2, 0);	break;
	case 1414:	Ench(player, creature, 14, 3296, 0, 2, 0);	break;
	case 1415:	Ench(player, creature, 14, 1951, 0, 2, 0);	break;
	case 1416:	Ench(player, creature, 14, 3294, 0, 2, 0);	break;
	case 1417:	Ench(player, creature, 14, 3831, 0, 2, 0);	break;
	case 1418:	Ench(player, creature, 14, 3230, 0, 2, 0);	break;
	case 1419:	Ench(player, creature, 14, 1446, 0, 2, 0);	break;

		
// Torse
	case 4:
		player->ADD_GOSSIP_ITEM(3, "275 vie", GOSSIP_SENDER_MAIN, 401);
		player->ADD_GOSSIP_ITEM(3, "100 vie", GOSSIP_SENDER_MAIN, 402);
		player->ADD_GOSSIP_ITEM(3, "250 mana", GOSSIP_SENDER_MAIN, 410);
		player->ADD_GOSSIP_ITEM(3, "100 mana", GOSSIP_SENDER_MAIN, 403);
		player->ADD_GOSSIP_ITEM(3, "10 caractéristiques", GOSSIP_SENDER_MAIN, 400);
		player->ADD_GOSSIP_ITEM(3, "4 caracteristiques", GOSSIP_SENDER_MAIN, 404);
		player->ADD_GOSSIP_ITEM(3, "8 endurance", GOSSIP_SENDER_MAIN, 411);
		player->ADD_GOSSIP_ITEM(3, "10 mana par 5 secondes", GOSSIP_SENDER_MAIN, 405);
		player->ADD_GOSSIP_ITEM(3, "15 esprit", GOSSIP_SENDER_MAIN, 407);
		player->ADD_GOSSIP_ITEM(3, "20 résilience", GOSSIP_SENDER_MAIN, 408);
		player->ADD_GOSSIP_ITEM(3, "22 score de défense", GOSSIP_SENDER_MAIN, 409);
		player->ADD_GOSSIP_ITEM(3, "8 score de défense", GOSSIP_SENDER_MAIN, 412);
		player->ADD_GOSSIP_ITEM(0, "=> Retour", GOSSIP_SENDER_MAIN, 100);
		player->SEND_GOSSIP_MENU(20005, creature->GetGUID());
		break;
	case 400:	Ench(player, creature, 4, 3832, 0, 2, 0);	break;
	case 401:	Ench(player, creature, 4, 3297, 0, 2, 0);	break;
	case 402:	Ench(player, creature, 4, 1892, 0, 0, 0);	break;
	case 403:	Ench(player, creature, 4, 1893, 0, 0, 0);	break;
	case 404:	Ench(player, creature, 4, 1891, 0, 0, 0);	break;
	case 405:	Ench(player, creature, 4, 2852, 0, 2, 0);	break;
	case 407:	Ench(player, creature, 4, 1144, 0, 1, 0);	break;
	case 408:	Ench(player, creature, 4, 3245, 0, 2, 0);	break;
	case 409:	Ench(player, creature, 4, 1953, 0, 2, 0);	break;
	case 410:	Ench(player, creature, 4, 3233, 0, 2, 0);	break;
	case 411:	Ench(player, creature, 4, 2792, 0, 0, 0);	break;
	case 412:	Ench(player, creature, 4, 2793, 0, 0, 0);	break;
  
// Bras
	case 8:
		player->ADD_GOSSIP_ITEM(3, "40 endurance", GOSSIP_SENDER_MAIN, 805);
		player->ADD_GOSSIP_ITEM(3, "16 intelligence", GOSSIP_SENDER_MAIN, 806);
		player->ADD_GOSSIP_ITEM(3, "12 force", GOSSIP_SENDER_MAIN, 801);
		player->ADD_GOSSIP_ITEM(3, "50 puissance d'attaque", GOSSIP_SENDER_MAIN, 807);
		player->ADD_GOSSIP_ITEM(3, "30 puissance des sorts", GOSSIP_SENDER_MAIN, 800);
		player->ADD_GOSSIP_ITEM(3, "6 caracteristiques", GOSSIP_SENDER_MAIN, 802);
		player->ADD_GOSSIP_ITEM(3, "18 esprit", GOSSIP_SENDER_MAIN, 808);
		player->ADD_GOSSIP_ITEM(3, "12 défense", GOSSIP_SENDER_MAIN, 803);
		player->ADD_GOSSIP_ITEM(3, "8 mana par les 5 secondes", GOSSIP_SENDER_MAIN, 804);
		player->ADD_GOSSIP_ITEM(3, "15 expertise", GOSSIP_SENDER_MAIN, 809);
		player->ADD_GOSSIP_ITEM(0, "=> Retour", GOSSIP_SENDER_MAIN, 100);
		player->SEND_GOSSIP_MENU(20006, creature->GetGUID());
		break;
	case 800:	Ench(player, creature, 8, 2332, 0, 2, 0);	break;
	case 801:	Ench(player, creature, 8, 372, 0, 1, 0);	break;
	case 802:	Ench(player, creature, 8, 2661, 0, 2, 0);	break;
	case 803:	Ench(player, creature, 8, 1943, 0, 1, 0);	break;
	case 804:	Ench(player, creature, 8, 2382, 0, 1, 0);	break;
	case 805:	Ench(player, creature, 8, 3850, 0, 2, 0);	break;
	case 806:	Ench(player, creature, 8, 1119, 0, 2, 0);	break;
	case 807:	Ench(player, creature, 8, 3845, 0, 2, 0);	break;
	case 808:	Ench(player, creature, 8, 1147, 0, 2, 0);	break;
	case 809:	Ench(player, creature, 8, 3231, 0, 2, 0);	break;

// Mains
	case 9:
		player->ADD_GOSSIP_ITEM(3, "44 puissance d'attaque", GOSSIP_SENDER_MAIN, 905);
		player->ADD_GOSSIP_ITEM(3, "28 puissance des sorts", GOSSIP_SENDER_MAIN, 906);
		player->ADD_GOSSIP_ITEM(3, "20 toucher", GOSSIP_SENDER_MAIN, 903);
		player->ADD_GOSSIP_ITEM(3, "16 critique", GOSSIP_SENDER_MAIN, 902);
		player->ADD_GOSSIP_ITEM(3, "15 expertise", GOSSIP_SENDER_MAIN, 910);
		player->ADD_GOSSIP_ITEM(3, "20 agilité", GOSSIP_SENDER_MAIN, 901);
		player->ADD_GOSSIP_ITEM(3, "15 force", GOSSIP_SENDER_MAIN, 904);
		player->ADD_GOSSIP_ITEM(3, "8 endurance", GOSSIP_SENDER_MAIN, 912);
		player->ADD_GOSSIP_ITEM(3, "4 mana par 5 secondes", GOSSIP_SENDER_MAIN, 914);
		player->ADD_GOSSIP_ITEM(3, "10 hâte", GOSSIP_SENDER_MAIN, 907);
		player->ADD_GOSSIP_ITEM(3, "10 score de parades et +2% menace", GOSSIP_SENDER_MAIN, 909);
		player->ADD_GOSSIP_ITEM(3, "8 score de défense", GOSSIP_SENDER_MAIN, 913);
		player->ADD_GOSSIP_ITEM(3, "2% vitesse monture", GOSSIP_SENDER_MAIN, 908);
		player->ADD_GOSSIP_ITEM(3, "5 pêche", GOSSIP_SENDER_MAIN, 900);
		player->ADD_GOSSIP_ITEM(3, "5 collecte", GOSSIP_SENDER_MAIN, 911);
		player->ADD_GOSSIP_ITEM(0, "=> Retour", GOSSIP_SENDER_MAIN, 100);
		player->SEND_GOSSIP_MENU(20007, creature->GetGUID());
		break;
	case 900:	Ench(player, creature, 9, 846, 0, 0, 0);	break;
	case 901:	Ench(player, creature, 9, 3222, 0, 2, 0);	break;
	case 902:	Ench(player, creature, 9, 3249, 0, 2, 0);	break;
	case 903:	Ench(player, creature, 9, 3234, 0, 2, 0);	break;
	case 904:	Ench(player, creature, 9, 684, 0, 1, 0);	break;
	case 905:	Ench(player, creature, 9, 1603, 0, 2, 0);	break;
	case 906:	Ench(player, creature, 9, 3246, 0, 2, 0);	break;
	case 907:	Ench(player, creature, 9, 931, 0, 0, 0);	break;
	case 908:	Ench(player, creature, 9, 930, 0, 0, 0);	break;
	case 909:	Ench(player, creature, 9, 3253, 0, 2, 0);	break;
	case 910:	Ench(player, creature, 9, 3231, 0, 2, 0);	break;
	case 911:	Ench(player, creature, 9, 3238, 0, 2, 0);	break;
	case 912:	Ench(player, creature, 9, 2792, 0, 0, 0);	break; //renforts
	case 913:	Ench(player, creature, 9, 2793, 0, 0, 0);	break;
	case 914:	Ench(player, creature, 9, 2794, 0, 0, 0);	break;

// Jambes
// Mains
	case 6:
		player->ADD_GOSSIP_ITEM(3, "40 armure", GOSSIP_SENDER_MAIN, 600);
		player->ADD_GOSSIP_ITEM(3, "8 endurance", GOSSIP_SENDER_MAIN, 601);
		player->ADD_GOSSIP_ITEM(3, "8 score de défense", GOSSIP_SENDER_MAIN, 602);
		player->ADD_GOSSIP_ITEM(3, "4 mana par seconde", GOSSIP_SENDER_MAIN, 603);
		player->ADD_GOSSIP_ITEM(0, "= Retour =", GOSSIP_SENDER_MAIN, 100);
		player->SEND_GOSSIP_MENU(20007, creature->GetGUID());
		break;
	case 600:	Ench(player, creature, 6, 1843, 0, 0, 0);	break;
	case 601:	Ench(player, creature, 6, 2792, 0, 0, 0);	break;
	case 602:	Ench(player, creature, 6, 2793, 0, 0, 0);	break;
	case 603:	Ench(player, creature, 6, 2794, 0, 0, 0);	break;

// Bottes
	case 7:
		player->ADD_GOSSIP_ITEM(3, "22 endurance", GOSSIP_SENDER_MAIN, 701);
		player->ADD_GOSSIP_ITEM(3, "18 esprit", GOSSIP_SENDER_MAIN, 708);
		player->ADD_GOSSIP_ITEM(3, "16 agilité", GOSSIP_SENDER_MAIN, 704);
		player->ADD_GOSSIP_ITEM(3, "15 endurance + vitesse mineur", GOSSIP_SENDER_MAIN, 703);
		player->ADD_GOSSIP_ITEM(3, "6 agilité + vitesse mineur", GOSSIP_SENDER_MAIN, 705);
		player->ADD_GOSSIP_ITEM(3, "32 puissance d'attaque", GOSSIP_SENDER_MAIN, 704);
		player->ADD_GOSSIP_ITEM(3, "7 vie et mana par 5 secondes", GOSSIP_SENDER_MAIN, 700);
		player->ADD_GOSSIP_ITEM(3, "12 toucher et critique", GOSSIP_SENDER_MAIN, 702);
		player->ADD_GOSSIP_ITEM(3, "8 score de défense", GOSSIP_SENDER_MAIN, 709);
		player->ADD_GOSSIP_ITEM(3, "5 toucher", GOSSIP_SENDER_MAIN, 706);
		player->ADD_GOSSIP_ITEM(0, "=> Retour", GOSSIP_SENDER_MAIN, 100);
		player->SEND_GOSSIP_MENU(20008, creature->GetGUID());
		break;
	case 700:	Ench(player, creature, 7, 3244, 0, 2, 0);	break;
	case 701:	Ench(player, creature, 7, 1075, 0, 2, 0);	break;
	case 702:	Ench(player, creature, 7, 3826, 0, 2, 0);	break;
	case 703:	Ench(player, creature, 7, 3232, 0, 2, 0);	break;
	case 704:	Ench(player, creature, 7, 983, 0, 2, 0);	break;
	case 705:	Ench(player, creature, 7, 2939, 0, 1, 0);	break;
	case 706:	Ench(player, creature, 7, 3858, 0, 0, 0);	break;
	case 707:	Ench(player, creature, 7, 1597, 0, 2, 0);	break;
	case 708:	Ench(player, creature, 7, 1147, 0, 2, 0);	break;
	case 709:	Ench(player, creature, 7, 2793, 0, 0, 0);	break;
		
// Armes
	case 15:	player->SetClmSlotid(15);	goto l16;	break;
	case 16:	player->SetClmSlotid(16);	l16:
	case 153:	player->SetClmSlty(1);
		player->ADD_GOSSIP_ITEM(0, "=> Page 2", GOSSIP_SENDER_MAIN, 154);
		player->ADD_GOSSIP_ITEM(3, "50 endurance", GOSSIP_SENDER_MAIN, 1530);
		player->ADD_GOSSIP_ITEM(3, "45 esprit", GOSSIP_SENDER_MAIN, 1504);
		player->ADD_GOSSIP_ITEM(3, "26 agilité", GOSSIP_SENDER_MAIN, 1517);
		player->ADD_GOSSIP_ITEM(3, "22 intelligence", GOSSIP_SENDER_MAIN, 1505);
		player->ADD_GOSSIP_ITEM(3, "20 force", GOSSIP_SENDER_MAIN, 1508);
		player->ADD_GOSSIP_ITEM(3, "15 agilité", GOSSIP_SENDER_MAIN, 1503);
		player->ADD_GOSSIP_ITEM(3, "65 puissance d'attaque", GOSSIP_SENDER_MAIN, 1501);
		player->ADD_GOSSIP_ITEM(3, "63 puissance des sorts", GOSSIP_SENDER_MAIN, 1515);
		player->ADD_GOSSIP_ITEM(3, "30 puissance des sorts", GOSSIP_SENDER_MAIN, 1538);
		player->ADD_GOSSIP_ITEM(3, "25 critique et toucher", GOSSIP_SENDER_MAIN, 1533);
		player->ADD_GOSSIP_ITEM(3, "7 dégâts de l'arme", GOSSIP_SENDER_MAIN, 1506);
		player->ADD_GOSSIP_ITEM(3, "5 dégâts de l'arme", GOSSIP_SENDER_MAIN, 1521);
		player->ADD_GOSSIP_ITEM(0, "= Retour =", GOSSIP_SENDER_MAIN, 100);
		player->SEND_GOSSIP_MENU(20009, creature->GetGUID());
		break;
	case 154:
		player->ADD_GOSSIP_ITEM(0, "=> Page 2", GOSSIP_SENDER_MAIN, 155);
		player->ADD_GOSSIP_ITEM(0, "Page 1 <=", GOSSIP_SENDER_MAIN, 153);
		player->ADD_GOSSIP_ITEM(3, "Berserker", GOSSIP_SENDER_MAIN, 1531);
		player->ADD_GOSSIP_ITEM(3, "Magie noire", GOSSIP_SENDER_MAIN, 1532);
		player->ADD_GOSSIP_ITEM(3, "Bourreau", GOSSIP_SENDER_MAIN, 1536);
		player->ADD_GOSSIP_ITEM(3, "Mangouste", GOSSIP_SENDER_MAIN, 1512);
		player->ADD_GOSSIP_ITEM(3, "Brise-glace", GOSSIP_SENDER_MAIN, 1520);
		player->ADD_GOSSIP_ITEM(3, "Gardevie", GOSSIP_SENDER_MAIN, 1535);
		player->ADD_GOSSIP_ITEM(3, "Maître de guerre", GOSSIP_SENDER_MAIN, 1514);
		player->ADD_GOSSIP_ITEM(3, "Eruption de sort", GOSSIP_SENDER_MAIN, 1513);
		player->ADD_GOSSIP_ITEM(3, "Croisé", GOSSIP_SENDER_MAIN, 1500);
		player->ADD_GOSSIP_ITEM(3, "Vol-de-vie", GOSSIP_SENDER_MAIN, 1518);
		player->ADD_GOSSIP_ITEM(3, "Flamboyante", GOSSIP_SENDER_MAIN, 1537);
		player->ADD_GOSSIP_ITEM(3, "Impie", GOSSIP_SENDER_MAIN, 1519);
		player->ADD_GOSSIP_ITEM(3, "Frisson glacial", GOSSIP_SENDER_MAIN, 1522);
		player->ADD_GOSSIP_ITEM(3, "Tueur de démons", GOSSIP_SENDER_MAIN, 1523);
		player->ADD_GOSSIP_ITEM(3, "Tueur de géants", GOSSIP_SENDER_MAIN, 1534);
		player->ADD_GOSSIP_ITEM(0, "= Retour =", GOSSIP_SENDER_MAIN, 100);
		player->SEND_GOSSIP_MENU(20009, creature->GetGUID());
		break;
	case 155:
		player->ADD_GOSSIP_ITEM(0, "Page 2 <=", GOSSIP_SENDER_MAIN, 154);
		player->ADD_GOSSIP_ITEM(3, "Bâton - 81 puissance des sorts", GOSSIP_SENDER_MAIN, 1540);
		player->ADD_GOSSIP_ITEM(3, "2M - 110 puissance d'attaque", GOSSIP_SENDER_MAIN, 1525);
		player->ADD_GOSSIP_ITEM(3, "2M - 140 puissance d'attaque contre les morts vivants", GOSSIP_SENDER_MAIN, 1525);
		player->ADD_GOSSIP_ITEM(3, "2M - 35 agilité", GOSSIP_SENDER_MAIN, 1526);
		player->ADD_GOSSIP_ITEM(3, "2M - 25 agilité", GOSSIP_SENDER_MAIN, 1524);
		player->ADD_GOSSIP_ITEM(3, "2M - 9 dégâts de l'arme", GOSSIP_SENDER_MAIN, 1527);
		player->ADD_GOSSIP_ITEM(0, "= Retour =", GOSSIP_SENDER_MAIN, 100);
		player->SEND_GOSSIP_MENU(20009, creature->GetGUID());
		break;
// 1M
	case 1500:	Ench(player, creature, player->GetClmSlotid(), 1900, 0, 0, player->GetClmSlty());	break;
	case 1501:	Ench(player, creature, player->GetClmSlotid(), 3833, 0, 2, player->GetClmSlty());	break;
	case 1503:	Ench(player, creature, player->GetClmSlotid(), 2564, 0, 0, player->GetClmSlty());	break;
	case 1504:	Ench(player, creature, player->GetClmSlotid(), 3844, 0, 2, player->GetClmSlty());	break;
	case 1505:	Ench(player, creature, player->GetClmSlotid(), 2568, 0, 0, player->GetClmSlty());	break;
	case 1506:	Ench(player, creature, player->GetClmSlotid(), 120, 0, 1, player->GetClmSlty());	break;
	case 1508:	Ench(player, creature, player->GetClmSlotid(), 2668, 0, 1, player->GetClmSlty());	break;
	case 1512:	Ench(player, creature, player->GetClmSlotid(), 2673, 0, 1, player->GetClmSlty());	break;
	case 1513:	Ench(player, creature, player->GetClmSlotid(), 2674, 0, 1, player->GetClmSlty());	break;
	case 1514:	Ench(player, creature, player->GetClmSlotid(), 2675, 0, 1, player->GetClmSlty());	break;
	case 1515:	Ench(player, creature, player->GetClmSlotid(), 3834, 0, 2, player->GetClmSlty());	break;
	case 1517:	Ench(player, creature, player->GetClmSlotid(), 1103, 0, 2, player->GetClmSlty());	break;
	case 1518:	Ench(player, creature, player->GetClmSlotid(), 1898, 0, 0, player->GetClmSlty());	break;
	case 1519:	Ench(player, creature, player->GetClmSlotid(), 1899, 0, 0, player->GetClmSlty());	break;
	case 1520:	Ench(player, creature, player->GetClmSlotid(), 3239, 0, 2, player->GetClmSlty());	break;
	case 1521:	Ench(player, creature, player->GetClmSlotid(), 118, 0, 0, player->GetClmSlty());	break;
	case 1522:	Ench(player, creature, player->GetClmSlotid(), 1894, 0, 0, player->GetClmSlty());	break;
	case 1523:	Ench(player, creature, player->GetClmSlotid(), 912, 0, 0, player->GetClmSlty());	break;
	
	case 1530:	Ench(player, creature, player->GetClmSlotid(), 3851, 0, 2, player->GetClmSlty());	break;
	case 1531:	Ench(player, creature, player->GetClmSlotid(), 3789, 0, 2, player->GetClmSlty());	break;
	case 1532:	Ench(player, creature, player->GetClmSlotid(), 3790, 0, 2, player->GetClmSlty());	break;
	case 1533:	Ench(player, creature, player->GetClmSlotid(), 3788, 0, 2, player->GetClmSlty());	break;
	case 1534:	Ench(player, creature, player->GetClmSlotid(), 3251, 0, 2, player->GetClmSlty());	break;
	case 1535:	Ench(player, creature, player->GetClmSlotid(), 3241, 0, 2, player->GetClmSlty());	break;
	case 1536:	Ench(player, creature, player->GetClmSlotid(), 3225, 0, 2, player->GetClmSlty());	break;
	case 1537:	Ench(player, creature, player->GetClmSlotid(), 803, 0, 0, player->GetClmSlty());	break;
	case 1538:	Ench(player, creature, player->GetClmSlotid(), 2504, 0, 0, player->GetClmSlty());	break;
	
	
// 2M
	case 1524:	Ench(player, creature, player->GetClmSlotid(), 2646, 1, 0, player->GetClmSlty());	break;
	case 1525:	Ench(player, creature, player->GetClmSlotid(), 3827, 1, 2, player->GetClmSlty());	break;
	case 1526:	Ench(player, creature, player->GetClmSlotid(), 2670, 1, 1, player->GetClmSlty());	break;
	case 1527:	Ench(player, creature, player->GetClmSlotid(), 1895, 1, 0, player->GetClmSlty());	break;
	
	case 1540:	Ench(player, creature, player->GetClmSlotid(), 3854, 1, 3, player->GetClmSlty());	break;
	case 1541:	Ench(player, creature, player->GetClmSlotid(), 3247, 1, 2, player->GetClmSlty());	break;

// Boucliers
	case 18:
		player->ADD_GOSSIP_ITEM(3, "18 endurance", GOSSIP_SENDER_MAIN, 1803);
		player->ADD_GOSSIP_ITEM(3, "25 inteligence", GOSSIP_SENDER_MAIN, 1804);
		player->ADD_GOSSIP_ITEM(3, "12 résilience", GOSSIP_SENDER_MAIN, 1800);
		player->ADD_GOSSIP_ITEM(3, "36 valeur de blacage", GOSSIP_SENDER_MAIN, 1801);
		player->ADD_GOSSIP_ITEM(3, "20 score de blocage", GOSSIP_SENDER_MAIN, 1802);
		player->ADD_GOSSIP_ITEM(3, "5 à toutes les résistances", GOSSIP_SENDER_MAIN, 1805);
		player->ADD_GOSSIP_ITEM(0, "=> Retour", GOSSIP_SENDER_MAIN, 100);
		player->SEND_GOSSIP_MENU(20010, creature->GetGUID());
		break;
	case 1800:	Ench(player, creature, 16, 3229, 0, 1, player->GetClmSlty());	break;
	case 1801:	Ench(player, creature, 16, 2653, 0, 1, player->GetClmSlty());	break;
	case 1802:	Ench(player, creature, 16, 1952, 0, 2, player->GetClmSlty());	break;
	case 1803:	Ench(player, creature, 16, 1071, 0, 1, player->GetClmSlty());	break;
	case 1804:	Ench(player, creature, 16, 1128, 0, 2, player->GetClmSlty());	break;
	case 1805:	Ench(player, creature, 16, 1888, 0, 1, player->GetClmSlty());	break;
		
// Ranged
	case 17:	Ench(player, creature, 17, 663, 0, 0, 0);	break;
	
		}
	return true; }
};

void AddSc_enchant_npc() {
	new enchant_npc(); }