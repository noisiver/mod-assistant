#ifndef MOD_ASSISTANT_H
#define MOD_ASSISTANT_H

#include "Chat.h"
#include "Config.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedGossip.h"

enum GossipId
{
    ASSISTANT_GOSSIP_TEXT = 48,
    ASSISTANT_GOSSIP_HEIRLOOM = 100,
    ASSISTANT_GOSSIP_GLYPH = 200,
    ASSISTANT_GOSSIP_GEM = 400,
    ASSISTANT_GOSSIP_CONTAINER = 500,
    ASSISTANT_GOSSIP_FLIGHT_PATHS = 600,
    ASSISTANT_GOSSIP_UTILITIES = 700,
    ASSISTANT_GOSSIP_PROFESSIONS = 800,
};

enum VendorId
{
    ASSISTANT_VENDOR_HEIRLOOM_WEAPON = 9000000,
    ASSISTANT_VENDOR_HEIRLOOM_ARMOR = 9000001,
    ASSISTANT_VENDOR_HEIRLOOM_OTHER = 9000002,
    ASSISTANT_VENDOR_GLYPH = 9000003,
    ASSISTANT_VENDOR_GEM = 9000023,
    ASSISTANT_VENDOR_CONTAINER = 9000030,
};

enum Profession
{
    PROFESSION_LEVEL_APPRENTICE = 75,
    PROFESSION_LEVEL_JOURNEYMAN = 150,
    PROFESSION_LEVEL_EXPERT = 225,
    PROFESSION_LEVEL_ARTISAN = 300,
    PROFESSION_LEVEL_MASTER = 375,
    PROFESSION_LEVEL_GRAND_MASTER = 450,
};

class Assistant : public CreatureScript, WorldScript
{
public:
    Assistant();

    // CreatureScript
    bool OnGossipHello(Player* /*player*/, Creature* /*creature*/) override;
    bool OnGossipSelect(Player* /*player*/, Creature* /*creature*/, uint32 /*sender*/, uint32 /*action*/) override;

    // WorldScript
    void OnAfterConfigLoad(bool /*reload*/) override;

private:
    bool HasLoginFlag(Player* /*player*/);
    bool HasValidProfession(Player* /*player*/);
    bool IsValidProfession(Player* /*player*/, uint32 /*skillId*/);
    int GetProfessionCost(Player* /*player*/, uint32 /*skill*/);
    bool CanUnlockFlightPaths(Player* /*player*/);
    void UnlockFlightPaths(Player* /*player*/, int /*map*/);

    bool EnableHeirlooms;
    bool EnableGlyphs;
    bool EnableGems;
    bool EnableContainers;

    // Utilities
    bool EnableUtilities;
    uint32 CostNameChange;
    uint32 CostCustomization;
    uint32 CostRaceChange;
    uint32 CostFactionChange;

    // Flight Paths
    bool EnableFlightPaths[3];
    uint32 RequiredLevelForFlightPaths[3];
    uint32 CostFlightPaths[3];

    // Professions
    bool EnableApprenticeProfession;
    bool EnableJourneymanProfession;
    bool EnableExpertProfession;
    bool EnableArtisanProfession;
    bool EnableMasterProfession;
    bool EnableGrandMasterProfession;
    uint32 CostApprenticeProfession;
    uint32 CostJourneymanProfession;
    uint32 CostExpertProfession;
    uint32 CostArtisanProfession;
    uint32 CostMasterProfession;
    uint32 CostGrandMasterProfession;
};

#endif
