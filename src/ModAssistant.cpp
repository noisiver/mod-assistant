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
            }

            if (sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Enabled", 0) && sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.OnLogin", 0))
            {
                LearnMountForNewLevel(player);
            }

            if (sConfigMgr->GetBoolDefault("Assistant.Spells.MaxSkill.Enabled", 0))
            {
                MaxAllWeaponSkill(player);
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
            }

            if (sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Enabled", 0) && sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.OnLevelUp", 0))
            {
                LearnMountForNewLevel(player);
            }

            if (sConfigMgr->GetBoolDefault("Assistant.Spells.MaxSkill.Enabled", 0))
            {
                MaxAllWeaponSkill(player);
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
    new DynamicExperience();
    new DynamicReputation();
}
