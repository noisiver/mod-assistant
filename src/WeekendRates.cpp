#include "Player.h"
#include "Config.h"

time_t t = time(NULL);
tm* now = localtime(&t);

class WeekendRates : public PlayerScript
{
    public:
        WeekendRates() : PlayerScript("WeekendRates") { }

        void OnGiveXP(Player* player, uint32& amount, Unit* /*victim*/) override
        {
            if (sConfigMgr->GetBoolDefault("Assistant.Weekend.Rate.Enabled", 0))
            {
                if (isWeekend())
                {
                    amount *= sConfigMgr->GetIntDefault("Assistant.Weekend.Rate.Multiplier", 1);
                }
            }
        }

        void OnReputationChange(Player* player, uint32 /*factionId*/, int32& standing, bool /*incremental*/) override
        {
            if (sConfigMgr->GetBoolDefault("Assistant.Weekend.Rate.Enabled", 0))
            {
                if (isWeekend())
                {
                    standing *= sConfigMgr->GetIntDefault("Assistant.Weekend.Rate.Multiplier", 1);
                }
            }
        }

        void OnLogin(Player* player) override
        {
            if (isWeekend())
            {
                ChatHandler(player->GetSession()).PSendSysMessage("The weekend bonus is active, giving you twice the experience and reputation!");
            }
        }

    private:
        bool isWeekend()
        {
            if (now->tm_wday == 5 /*Friday*/ || now->tm_wday == 6 /*Saturday*/ || now->tm_wday == 0 /*Sunday*/)
            {
                return true;
            }

            return false;
        }
};

void AddWeekendRatesScripts()
{
    new WeekendRates();
}
