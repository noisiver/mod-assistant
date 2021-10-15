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
        }

        void LearnProficienciesForNewLevel(Player* player)
        {
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
                int32 raceId = assistantData->GetMounts()[i].RaceId;
                uint32 spellId = assistantData->GetMounts()[i].SpellId;
                uint32 requiredLevel = assistantData->GetMounts()[i].RequiredLevel;
                uint32 requiredSpellId = assistantData->GetMounts()[i].RequiredSpellId;

                if (((spellId == 33388 || requiredSpellId == 33388) && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Apprentice", 0)) || 
                    ((spellId == 33391 || requiredSpellId == 33391) && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Journeyman", 0)) || 
                    ((spellId == 34090 || requiredSpellId == 34090) && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Expert", 0)) || 
                    ((spellId == 34091 || requiredSpellId == 34091) && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.Artisan", 0)) || 
                    (spellId == 54197 && !sConfigMgr->GetBoolDefault("Assistant.Spells.Riding.ColdWeather", 0)))
                    break;

                if (raceId == -1 || raceId == player->getRace())
                    if (requiredSpellId == -1 || player->HasSpell(requiredSpellId))
                        if (player->getLevel() >= requiredLevel)
                            if (!player->HasSpell(spellId))
                                player->learnSpell(spellId);
            }
        }

    private:
        AssistantData* assistantData = new AssistantData();
};

void AddLearnSpellsOnLevelUpScripts()
{
    new LearnSpellsOnLevelUp();
}
