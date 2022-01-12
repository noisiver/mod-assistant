#include "Chat.h"
#include "Config.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedGossip.h"

enum GossipId
{
    ASSISTANT_GOSSIP_TEXT        = 48,
    ASSISTANT_GOSSIP_HEIRLOOM    = 100,
    ASSISTANT_GOSSIP_GLYPH       = 200,
    ASSISTANT_GOSSIP_GEM         = 400,
    ASSISTANT_GOSSIP_CONTAINER   = 500,
    ASSISTANT_GOSSIP_UTILITIES   = 600,
    ASSISTANT_GOSSIP_PROFESSIONS = 700,
};

enum VendorId
{
    ASSISTANT_VENDOR_HEIRLOOM_WEAPON = 9000000,
    ASSISTANT_VENDOR_HEIRLOOM_ARMOR  = 9000001,
    ASSISTANT_VENDOR_HEIRLOOM_OTHER  = 9000002,
    ASSISTANT_VENDOR_GLYPH           = 9000003,
    ASSISTANT_VENDOR_GEM             = 9000023,
    ASSISTANT_VENDOR_CONTAINER       = 9000030,
};

// Vendors
bool enableHeirlooms;
bool enableGlyphs;
bool enableGems;
bool enableContainers;

// Utilities
bool enableUtilities;
uint32 costNameChange;
uint32 costCustomization;
uint32 costRaceChange;
uint32 costFactionChange;

// Professions
bool enableProfessions;
bool enableApprenticeProfession;
bool enableJourneymanProfession;
bool enableExpertProfession;
bool enableArtisanProfession;
bool enableMasterProfession;
bool enableGrandMasterProfession;
uint32 costApprenticeProfession;
uint32 costJourneymanProfession;
uint32 costExpertProfession;
uint32 costArtisanProfession;
uint32 costMasterProfession;
uint32 costGrandMasterProfession;

class AssistantCreature : public CreatureScript
{
    public:
        AssistantCreature() : CreatureScript("npc_assistant") { }

        bool OnGossipHello(Player* player, Creature* creature)
        {
            ClearGossipMenuFor(player);

            if (enableHeirlooms)
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want heirlooms", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM);

            if (enableGlyphs)
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want glyphs", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH);

            if (enableGems)
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want gems", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GEM);

            if (enableContainers)
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want containers", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_CONTAINER);

            if (enableUtilities)
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want utilities", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_UTILITIES);

            if (enableProfessions && hasValidProfession(player))
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want to manage my professions", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_PROFESSIONS);

            SendGossipMenuFor(player, ASSISTANT_GOSSIP_TEXT, creature->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
        {
            if (sender != GOSSIP_SENDER_MAIN)
                return false;

            if (action == 1)
            {
                OnGossipHello(player, creature);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM)
            {
                ClearGossipMenuFor(player);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want weapons", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+1);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want armor", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+2);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want something else", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+3);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, 1);
                SendGossipMenuFor(player, ASSISTANT_GOSSIP_TEXT, creature->GetGUID());
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+1)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_HEIRLOOM_WEAPON);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+2)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_HEIRLOOM_ARMOR);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+3)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_HEIRLOOM_OTHER);
            }
            else if (action == ASSISTANT_GOSSIP_GLYPH)
            {
                ClearGossipMenuFor(player);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want some major glyphs", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+1);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want some minor glyphs", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+2);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, 1);
                SendGossipMenuFor(player, ASSISTANT_GOSSIP_TEXT, creature->GetGUID());
            }
            else if (action == ASSISTANT_GOSSIP_GLYPH+1)
            {
                switch (player->getClass())
                {
                    case CLASS_WARRIOR:
                        player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH);
                        break;
                    case CLASS_PALADIN:
                        player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH+1);
                        break;
                    case CLASS_HUNTER:
                        player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH+2);
                        break;
                    case CLASS_ROGUE:
                        player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH+3);
                        break;
                    case CLASS_PRIEST:
                        player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH+4);
                        break;
                    case CLASS_DEATH_KNIGHT:
                        player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH+5);
                        break;
                    case CLASS_SHAMAN:
                        player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH+6);
                        break;
                    case CLASS_MAGE:
                        player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH+7);
                        break;
                    case CLASS_WARLOCK:
                        player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH+8);
                        break;
                    case CLASS_DRUID:
                        player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH+9);
                        break;
                }
            }
            else if (action == ASSISTANT_GOSSIP_GLYPH+2)
            {
                switch (player->getClass())
                {
                    case CLASS_WARRIOR:
                        player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH+10);
                        break;
                    case CLASS_PALADIN:
                        player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH+11);
                        break;
                    case CLASS_HUNTER:
                        player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH+12);
                        break;
                    case CLASS_ROGUE:
                        player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH+13);
                        break;
                    case CLASS_PRIEST:
                        player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH+14);
                        break;
                    case CLASS_DEATH_KNIGHT:
                        player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH+15);
                        break;
                    case CLASS_SHAMAN:
                        player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH+16);
                        break;
                    case CLASS_MAGE:
                        player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH+17);
                        break;
                    case CLASS_WARLOCK:
                        player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH+18);
                        break;
                    case CLASS_DRUID:
                        player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH+19);
                        break;
                }
            }
            else if (action == ASSISTANT_GOSSIP_GEM)
            {
                ClearGossipMenuFor(player);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want some meta gems", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GEM+1);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want some red gems", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GEM+2);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want some blue gems", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GEM+3);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want some yellow gems", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GEM+4);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want some purple gems", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GEM+5);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want some green gems", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GEM+6);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want some orange gems", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GEM+7);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, 1);
                SendGossipMenuFor(player, ASSISTANT_GOSSIP_TEXT, creature->GetGUID());
            }
            else if (action == ASSISTANT_GOSSIP_GEM+1)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GEM);
            }
            else if (action == ASSISTANT_GOSSIP_GEM+2)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GEM+1);
            }
            else if (action == ASSISTANT_GOSSIP_GEM+3)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GEM+2);
            }
            else if (action == ASSISTANT_GOSSIP_GEM+4)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GEM+3);
            }
            else if (action == ASSISTANT_GOSSIP_GEM+5)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GEM+4);
            }
            else if (action == ASSISTANT_GOSSIP_GEM+6)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GEM+5);
            }
            else if (action == ASSISTANT_GOSSIP_GEM+7)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GEM+6);
            }
            else if (action == ASSISTANT_GOSSIP_CONTAINER)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_CONTAINER);
            }
            else if (action == ASSISTANT_GOSSIP_UTILITIES)
            {
                ClearGossipMenuFor(player);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want to change my name", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_UTILITIES + 1, "Do you wish to continue the transaction?", costNameChange, false);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want to change my appearance", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_UTILITIES + 2, "Do you wish to continue the transaction?", costCustomization, false);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want to change my race", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_UTILITIES + 3, "Do you wish to continue the transaction?", costRaceChange, false);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want to change my faction", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_UTILITIES + 4, "Do you wish to continue the transaction?", costFactionChange, false);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, 1);
                SendGossipMenuFor(player, ASSISTANT_GOSSIP_TEXT, creature->GetGUID());
            }
            else if (action == ASSISTANT_GOSSIP_UTILITIES + 1)
            {
                if (hasLoginFlag(player))
                {
                    ChatHandler(player->GetSession()).PSendSysMessage("You have to complete the previously activated feature before trying to perform another.");
                    OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_UTILITIES);
                }
                else
                {
                    player->ModifyMoney(-(costNameChange));
                    player->SetAtLoginFlag(AT_LOGIN_RENAME);
                    ChatHandler(player->GetSession()).PSendSysMessage("You can now log out to apply the name change.");
                    ClearGossipMenuFor(player);
                }
            }
            else if (action == ASSISTANT_GOSSIP_UTILITIES + 2)
            {
                if (hasLoginFlag(player))
                {
                    ChatHandler(player->GetSession()).PSendSysMessage("You have to complete the previously activated feature before trying to perform another.");
                    OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_UTILITIES);
                }
                else
                {
                    player->ModifyMoney(-(costCustomization));
                    player->SetAtLoginFlag(AT_LOGIN_CUSTOMIZE);
                    ChatHandler(player->GetSession()).PSendSysMessage("You can now log out to apply the customization.");
                    ClearGossipMenuFor(player);
                }
            }
            else if (action == ASSISTANT_GOSSIP_UTILITIES + 3)
            {
                if (hasLoginFlag(player))
                {
                    ChatHandler(player->GetSession()).PSendSysMessage("You have to complete the previously activated feature before trying to perform another.");
                    OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_UTILITIES);
                }
                else
                {
                    player->ModifyMoney(-(costRaceChange));
                    player->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
                    ChatHandler(player->GetSession()).PSendSysMessage("You can now log out to apply the race change.");
                    ClearGossipMenuFor(player);
                }
            }
            else if (action == ASSISTANT_GOSSIP_UTILITIES + 4)
            {
                if (hasLoginFlag(player))
                {
                    ChatHandler(player->GetSession()).PSendSysMessage("You have to complete the previously activated feature before trying to perform another.");
                    OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_UTILITIES);
                }
                else
                {
                    player->ModifyMoney(-(costFactionChange));
                    player->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
                    ChatHandler(player->GetSession()).PSendSysMessage("You can now log out to apply the faction change.");
                    ClearGossipMenuFor(player);
                }
            }
            else if (action == ASSISTANT_GOSSIP_PROFESSIONS)
            {
                ClearGossipMenuFor(player);
                addProfessionToList(player, SKILL_FIRST_AID, "I want to increase my first aid", ASSISTANT_GOSSIP_PROFESSIONS + 1);
                addProfessionToList(player, SKILL_BLACKSMITHING, "I want to increase my blacksmithing", ASSISTANT_GOSSIP_PROFESSIONS + 2);
                addProfessionToList(player, SKILL_LEATHERWORKING, "I want to increase my leatherworking", ASSISTANT_GOSSIP_PROFESSIONS + 3);
                addProfessionToList(player, SKILL_HERBALISM, "I want to increase my herbalism", ASSISTANT_GOSSIP_PROFESSIONS + 4);
                addProfessionToList(player, SKILL_COOKING, "I want to increase my cooking", ASSISTANT_GOSSIP_PROFESSIONS + 5);
                addProfessionToList(player, SKILL_MINING, "I want to increase my mining", ASSISTANT_GOSSIP_PROFESSIONS + 6);
                addProfessionToList(player, SKILL_ENGINEERING, "I want to increase my engineering", ASSISTANT_GOSSIP_PROFESSIONS + 7);
                addProfessionToList(player, SKILL_ENCHANTING, "I want to increase my enchanting", ASSISTANT_GOSSIP_PROFESSIONS + 8);
                addProfessionToList(player, SKILL_FISHING, "I want to increase my fishing", ASSISTANT_GOSSIP_PROFESSIONS + 9);
                addProfessionToList(player, SKILL_SKINNING, "I want to increase my skinning", ASSISTANT_GOSSIP_PROFESSIONS + 10);
                addProfessionToList(player, SKILL_INSCRIPTION, "I want to increase my inscription", ASSISTANT_GOSSIP_PROFESSIONS + 11);
                addProfessionToList(player, SKILL_JEWELCRAFTING, "I want to increase my jewelcrafting", ASSISTANT_GOSSIP_PROFESSIONS + 12);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, 1);
                SendGossipMenuFor(player, ASSISTANT_GOSSIP_TEXT, creature->GetGUID());
            }
            else if (action == ASSISTANT_GOSSIP_PROFESSIONS + 1)
            {
                increaseProfessionSkill(player, SKILL_FIRST_AID);
                CloseGossipMenuFor(player);
            }
            else if (action == ASSISTANT_GOSSIP_PROFESSIONS + 2)
            {
                increaseProfessionSkill(player, SKILL_BLACKSMITHING);
                CloseGossipMenuFor(player);
            }
            else if (action == ASSISTANT_GOSSIP_PROFESSIONS + 3)
            {
                increaseProfessionSkill(player, SKILL_LEATHERWORKING);
                CloseGossipMenuFor(player);
            }
            else if (action == ASSISTANT_GOSSIP_PROFESSIONS + 4)
            {
                increaseProfessionSkill(player, SKILL_HERBALISM);
                CloseGossipMenuFor(player);
            }
            else if (action == ASSISTANT_GOSSIP_PROFESSIONS + 5)
            {
                increaseProfessionSkill(player, SKILL_COOKING);
                CloseGossipMenuFor(player);
            }
            else if (action == ASSISTANT_GOSSIP_PROFESSIONS + 6)
            {
                increaseProfessionSkill(player, SKILL_MINING);
                CloseGossipMenuFor(player);
            }
            else if (action == ASSISTANT_GOSSIP_PROFESSIONS + 7)
            {
                increaseProfessionSkill(player, SKILL_ENGINEERING);
                CloseGossipMenuFor(player);
            }
            else if (action == ASSISTANT_GOSSIP_PROFESSIONS + 8)
            {
                increaseProfessionSkill(player, SKILL_ENCHANTING);
                CloseGossipMenuFor(player);
            }
            else if (action == ASSISTANT_GOSSIP_PROFESSIONS + 9)
            {
                increaseProfessionSkill(player, SKILL_FISHING);
                CloseGossipMenuFor(player);
            }
            else if (action == ASSISTANT_GOSSIP_PROFESSIONS + 10)
            {
                increaseProfessionSkill(player, SKILL_SKINNING);
                CloseGossipMenuFor(player);
            }
            else if (action == ASSISTANT_GOSSIP_PROFESSIONS + 11)
            {
                increaseProfessionSkill(player, SKILL_INSCRIPTION);
                CloseGossipMenuFor(player);
            }
            else if (action == ASSISTANT_GOSSIP_PROFESSIONS + 12)
            {
                increaseProfessionSkill(player, SKILL_JEWELCRAFTING);
                CloseGossipMenuFor(player);
            }

            return true;
        }

    private:
        bool hasLoginFlag(Player* player)
        {
            if (player->HasAtLoginFlag(AT_LOGIN_RENAME) || player->HasAtLoginFlag(AT_LOGIN_CUSTOMIZE) || player->HasAtLoginFlag(AT_LOGIN_CHANGE_RACE) || player->HasAtLoginFlag(AT_LOGIN_CHANGE_FACTION))
                return true;

            return false;
        }

        bool hasValidProfession(Player* player)
        {
            if (((player->HasSkill(SKILL_FIRST_AID) && player->GetSkillValue(SKILL_FIRST_AID) < 75) ||
                (player->HasSkill(SKILL_BLACKSMITHING) && player->GetSkillValue(SKILL_BLACKSMITHING) < 75) ||
                (player->HasSkill(SKILL_LEATHERWORKING) && player->GetSkillValue(SKILL_LEATHERWORKING) < 75) ||
                (player->HasSkill(SKILL_HERBALISM) && player->GetSkillValue(SKILL_HERBALISM) < 75) ||
                (player->HasSkill(SKILL_COOKING) && player->GetSkillValue(SKILL_COOKING) < 75) ||
                (player->HasSkill(SKILL_MINING) && player->GetSkillValue(SKILL_MINING) < 75) ||
                (player->HasSkill(SKILL_ENGINEERING) && player->GetSkillValue(SKILL_ENGINEERING) < 75) ||
                (player->HasSkill(SKILL_ENCHANTING) && player->GetSkillValue(SKILL_ENCHANTING) < 75) ||
                (player->HasSkill(SKILL_FISHING) && player->GetSkillValue(SKILL_FISHING) < 75) ||
                (player->HasSkill(SKILL_SKINNING) && player->GetSkillValue(SKILL_SKINNING) < 75) ||
                (player->HasSkill(SKILL_INSCRIPTION) && player->GetSkillValue(SKILL_INSCRIPTION) < 75) ||
                (player->HasSkill(SKILL_JEWELCRAFTING) && player->GetSkillValue(SKILL_JEWELCRAFTING) < 75)) &&
                enableApprenticeProfession)
                return true;

            if (((player->HasSkill(SKILL_FIRST_AID) && player->GetSkillValue(SKILL_FIRST_AID) < 150) ||
                (player->HasSkill(SKILL_BLACKSMITHING) && player->GetSkillValue(SKILL_BLACKSMITHING) < 150) ||
                (player->HasSkill(SKILL_LEATHERWORKING) && player->GetSkillValue(SKILL_LEATHERWORKING) < 150) ||
                (player->HasSkill(SKILL_HERBALISM) && player->GetSkillValue(SKILL_HERBALISM) < 150) ||
                (player->HasSkill(SKILL_COOKING) && player->GetSkillValue(SKILL_COOKING) < 150) ||
                (player->HasSkill(SKILL_MINING) && player->GetSkillValue(SKILL_MINING) < 150) ||
                (player->HasSkill(SKILL_ENGINEERING) && player->GetSkillValue(SKILL_ENGINEERING) < 150) ||
                (player->HasSkill(SKILL_ENCHANTING) && player->GetSkillValue(SKILL_ENCHANTING) < 150) ||
                (player->HasSkill(SKILL_FISHING) && player->GetSkillValue(SKILL_FISHING) < 150) ||
                (player->HasSkill(SKILL_SKINNING) && player->GetSkillValue(SKILL_SKINNING) < 150) ||
                (player->HasSkill(SKILL_INSCRIPTION) && player->GetSkillValue(SKILL_INSCRIPTION) < 150) ||
                (player->HasSkill(SKILL_JEWELCRAFTING) && player->GetSkillValue(SKILL_JEWELCRAFTING) < 150)) &&
                enableJourneymanProfession)
                return true;

            if (((player->HasSkill(SKILL_FIRST_AID) && player->GetSkillValue(SKILL_FIRST_AID) < 225) ||
                (player->HasSkill(SKILL_BLACKSMITHING) && player->GetSkillValue(SKILL_BLACKSMITHING) < 225) ||
                (player->HasSkill(SKILL_LEATHERWORKING) && player->GetSkillValue(SKILL_LEATHERWORKING) < 225) ||
                (player->HasSkill(SKILL_HERBALISM) && player->GetSkillValue(SKILL_HERBALISM) < 225) ||
                (player->HasSkill(SKILL_COOKING) && player->GetSkillValue(SKILL_COOKING) < 225) ||
                (player->HasSkill(SKILL_MINING) && player->GetSkillValue(SKILL_MINING) < 225) ||
                (player->HasSkill(SKILL_ENGINEERING) && player->GetSkillValue(SKILL_ENGINEERING) < 225) ||
                (player->HasSkill(SKILL_ENCHANTING) && player->GetSkillValue(SKILL_ENCHANTING) < 225) ||
                (player->HasSkill(SKILL_FISHING) && player->GetSkillValue(SKILL_FISHING) < 225) ||
                (player->HasSkill(SKILL_SKINNING) && player->GetSkillValue(SKILL_SKINNING) < 225) ||
                (player->HasSkill(SKILL_INSCRIPTION) && player->GetSkillValue(SKILL_INSCRIPTION) < 225) ||
                (player->HasSkill(SKILL_JEWELCRAFTING) && player->GetSkillValue(SKILL_JEWELCRAFTING) < 225)) &&
                enableExpertProfession)
                return true;

            if (((player->HasSkill(SKILL_FIRST_AID) && player->GetSkillValue(SKILL_FIRST_AID) < 300) ||
                (player->HasSkill(SKILL_BLACKSMITHING) && player->GetSkillValue(SKILL_BLACKSMITHING) < 300) ||
                (player->HasSkill(SKILL_LEATHERWORKING) && player->GetSkillValue(SKILL_LEATHERWORKING) < 300) ||
                (player->HasSkill(SKILL_HERBALISM) && player->GetSkillValue(SKILL_HERBALISM) < 300) ||
                (player->HasSkill(SKILL_COOKING) && player->GetSkillValue(SKILL_COOKING) < 300) ||
                (player->HasSkill(SKILL_MINING) && player->GetSkillValue(SKILL_MINING) < 300) ||
                (player->HasSkill(SKILL_ENGINEERING) && player->GetSkillValue(SKILL_ENGINEERING) < 300) ||
                (player->HasSkill(SKILL_ENCHANTING) && player->GetSkillValue(SKILL_ENCHANTING) < 300) ||
                (player->HasSkill(SKILL_FISHING) && player->GetSkillValue(SKILL_FISHING) < 300) ||
                (player->HasSkill(SKILL_SKINNING) && player->GetSkillValue(SKILL_SKINNING) < 300) ||
                (player->HasSkill(SKILL_INSCRIPTION) && player->GetSkillValue(SKILL_INSCRIPTION) < 300) ||
                (player->HasSkill(SKILL_JEWELCRAFTING) && player->GetSkillValue(SKILL_JEWELCRAFTING) < 300)) &&
                enableArtisanProfession)
                return true;

            if (((player->HasSkill(SKILL_FIRST_AID) && player->GetSkillValue(SKILL_FIRST_AID) < 375) ||
                (player->HasSkill(SKILL_BLACKSMITHING) && player->GetSkillValue(SKILL_BLACKSMITHING) < 375) ||
                (player->HasSkill(SKILL_LEATHERWORKING) && player->GetSkillValue(SKILL_LEATHERWORKING) < 375) ||
                (player->HasSkill(SKILL_HERBALISM) && player->GetSkillValue(SKILL_HERBALISM) < 375) ||
                (player->HasSkill(SKILL_COOKING) && player->GetSkillValue(SKILL_COOKING) < 375) ||
                (player->HasSkill(SKILL_MINING) && player->GetSkillValue(SKILL_MINING) < 375) ||
                (player->HasSkill(SKILL_ENGINEERING) && player->GetSkillValue(SKILL_ENGINEERING) < 375) ||
                (player->HasSkill(SKILL_ENCHANTING) && player->GetSkillValue(SKILL_ENCHANTING) < 375) ||
                (player->HasSkill(SKILL_FISHING) && player->GetSkillValue(SKILL_FISHING) < 375) ||
                (player->HasSkill(SKILL_SKINNING) && player->GetSkillValue(SKILL_SKINNING) < 375) ||
                (player->HasSkill(SKILL_INSCRIPTION) && player->GetSkillValue(SKILL_INSCRIPTION) < 375) ||
                (player->HasSkill(SKILL_JEWELCRAFTING) && player->GetSkillValue(SKILL_JEWELCRAFTING) < 375)) &&
                enableMasterProfession)
                return true;

            if (((player->HasSkill(SKILL_FIRST_AID) && player->GetSkillValue(SKILL_FIRST_AID) < 450) ||
                (player->HasSkill(SKILL_BLACKSMITHING) && player->GetSkillValue(SKILL_BLACKSMITHING) < 450) ||
                (player->HasSkill(SKILL_LEATHERWORKING) && player->GetSkillValue(SKILL_LEATHERWORKING) < 450) ||
                (player->HasSkill(SKILL_HERBALISM) && player->GetSkillValue(SKILL_HERBALISM) < 450) ||
                (player->HasSkill(SKILL_COOKING) && player->GetSkillValue(SKILL_COOKING) < 450) ||
                (player->HasSkill(SKILL_MINING) && player->GetSkillValue(SKILL_MINING) < 450) ||
                (player->HasSkill(SKILL_ENGINEERING) && player->GetSkillValue(SKILL_ENGINEERING) < 450) ||
                (player->HasSkill(SKILL_ENCHANTING) && player->GetSkillValue(SKILL_ENCHANTING) < 450) ||
                (player->HasSkill(SKILL_FISHING) && player->GetSkillValue(SKILL_FISHING) < 450) ||
                (player->HasSkill(SKILL_SKINNING) && player->GetSkillValue(SKILL_SKINNING) < 450) ||
                (player->HasSkill(SKILL_INSCRIPTION) && player->GetSkillValue(SKILL_INSCRIPTION) < 450) ||
                (player->HasSkill(SKILL_JEWELCRAFTING) && player->GetSkillValue(SKILL_JEWELCRAFTING) < 450)) &&
                enableGrandMasterProfession)
                return true;

            return false;
        }

        void addProfessionToList(Player* player, SkillType skill, std::string text, uint32 action)
        {
            if (player->HasSkill(skill))
            {
                uint16 maxSkillValue = player->GetMaxSkillValue(skill);
                uint16 skillValue = player->GetSkillValue(skill);
                uint32 cost       = 0;

                if (skillValue < maxSkillValue)
                {

                    if (skillValue < 75)
                        cost = costApprenticeProfession;
                    else if (skillValue < 150)
                        cost = costJourneymanProfession;
                    else if (skillValue < 225)
                        cost = costExpertProfession;
                    else if (skillValue < 300)
                        cost = costArtisanProfession;
                    else if (skillValue < 375)
                        cost = costMasterProfession;
                    else if (skillValue < 450)
                        cost = costGrandMasterProfession;

                    AddGossipItemFor(player, GOSSIP_ICON_TRAINER, text, GOSSIP_SENDER_MAIN, action, "Do you wish to continue the transaction?", cost, false);
                }
            }
        }

        void increaseProfessionSkill(Player* player, SkillType skill)
        {
            uint8 race           = player->getRace();
            uint32 skillValue    = player->GetSkillValue(skill);
            uint16 maxSkillValue = player->GetMaxSkillValue(skill);
            uint32 cost          = 0;

            // Properly handle racial bonuses
            // Leaving this out doubles the bonuses gained, for whatever reason
            if ((skill == SKILL_HERBALISM && race == RACE_TAUREN) || (skill == SKILL_ENGINEERING && race == RACE_GNOME))
                maxSkillValue -= 15;
            else if (skill == SKILL_ENCHANTING && race == RACE_BLOODELF)
                maxSkillValue -= 10;
            else if (skill == SKILL_JEWELCRAFTING && race == RACE_DRAENEI)
                maxSkillValue -= 5;

            if (skillValue < 75)
                cost = costApprenticeProfession;
            else if (skillValue < 150)
                cost = costJourneymanProfession;
            else if (skillValue < 225)
                cost = costExpertProfession;
            else if (skillValue < 300)
                cost = costArtisanProfession;
            else if (skillValue < 375)
                cost = costMasterProfession;
            else if (skillValue < 450)
                cost = costGrandMasterProfession;

            player->ModifyMoney(-cost);
            player->SetSkill(skill, 0, maxSkillValue, maxSkillValue);
        }
};

class AssistantWorld : public WorldScript
{
    public:
        AssistantWorld() : WorldScript("AssistantWorld") {}

    void OnAfterConfigLoad(bool /*reload*/) override
    {
        // Vendors
        enableHeirlooms = sConfigMgr->GetOption<bool>("Assistant.Heirlooms", 0);
        enableGlyphs = sConfigMgr->GetOption<bool>("Assistant.Glyphs", 0);
        enableGems = sConfigMgr->GetOption<bool>("Assistant.Gems", 0);
        enableContainers = sConfigMgr->GetOption<bool>("Assistant.Containers", 0);

        // Utilities
        enableUtilities = sConfigMgr->GetOption<bool>("Assistant.Utilities", 0);
        costNameChange = sConfigMgr->GetOption<int32>("Assistant.Utilities.NameChange", 10) * 10000;
        costCustomization = sConfigMgr->GetOption<int32>("Assistant.Utilities.Customization", 50) * 10000;
        costRaceChange = sConfigMgr->GetOption<int32>("Assistant.Utilities.RaceChange", 500) * 10000;
        costFactionChange = sConfigMgr->GetOption<int32>("Assistant.Utilities.FactionChange", 1000) * 10000;

        // Professions
        enableProfessions = sConfigMgr->GetOption<bool>("Assistant.Professions.Enabled", 0);
        enableApprenticeProfession = sConfigMgr->GetOption<bool>("Assistant.Professions.Apprentice.Enabled", 0);
        enableJourneymanProfession = sConfigMgr->GetOption<bool>("Assistant.Professions.Journeyman.Enabled", 0);
        enableExpertProfession = sConfigMgr->GetOption<bool>("Assistant.Professions.Expert.Enabled", 0);
        enableArtisanProfession = sConfigMgr->GetOption<bool>("Assistant.Professions.Artisan.Enabled", 0);
        enableMasterProfession = sConfigMgr->GetOption<bool>("Assistant.Professions.Master.Enabled", 0);
        enableGrandMasterProfession = sConfigMgr->GetOption<bool>("Assistant.Professions.GrandMaster.Enabled", 0);
        costApprenticeProfession = sConfigMgr->GetOption<int32>("Assistant.Professions.Apprentice.Cost", 10) * 10000;
        costJourneymanProfession = sConfigMgr->GetOption<int32>("Assistant.Professions.Journeyman.Cost", 25) * 10000;
        costExpertProfession = sConfigMgr->GetOption<int32>("Assistant.Professions.Expert.Cost", 45) * 10000;
        costArtisanProfession = sConfigMgr->GetOption<int32>("Assistant.Professions.Artisan.Cost", 100) * 10000;
        costMasterProfession = sConfigMgr->GetOption<int32>("Assistant.Professions.Master.Cost", 200) * 10000;
        costGrandMasterProfession = sConfigMgr->GetOption<int32>("Assistant.Professions.GrandMaster.Cost", 500) * 10000;
    }
};

void AddAssistantScripts()
{
    new AssistantCreature();
    new AssistantWorld();
}
