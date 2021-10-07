#include "Player.h"
#include "Config.h"

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

void AddDynamicRatesScripts()
{
    new DynamicExperience();
    new DynamicReputation();
}
