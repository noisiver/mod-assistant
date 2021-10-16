#include "Player.h"
#include "Config.h"

enum GossipId
{
    ASSISTANT_GOSSIP_TEXT      = 48,
    ASSISTANT_GOSSIP_HEIRLOOM  = 100,
    ASSISTANT_GOSSIP_GLYPH     = 200,
    ASSISTANT_GOSSIP_GEM       = 400,
    ASSISTANT_GOSSIP_CONTAINER = 500,
    ASSISTANT_GOSSIP_UTILITIES = 600,
    ASSISTANT_GOSSIP_TOTEMS    = 700
};

enum VendorId
{
    ASSISTANT_VENDOR_HEIRLOOM_WEAPON = 9000000,
    ASSISTANT_VENDOR_HEIRLOOM_ARMOR  = 9000001,
    ASSISTANT_VENDOR_HEIRLOOM_OTHER  = 9000002,
    ASSISTANT_VENDOR_GLYPH           = 9000003,
    ASSISTANT_VENDOR_GEM             = 9000023,
    ASSISTANT_VENDOR_CONTAINER       = 9000030,
    ASSISTANT_VENDOR_TOTEM           = 9000031
};

class AssistantNPC : public CreatureScript
{
    public:
        AssistantNPC() : CreatureScript("npc_assistant") { }

        bool OnGossipHello(Player* player, Creature* creature)
        {
            ClearGossipMenuFor(player);

            if (sConfigMgr->GetBoolDefault("Assistant.Gossip.Heirlooms", 0))
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want heirlooms", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM);

            if (sConfigMgr->GetBoolDefault("Assistant.Gossip.Glyphs", 0))
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want glyphs", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH);

            if (sConfigMgr->GetBoolDefault("Assistant.Gossip.Gems", 0))
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want gems", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GEM);

            if (sConfigMgr->GetBoolDefault("Assistant.Gossip.Containers", 0))
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want containers", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_CONTAINER);

            if (sConfigMgr->GetBoolDefault("Assistant.Gossip.Utilities", 0))
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want utilities", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_UTILITIES);

            if (sConfigMgr->GetBoolDefault("Assistant.Spells.Quest", 0) && player->getClass() == CLASS_SHAMAN)
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want totems", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_TOTEMS);

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
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want to change my name", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_UTILITIES+1, "Do you wish to continue the transaction?", (sConfigMgr->GetIntDefault("Assistant.Gossip.Utilities.NameChange", 10) * 10000), false);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want to change my appearance", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_UTILITIES+2, "Do you wish to continue the transaction?", (sConfigMgr->GetIntDefault("Assistant.Gossip.Utilities.Customization", 50) * 10000), false);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want to change my race", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_UTILITIES+3, "Do you wish to continue the transaction?", (sConfigMgr->GetIntDefault("Assistant.Gossip.Utilities.RaceChange", 500) * 10000), false);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want to change my faction", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_UTILITIES+4, "Do you wish to continue the transaction?", (sConfigMgr->GetIntDefault("Assistant.Gossip.Utilities.FactionChange", 1000) * 10000), false);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, 1);
                SendGossipMenuFor(player, ASSISTANT_GOSSIP_TEXT, creature->GetGUID());
            }
            else if (action == ASSISTANT_GOSSIP_UTILITIES+1)
            {
                if (hasLoginFlag(player))
                {
                    ChatHandler(player->GetSession()).PSendSysMessage("You have to complete the previously activated feature before trying to perform another.");
                    OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_UTILITIES);
                }
                else
                {
                    player->ModifyMoney(-(sConfigMgr->GetIntDefault("Assistant.Gossip.Utilities.NameChange", 10) * 10000));
                    player->SetAtLoginFlag(AT_LOGIN_RENAME);
                    ChatHandler(player->GetSession()).PSendSysMessage("You can now log out to apply the name change.");
                    ClearGossipMenuFor(player);
                }
            }
            else if (action == ASSISTANT_GOSSIP_UTILITIES+2)
            {
                if (hasLoginFlag(player))
                {
                    ChatHandler(player->GetSession()).PSendSysMessage("You have to complete the previously activated feature before trying to perform another.");
                    OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_UTILITIES);
                }
                else
                {
                    player->ModifyMoney(-(sConfigMgr->GetIntDefault("Assistant.Gossip.Utilities.Customization", 50) * 10000));
                    player->SetAtLoginFlag(AT_LOGIN_CUSTOMIZE);
                    ChatHandler(player->GetSession()).PSendSysMessage("You can now log out to apply the customization.");
                    ClearGossipMenuFor(player);
                }
            }
            else if (action == ASSISTANT_GOSSIP_UTILITIES+3)
            {
                if (hasLoginFlag(player))
                {
                    ChatHandler(player->GetSession()).PSendSysMessage("You have to complete the previously activated feature before trying to perform another.");
                    OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_UTILITIES);
                }
                else
                {
                    player->ModifyMoney(-(sConfigMgr->GetIntDefault("Assistant.Gossip.Utilities.RaceChange", 500) * 10000));
                    player->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
                    ChatHandler(player->GetSession()).PSendSysMessage("You can now log out to apply the race change.");
                    ClearGossipMenuFor(player);
                }
            }
            else if (action == ASSISTANT_GOSSIP_UTILITIES+4)
            {
                if (hasLoginFlag(player))
                {
                    ChatHandler(player->GetSession()).PSendSysMessage("You have to complete the previously activated feature before trying to perform another.");
                    OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_UTILITIES);
                }
                else
                {
                    player->ModifyMoney(-(sConfigMgr->GetIntDefault("Assistant.Gossip.Utilities.FactionChange", 1000) * 10000));
                    player->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
                    ChatHandler(player->GetSession()).PSendSysMessage("You can now log out to apply the faction change.");
                    ClearGossipMenuFor(player);
                }
            }
            else if (action == ASSISTANT_GOSSIP_TOTEMS)
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_TOTEM);
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
};

void AddAssistantNPCScripts()
{
    new AssistantNPC();
}
