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
	player->ADD_GOSSIP_ITEM(6, "Sombrecrête (Plaque)", GOSSIP_SENDER_MAIN, 500);
	player->ADD_GOSSIP_ITEM(6, "De Traqueur du néant (Maille)", GOSSIP_SENDER_MAIN, 450);
	player->ADD_GOSSIP_ITEM(6, "Vengeur (Cuir)", GOSSIP_SENDER_MAIN, 400);
	player->ADD_GOSSIP_ITEM(6, "De feu stellaire (Tissu)", GOSSIP_SENDER_MAIN, 350);
	player->ADD_GOSSIP_ITEM(6, "Hors set", GOSSIP_SENDER_MAIN, 250);
	player->SEND_GOSSIP_MENU(1000023, creature->GetGUID()); }
	
bool OnGossipHello(Player *player, Creature * creature) { MainMenu(player, creature); return true; }
	
bool OnGossipSelect(Player *player, Creature * creature, uint32 sender, uint32 action) {
    player->PlayerTalkClass->ClearMenus();

		switch (action) {
	
	case 100: MainMenu(player, creature); break;
	case 101: player->CLOSE_GOSSIP_MENU(); break;

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
        player->ADD_GOSSIP_ITEM(6, "Cape turbulente (60)", GOSSIP_SENDER_MAIN, 302);
        player->ADD_GOSSIP_ITEM(6, "Collier turbulent (64)", GOSSIP_SENDER_MAIN, 303);
        player->ADD_GOSSIP_ITEM(6, "Ceinturon lié à la terre (60)", GOSSIP_SENDER_MAIN, 304);
        player->ADD_GOSSIP_ITEM(6, "Poignes liées à la terre (64)", GOSSIP_SENDER_MAIN, 305);
        player->ADD_GOSSIP_ITEM(6, "Ceinture dénombrée (60)", GOSSIP_SENDER_MAIN, 306);
        player->ADD_GOSSIP_ITEM(6, "Gants dénombrés (64)", GOSSIP_SENDER_MAIN, 307);
        player->ADD_GOSSIP_ITEM(6, "Ceinture infrangible (60)", GOSSIP_SENDER_MAIN, 308);
        player->ADD_GOSSIP_ITEM(6, "Poignes infrangibles (64)", GOSSIP_SENDER_MAIN, 309);
        player->ADD_GOSSIP_ITEM(6, "Ceinture vigoureuse (60)", GOSSIP_SENDER_MAIN, 310);
        player->ADD_GOSSIP_ITEM(6, "Gants vigoureux (64)", GOSSIP_SENDER_MAIN, 311);
        player->ADD_GOSSIP_ITEM(20, "= Retour =", GOSSIP_SENDER_MAIN, 100);
        player->SEND_GOSSIP_MENU(1000023, creature->GetGUID());
		break;
	    case 302: player->SetRandItId(51993); goto l276276; break;
	    case 303: player->SetRandItId(51995); goto l276276; break;
	    case 305: player->SetRandItId(51977); goto l276276; break;
	    case 305: player->SetRandItId(51979); goto l276276; break;
	    case 306: player->SetRandItId(51971); goto l276276; break;
	    case 307: player->SetRandItId(51970); goto l276276; break;
	    case 308: player->SetRandItId(51985); goto l276276; break;
	    case 309: player->SetRandItId(51987); goto l276276; break;
	    case 310: player->SetRandItId(51959); goto l276276; break;
	    case 311: player->SetRandItId(51960); goto l276276; break;;

    case 350:
        player->SetRandRetour(action);
        player->ADD_GOSSIP_ITEM(6, "Diadème de feu stellaire", GOSSIP_SENDER_MAIN, 352);
        player->ADD_GOSSIP_ITEM(6, "Mantelet de feu stellaire", GOSSIP_SENDER_MAIN, 353);
        player->ADD_GOSSIP_ITEM(6, "Gilet de feu stellaire", GOSSIP_SENDER_MAIN, 354);
        player->ADD_GOSSIP_ITEM(6, "Bandelettes de feu stellaire", GOSSIP_SENDER_MAIN, 355);
        player->ADD_GOSSIP_ITEM(6, "Gants de feu stellaire", GOSSIP_SENDER_MAIN, 356);
        player->ADD_GOSSIP_ITEM(6, "Echarpe de feu stellaire", GOSSIP_SENDER_MAIN, 357);
        player->ADD_GOSSIP_ITEM(6, "Chausses de feu stellaire", GOSSIP_SENDER_MAIN, 358);
        player->ADD_GOSSIP_ITEM(6, "Sandales de feu stellaire", GOSSIP_SENDER_MAIN, 359);
        player->ADD_GOSSIP_ITEM(20, "= Retour =", GOSSIP_SENDER_MAIN, 100);
        player->SEND_GOSSIP_MENU(1000023, creature->GetGUID());
		break;
	    case 352: player->SetRandItId(24601); goto l276276; break;
	    case 353: player->SetRandItId(24603); goto l276276; break;
	    case 354: player->SetRandItId(24599); goto l276276; break;
	    case 355: player->SetRandItId(24604); goto l276276; break;
	    case 356: player->SetRandItId(24600); goto l276276; break;
	    case 357: player->SetRandItId(24597); goto l276276; break;
	    case 358: player->SetRandItId(24602); goto l276276; break;
	    case 359: player->SetRandItId(24598); goto l276276; break;
		
    case 400:
        player->SetRandRetour(action);
        player->ADD_GOSSIP_ITEM(6, "Heaume vengeur", GOSSIP_SENDER_MAIN, 404);
        player->ADD_GOSSIP_ITEM(6, "Espauliers vengeurs", GOSSIP_SENDER_MAIN, 405);
        player->ADD_GOSSIP_ITEM(6, "Plastron vengeur", GOSSIP_SENDER_MAIN, 406);
        player->ADD_GOSSIP_ITEM(6, "Poignets vengeurs", GOSSIP_SENDER_MAIN, 407);
        player->ADD_GOSSIP_ITEM(6, "Gants vengeurs", GOSSIP_SENDER_MAIN, 408);
        player->ADD_GOSSIP_ITEM(6, "Ceinture vengeresse", GOSSIP_SENDER_MAIN, 409);
        player->ADD_GOSSIP_ITEM(6, "Garde-jambes vengeurs", GOSSIP_SENDER_MAIN, 410);
        player->ADD_GOSSIP_ITEM(6, "Bottes vengeresses", GOSSIP_SENDER_MAIN, 411);
        player->ADD_GOSSIP_ITEM(20, "= Retour =", GOSSIP_SENDER_MAIN, 10);
        player->SEND_GOSSIP_MENU(1000023, creature->GetGUID());
		break;
	    case 404: player->SetRandItId(24713); goto l276276; break;
	    case 405: player->SetRandItId(24715); goto l276276; break;
	    case 406: player->SetRandItId(24711); goto l276276; break;
	    case 407: player->SetRandItId(24716); goto l276276; break;
	    case 408: player->SetRandItId(24712); goto l276276; break;
	    case 409: player->SetRandItId(24709); goto l276276; break;
	    case 410: player->SetRandItId(24714); goto l276276; break;
	    case 411: player->SetRandItId(24715); goto l276276; break;
		
    case 450:
        player->SetRandRetour(action);
        player->ADD_GOSSIP_ITEM(6, "Casque de traqueur du Néant", GOSSIP_SENDER_MAIN, 454);
        player->ADD_GOSSIP_ITEM(6, "Mantelet de traqueur du Néant", GOSSIP_SENDER_MAIN, 455);
        player->ADD_GOSSIP_ITEM(6, "Armure de traqueur du Néant", GOSSIP_SENDER_MAIN, 456);
        player->ADD_GOSSIP_ITEM(6, "Brassards de traqueur du Néant", GOSSIP_SENDER_MAIN, 457);
        player->ADD_GOSSIP_ITEM(6, "Gants de traqueur du Néant", GOSSIP_SENDER_MAIN, 458);
        player->ADD_GOSSIP_ITEM(6, "Ceinture de traqueur du Néant", GOSSIP_SENDER_MAIN, 459);
        player->ADD_GOSSIP_ITEM(6, "Garde-jambes de traqueur du Néant", GOSSIP_SENDER_MAIN, 460);
        player->ADD_GOSSIP_ITEM(6, "Grêves de traqueur du Néant", GOSSIP_SENDER_MAIN, 461);
        player->ADD_GOSSIP_ITEM(20, "= Retour =", GOSSIP_SENDER_MAIN, 10);
        player->SEND_GOSSIP_MENU(1000023, creature->GetGUID());
		break;
	    case 454: player->SetRandItId(24826); goto l276276; break;
	    case 455: player->SetRandItId(24828); goto l276276; break;
	    case 456: player->SetRandItId(24824); goto l276276; break;
	    case 457: player->SetRandItId(24829); goto l276276; break;
	    case 458: player->SetRandItId(24825); goto l276276; break;
	    case 459: player->SetRandItId(24822); goto l276276; break;
	    case 460: player->SetRandItId(24827); goto l276276; break;
	    case 461: player->SetRandItId(24823); goto l276276; break;
		
    case 500:
        player->SetRandRetour(action);
        player->ADD_GOSSIP_ITEM(6, "Casque sombrecrête", GOSSIP_SENDER_MAIN, 504);
        player->ADD_GOSSIP_ITEM(6, "Espauliers sombrecrête", GOSSIP_SENDER_MAIN, 505);
        player->ADD_GOSSIP_ITEM(6, "Cuirasse sombrecrête", GOSSIP_SENDER_MAIN, 506);
        player->ADD_GOSSIP_ITEM(6, "Brassards sombrecrête", GOSSIP_SENDER_MAIN, 507);
        player->ADD_GOSSIP_ITEM(6, "Gantelets sombrecrête", GOSSIP_SENDER_MAIN, 508);
        player->ADD_GOSSIP_ITEM(6, "Ceinture sombrecrête", GOSSIP_SENDER_MAIN, 509);
        player->ADD_GOSSIP_ITEM(6, "Garde-jambes sombrecrête", GOSSIP_SENDER_MAIN, 510);
        player->ADD_GOSSIP_ITEM(6, "Solerets sombrecrête", GOSSIP_SENDER_MAIN, 511);
        player->ADD_GOSSIP_ITEM(20, "= Retour =", GOSSIP_SENDER_MAIN, 10);
        player->SEND_GOSSIP_MENU(1000023, creature->GetGUID());
		break;
	    case 504: player->SetRandItId(24938); goto l276276; break;
	    case 505: player->SetRandItId(24940); goto l276276; break;
	    case 506: player->SetRandItId(24936); goto l276276; break;
	    case 507: player->SetRandItId(24941); goto l276276; break;
	    case 508: player->SetRandItId(24937); goto l276276; break;
	    case 509: player->SetRandItId(24934); goto l276276; break;
	    case 510: player->SetRandItId(24939); goto l276276; break;
	    case 511: player->SetRandItId(24935); goto l276276; break;

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