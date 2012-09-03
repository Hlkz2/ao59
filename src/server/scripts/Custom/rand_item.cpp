#include "ScriptPCH.h"

class rand_item : public CreatureScript {
	public: rand_item() : CreatureScript("rand_item") {}

uint32 count; std::string* rie;

int32 Choix(int32 item_id, int choix) {
    ItemTemplate const* itemProto = sObjectMgr->GetItemTemplate(item_id);
    if (!itemProto) return 0;
    if ((!itemProto->RandomProperty) && (!itemProto->RandomSuffix)) return 0;
    if ((itemProto->RandomProperty) && (itemProto->RandomSuffix)) return 0;
    if (itemProto->RandomProperty) {
        uint32 randomPropId = choix;
        ItemRandomPropertiesEntry const* random_id = sItemRandomPropertiesStore.LookupEntry(randomPropId);
        if (!random_id) return 0;
        return random_id->ID; }
    else {
        uint32 randomPropId = choix;
        ItemRandomSuffixEntry const* random_id = sItemRandomSuffixStore.LookupEntry(randomPropId);
        if (!random_id) return 0;
        return -int32(random_id->ID); } }

void AddItemChoix(Player *player, uint32 item_id, int choix) {
    uint32 noSpaceForCount = 0;
    ItemPosCountVec dest;
    InventoryResult msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, item_id, 1, &noSpaceForCount);
    if (msg != EQUIP_ERR_OK)
    if (dest.empty()) {
        ChatHandler(player).PSendSysMessage("Vous n'avez plus de place.");
        return; }
		Item* item = player->StoreNewItem(dest, item_id, true, Choix(item_id, choix));
		if (item) player->SendNewItem(item, 1, true, false);
    return; }

void MainMenu(Player *player, Creature *creature) {
	player->ADD_GOSSIP_ITEM(6, "Rare..", GOSSIP_SENDER_MAIN, 150);
	player->ADD_GOSSIP_ITEM(6, "Sacoche..", GOSSIP_SENDER_MAIN, 300);
	player->ADD_GOSSIP_ITEM(6, "Atal'ai..", GOSSIP_SENDER_MAIN, 350);
	player->ADD_GOSSIP_ITEM(6, "Inhabituel 47-49..", GOSSIP_SENDER_MAIN, 10);
	player->ADD_GOSSIP_ITEM(6, "Hors set", GOSSIP_SENDER_MAIN, 250);
	player->SEND_GOSSIP_MENU(1000023, creature->GetGUID()); }
	
bool OnGossipHello(Player *player, Creature * creature) { MainMenu(player, creature); return true; }
	
bool OnGossipSelect(Player *player, Creature * creature, uint32 sender, uint32 action) {
    player->PlayerTalkClass->ClearMenus();

		switch (action) {
	
	case 100: MainMenu(player, creature); break;
	case 101: player->CLOSE_GOSSIP_MENU(); break;
	
    case 10:
        player->SetRandRetour(action);
        player->ADD_GOSSIP_ITEM(6, "Tissu..", GOSSIP_SENDER_MAIN, 400);
        player->ADD_GOSSIP_ITEM(6, "Cuir..", GOSSIP_SENDER_MAIN, 500);
        player->ADD_GOSSIP_ITEM(6, "Mailles..", GOSSIP_SENDER_MAIN, 600);
        player->ADD_GOSSIP_ITEM(6, "Plaques..", GOSSIP_SENDER_MAIN, 700);
        player->ADD_GOSSIP_ITEM(20, "= Retour =", GOSSIP_SENDER_MAIN, 100);
        player->SEND_GOSSIP_MENU(1000023, creature->GetGUID());
		break;

    case 150:
        player->SetRandRetour(action);
        player->ADD_GOSSIP_ITEM(6, "Collier d'opales de feu (47)", GOSSIP_SENDER_MAIN, 152);
        player->ADD_GOSSIP_ITEM(6, "Fend-les-côtes (48)", GOSSIP_SENDER_MAIN, 153);
        player->ADD_GOSSIP_ITEM(6, "Pierre de drake (49)", GOSSIP_SENDER_MAIN, 154);
        player->ADD_GOSSIP_ITEM(6, "Bague griffe-de-drake (49)", GOSSIP_SENDER_MAIN, 155);
        player->ADD_GOSSIP_ITEM(6, "Anneau en sombrefer (48)", GOSSIP_SENDER_MAIN, 156);
        player->ADD_GOSSIP_ITEM(6, "Anneau runique (45)", GOSSIP_SENDER_MAIN, 157);
        player->ADD_GOSSIP_ITEM(6, "Chevalière d'aigue-marine (43)", GOSSIP_SENDER_MAIN, 162);
        player->ADD_GOSSIP_ITEM(6, "Lentille verte (Ingé)", GOSSIP_SENDER_MAIN, 158);
        player->ADD_GOSSIP_ITEM(6, "Brassards des eaux sombres (47)", GOSSIP_SENDER_MAIN, 159);
        player->ADD_GOSSIP_ITEM(6, "Poignes de fer (43)", GOSSIP_SENDER_MAIN, 160);
        player->ADD_GOSSIP_ITEM(6, "Poings de la combe(40)", GOSSIP_SENDER_MAIN, 161);
        player->ADD_GOSSIP_ITEM(20, "= Retour =", GOSSIP_SENDER_MAIN, 100);
        player->SEND_GOSSIP_MENU(1000023, creature->GetGUID());
		break;
	    case 152: player->SetRandItId(11946); goto l276276; break;
	    case 153: player->SetRandItId(12527); goto l276276; break;
	    case 154: player->SetRandItId(10796); goto l276276; break;
	    case 155: player->SetRandItId(10795); goto l276276; break;
	    case 156: player->SetRandItId(11945); goto l276276; break;
	    case 157: player->SetRandItId(862); goto l276276; break;
	    case 158: player->SetRandItId(10504); goto l276276; break;
	    case 159: player->SetRandItId(10800); goto l276276; break;
	    case 160: player->SetRandItId(9640); goto l276276; break;
	    case 161: player->SetRandItId(9410); goto l276276; break;
	    case 162: player->SetRandItId(20964); goto l276276; break;

    case 250:
        player->SetRandRetour(action);
        player->ADD_GOSSIP_ITEM(6, "Cape céleste", GOSSIP_SENDER_MAIN, 265);
        player->ADD_GOSSIP_ITEM(6, "Cape sans pareille", GOSSIP_SENDER_MAIN, 266);
        player->ADD_GOSSIP_ITEM(6, "Main de sorcier", GOSSIP_SENDER_MAIN, 252);
        player->ADD_GOSSIP_ITEM(6, "Arc de siège", GOSSIP_SENDER_MAIN, 253);
        player->ADD_GOSSIP_ITEM(6, "Déflecteur de revenant", GOSSIP_SENDER_MAIN, 254);
        player->ADD_GOSSIP_ITEM(6, "Bouclier de jade", GOSSIP_SENDER_MAIN, 255);
        player->ADD_GOSSIP_ITEM(6, "Cristal d'abjurateur", GOSSIP_SENDER_MAIN, 256);
        player->ADD_GOSSIP_ITEM(6, "Sceptre de Gaïa", GOSSIP_SENDER_MAIN, 257);
        player->ADD_GOSSIP_ITEM(6, "Lame veuve", GOSSIP_SENDER_MAIN, 258);
        player->ADD_GOSSIP_ITEM(6, "Etoile fracassante", GOSSIP_SENDER_MAIN, 259);
        player->ADD_GOSSIP_ITEM(6, "Fendoir lunaire", GOSSIP_SENDER_MAIN, 260);
        player->ADD_GOSSIP_ITEM(6, "Espadon noir", GOSSIP_SENDER_MAIN, 261);
        player->ADD_GOSSIP_ITEM(6, "Lame de décapitation", GOSSIP_SENDER_MAIN, 262);
        player->ADD_GOSSIP_ITEM(6, "Bâton de thaumaturge", GOSSIP_SENDER_MAIN, 263);
        player->ADD_GOSSIP_ITEM(6, "Bâton long de divination", GOSSIP_SENDER_MAIN, 264);
        player->ADD_GOSSIP_ITEM(20, "= Retour =", GOSSIP_SENDER_MAIN, 100);
        player->SEND_GOSSIP_MENU(1000023, creature->GetGUID());
		break;
	    case 252: player->SetRandItId(15280); goto l276276; break;
	    case 253: player->SetRandItId(15294); goto l276276; break;
	    case 254: player->SetRandItId(10093); goto l276276; break;
	    case 255: player->SetRandItId(14916); goto l276276; break;
	    case 256: player->SetRandItId(9944); goto l276276; break;
	    case 257: player->SetRandItId(15983); goto l276276; break;
	    case 258: player->SetRandItId(15217); goto l276276; break;
	    case 259: player->SetRandItId(15228); goto l276276; break;
	    case 260: player->SetRandItId(15236); goto l276276; break;
	    case 261: player->SetRandItId(15254); goto l276276; break;
	    case 262: player->SetRandItId(15253); goto l276276; break;
	    case 263: player->SetRandItId(15275); goto l276276; break;
	    case 264: player->SetRandItId(15274); goto l276276; break;
	    case 265: player->SetRandItId(14313); goto l276276; break;
	    case 266: player->SetRandItId(15427); goto l276276; break;
		
    case 300:
        player->SetRandRetour(action);
        player->ADD_GOSSIP_ITEM(6, "Sandales dénombrées (45)", GOSSIP_SENDER_MAIN, 302);
        player->ADD_GOSSIP_ITEM(6, "Brassards dénombrés (45)", GOSSIP_SENDER_MAIN, 303);
        player->ADD_GOSSIP_ITEM(6, "Croquenots vigoureux (45)", GOSSIP_SENDER_MAIN, 304);
        player->ADD_GOSSIP_ITEM(6, "Brassards vigoureux.(45)", GOSSIP_SENDER_MAIN, 305);
        player->ADD_GOSSIP_ITEM(6, "Bottes liées à la terre (45)", GOSSIP_SENDER_MAIN, 306);
        player->ADD_GOSSIP_ITEM(6, "Garde-poignets liés à la terre (45)", GOSSIP_SENDER_MAIN, 307);
        player->ADD_GOSSIP_ITEM(6, "Bottines infrangibles (45)", GOSSIP_SENDER_MAIN, 308);
        player->ADD_GOSSIP_ITEM(6, "Poignets infrangibles (45)", GOSSIP_SENDER_MAIN, 309);
        player->ADD_GOSSIP_ITEM(6, "Anneau tumultueux (35)", GOSSIP_SENDER_MAIN, 310);
        player->ADD_GOSSIP_ITEM(6, "Protège-épaules dénombrés (35)", GOSSIP_SENDER_MAIN, 311);
        player->ADD_GOSSIP_ITEM(6, "Spallières vigoureuses (35)", GOSSIP_SENDER_MAIN, 312);
        player->ADD_GOSSIP_ITEM(6, "Garde-épaules liés à la terre (35)", GOSSIP_SENDER_MAIN, 313);
        player->ADD_GOSSIP_ITEM(6, "Protège-épaules infrangibles (35)", GOSSIP_SENDER_MAIN, 314);
        player->ADD_GOSSIP_ITEM(6, "Collier tumultueux (25)", GOSSIP_SENDER_MAIN, 315);
        player->ADD_GOSSIP_ITEM(6, "Protège-mains dénombrés (25)", GOSSIP_SENDER_MAIN, 316);
        player->ADD_GOSSIP_ITEM(6, "Garde-mains vigoureux (25)", GOSSIP_SENDER_MAIN, 317);
        player->ADD_GOSSIP_ITEM(6, "Manicles liées à la terre (25)", GOSSIP_SENDER_MAIN, 318);
        player->ADD_GOSSIP_ITEM(20, "= Retour =", GOSSIP_SENDER_MAIN, 100);
        player->SEND_GOSSIP_MENU(1000023, creature->GetGUID());
		break;
	    case 302: player->SetRandItId(51967); goto l276276; break;
	    case 303: player->SetRandItId(51972); goto l276276; break;
	    case 304: player->SetRandItId(51963); goto l276276; break;
	    case 305: player->SetRandItId(51962); goto l276276; break;
	    case 306: player->SetRandItId(51982); goto l276276; break;
	    case 307: player->SetRandItId(51981); goto l276276; break;
	    case 308: player->SetRandItId(51990); goto l276276; break;
	    case 309: player->SetRandItId(51989); goto l276276; break;
	    case 310: player->SetRandItId(51992); goto l276276; break;
	    case 311: player->SetRandItId(51974); goto l276276; break;
	    case 312: player->SetRandItId(51966); goto l276276; break;
	    case 313: player->SetRandItId(51976); goto l276276; break;
	    case 314: player->SetRandItId(51984); goto l276276; break;
	    case 315: player->SetRandItId(51996); goto l276276; break;
	    case 316: player->SetRandItId(51973); goto l276276; break;
	    case 317: player->SetRandItId(51965); goto l276276; break;
	    case 318: player->SetRandItId(51980); goto l276276; break;

    case 350:
        player->SetRandRetour(action);
        player->ADD_GOSSIP_ITEM(6, "Gants atal'ai (Tissu)", GOSSIP_SENDER_MAIN, 352);
        player->ADD_GOSSIP_ITEM(6, "Spallières atal'ai (Cuir)", GOSSIP_SENDER_MAIN, 353);
        player->ADD_GOSSIP_ITEM(6, "Jambières atal'ai (Cuir)", GOSSIP_SENDER_MAIN, 354);
        player->ADD_GOSSIP_ITEM(6, "Cuirasse atal'ai (Mailles)", GOSSIP_SENDER_MAIN, 355);
        player->ADD_GOSSIP_ITEM(6, "Bottes atal'ai (Mailles)", GOSSIP_SENDER_MAIN, 356);
        player->ADD_GOSSIP_ITEM(6, "Ceinturon atal'ai (Plaques)", GOSSIP_SENDER_MAIN, 357);
        player->ADD_GOSSIP_ITEM(20, "= Retour =", GOSSIP_SENDER_MAIN, 100);
        player->SEND_GOSSIP_MENU(1000023, creature->GetGUID());
		break;
	    case 352: player->SetRandItId(10787); goto l276276; break;
	    case 353: player->SetRandItId(10783); goto l276276; break;
	    case 354: player->SetRandItId(10785); goto l276276; break;
	    case 355: player->SetRandItId(10784); goto l276276; break;
	    case 356: player->SetRandItId(10786); goto l276276; break;
	    case 357: player->SetRandItId(10788); goto l276276; break;
		
    case 400:
        player->SetRandRetour(action);
        player->ADD_GOSSIP_ITEM(6, "Couronne opulente", GOSSIP_SENDER_MAIN, 404);
        player->ADD_GOSSIP_ITEM(6, "Espauliers arachnéens", GOSSIP_SENDER_MAIN, 405);
        player->ADD_GOSSIP_ITEM(6, "Robe d'abjurateur", GOSSIP_SENDER_MAIN, 406);
        player->ADD_GOSSIP_ITEM(6, "Tunique de Gaïa", GOSSIP_SENDER_MAIN, 407);
        player->ADD_GOSSIP_ITEM(6, "Crispins de conseiller", GOSSIP_SENDER_MAIN, 408);
        player->ADD_GOSSIP_ITEM(6, "Manchettes d'ossomancien", GOSSIP_SENDER_MAIN, 409);
        player->ADD_GOSSIP_ITEM(6, "Echarpe de conseiller", GOSSIP_SENDER_MAIN, 410);
        player->ADD_GOSSIP_ITEM(6, "Ceinture mystique", GOSSIP_SENDER_MAIN, 411);
        player->ADD_GOSSIP_ITEM(6, "Jambières opulentes", GOSSIP_SENDER_MAIN, 412);
        player->ADD_GOSSIP_ITEM(6, "Pantalon tissé de pénombre", GOSSIP_SENDER_MAIN, 413);
        player->ADD_GOSSIP_ITEM(6, "Bottes mystique", GOSSIP_SENDER_MAIN, 414);
        player->ADD_GOSSIP_ITEM(6, "Bottes d'ossomancien", GOSSIP_SENDER_MAIN, 415);
        player->ADD_GOSSIP_ITEM(20, "= Retour =", GOSSIP_SENDER_MAIN, 10);
        player->SEND_GOSSIP_MENU(1000023, creature->GetGUID());
		break;
	    case 404: player->SetRandItId(14281); goto l276276; break;
	    case 405: player->SetRandItId(14296); goto l276276; break;
	    case 406: player->SetRandItId(9943); goto l276276; break;
	    case 407: player->SetRandItId(14277); goto l276276; break;
	    case 408: player->SetRandItId(10096); goto l276276; break;
	    case 409: player->SetRandItId(14301); goto l276276; break;
	    case 410: player->SetRandItId(10103); goto l276276; break;
	    case 411: player->SetRandItId(10180); goto l276276; break;
	    case 412: player->SetRandItId(14283); goto l276276; break;
	    case 413: player->SetRandItId(10064); goto l276276; break;
	    case 414: player->SetRandItId(10179); goto l276276; break;
	    case 415: player->SetRandItId(14299); goto l276276; break;

    case 500:
        player->SetRandRetour(action);
        player->ADD_GOSSIP_ITEM(6, "Casque pieux", GOSSIP_SENDER_MAIN, 502);
        player->ADD_GOSSIP_ITEM(6, "Cuirasse de chef", GOSSIP_SENDER_MAIN, 505);
        player->ADD_GOSSIP_ITEM(6, "Armure tout-puissante", GOSSIP_SENDER_MAIN, 506);
        player->ADD_GOSSIP_ITEM(6, "Brassards d'errant", GOSSIP_SENDER_MAIN, 507);
        player->ADD_GOSSIP_ITEM(6, "Brassards de bretteur", GOSSIP_SENDER_MAIN, 508);
        player->ADD_GOSSIP_ITEM(6, "Gants prétoriens", GOSSIP_SENDER_MAIN, 509);
        player->ADD_GOSSIP_ITEM(6, "Gants de bretteur", GOSSIP_SENDER_MAIN, 510);
        player->ADD_GOSSIP_ITEM(6, "Ceinture d'errant", GOSSIP_SENDER_MAIN, 511);
        player->ADD_GOSSIP_ITEM(6, "Ceinturon prétorien", GOSSIP_SENDER_MAIN, 512);
        player->ADD_GOSSIP_ITEM(6, "Bottes de bretteur", GOSSIP_SENDER_MAIN, 513);
        player->ADD_GOSSIP_ITEM(6, "Solerets jadefeu", GOSSIP_SENDER_MAIN, 514);
        player->ADD_GOSSIP_ITEM(20, "= Retour =", GOSSIP_SENDER_MAIN, 10);
        player->SEND_GOSSIP_MENU(1000023, creature->GetGUID());
		break;
	    case 502: player->SetRandItId(10073); goto l276276; break;
	    case 505: player->SetRandItId(9650); goto l276276; break;
	    case 506: player->SetRandItId(15170); goto l276276; break;
	    case 507: player->SetRandItId(10107); goto l276276; break;
	    case 508: player->SetRandItId(10184); goto l276276; break;
	    case 509: player->SetRandItId(15180); goto l276276; break;
	    case 510: player->SetRandItId(10186); goto l276276; break;
	    case 511: player->SetRandItId(10109); goto l276276; break;
	    case 512: player->SetRandItId(15180); goto l276276; break;
	    case 513: player->SetRandItId(10064); goto l276276; break;
	    case 514: player->SetRandItId(10183); goto l276276; break;
	    case 515: player->SetRandItId(15389); goto l276276; break;

    case 600:
        player->SetRandRetour(action);
        player->ADD_GOSSIP_ITEM(6, "Heaume de croisé", GOSSIP_SENDER_MAIN, 602);
        player->ADD_GOSSIP_ITEM(6, "Diadème formidable", GOSSIP_SENDER_MAIN, 603);
        player->ADD_GOSSIP_ITEM(6, "Epaulettes impitoyables", GOSSIP_SENDER_MAIN, 604);
        player->ADD_GOSSIP_ITEM(6, "Espauliers en cuiracier", GOSSIP_SENDER_MAIN, 605);
        player->ADD_GOSSIP_ITEM(6, "Brassards ornés", GOSSIP_SENDER_MAIN, 606);
        player->ADD_GOSSIP_ITEM(6, "Gantelets impitoyables", GOSSIP_SENDER_MAIN, 607);
        player->ADD_GOSSIP_ITEM(6, "Gantelets en cuiracier", GOSSIP_SENDER_MAIN, 608);
        player->ADD_GOSSIP_ITEM(6, "Ceinture impitoyable", GOSSIP_SENDER_MAIN, 609);
        player->ADD_GOSSIP_ITEM(6, "Ceinture de croisé", GOSSIP_SENDER_MAIN, 610);
        player->ADD_GOSSIP_ITEM(6, "Jambières de croisé", GOSSIP_SENDER_MAIN, 611);
        player->ADD_GOSSIP_ITEM(6, "Garde-jambes de seigneur", GOSSIP_SENDER_MAIN, 612);
        player->ADD_GOSSIP_ITEM(20, "= Retour =", GOSSIP_SENDER_MAIN, 10);
        player->SEND_GOSSIP_MENU(1000023, creature->GetGUID());
		break;
	    case 602: player->SetRandItId(10198); goto l276276; break;
	    case 603: player->SetRandItId(15634); goto l276276; break;
	    case 604: player->SetRandItId(15656); goto l276276; break;
	    case 605: player->SetRandItId(15647); goto l276276; break;
	    case 606: player->SetRandItId(10126); goto l276276; break;
	    case 607: player->SetRandItId(15653); goto l276276; break;
	    case 608: player->SetRandItId(15644); goto l276276; break;
	    case 609: player->SetRandItId(15654); goto l276276; break;
	    case 610: player->SetRandItId(10197); goto l276276; break;
	    case 611: player->SetRandItId(10199); goto l276276; break;
	    case 612: player->SetRandItId(10084); goto l276276; break;
		
    case 700:
        player->SetRandRetour(action);
        player->ADD_GOSSIP_ITEM(6, "Heaume lamellaire lourd", GOSSIP_SENDER_MAIN, 702);
        player->ADD_GOSSIP_ITEM(6, "Espauliers lamellaires lourds", GOSSIP_SENDER_MAIN, 703);
        player->ADD_GOSSIP_ITEM(6, "Espauliers de grand chef", GOSSIP_SENDER_MAIN, 704);
        player->ADD_GOSSIP_ITEM(6, "Pansière de revenant", GOSSIP_SENDER_MAIN, 705);
        player->ADD_GOSSIP_ITEM(6, "Cuirasse de jade", GOSSIP_SENDER_MAIN, 706);
        player->ADD_GOSSIP_ITEM(6, "Brassards de templier", GOSSIP_SENDER_MAIN, 707);
        player->ADD_GOSSIP_ITEM(6, "Jambières lamellaires lourdes", GOSSIP_SENDER_MAIN, 708);
        player->ADD_GOSSIP_ITEM(6, "Garde-jambes de grand chef", GOSSIP_SENDER_MAIN, 709);
        player->ADD_GOSSIP_ITEM(6, "Bottes lamellaires lourdes", GOSSIP_SENDER_MAIN, 710);
        player->ADD_GOSSIP_ITEM(20, "= Retour =", GOSSIP_SENDER_MAIN, 10);
        player->SEND_GOSSIP_MENU(1000023, creature->GetGUID());
		break;
	    case 702: player->SetRandItId(10241); goto l276276; break;
	    case 703: player->SetRandItId(10245); goto l276276; break;
	    case 704: player->SetRandItId(14963); goto l276276; break;
	    case 705: player->SetRandItId(10128); goto l276276; break;
	    case 706: player->SetRandItId(14915); goto l276276; break;
	    case 707: player->SetRandItId(10171); goto l276276; break;
	    case 708: player->SetRandItId(10244); goto l276276; break;
	    case 709: player->SetRandItId(14962); goto l276276; break;
	    case 710: player->SetRandItId(10238); goto l276276; break;

l276276:
		case 9999:
			lmenu:
			player->PlayerTalkClass->ClearMenus();
			player->SetRandRis(RandItemSuffix(player->GetRandItId()));
			player->SetRandRie(RandItemEnch(player->GetRandItId()));
			for (count=0; count<31; count++) {
				if (player->GetRandRie()[count] == 2) goto lmenu2;
				player->ADD_GOSSIP_ITEM(6, " " + player->GetRandRis()[count], GOSSIP_SENDER_MAIN, 10001+count); }
			lmenu2:
			player->ADD_GOSSIP_ITEM(0, "<Retour>", GOSSIP_SENDER_MAIN, player->GetRandRetour());
			player->SEND_GOSSIP_MENU(1000023, creature->GetGUID());
			break;

		case 10001: case 10002: case 10003: case 10004: case 10005: case 10006: case 10007: case 10008: case 10009: case 10010:
		case 10011: case 10012: case 10013: case 10014: case 10015: case 10016: case 10017: case 10018: case 10019: case 10020:
		case 10021: case 10022: case 10023: case 10024: case 10025: case 10026: case 10027: case 10028: case 10029: case 10030:

			AddItemChoix(player, player->GetRandItId(), player->GetRandRie()[action-10001]);
			goto lmenu; break;
		}
	return true; }
};

void AddSc_rand_item() {
	new rand_item(); }