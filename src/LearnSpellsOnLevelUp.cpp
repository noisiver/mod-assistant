#include "Player.h"
#include "Config.h"

#include "AssistantData.h"

class LearnSpellsOnLevelUp : public PlayerScript
{
    public:
        LearnSpellsOnLevelUp() : PlayerScript("LearnSpellsOnLevelUp") { }

        void OnLogin(Player* player) override
        {
            if (sConfigMgr->GetBoolDefault("Assistant.Spells.OnLogin", 0))
                LearnAllSpells(player);
        }

        void OnLevelChanged(Player* player, uint8 oldLevel) override
        {
            if (sConfigMgr->GetBoolDefault("Assistant.Spells.OnLevelUp", 0))
                LearnAllSpells(player);
        }

    private:
        void LearnAllSpells(Player* player)
        {
            if (!sConfigMgr->GetBoolDefault("Assistant.Spells.Enabled", 0))
                return;

            if (sConfigMgr->GetBoolDefault("Assistant.Spells.Class", 0))
                LearnSpellsForNewLevel(player);

            if (sConfigMgr->GetBoolDefault("Assistant.Spells.Talent", 0))
                LearnTalentRanksForNewLevel(player);

            if (sConfigMgr->GetBoolDefault("Assistant.Spells.Proficiency", 0))
                LearnProficienciesForNewLevel(player);

            if (sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Enabled", 0))
                LearnMountsForNewLevel(player);

            if (sConfigMgr->GetBoolDefault("Assistant.Spells.MaxSkill.Enabled", 0))
                MaxAllWeaponSkills(player);
        }

        void LearnSpellsForNewLevel(Player* player)
        {
        }

        void LearnTalentRanksForNewLevel(Player* player)
        {
            for (int i = 0; i < assistantData->GetTalentRankCount(); i++)
            {
                if (assistantData->GetTalentRanks()[i].ClassId == player->getClass())
                    if (player->getLevel() >= assistantData->GetTalentRanks()[i].RequiredLevel)
                        if (player->HasSpell(assistantData->GetTalentRanks()[i].RequiredSpellId))
                            if (!player->HasSpell(assistantData->GetTalentRanks()[i].SpellId))
                                player->learnSpell(assistantData->GetTalentRanks()[i].SpellId);
            }
        }

        void LearnProficienciesForNewLevel(Player* player)
        {
            for (int i = 0; i < assistantData->GetProficiencyCount(); i++)
            {
                if (assistantData->GetProficiencies()[i].ClassId == player->getClass())
                    if (player->getLevel() >= assistantData->GetProficiencies()[i].RequiredLevel)
                        if (!player->HasSpell(assistantData->GetProficiencies()[i].SpellId))
                            player->learnSpell(assistantData->GetProficiencies()[i].SpellId);
            }
        }

        void MaxAllWeaponSkills(Player* player)
        {
            if (player->getLevel() <= sConfigMgr->GetIntDefault("Assistant.Spells.MaxSkill.MaxLevel", 60))
                player->UpdateSkillsToMaxSkillsForLevel();
        }

        void LearnMountsForNewLevel(Player* player)
        {
            for (int i = 0; i < assistantData->GetMountsCount(); i++)
            {
                if ((assistantData->GetMounts()[i].SpellId == 33388 && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Apprentice", 0)) || 
                    (assistantData->GetMounts()[i].SpellId == 33391 && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Journeyman", 0)) || 
                    (assistantData->GetMounts()[i].SpellId == 34090 && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Expert", 0)) || 
                    (assistantData->GetMounts()[i].SpellId == 34091 && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Artisan", 0)) || 
                    (assistantData->GetMounts()[i].SpellId == 54197 && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.ColdWeather", 0)) || 
                    (assistantData->GetMounts()[i].RequiresQuest == 1 && !sConfigMgr->GetBoolDefault("Assistant.Spells.Quest", 0)))
                    continue;

                if (assistantData->GetMounts()[i].RaceId == -1 || assistantData->GetMounts()[i].RaceId == player->getRace())
                    if (assistantData->GetMounts()[i].ClassId == -1 || assistantData->GetMounts()[i].ClassId == player->getClass())
                        if (assistantData->GetMounts()[i].TeamId == -1 || assistantData->GetMounts()[i].TeamId == player->GetTeamId())
                            if (assistantData->GetMounts()[i].RequiredSpellId == -1 || player->HasSpell(assistantData->GetMounts()[i].RequiredSpellId))
                                if (player->getLevel() >= assistantData->GetMounts()[i].RequiredLevel)
                                    if (!player->HasSpell(assistantData->GetMounts()[i].SpellId))
                                        player->learnSpell(assistantData->GetMounts()[i].SpellId);
            }
        }

    private:
        AssistantData* assistantData = new AssistantData();
};

void AddLearnSpellsOnLevelUpScripts()
{
    new LearnSpellsOnLevelUp();
}
