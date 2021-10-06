#include "ModAssistant.h"

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
                ClearGossipMenuFor(player);

                if (player->getClass() == CLASS_WARRIOR || player->getClass() == CLASS_PALADIN || player->getClass() == CLASS_DEATH_KNIGHT)
                {
                    AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_axe_09:25:25:-19|tBloodied Arcanite Reaper", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+4);
                }

                if (player->getClass() == CLASS_HUNTER || player->getClass() == CLASS_ROGUE || player->getClass() == CLASS_SHAMAN)
                {
                    AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_sword_17:25:25:-19|tBalanced Heartseeker", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+5);
                }

                if (player->getClass() == CLASS_WARRIOR || player->getClass() == CLASS_PALADIN || player->getClass() == CLASS_HUNTER || player->getClass() == CLASS_ROGUE || player->getClass() == CLASS_DEATH_KNIGHT)
                {
                    AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_sword_43:25:25:-19|tVenerable Dal'Rend's Sacred Charge", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+6);
                }

                if (player->getClass() == CLASS_WARRIOR || player->getClass() == CLASS_HUNTER || player->getClass() == CLASS_ROGUE)
                {
                    AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_weapon_bow_08:25:25:-19|tCharmed Ancient Bone Bow", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+7);
                }

                if (player->getClass() == CLASS_PRIEST || player->getClass() == CLASS_SHAMAN || player->getClass() == CLASS_MAGE || player->getClass() == CLASS_WARLOCK || player->getClass() == CLASS_DRUID)
                {
                    AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_jewelry_talisman_12:25:25:-19|tDignified Headmaster's Charge", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+8);
                }

                if (player->getClass() == CLASS_PALADIN || player->getClass() == CLASS_PRIEST || player->getClass() == CLASS_SHAMAN || player->getClass() == CLASS_DRUID)
                {
                    AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_hammer_05:25:25:-19|tDevout Aurastone Hammer", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+9);
                }

                if (player->getClass() == CLASS_WARRIOR || player->getClass() == CLASS_HUNTER || player->getClass() == CLASS_ROGUE || player->getClass() == CLASS_SHAMAN)
                {
                    AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_weapon_shortblade_03:25:25:-19|tSharpened Scarlet Kris", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+10);
                }

                if (player->getClass() == CLASS_WARRIOR || player->getClass() == CLASS_PALADIN || player->getClass() == CLASS_DEATH_KNIGHT)
                {
                    AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_sword_19:25:25:-19|tReforged Truesilver Champion", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+11);
                }

                if (player->getClass() == CLASS_WARRIOR || player->getClass() == CLASS_HUNTER || player->getClass() == CLASS_ROGUE)
                {
                    AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_weapon_rifle_09:25:25:-19|tUpgraded Dwarven Hand Cannon", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+12);
                }

                if (player->getClass() == CLASS_PALADIN || player->getClass() == CLASS_PRIEST || player->getClass() == CLASS_SHAMAN || player->getClass() == CLASS_DRUID)
                {
                    AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_hammer_07:25:25:-19|tThe Blessed Hammer of Grace", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+13);
                }

                if (player->getClass() == CLASS_PRIEST || player->getClass() == CLASS_SHAMAN || player->getClass() == CLASS_MAGE || player->getClass() == CLASS_WARLOCK || player->getClass() == CLASS_DRUID)
                {
                    AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_staff_13:25:25:-19|tGrand Staff of Jordan", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+14);
                }

                if (player->getClass() == CLASS_WARRIOR || player->getClass() == CLASS_PALADIN || player->getClass() == CLASS_HUNTER || player->getClass() == CLASS_ROGUE || player->getClass() == CLASS_DEATH_KNIGHT || player->getClass() == CLASS_MAGE || player->getClass() == CLASS_WARLOCK)
                {
                    AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_sword_36:25:25:-19|tBattleworn Thrash Blade", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+15);
                }

                if (player->getClass() == CLASS_ROGUE || player->getClass() == CLASS_SHAMAN)
                {
                    AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_hammer_17:25:25:-19|tVenerable Mass of McGowan", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+16);
                }

                if (player->getClass() == CLASS_SHAMAN || player->getClass() == CLASS_DRUID)
                {
                    AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_gizmo_02:25:25:-19|tRepurposed Lava Dredger", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+17);
                }

                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM);
                SendGossipMenuFor(player, ASSISTANT_GOSSIP_TEXT, creature->GetGUID());
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+2)
            {
                ClearGossipMenuFor(player);

                switch (player->getClass())
                {
                    case CLASS_WARRIOR:
                    case CLASS_PALADIN:
                    case CLASS_DEATH_KNIGHT:
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_shoulder_30:25:25:-19|tPolished Spaulders of Valor", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+18);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_chest_plate03:25:25:-19|tPolished Breastplate of Valor", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+19);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_shoulder_20:25:25:-19|tStrengthened Stockade Pauldrons", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+20);
                        break;
                    case CLASS_HUNTER:
                    case CLASS_SHAMAN:
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_shoulder_01:25:25:-19|tChampion Herod's Shoulder", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+21);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_chest_chain_07:25:25:-19|tChampion's Deathdealer Breastplate", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+22);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_shoulder_10:25:25:-19|tPrized Beastmaster's Mantle", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+23);
                        break;
                    case CLASS_ROGUE:
                    case CLASS_DRUID:
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_shoulder_07:25:25:-19|tStained Shadowcraft Spaulders", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+24);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_chest_leather_07:25:25:-19|tStained Shadowcraft Tunic", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+25);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_shoulder_05:25:25:-19|tExceptional Stormshroud Shoulders", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+26);
                        break;
                    case CLASS_PRIEST:
                    case CLASS_MAGE:
                    case CLASS_WARLOCK:
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_misc_bone_taurenskull_01:25:25:-19|tTattered Dreadmist Mantle", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+27);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_chest_cloth_49:25:25:-19|tTattered Dreadmist Robe", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+28);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_shoulder_02:25:25:-19|tExquisite Sunderseer Mantle", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+29);
                        break;
                }

                if (player->getClass() == CLASS_PALADIN)
                {
                    AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_shoulder_10:25:25:-19|tPristine Lightforge Spaulders", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+30);
                }
                else if (player->getClass() == CLASS_SHAMAN)
                {
                    AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_shoulder_29:25:25:-19|tMystical Pauldrons of Elements", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+31);
                    AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_chest_chain_11:25:25:-19|tMystical Vest of Elements", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+32);
                    AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_shoulder_29:25:25:-19|tAged Pauldrons of The Five Thunders", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+33);
                }
                else if (player->getClass() == CLASS_DRUID)
                {
                    AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_shoulder_06:25:25:-19|tPreened Ironfeather Shoulders", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+34);
                    AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_chest_leather_06:25:25:-19|tPreened Ironfeather Breastplate", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+35);
                    AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_shoulder_01:25:25:-19|tLasting Feralheart Spaulders", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+36);
                }

                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_jewelry_ring_39:25:25:-19|tDread Pirate Ring", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+37);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_jewelry_talisman_01:25:25:-19|tSwift Hand of Justice", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+38);

                if (player->getClass() == CLASS_PALADIN || 
                    player->getClass() == CLASS_HUNTER || 
                    player->getClass() == CLASS_PRIEST || 
                    player->getClass() == CLASS_SHAMAN || 
                    player->getClass() == CLASS_MAGE || 
                    player->getClass() == CLASS_WARLOCK || 
                    player->getClass() == CLASS_DRUID)
                {
                    AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_jewelry_talisman_08:25:25:-19|tDiscerning Eye of the Beast", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+39);
                }

                if (player->GetTeamId() == TEAM_ALLIANCE)
                {
                    AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_jewelry_trinketpvp_01:25:25:-19|tInherited Insignia of the Alliance", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+40);
                }
                else if (player->GetTeamId() == TEAM_HORDE)
                {
                    AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_jewelry_trinketpvp_02:25:25:-19|tInherited Insignia of the Horde", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+41);
                }

                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM);
                SendGossipMenuFor(player, ASSISTANT_GOSSIP_TEXT, creature->GetGUID());
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+3)
            {
                ClearGossipMenuFor(player);
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_misc_book_11:25:25:-19|tTome of Cold Weather Flight", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM + 42, "Do you wish to purchase this?", 10000000, false);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM);
                SendGossipMenuFor(player, ASSISTANT_GOSSIP_TEXT, creature->GetGUID());
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+4)
            {
                player->AddItem(42943, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+1);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+5)
            {
                player->AddItem(42944, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+1);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+6)
            {
                player->AddItem(42945, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+1);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+7)
            {
                player->AddItem(42946, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+1);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+8)
            {
                player->AddItem(42947, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+1);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+9)
            {
                player->AddItem(42948, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+1);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+10)
            {
                player->AddItem(44091, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+1);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+11)
            {
                player->AddItem(44092, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+1);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+12)
            {
                player->AddItem(44093, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+1);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+13)
            {
                player->AddItem(44094, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+1);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+14)
            {
                player->AddItem(44095, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+1);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+15)
            {
                player->AddItem(44096, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+1);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+16)
            {
                player->AddItem(48716, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+1);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+17)
            {
                player->AddItem(48718, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+1);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+18)
            {
                player->AddItem(42949, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+2);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+19)
            {
                player->AddItem(48685, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+2);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+20)
            {
                player->AddItem(44099, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+2);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+21)
            {
                player->AddItem(42950, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+2);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+22)
            {
                player->AddItem(48677, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+2);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+23)
            {
                player->AddItem(44101, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+2);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+24)
            {
                player->AddItem(42952, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+2);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+25)
            {
                player->AddItem(48689, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+2);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+26)
            {
                player->AddItem(44103, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+2);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+27)
            {
                player->AddItem(42985, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+2);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+28)
            {
                player->AddItem(48691, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+2);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+29)
            {
                player->AddItem(44107, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+2);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+30)
            {
                player->AddItem(44100, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+2);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+31)
            {
                player->AddItem(42951, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+2);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+32)
            {
                player->AddItem(48683, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+2);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+33)
            {
                player->AddItem(44102, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+2);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+34)
            {
                player->AddItem(42984, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+2);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+35)
            {
                player->AddItem(48687, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+2);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+36)
            {
                player->AddItem(44105, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+2);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+37)
            {
                player->AddItem(50255, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+2);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+38)
            {
                player->AddItem(42991, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+2);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+39)
            {
                player->AddItem(42992, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+2);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+40)
            {
                player->AddItem(44098, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+2);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+41)
            {
                player->AddItem(44097, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+2);
            }
            else if (action == ASSISTANT_GOSSIP_HEIRLOOM+42)
            {
                player->ModifyMoney(-10000000);
                player->AddItem(49177, 1);
                OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM+3);
            }

            return true;
        }
};

class LearnSpellOnLevelUp : public PlayerScript
{
    public:
        LearnSpellOnLevelUp() : PlayerScript("LearnSpellOnLevelUp") { }

        void OnLogin(Player* player) override
        {
            if (sConfigMgr->GetBoolDefault("Assistant.Spells.Enabled", 0) && sConfigMgr->GetBoolDefault("Assistant.Spells.OnLogin", 0))
            {
                if (sConfigMgr->GetBoolDefault("Assistant.Spells.Class", 0))
                {
                    LearnSpellForNewLevel(player);
                }

                if (sConfigMgr->GetBoolDefault("Assistant.Spells.Talent", 0))
                {
                    LearnTalentRankForNewLevel(player);
                }

                if (sConfigMgr->GetBoolDefault("Assistant.Spells.Proficiency", 0))
                {
                    LearnProficiencyForNewLevel(player);
                }

                if (sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Enabled", 0))
                {
                    LearnMountForNewLevel(player);
                }

                if (sConfigMgr->GetBoolDefault("Assistant.Spells.MaxSkill.Enabled", 0))
                {
                    MaxAllWeaponSkill(player);
                }
            }
        }

        void OnLevelChanged(Player* player, uint8 oldLevel) override
        {
            if (sConfigMgr->GetBoolDefault("Assistant.Spells.Enabled", 0) && sConfigMgr->GetBoolDefault("Assistant.Spells.OnLevelUp", 0))
            {
                if (sConfigMgr->GetBoolDefault("Assistant.Spells.Class", 0))
                {
                    LearnSpellForNewLevel(player);
                }

                if (sConfigMgr->GetBoolDefault("Assistant.Spells.Talent", 0))
                {
                    LearnTalentRankForNewLevel(player);
                }

                if (sConfigMgr->GetBoolDefault("Assistant.Spells.Proficiency", 0))
                {
                    LearnProficiencyForNewLevel(player);
                }

                if (sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Enabled", 0))
                {
                    LearnMountForNewLevel(player);
                }

                if (sConfigMgr->GetBoolDefault("Assistant.Spells.MaxSkill.Enabled", 0))
                {
                    MaxAllWeaponSkill(player);
                }
            }
        }

    private:
        void LearnSpellForNewLevel(Player* player)
        {
            switch (player->getClass())
            {
                case CLASS_WARRIOR:
                    for (int i = 0; i < 124; i++)
                    {
                        if (player->getLevel() >= classSpellWarrior[i][1] && !player->HasSpell(classSpellWarrior[i][0]))
                        {
                            player->learnSpell(classSpellWarrior[i][0]);
                        }
                    }
                    break;
                case CLASS_PALADIN:
                    for (int i = 0; i < 160; i++)
                    {
                        if (player->getLevel() >= classSpellPaladin[i][1] && !player->HasSpell(classSpellPaladin[i][0]))
                        {
                            player->learnSpell(classSpellPaladin[i][0]);
                        }
                    }
                    break;
                case CLASS_HUNTER:
                    for (int i = 0; i < 149; i++)
                    {
                        if (player->getLevel() >= classSpellHunter[i][1] && !player->HasSpell(classSpellHunter[i][0]))
                        {
                            player->learnSpell(classSpellHunter[i][0]);
                        }
                    }
                    break;
                case CLASS_ROGUE:
                    for (int i = 0; i < 113; i++)
                    {
                        if (player->getLevel() >= classSpellRogue[i][1] && !player->HasSpell(classSpellRogue[i][0]))
                        {
                            player->learnSpell(classSpellRogue[i][0]);
                        }
                    }
                    break;
                case CLASS_PRIEST:
                    for (int i = 0; i < 208; i++)
                    {
                        if (player->getLevel() >= classSpellPriest[i][1] && !player->HasSpell(classSpellPriest[i][0]))
                        {
                            player->learnSpell(classSpellPriest[i][0]);
                        }
                    }
                    break;
                case CLASS_DEATH_KNIGHT:
                    for (int i = 0; i < 69; i++)
                    {
                        if (player->getLevel() >= classSpellDeathKnight[i][1] && !player->HasSpell(classSpellDeathKnight[i][0]))
                        {
                            player->learnSpell(classSpellDeathKnight[i][0]);
                        }
                    }
                    break;
                case CLASS_SHAMAN:
                    for (int i = 0; i < 266; i++)
                    {
                        if (player->getLevel() >= classSpellShaman[i][1] && !player->HasSpell(classSpellShaman[i][0]))
                        {
                            player->learnSpell(classSpellShaman[i][0]);
                        }
                    }
                    break;
                case CLASS_MAGE:
                    for (int i = 0; i < 223; i++)
                    {
                        if (player->getLevel() >= classSpellMage[i][1] && !player->HasSpell(classSpellMage[i][0]))
                        {
                            player->learnSpell(classSpellMage[i][0]);
                        }
                    }
                    break;
                case CLASS_WARLOCK:
                    for (int i = 0; i < 211; i++)
                    {
                        if (player->getLevel() >= classSpellWarlock[i][1] && !player->HasSpell(classSpellWarlock[i][0]))
                        {
                            player->learnSpell(classSpellWarlock[i][0]);
                        }
                    }
                    break;
                case CLASS_DRUID:
                    for (int i = 0; i < 276; i++)
                    {
                        if (player->getLevel() >= classSpellDruid[i][1] && !player->HasSpell(classSpellDruid[i][0]))
                        {
                            player->learnSpell(classSpellDruid[i][0]);
                        }
                    }
                    break;
            }
        }

        void LearnTalentRankForNewLevel(Player* player)
        {
            switch (player->getClass())
            {
                case CLASS_WARRIOR:
                    for (int i = 0; i < 276; i++)
                    {
                        if (player->getLevel() >= talentSpellWarrior[i][1] && !player->HasSpell(talentSpellWarrior[i][0]) && player->HasSpell(talentSpellWarrior[i][2]))
                        {
                            player->learnSpell(talentSpellWarrior[i][0]);
                        }
                    }
                    break;
                case CLASS_PALADIN:
                    for (int i = 0; i < 16; i++)
                    {
                        if (player->getLevel() >= talentSpellPaladin[i][1] && !player->HasSpell(talentSpellPaladin[i][0]) && player->HasSpell(talentSpellWarrior[i][2]))
                        {
                            player->learnSpell(talentSpellPaladin[i][0]);
                        }
                    }
                    break;
                case CLASS_HUNTER:
                    for (int i = 0; i < 26; i++)
                    {
                        if (player->getLevel() >= talentSpellHunter[i][1] && !player->HasSpell(talentSpellHunter[i][0]) && player->HasSpell(talentSpellWarrior[i][2]))
                        {
                            player->learnSpell(talentSpellHunter[i][0]);
                        }
                    }
                    break;
                case CLASS_ROGUE:
                    for (int i = 0; i < 9; i++)
                    {
                        if (player->getLevel() >= talentSpellRogue[i][1] && !player->HasSpell(talentSpellRogue[i][0]) && player->HasSpell(talentSpellWarrior[i][2]))
                        {
                            player->learnSpell(talentSpellRogue[i][0]);
                        }
                    }
                    break;
                case CLASS_PRIEST:
                    for (int i = 0; i < 34; i++)
                    {
                        if (player->getLevel() >= talentSpellPriest[i][1] && !player->HasSpell(talentSpellPriest[i][0]) && player->HasSpell(talentSpellWarrior[i][2]))
                        {
                            player->learnSpell(talentSpellPriest[i][0]);
                        }
                    }
                    break;
                case CLASS_DEATH_KNIGHT:
                    for (int i = 0; i < 20; i++)
                    {
                        if (player->getLevel() >= talentSpellDeathKnight[i][1] && !player->HasSpell(talentSpellDeathKnight[i][0]) && player->HasSpell(talentSpellWarrior[i][2]))
                        {
                            player->learnSpell(talentSpellDeathKnight[i][0]);
                        }
                    }
                    break;
                case CLASS_SHAMAN:
                    for (int i = 0; i < 13; i++)
                    {
                        if (player->getLevel() >= talentSpellShaman[i][1] && !player->HasSpell(talentSpellShaman[i][0]) && player->HasSpell(talentSpellWarrior[i][2]))
                        {
                            player->learnSpell(talentSpellShaman[i][0]);
                        }
                    }
                    break;
                case CLASS_MAGE:
                    for (int i = 0; i < 35; i++)
                    {
                        if (player->getLevel() >= talentSpellMage[i][1] && !player->HasSpell(talentSpellMage[i][0]) && player->HasSpell(talentSpellWarrior[i][2]))
                        {
                            player->learnSpell(talentSpellMage[i][0]);
                        }
                    }
                    break;
                case CLASS_WARLOCK:
                    for (int i = 0; i < 27; i++)
                    {
                        if (player->getLevel() >= talentSpellWarlock[i][1] && !player->HasSpell(talentSpellWarlock[i][0]) && player->HasSpell(talentSpellWarrior[i][2]))
                        {
                            player->learnSpell(talentSpellWarlock[i][0]);
                        }
                    }
                    break;
                case CLASS_DRUID:
                    for (int i = 0; i < 24; i++)
                    {
                        if (player->getLevel() >= talentSpellDruid[i][1] && !player->HasSpell(talentSpellDruid[i][0]) && player->HasSpell(talentSpellWarrior[i][2]))
                        {
                            player->learnSpell(talentSpellDruid[i][0]);
                        }
                    }
                    break;
            }
        }

        void LearnProficiencyForNewLevel(Player* player)
        {
            switch (player->getClass())
            {
                case CLASS_WARRIOR:
                    for (int i = 0; i < 16; i++)
                    {
                        if (player->getLevel() >= proficiencySpellWarrior[i][1] && !player->HasSpell(proficiencySpellWarrior[i][0]))
                        {
                            player->learnSpell(proficiencySpellWarrior[i][0]);
                        }
                    }
                    break;
                case CLASS_PALADIN:
                    for (int i = 0; i < 9; i++)
                    {
                        if (player->getLevel() >= proficiencySpellPaladin[i][1] && !player->HasSpell(proficiencySpellPaladin[i][0]))
                        {
                            player->learnSpell(proficiencySpellPaladin[i][0]);
                        }
                    }
                    break;
                case CLASS_HUNTER:
                    for (int i = 0; i < 14; i++)
                    {
                        if (player->getLevel() >= proficiencySpellHunter[i][1] && !player->HasSpell(proficiencySpellHunter[i][0]))
                        {
                            player->learnSpell(proficiencySpellHunter[i][0]);
                        }
                    }
                    break;
                case CLASS_ROGUE:
                    for (int i = 0; i < 10; i++)
                    {
                        if (player->getLevel() >= proficiencySpellRogue[i][1] && !player->HasSpell(proficiencySpellRogue[i][0]))
                        {
                            player->learnSpell(proficiencySpellRogue[i][0]);
                        }
                    }
                    break;
                case CLASS_PRIEST:
                    for (int i = 0; i < 4; i++)
                    {
                        if (player->getLevel() >= proficiencySpellPriest[i][1] && !player->HasSpell(proficiencySpellPriest[i][0]))
                        {
                            player->learnSpell(proficiencySpellPriest[i][0]);
                        }
                    }
                    break;
                case CLASS_DEATH_KNIGHT:
                    for (int i = 0; i < 10; i++)
                    {
                        if (player->getLevel() >= proficiencySpellDeathKnight[i][1] && !player->HasSpell(proficiencySpellDeathKnight[i][0]))
                        {
                            player->learnSpell(proficiencySpellDeathKnight[i][0]);
                        }
                    }
                    break;
                case CLASS_SHAMAN:
                    for (int i = 0; i < 9; i++)
                    {
                        if (player->getLevel() >= proficiencySpellShaman[i][1] && !player->HasSpell(proficiencySpellShaman[i][0]))
                        {
                            player->learnSpell(proficiencySpellShaman[i][0]);
                        }
                    }
                    break;
                case CLASS_MAGE:
                    for (int i = 0; i < 4; i++)
                    {
                        if (player->getLevel() >= proficiencySpellMage[i][1] && !player->HasSpell(proficiencySpellMage[i][0]))
                        {
                            player->learnSpell(proficiencySpellMage[i][0]);
                        }
                    }
                    break;
                case CLASS_WARLOCK:
                    for (int i = 0; i < 4; i++)
                    {
                        if (player->getLevel() >= proficiencySpellWarlock[i][1] && !player->HasSpell(proficiencySpellWarlock[i][0]))
                        {
                            player->learnSpell(proficiencySpellWarlock[i][0]);
                        }
                    }
                    break;
                case CLASS_DRUID:
                    for (int i = 0; i < 6; i++)
                    {
                        if (player->getLevel() >= proficiencySpellDruid[i][1] && !player->HasSpell(proficiencySpellDruid[i][0]))
                        {
                            player->learnSpell(proficiencySpellDruid[i][0]);
                        }
                    }
                    break;
            }
        }

        void MaxAllWeaponSkill(Player* player)
        {
            if (player->getLevel() <= sConfigMgr->GetIntDefault("Assistant.Spells.MaxSkill.MaxLevel", 80))
            {
                player->UpdateSkillsToMaxSkillsForLevel();
            }
        }

        void LearnMountForNewLevel(Player* player)
        {
            for (int i = 0; i < 5; i++)
            {
                if (player->getLevel() >= ridingSpell[i][1] && !player->HasSpell(ridingSpell[i][0]))
                {
                    if ((ridingSpell[i][2] == MOUNT_APPRENTICE && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Apprentice", 0)) || 
                        (ridingSpell[i][2] == MOUNT_JOURNEYMAN && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Journeyman", 0)) || 
                        (ridingSpell[i][2] == MOUNT_EXPERT && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Expert", 0)) || 
                        (ridingSpell[i][2] == MOUNT_ARTISAN && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Artisan", 0)) || 
                        (ridingSpell[i][2] == MOUNT_COLD_WEATHER && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.ColdWeather", 0)) || 
                        (ridingSpell[i][3] > 0 && !player->HasSpell(ridingSpell[i][3])))
                        continue;

                    player->learnSpell(ridingSpell[i][0]);
                }
            }

            switch (player->getRace())
            {
                case RACE_HUMAN:
                    for (int i = 0; i < 13; i++)
                    {
                        if (player->getLevel() >= mountSpellHuman[i][1] && !player->HasSpell(mountSpellHuman[i][0]) && player->HasSpell(mountSpellHuman[i][3]))
                        {
                            if ((mountSpellHuman[i][2] == MOUNT_APPRENTICE && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Apprentice", 0)) || 
                                (mountSpellHuman[i][2] == MOUNT_JOURNEYMAN && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Journeyman", 0)) || 
                                (mountSpellHuman[i][2] == MOUNT_EXPERT && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Expert", 0)) || 
                                (mountSpellHuman[i][2] == MOUNT_ARTISAN && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Artisan", 0)))
                                continue;

                            player->learnSpell(mountSpellHuman[i][0]);
                        }
                    }
                    break;
                case RACE_ORC:
                    for (int i = 0; i < 14; i++)
                    {
                        if (player->getLevel() >= mountSpellOrc[i][1] && !player->HasSpell(mountSpellOrc[i][0]) && player->HasSpell(mountSpellOrc[i][3]))
                        {
                            if ((mountSpellOrc[i][2] == MOUNT_APPRENTICE && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Apprentice", 0)) || 
                                (mountSpellOrc[i][2] == MOUNT_JOURNEYMAN && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Journeyman", 0)) || 
                                (mountSpellOrc[i][2] == MOUNT_EXPERT && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Expert", 0)) || 
                                (mountSpellOrc[i][2] == MOUNT_ARTISAN && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Artisan", 0)))
                                continue;

                            player->learnSpell(mountSpellOrc[i][0]);
                        }
                    }
                    break;
                case RACE_DWARF:
                    for (int i = 0; i < 13; i++)
                    {
                        if (player->getLevel() >= mountSpellDwarf[i][1] && !player->HasSpell(mountSpellDwarf[i][0]) && player->HasSpell(mountSpellDwarf[i][3]))
                        {
                            if ((mountSpellDwarf[i][2] == MOUNT_APPRENTICE && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Apprentice", 0)) || 
                                (mountSpellDwarf[i][2] == MOUNT_JOURNEYMAN && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Journeyman", 0)) || 
                                (mountSpellDwarf[i][2] == MOUNT_EXPERT && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Expert", 0)) || 
                                (mountSpellDwarf[i][2] == MOUNT_ARTISAN && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Artisan", 0)))
                                continue;

                            player->learnSpell(mountSpellDwarf[i][0]);
                        }
                    }
                    break;
                case RACE_NIGHTELF:
                    for (int i = 0; i < 14; i++)
                    {
                        if (player->getLevel() >= mountSpellNightElf[i][1] && !player->HasSpell(mountSpellNightElf[i][0]) && player->HasSpell(mountSpellNightElf[i][3]))
                        {
                            if ((mountSpellNightElf[i][2] == MOUNT_APPRENTICE && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Apprentice", 0)) || 
                                (mountSpellNightElf[i][2] == MOUNT_JOURNEYMAN && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Journeyman", 0)) || 
                                (mountSpellNightElf[i][2] == MOUNT_EXPERT && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Expert", 0)) || 
                                (mountSpellNightElf[i][2] == MOUNT_ARTISAN && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Artisan", 0)))
                                continue;

                            player->learnSpell(mountSpellNightElf[i][0]);
                        }
                    }
                    break;
                case RACE_UNDEAD_PLAYER:
                    for (int i = 0; i < 14; i++)
                    {
                        if (player->getLevel() >= mountSpellUndead[i][1] && !player->HasSpell(mountSpellUndead[i][0]) && player->HasSpell(mountSpellUndead[i][3]))
                        {
                            if ((mountSpellUndead[i][2] == MOUNT_APPRENTICE && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Apprentice", 0)) || 
                                (mountSpellUndead[i][2] == MOUNT_JOURNEYMAN && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Journeyman", 0)) || 
                                (mountSpellUndead[i][2] == MOUNT_EXPERT && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Expert", 0)) || 
                                (mountSpellUndead[i][2] == MOUNT_ARTISAN && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Artisan", 0)))
                                continue;

                            player->learnSpell(mountSpellUndead[i][0]);
                        }
                    }
                    break;
                case RACE_TAUREN:
                    for (int i = 0; i < 13; i++)
                    {
                        if (player->getLevel() >= mountSpellTauren[i][1] && !player->HasSpell(mountSpellTauren[i][0]) && player->HasSpell(mountSpellTauren[i][3]))
                        {
                            if ((mountSpellTauren[i][2] == MOUNT_APPRENTICE && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Apprentice", 0)) || 
                                (mountSpellTauren[i][2] == MOUNT_JOURNEYMAN && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Journeyman", 0)) || 
                                (mountSpellTauren[i][2] == MOUNT_EXPERT && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Expert", 0)) || 
                                (mountSpellTauren[i][2] == MOUNT_ARTISAN && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Artisan", 0)))
                                continue;

                            player->learnSpell(mountSpellTauren[i][0]);
                        }
                    }
                    break;
                case RACE_GNOME:
                    for (int i = 0; i < 14; i++)
                    {
                        if (player->getLevel() >= mountSpellGnome[i][1] && !player->HasSpell(mountSpellGnome[i][0]) && player->HasSpell(mountSpellGnome[i][3]))
                        {
                            if ((mountSpellGnome[i][2] == MOUNT_APPRENTICE && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Apprentice", 0)) || 
                                (mountSpellGnome[i][2] == MOUNT_JOURNEYMAN && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Journeyman", 0)) || 
                                (mountSpellGnome[i][2] == MOUNT_EXPERT && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Expert", 0)) || 
                                (mountSpellGnome[i][2] == MOUNT_ARTISAN && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Artisan", 0)))
                                continue;

                            player->learnSpell(mountSpellGnome[i][0]);
                        }
                    }
                    break;
                case RACE_TROLL:
                    for (int i = 0; i < 13; i++)
                    {
                        if (player->getLevel() >= mountSpellTroll[i][1] && !player->HasSpell(mountSpellTroll[i][0]) && player->HasSpell(mountSpellTroll[i][3]))
                        {
                            if ((mountSpellTroll[i][2] == MOUNT_APPRENTICE && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Apprentice", 0)) || 
                                (mountSpellTroll[i][2] == MOUNT_JOURNEYMAN && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Journeyman", 0)) || 
                                (mountSpellTroll[i][2] == MOUNT_EXPERT && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Expert", 0)) || 
                                (mountSpellTroll[i][2] == MOUNT_ARTISAN && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Artisan", 0)))
                                continue;

                            player->learnSpell(mountSpellTroll[i][0]);
                        }
                    }
                    break;
                case RACE_BLOODELF:
                    for (int i = 0; i < 14; i++)
                    {
                        if (player->getLevel() >= mountSpellBloodElf[i][1] && !player->HasSpell(mountSpellBloodElf[i][0]) && player->HasSpell(mountSpellBloodElf[i][3]))
                        {
                            if ((mountSpellBloodElf[i][2] == MOUNT_APPRENTICE && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Apprentice", 0)) || 
                                (mountSpellBloodElf[i][2] == MOUNT_JOURNEYMAN && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Journeyman", 0)) || 
                                (mountSpellBloodElf[i][2] == MOUNT_EXPERT && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Expert", 0)) || 
                                (mountSpellBloodElf[i][2] == MOUNT_ARTISAN && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Artisan", 0)))
                                continue;

                            player->learnSpell(mountSpellBloodElf[i][0]);
                        }
                    }
                    break;
                case RACE_DRAENEI:
                    for (int i = 0; i < 13; i++)
                    {
                        if (player->getLevel() >= mountSpellDraenei[i][1] && !player->HasSpell(mountSpellDraenei[i][0]) && player->HasSpell(mountSpellDraenei[i][3]))
                        {
                            if ((mountSpellDraenei[i][2] == MOUNT_APPRENTICE && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Apprentice", 0)) || 
                                (mountSpellDraenei[i][2] == MOUNT_JOURNEYMAN && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Journeyman", 0)) || 
                                (mountSpellDraenei[i][2] == MOUNT_EXPERT && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Expert", 0)) || 
                                (mountSpellDraenei[i][2] == MOUNT_ARTISAN && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Artisan", 0)))
                                continue;

                            player->learnSpell(mountSpellDraenei[i][0]);
                        }
                    }
                    break;
            }
        }
};

class SetSpawnPoint : public PlayerScript
{
    public:
        SetSpawnPoint() : PlayerScript("SetSpawnPoint") { }

        void OnFirstLogin(Player* player) override
        {
            if (sConfigMgr->GetBoolDefault("Assistant.SpawnPoint.Enabled", 0))
            {
                if (player->getClass() == CLASS_DEATH_KNIGHT && !sConfigMgr->GetBoolDefault("Assistant.SpawnPoint.DeathKnight", 0))
                    return;

                if (player->GetTeamId() == TEAM_ALLIANCE)
                {
                    player->TeleportTo(0, -8830.438477, 626.666199, 93.982887, 0.682076);
                }
                else if (player->GetTeamId() == TEAM_HORDE)
                {
                    player->TeleportTo(1, 1630.776001,  -4412.993652, 16.567701, 0.080535);
                }
            }
        }
};

class DazeImmunity : public PlayerScript
{
    public:
        DazeImmunity() : PlayerScript("DazeImmunity") { }

        void OnLogin(Player* player) override
        {
            if (sConfigMgr->GetBoolDefault("Assistant.Spells.Immunity.Daze", 0))
            {
                if (!player->HasAura(57416))
                {
                    player->AddAura(57416, player);
                }
            }
            else
            {
                if (player->HasAura(57416))
                {
                    player->RemoveAura(57416);
                }
            }
        }
};

class DynamicExperience : public PlayerScript
{
    public:
        DynamicExperience() : PlayerScript("DynamicExperience") { }

        void OnGiveXP(Player* player, uint32& amount, Unit* /*victim*/) override
        {
            if (sConfigMgr->GetBoolDefault("Assistant.Rate.Experience.Enabled", 0))
            {
                if (player->getLevel() <= 9)
                {
                    amount *= sConfigMgr->GetIntDefault("Assistant.Rate.Experience.1-9", 1);
                }
                else if (player->getLevel() <= 19)
                {
                    amount *= sConfigMgr->GetIntDefault("Assistant.Rate.Experience.10-19", 1);
                }
                else if (player->getLevel() <= 29)
                {
                    amount *= sConfigMgr->GetIntDefault("Assistant.Rate.Experience.20.29", 1);
                }
                else if (player->getLevel() <= 39)
                {
                    amount *= sConfigMgr->GetIntDefault("Assistant.Rate.Experience.30-39", 1);
                }
                else if (player->getLevel() <= 49)
                {
                    amount *= sConfigMgr->GetIntDefault("Assistant.Rate.Experience.40-49", 1);
                }
                else if (player->getLevel() <= 59)
                {
                    amount *= sConfigMgr->GetIntDefault("Assistant.Rate.Experience.50-59", 1);
                }
                else if (player->getLevel() <= 69)
                {
                    amount *= sConfigMgr->GetIntDefault("Assistant.Rate.Experience.60-69", 1);
                }
                else if (player->getLevel() <= 79)
                {
                    amount *= sConfigMgr->GetIntDefault("Assistant.Rate.Experience.70-79", 1);
                }
                else if (player->getLevel() == 80)
                {
                    amount *= sConfigMgr->GetIntDefault("Assistant.Rate.Experience.80", 1);
                }
            }
        }
};

class DynamicReputation : public PlayerScript
{
    public:
        DynamicReputation() : PlayerScript("DynamicReputation") { }

        void OnReputationChange(Player* player, uint32 /*factionId*/, int32& standing, bool /*incremental*/) override
        {
            if (sConfigMgr->GetBoolDefault("Assistant.Rate.Reputation.Enabled", 0))
            {
                if (player->getLevel() <= 9)
                {
                    standing *= sConfigMgr->GetIntDefault("Assistant.Rate.Reputation.1-9", 1);
                }
                else if (player->getLevel() <= 19)
                {
                    standing *= sConfigMgr->GetIntDefault("Assistant.Rate.Reputation.10-19", 1);
                }
                else if (player->getLevel() <= 29)
                {
                    standing *= sConfigMgr->GetIntDefault("Assistant.Rate.Reputation.20.29", 1);
                }
                else if (player->getLevel() <= 39)
                {
                    standing *= sConfigMgr->GetIntDefault("Assistant.Rate.Reputation.30-39", 1);
                }
                else if (player->getLevel() <= 49)
                {
                    standing *= sConfigMgr->GetIntDefault("Assistant.Rate.Reputation.40-49", 1);
                }
                else if (player->getLevel() <= 59)
                {
                    standing *= sConfigMgr->GetIntDefault("Assistant.Rate.Reputation.50-59", 1);
                }
                else if (player->getLevel() <= 69)
                {
                    standing *= sConfigMgr->GetIntDefault("Assistant.Rate.Reputation.60-69", 1);
                }
                else if (player->getLevel() <= 79)
                {
                    standing *= sConfigMgr->GetIntDefault("Assistant.Rate.Reputation.70-79", 1);
                }
                else if (player->getLevel() == 80)
                {
                    standing *= sConfigMgr->GetIntDefault("Assistant.Rate.Reputation.80", 1);
                }
            }
        }
};

void AddModAssistantScripts()
{
    new AssistantNPC();
    new LearnSpellOnLevelUp();
    new SetSpawnPoint();
    new DazeImmunity();
    new DynamicExperience();
    new DynamicReputation();
}
