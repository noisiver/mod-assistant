#include "Player.h"
#include "Config.h"

class WeekendBonus : public PlayerScript
{
    public:
        WeekendBonus() : PlayerScript("WeekendBonus") { }

        void OnGiveXP(Player* player, uint32& amount, Unit* /*victim*/) override
        {
            if (sConfigMgr->GetBoolDefault("Assistant.Rate.Weekend.Enabled", 0))
                if (localtime(&t)->tm_wday == 5 /*Friday*/ || localtime(&t)->tm_wday == 6 /*Saturday*/ || localtime(&t)->tm_wday == 0 /*Sunday*/)
                    amount *= 2;
        }

        void OnReputationChange(Player* player, uint32 /*factionId*/, int32& standing, bool /*incremental*/) override
        {
            if (sConfigMgr->GetBoolDefault("Assistant.Rate.Weekend.Enabled", 0))
                if (localtime(&t)->tm_wday == 5 /*Friday*/ || localtime(&t)->tm_wday == 6 /*Saturday*/ || localtime(&t)->tm_wday == 0 /*Sunday*/)
                    standing *= 2;
        }

        void OnLogin(Player* player) override
        {
            if (sConfigMgr->GetBoolDefault("Assistant.Rate.Weekend.Enabled", 0))
                if (localtime(&t)->tm_wday == 5 /*Friday*/ || localtime(&t)->tm_wday == 6 /*Saturday*/ || localtime(&t)->tm_wday == 0 /*Sunday*/)
                    ChatHandler(player->GetSession()).PSendSysMessage("The weekend bonus is active, doubling the experience and reputation received!");
        }

    private:
        time_t t = time(NULL);
};

void AddWeekendBonusScripts()
{
    new WeekendBonus();
}
