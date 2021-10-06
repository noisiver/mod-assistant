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
                ClearGossipMenuFor(player);

                switch (player->getClass())
                {
                    case CLASS_WARRIOR:
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorwarrior:25:25:-19|tGlyph of Bloodthirst", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+3);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorwarrior:25:25:-19|tGlyph of Devastate", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+4);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorwarrior:25:25:-19|tGlyph of Intervene", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+5);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorwarrior:25:25:-19|tGlyph of Mortal Strike", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+6);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorwarrior:25:25:-19|tGlyph of Bladestorm", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+7);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorwarrior:25:25:-19|tGlyph of Shockwave", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+8);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorwarrior:25:25:-19|tGlyph of Vigilance", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+9);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorwarrior:25:25:-19|tGlyph of Enraged Regeneration", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+10);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorwarrior:25:25:-19|tGlyph of Spell Reflection", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+11);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorwarrior:25:25:-19|tGlyph of Shield Wall", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+12);
                        break;
                    case CLASS_PALADIN:
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorpaladin:25:25:-19|tGlyph of Hammer of Wrath", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+13);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorpaladin:25:25:-19|tGlyph of Avenging Wrath", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+14);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorpaladin:25:25:-19|tGlyph of Avenger's Shield", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+15);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorpaladin:25:25:-19|tGlyph of Holy Wrath", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+16);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorpaladin:25:25:-19|tGlyph of Seal of Righteousness", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+17);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorpaladin:25:25:-19|tGlyph of Seal of Vengeance", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+18);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorpaladin:25:25:-19|tGlyph of Beacon of Light", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+19);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorpaladin:25:25:-19|tGlyph of Hammer of the Righteous", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+20);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorpaladin:25:25:-19|tGlyph of Divine Storm", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+21);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorpaladin:25:25:-19|tGlyph of Shield of Righteousness", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+22);
                        break;
                    case CLASS_HUNTER:
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorhunter:25:25:-19|tGlyph of Bestial Wrath", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+23);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorhunter:25:25:-19|tGlyph of Snake Trap", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+24);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorhunter:25:25:-19|tGlyph of Steady Shot", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+25);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorhunter:25:25:-19|tGlyph of Trueshot Aura", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+26);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorhunter:25:25:-19|tGlyph of Volley", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+27);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorhunter:25:25:-19|tGlyph of Wyvern Sting", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+28);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorhunter:25:25:-19|tGlyph of Chimera Shot", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+29);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorhunter:25:25:-19|tGlyph of Explosive Shot", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+30);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorhunter:25:25:-19|tGlyph of Kill Shot", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+31);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorhunter:25:25:-19|tGlyph of Explosive Trap", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+32);
                        break;
                    case CLASS_ROGUE:
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorrogue:25:25:-19|tGlyph of Adrenaline Rush", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+33);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorrogue:25:25:-19|tGlyph of Deadly Throw", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+34);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorrogue:25:25:-19|tGlyph of Vigor", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+35);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorrogue:25:25:-19|tGlyph of Hunger for Blood", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+36);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorrogue:25:25:-19|tGlyph of Killing Spree", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+37);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorrogue:25:25:-19|tGlyph of Shadow Dance", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+38);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorrogue:25:25:-19|tGlyph of Fan of Knives", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+39);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorrogue:25:25:-19|tGlyph of Tricks of the Trade", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+40);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorrogue:25:25:-19|tGlyph of Mutilate", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+41);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorrogue:25:25:-19|tGlyph of Cloak of Shadows", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+42);
                        break;
                    case CLASS_PRIEST:
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorpriest:25:25:-19|tGlyph of Circle of Healing", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+43);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorpriest:25:25:-19|tGlyph of Lightwell", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+44);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorpriest:25:25:-19|tGlyph of Mass Dispel", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+45);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorpriest:25:25:-19|tGlyph of Shadow Word: Death", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+46);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorpriest:25:25:-19|tGlyph of Dispersion", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+47);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorpriest:25:25:-19|tGlyph of Guardian Spirit", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+48);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorpriest:25:25:-19|tGlyph of Penance", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+49);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorpriest:25:25:-19|tGlyph of Mind Sear", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+50);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorpriest:25:25:-19|tGlyph of Hymn of Hope", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+51);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorpriest:25:25:-19|tGlyph of Pain Suppression", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+52);
                        break;
                    case CLASS_DEATH_KNIGHT:
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majordeathknight:25:25:-19|tGlyph of Anti-Magic Shell", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+53);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majordeathknight:25:25:-19|tGlyph of Heart Strike", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+54);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majordeathknight:25:25:-19|tGlyph of Bone Shield", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+55);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majordeathknight:25:25:-19|tGlyph of Chains of Ice", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+56);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majordeathknight:25:25:-19|tGlyph of Dark Command", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+57);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majordeathknight:25:25:-19|tGlyph of Death Grip", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+58);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majordeathknight:25:25:-19|tGlyph of Death and Decay", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+59);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majordeathknight:25:25:-19|tGlyph of Frost Strike", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+60);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majordeathknight:25:25:-19|tGlyph of Icebound Fortitude", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+61);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majordeathknight:25:25:-19|tGlyph of Icy Touch", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+62);
                        break;
                    case CLASS_SHAMAN:
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorshaman:25:25:-19|tGlyph of Chain Heal", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+63);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorshaman:25:25:-19|tGlyph of Lava", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+64);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorshaman:25:25:-19|tGlyph of Fire Elemental Totem", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+65);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorshaman:25:25:-19|tGlyph of Mana Tide Totem", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+66);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorshaman:25:25:-19|tGlyph of Stormstrike", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+67);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorshaman:25:25:-19|tGlyph of Elemental Mastery", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+68);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorshaman:25:25:-19|tGlyph of Thunder", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+69);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorshaman:25:25:-19|tGlyph of Feral Spirit", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+70);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorshaman:25:25:-19|tGlyph of Riptide", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+71);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorshaman:25:25:-19|tGlyph of Earth Shield", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+72);
                        break;
                    case CLASS_MAGE:
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majormage:25:25:-19|tGlyph of Arcane Power", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+73);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majormage:25:25:-19|tGlyph of Deep Freeze", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+74);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majormage:25:25:-19|tGlyph of Living Bomb", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+75);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majormage:25:25:-19|tGlyph of Invisibility", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+76);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majormage:25:25:-19|tGlyph of Ice Lance", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+77);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majormage:25:25:-19|tGlyph of Molten Armor", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+78);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majormage:25:25:-19|tGlyph of Water Elemental", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+79);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majormage:25:25:-19|tGlyph of Frostfire", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+80);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majormage:25:25:-19|tGlyph of Arcane Blast", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+81);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majormage:25:25:-19|tGlyph of Eternal Water", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+82);
                        break;
                    case CLASS_WARLOCK:
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorwarlock:25:25:-19|tGlyph of Conflagrate", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+83);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorwarlock:25:25:-19|tGlyph of Death Coil", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+84);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorwarlock:25:25:-19|tGlyph of Felguard", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+85);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorwarlock:25:25:-19|tGlyph of Howl of Terror", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+86);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorwarlock:25:25:-19|tGlyph of Unstable Affliction", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+87);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorwarlock:25:25:-19|tGlyph of Haunt", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+88);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorwarlock:25:25:-19|tGlyph of Metamorphosis", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+89);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorwarlock:25:25:-19|tGlyph of Chaos Bolt", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+90);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorwarlock:25:25:-19|tGlyph of Demonic Circle", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+91);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majorwarlock:25:25:-19|tGlyph of Shadowflame", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+92);
                        break;
                    case CLASS_DRUID:
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majordruid:25:25:-19|tGlyph of Mangle", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+93);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majordruid:25:25:-19|tGlyph of Swiftmend", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+94);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majordruid:25:25:-19|tGlyph of Innervate", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+95);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majordruid:25:25:-19|tGlyph of Lifebloom", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+96);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majordruid:25:25:-19|tGlyph of Hurricane", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+97);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majordruid:25:25:-19|tGlyph of Starfall", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+98);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majordruid:25:25:-19|tGlyph of Focus", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+99);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majordruid:25:25:-19|tGlyph of Berserk", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+100);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majordruid:25:25:-19|tGlyph of Wild Growth", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+101);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_majordruid:25:25:-19|tGlyph of Nourish", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+102);
                        break;
                }

                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH);
                SendGossipMenuFor(player, ASSISTANT_GOSSIP_TEXT, creature->GetGUID());
            }
            else if (action == ASSISTANT_GOSSIP_GLYPH+2)
            {
                ClearGossipMenuFor(player);

                switch (player->getClass())
                {
                    case CLASS_WARRIOR:
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorwarrior:25:25:-19|tGlyph of Battle", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+103);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorwarrior:25:25:-19|tGlyph of Bloodrage", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+104);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorwarrior:25:25:-19|tGlyph of Charge", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+105);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorwarrior:25:25:-19|tGlyph of Mocking Blow", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+106);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorwarrior:25:25:-19|tGlyph of Thunder Clap", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+107);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorwarrior:25:25:-19|tGlyph of Enduring Victory", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+108);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorwarrior:25:25:-19|tGlyph of Command", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+109);
                        break;
                    case CLASS_PALADIN:
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorpaladin:25:25:-19|tGlyph of Blessing of Might", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+110);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorpaladin:25:25:-19|tGlyph of Blessing of Kings", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+111);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorpaladin:25:25:-19|tGlyph of Blessing of Wisdom", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+112);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorpaladin:25:25:-19|tGlyph of Lay on Hands", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+113);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorpaladin:25:25:-19|tGlyph of Sense Undead", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+114);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorpaladin:25:25:-19|tGlyph of the Wise", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+115);
                        break;
                    case CLASS_HUNTER:
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorhunter:25:25:-19|tGlyph of Revive Pet", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+116);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorhunter:25:25:-19|tGlyph of Mend Pet", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+117);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorhunter:25:25:-19|tGlyph of Feign Death", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+118);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorhunter:25:25:-19|tGlyph of Possessed Strength", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+119);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorhunter:25:25:-19|tGlyph of the Pack", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+120);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorhunter:25:25:-19|tGlyph of Scare Beast", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+121);
                        break;
                    case CLASS_ROGUE:
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorrogue:25:25:-19|tGlyph of Pick Pocket", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+122);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorrogue:25:25:-19|tGlyph of Distract", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+123);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorrogue:25:25:-19|tGlyph of Pick Lock", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+124);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorrogue:25:25:-19|tGlyph of Safe Fall", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+125);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorrogue:25:25:-19|tGlyph of Blurred Speed", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+126);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorrogue:25:25:-19|tGlyph of Vanish", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+127);
                        break;
                    case CLASS_PRIEST:
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorpriest:25:25:-19|tGlyph of Fading", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+128);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorpriest:25:25:-19|tGlyph of Levitate", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+129);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorpriest:25:25:-19|tGlyph of Fortitude", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+130);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorpriest:25:25:-19|tGlyph of Shadow Protection", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+131);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorpriest:25:25:-19|tGlyph of Shackle Undead", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+132);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorpriest:25:25:-19|tGlyph of Shadowfiend", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+133);
                        break;
                    case CLASS_DEATH_KNIGHT:
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minordeathknight:25:25:-19|tGlyph of Blood Tap", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+134);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minordeathknight:25:25:-19|tGlyph of Death's Embrace", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+135);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minordeathknight:25:25:-19|tGlyph of Horn of Winter", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+136);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minordeathknight:25:25:-19|tGlyph of Corpse Explosion", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+137);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minordeathknight:25:25:-19|tGlyph of Pestilence", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+138);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minordeathknight:25:25:-19|tGlyph of Raise Dead", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+139);
                        break;
                    case CLASS_SHAMAN:
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorshaman:25:25:-19|tGlyph of Thunderstorm", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+140);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorshaman:25:25:-19|tGlyph of Water Breathing", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+141);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorshaman:25:25:-19|tGlyph of Astral Recall", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+142);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorshaman:25:25:-19|tGlyph of Renewed Life", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+143);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorshaman:25:25:-19|tGlyph of Water Shield", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+144);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorshaman:25:25:-19|tGlyph of Water Walking", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+145);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorshaman:25:25:-19|tGlyph of Ghost Wolf", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+146);
                        break;
                    case CLASS_MAGE:
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minormage:25:25:-19|tGlyph of Arcane Intellect", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+147);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minormage:25:25:-19|tGlyph of Fire Ward", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+148);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minormage:25:25:-19|tGlyph of Frost Armor", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+149);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minormage:25:25:-19|tGlyph of Frost Ward", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+150);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minormage:25:25:-19|tGlyph of the Penguin", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+151);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minormage:25:25:-19|tGlyph of the Bear Cub", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+152);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minormage:25:25:-19|tGlyph of Slow Fall", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+153);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minormage:25:25:-19|tGlyph of Blast Wave", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+154);
                        break;
                    case CLASS_WARLOCK:
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorwarlock:25:25:-19|tGlyph of Unending Breath", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+155);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorwarlock:25:25:-19|tGlyph of Drain Soul", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+156);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorwarlock:25:25:-19|tGlyph of Kilrogg", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+157);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorwarlock:25:25:-19|tGlyph of Curse of Exhaustion", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+158);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorwarlock:25:25:-19|tGlyph of Enslave Demon", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+159);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minorwarlock:25:25:-19|tGlyph of Souls", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+160);
                        break;
                    case CLASS_DRUID:
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minordruid:25:25:-19|tGlyph of Aquatic Form", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+161);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minordruid:25:25:-19|tGlyph of Unburdened Rebirth", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+162);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minordruid:25:25:-19|tGlyph of Thorns", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+163);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minordruid:25:25:-19|tGlyph of Challenging Roar", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+164);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minordruid:25:25:-19|tGlyph of the Wild", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+165);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minordruid:25:25:-19|tGlyph of Dash", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+166);
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "|TInterface\\icons\\inv_glyph_minordruid:25:25:-19|tGlyph of Typhoon", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH+167);
                        break;
                }

                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH);
                SendGossipMenuFor(player, ASSISTANT_GOSSIP_TEXT, creature->GetGUID());
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
