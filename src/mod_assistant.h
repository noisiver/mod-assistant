#ifndef MOD_ASSISTANT_H
#define MOD_ASSISTANT_H

#include "Chat.h"
#include "Config.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedGossip.h"

enum
{
    ASSISTANT_GOSSIP_HEIRLOOM        = 100,
    ASSISTANT_GOSSIP_GLYPH           = 200,
    ASSISTANT_GOSSIP_GEM             = 400,
    ASSISTANT_GOSSIP_ELIXIRS         = 500,
    ASSISTANT_GOSSIP_FOOD            = 600,
    ASSISTANT_GOSSIP_CONTAINER       = 700,
    ASSISTANT_GOSSIP_FLIGHT_PATHS    = 800,
    ASSISTANT_GOSSIP_UTILITIES       = 900,
    ASSISTANT_GOSSIP_PROFESSIONS     = 1000,
    ASSISTANT_GOSSIP_INSTANCES       = 1100,

    ASSISTANT_GOSSIP_TEXT            = 48,

    ASSISTANT_VENDOR_HEIRLOOM_WEAPON = 9000000,
    ASSISTANT_VENDOR_HEIRLOOM_ARMOR  = 9000001,
    ASSISTANT_VENDOR_HEIRLOOM_OTHER  = 9000002,
    ASSISTANT_VENDOR_GLYPH           = 9000003,
    ASSISTANT_VENDOR_GEM             = 9000023,
    ASSISTANT_VENDOR_ELIXIR          = 9000030,
    ASSISTANT_VENDOR_FOOD            = 9000032,
    ASSISTANT_VENDOR_CONTAINER       = 9000033,

    PROFESSION_LEVEL_APPRENTICE      = 75,
    PROFESSION_LEVEL_JOURNEYMAN      = 150,
    PROFESSION_LEVEL_EXPERT          = 225,
    PROFESSION_LEVEL_ARTISAN         = 300,
    PROFESSION_LEVEL_MASTER          = 375,
    PROFESSION_LEVEL_GRAND_MASTER    = 450,

    INSTANCE_TYPE_HEROIC             = 0,
    INSTANCE_TYPE_RAID               = 1,

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

#define GOSSIP_HEIRLOOMS "I want heirlooms"
#define GOSSIP_HEIRLOOMS_WEAPONS "I want weapons"
#define GOSSIP_HEIRLOOMS_ARMOR "I want armor"
#define GOSSIP_HEIRLOOMS_OTHER "I want something else"

#define GOSSIP_GLYPHS "I want glyphs"
#define GOSSIP_GLYPHS_MAJOR "I want some major glyphs"
#define GOSSIP_GLYPHS_MINOR "I want some minor glyphs"

#define GOSSIP_GEMS "I want gems"
#define GOSSIP_GEMS_META "I want some meta gems"
#define GOSSIP_GEMS_RED "I want some red gems"
#define GOSSIP_GEMS_BLUE "I want some blue gems"
#define GOSSIP_GEMS_YELLOW "I want some yellow gems"
#define GOSSIP_GEMS_PURPLE "I want some purple gems"
#define GOSSIP_GEMS_GREEN "I want some green gems"
#define GOSSIP_GEMS_ORANGE "I want some orange gems"

#define GOSSIP_ELIXIRS "I want elixirs"
#define GOSSIP_ELIXIRS_BATTLE "I want some battle elixirs"
#define GOSSIP_ELIXIRS_GUARDIAN "I want some guardian elixirs"

#define GOSSIP_FOOD "I want food"

#define GOSSIP_CONTAINERS "I want containers"

#define GOSSIP_UTILITIES "I want utilities"
#define GOSSIP_UTILITIES_NAME "I want to change my name"
#define GOSSIP_UTILITIES_APPEARANCE "I want to change my appearance"
#define GOSSIP_UTILITIES_RACE "I want to change my race"
#define GOSSIP_UTILITIES_FACTION "I want to change my faction"
#define GOSSIP_UTILITIES_IN_PROGRESS "You must complete the previously activated feature before trying to perform another."
#define GOSSIP_UTILITIES_DONE "You can now log out to continue using the activated feature."

#define GOSSIP_FLIGHT_PATHS "I want to unlock flight paths"
#define GOSSIP_FLIGHT_PATHS_KALIMDOR_EASTERN_KINGDOMS "Kalimdor & Eastern Kingdoms"
#define GOSSIP_FLIGHT_PATHS_OUTLAND "Outland"
#define GOSSIP_FLIGHT_PATHS_NORTHREND "Northrend"

#define GOSSIP_PROFESSIONS "I want help with my professions"
#define GOSSIP_PROFESSIONS_CHOOSE "I want help with my skill in"
#define GOSSIP_PROFESSIONS_FIRST_AID "First Aid"
#define GOSSIP_PROFESSIONS_BLACKSMITHING "Blacksmithing"
#define GOSSIP_PROFESSIONS_LEATHERWORKING "Leatherworking"
#define GOSSIP_PROFESSIONS_ALCHEMY "Alchemy"
#define GOSSIP_PROFESSIONS_HERBALISM "Herbalism"
#define GOSSIP_PROFESSIONS_COOKING "Cooking"
#define GOSSIP_PROFESSIONS_MINING "Mining"
#define GOSSIP_PROFESSIONS_TAILORING "Tailoring"
#define GOSSIP_PROFESSIONS_ENGINEERING "Engineering"
#define GOSSIP_PROFESSIONS_ENCHANTING "Enchanting"
#define GOSSIP_PROFESSIONS_FISHING "Fishing"
#define GOSSIP_PROFESSIONS_SKINNING "Skinning"
#define GOSSIP_PROFESSIONS_INSCRIPTION "Inscription"
#define GOSSIP_PROFESSIONS_JEWELCRAFTING "Jewelcrafting"

#define GOSSIP_INSTANCES "I want to reset instances"
#define GOSSIP_INSTANCES_HEROIC "I want to reset heroic dungeons"
#define GOSSIP_INSTANCES_RAID "I want to reset raids"
#define GOSSIP_INSTANCES_PLAYER "Just for me"
#define GOSSIP_INSTANCES_GROUP "For my entire group"
#define GOSSIP_INSTANCES_HEROIC_RESET "All heroic dungeons have been reset."
#define GOSSIP_INSTANCES_HEROIC_GROUP_RESET "All of your groups heroic dungeons have been reset."
#define GOSSIP_INSTANCES_RAID_RESET "All raids have been reset."
#define GOSSIP_INSTANCES_RAID_GROUP_RESET "All of your groups raids have been reset."

#define GOSSIP_CONTINUE_TRANSACTION "Do you wish to continue the transaction?"
#define GOSSIP_PREVIOUS_PAGE "Previous Page"

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
    bool ElixirsEnabled;
    bool FoodEnabled;
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

    // Instances
    bool HeroicInstanceEnabled;
    uint32 HeroicInstanceCost;
    bool RaidInstanceEnabled;
    uint32 RaidInstanceCost;

    bool CanResetInstances(Player* /*player*/);
    bool HasSavedInstances(Player* /*player*/, uint8 /*type*/);
    void ResetInstances(Player* /*player*/, uint8 /*type*/);
};

#endif
