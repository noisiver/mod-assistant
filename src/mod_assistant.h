#ifndef MOD_ASSISTANT_H
#define MOD_ASSISTANT_H

#include "Chat.h"
#include "Config.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedGossip.h"

enum GossipId
{
    ASSISTANT_GOSSIP_TEXT            = 48,
    ASSISTANT_GOSSIP_HEIRLOOM        = 100,
    ASSISTANT_GOSSIP_GLYPH           = 200,
    ASSISTANT_GOSSIP_GEM             = 400,
    ASSISTANT_GOSSIP_CONTAINER       = 500,
    ASSISTANT_GOSSIP_FLIGHT_PATHS    = 600,
    ASSISTANT_GOSSIP_UTILITIES       = 700,
    ASSISTANT_GOSSIP_PROFESSIONS     = 800,
};

enum VendorId
{
    ASSISTANT_VENDOR_HEIRLOOM_WEAPON = 9000000,
    ASSISTANT_VENDOR_HEIRLOOM_ARMOR  = 9000001,
    ASSISTANT_VENDOR_HEIRLOOM_OTHER  = 9000002,
    ASSISTANT_VENDOR_GLYPH           = 9000003,
    ASSISTANT_VENDOR_GEM             = 9000023,
    ASSISTANT_VENDOR_CONTAINER       = 9000030,
};

enum Profession
{
    PROFESSION_LEVEL_APPRENTICE      = 75,
    PROFESSION_LEVEL_JOURNEYMAN      = 150,
    PROFESSION_LEVEL_EXPERT          = 225,
    PROFESSION_LEVEL_ARTISAN         = 300,
    PROFESSION_LEVEL_MASTER          = 375,
    PROFESSION_LEVEL_GRAND_MASTER    = 450,
};

enum Glyph
{
    GLYPH_WARRIOR                    = 0,
    GLYPH_PALADIN                    = 1,
    GLYPH_HUNTER                     = 2,
    GLYPH_ROGUE                      = 3,
    GLYPH_PRIEST                     = 4,
    GLYPH_DEATH_KNIGHT               = 5,
    GLYPH_SHAMAN                     = 6,
    GLYPH_MAGE                       = 7,
    GLYPH_WARLOCK                    = 8,
    GLYPH_DRUID                      = 9
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
    bool HeirloomsEnabled;
    bool GlyphsEnabled;
    bool GemsEnabled;
    bool ContainersEnabled;

    uint32 GetGlyphId(uint32 /*id*/, bool /*major*/);

    // Utilities
    bool UtilitiesEnabled;
    uint32 NameChangeCost;
    uint32 CustomizeCost;
    uint32 RaceChangeCost;
    uint32 FactionChangeCost;

    bool HasLoginFlag(Player* /*player*/);
    void SetLoginFlag(Player* /*player*/, AtLoginFlags /*flag*/, uint32 /*cost*/);

    // Flight Paths
    bool FlightPathsEnabled[EXPANSION_WRATH_OF_THE_LICH_KING + 1];
    uint32 FlightPathsRequiredLevel[EXPANSION_WRATH_OF_THE_LICH_KING + 1];
    uint32 FlightPathsCost[EXPANSION_WRATH_OF_THE_LICH_KING + 1];

    bool CanUnlockFlightPaths(Player* /*player*/);
    std::vector<int> GetAvailableFlightPaths(Player* /*player*/, uint8 /*expansion*/);
    bool HasAvailableFlightPaths(Player* /*player*/, uint8 /*expansion*/);
    void UnlockFlightPaths(Player* /*player*/, uint8 /*expansion*/);

    // Professions
    bool ApprenticeProfessionEnabled;
    uint32 ApprenticeProfessionCost;
    bool JourneymanProfessionEnabled;
    uint32 JourneymanProfessionCost;
    bool ExpertProfessionEnabled;
    uint32 ExpertProfessionCost;
    bool ArtisanProfessionEnabled;
    uint32 ArtisanProfessionCost;
    bool MasterProfessionEnabled;
    uint32 MasterProfessionCost;
    bool GrandMasterProfessionEnabled;
    uint32 GrandMasterProfessionCost;

    void ListProfession(Player* /*player*/, uint32 /*id*/);
    void SetProfession(Player* /*player*/, uint32 /*id*/);
    bool HasValidProfession(Player* /*player*/);
    bool IsValidProfession(Player* /*player*/, uint32 /*id*/);
    uint32 GetProfessionCost(Player* /*player*/, uint32 /*id*/);
};

#endif
