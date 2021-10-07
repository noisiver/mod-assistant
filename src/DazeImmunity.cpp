#include "Player.h"
#include "Config.h"

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

void AddDazeImmunityScripts()
{
    new DazeImmunity();
}
