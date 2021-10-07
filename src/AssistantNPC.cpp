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
    ASSISTANT_GOSSIP_OTHER     = 700
};

enum VendorId
{
    ASSISTANT_VENDOR_HEIRLOOM_WEAPON = 9000000,
    ASSISTANT_VENDOR_HEIRLOOM_ARMOR = 9000001,
    ASSISTANT_VENDOR_HEIRLOOM_OTHER = 9000002
};

class AssistantNPC : public CreatureScript
{
    public:
        AssistantNPC() : CreatureScript("npc_assistant") { }

        bool OnGossipHello(Player* player, Creature* creature)
        {
            ClearGossipMenuFor(player);
            if (sConfigMgr->GetBoolDefault("Assistant.Gossip.Heirlooms", 0))
            {
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want heirlooms", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM);
            }

            if (sConfigMgr->GetBoolDefault("Assistant.Gossip.Glyphs", 0))
            {
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want glyphs", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH);
            }

            if (sConfigMgr->GetBoolDefault("Assistant.Gossip.Gems", 0))
            {
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want gems", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GEM);
            }

            if (sConfigMgr->GetBoolDefault("Assistant.Gossip.Containers", 0))
            {
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want containers", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_CONTAINER);
            }

            if (sConfigMgr->GetBoolDefault("Assistant.Gossip.Utilities", 0))
            {
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "I want utilities", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_UTILITIES);
            }

            if (sConfigMgr->GetBoolDefault("Assistant.Gossip.Other", 0))
            {
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "What else can I get?", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_OTHER);
            }

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

            return true;
        }
};

void AddAssistantNPCScripts()
{
    new AssistantNPC();
}
