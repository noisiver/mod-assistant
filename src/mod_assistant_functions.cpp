#include "mod_assistant.h"

uint32 Assistant::GetGlyphId(uint32 id, bool major)
{
    return (major ? ASSISTANT_VENDOR_GLYPH : ASSISTANT_VENDOR_GLYPH + 10) + id;
}

bool Assistant::HasLoginFlag(Player* player)
{
    if (player->HasAtLoginFlag(AT_LOGIN_RENAME) || player->HasAtLoginFlag(AT_LOGIN_CUSTOMIZE) || player->HasAtLoginFlag(AT_LOGIN_CHANGE_RACE) || player->HasAtLoginFlag(AT_LOGIN_CHANGE_FACTION))
    {
        return true;
    }

    return false;
}

void Assistant::SetLoginFlag(Player* player, AtLoginFlags flag, uint32 cost)
{
    if (HasLoginFlag(player))
    {
        ChatHandler(player->GetSession()).PSendSysMessage(GOSSIP_UTILITIES_IN_PROGRESS);
        return;
    }

    player->ModifyMoney(-cost);
    player->SetAtLoginFlag(flag);
    ChatHandler(player->GetSession()).PSendSysMessage(GOSSIP_UTILITIES_DONE);
}

bool Assistant::CanUnlockFlightPaths(Player* player)
{
    if ((FlightPathsEnabled[EXPANSION_CLASSIC] && player->GetLevel() >= FlightPathsRequiredLevel[EXPANSION_CLASSIC] && HasAvailableFlightPaths(player, EXPANSION_CLASSIC)) || (FlightPathsEnabled[EXPANSION_THE_BURNING_CRUSADE] && player->GetLevel() >= FlightPathsRequiredLevel[EXPANSION_THE_BURNING_CRUSADE] && HasAvailableFlightPaths(player, EXPANSION_THE_BURNING_CRUSADE)) || (FlightPathsEnabled[EXPANSION_WRATH_OF_THE_LICH_KING] && player->GetLevel() >= FlightPathsRequiredLevel[EXPANSION_WRATH_OF_THE_LICH_KING] && HasAvailableFlightPaths(player, EXPANSION_WRATH_OF_THE_LICH_KING)))
    {
        return true;
    }

    return false;
}

std::vector<int> Assistant::GetAvailableFlightPaths(Player* player, uint8 expansion)
{
    std::vector<int> flightpaths;

    switch (expansion)
    {
    case EXPANSION_CLASSIC:
        flightpaths.push_back(79); // Marshal's Refuge, Un'Goro Crater
        flightpaths.push_back(80); // Ratchet, The Barrens
        flightpaths.push_back(166); // Emerald Sanctuary, Felwood
        flightpaths.push_back(179); // Mudsprocket, Dustwallow Marsh
        flightpaths.push_back(205); // Hatchet Hills, Ghostlands
        flightpaths.push_back(383); // Thondoril River, Western Plaguelands

        if (player->GetTeamId() == TEAM_ALLIANCE)
        {
            flightpaths.push_back(2); // Stormwind City
            flightpaths.push_back(4); // Sentinel Hill, Westfall
            flightpaths.push_back(5); // Lakeshire, Redridge Mountains
            flightpaths.push_back(6); // Ironforge, Dun Morogh
            flightpaths.push_back(7); // Menethil Harbor, Wetlands
            flightpaths.push_back(8); // Thelsamar, Loch Modan
            flightpaths.push_back(12); // Darkshire, Duskwood
            flightpaths.push_back(14); // Southshore, Hillsbrad Foothills
            flightpaths.push_back(16); // Refuge Pointe, Arathi Highlands
            flightpaths.push_back(19); // Booty Bay, Stranglethorn Vale
            flightpaths.push_back(26); // Auberdine, Darkshore
            flightpaths.push_back(27); // Rut'theran Village, Teldrassil
            flightpaths.push_back(28); // Astranaar, Ashenvale
            flightpaths.push_back(31); // Thalanaar, Feralas
            flightpaths.push_back(32); // Theramore Isle, Dustwallow Marsh
            flightpaths.push_back(33); // Stonetalon Peak, Stonetalon Mountains
            flightpaths.push_back(37); // Nijel's Point, Desolace
            flightpaths.push_back(38); // Shadowprey Village, Desolace
            flightpaths.push_back(39); // Gadgetzan, Tanaris
            flightpaths.push_back(41); // Feathermoon Stronghold, Feralas
            flightpaths.push_back(43); // Aerie Peak, The Hinterlands
            flightpaths.push_back(45); // Nethergarde Keep, Blasted Lands
            flightpaths.push_back(49); // Moonglade
            flightpaths.push_back(52); // Everlook, Winterspring
            flightpaths.push_back(62); // Nighthaven, Moonglade
            flightpaths.push_back(64); // Talrendis Point, Azshara
            flightpaths.push_back(65); // Talonbranch Glade, Felwood
            flightpaths.push_back(66); // Chillwind Camp, Western Plaguelands
            flightpaths.push_back(67); // Light's Hope Chapel, Eastern Plaguelands
            flightpaths.push_back(71); // Morgan's Vigil, Burning Steppes
            flightpaths.push_back(73); // Cenarion Hold, Silithus
            flightpaths.push_back(74); // Thorium Point, Searing Gorge
            flightpaths.push_back(93); // Blood Watch, Bloodmyst Isle
            flightpaths.push_back(94); // The Exodar
            flightpaths.push_back(167); // Forest Song, Ashenvale
            flightpaths.push_back(195); // Rebel Camp, Stranglethorn Vale
        }
        else if (player->GetTeamId() == TEAM_HORDE)
        {
            flightpaths.push_back(10); // The Sepulcher, Silverpine Forest
            flightpaths.push_back(11); // Undercity
            flightpaths.push_back(13); // Tarren Mill, Hillsbrad Foothills
            flightpaths.push_back(17); // Hammerfall, Arathi Highlands
            flightpaths.push_back(18); // Booty Bay, Stranglethorn Vale
            flightpaths.push_back(20); // Grom'gol, Stranglethorn Vale
            flightpaths.push_back(21); // Kargath, Badlands
            flightpaths.push_back(22); // Thunder Bluff
            flightpaths.push_back(23); // Orgrimmar
            flightpaths.push_back(25); // The Crossroads, The Barrens
            flightpaths.push_back(29); // Sun Rock Retreat, Stonetalon Mountains
            flightpaths.push_back(30); // Freewind Post, Thousand Needles
            flightpaths.push_back(38); // Shadowprey Village, Desolace
            flightpaths.push_back(40); // Gadgetzan, Tanaris
            flightpaths.push_back(42); // Camp Mojache, Feralas
            flightpaths.push_back(44); // Valormok, Azshara
            flightpaths.push_back(48); // Bloodvenom Post, Felwood
            flightpaths.push_back(53); // Everlook, Winterspring
            flightpaths.push_back(55); // Brackenwall Village, Dustwallow Marsh
            flightpaths.push_back(56); // Stonard, Swamp of Sorrows
            flightpaths.push_back(58); // Zoram'gar Outpost, Ashenvale
            flightpaths.push_back(61); // Splintertree Post, Ashenvale
            flightpaths.push_back(63); // Nighthaven, Moonglade
            flightpaths.push_back(68); // Light's Hope Chapel, Eastern Plaguelands
            flightpaths.push_back(69); // Moonglade
            flightpaths.push_back(70); // Flame Crest, Burning Steppes
            flightpaths.push_back(72); // Cenarion Hold, Silithus
            flightpaths.push_back(75); // Thorium Point, Searing Gorge
            flightpaths.push_back(76); // Revantusk Village, The Hinterlands
            flightpaths.push_back(77); // Camp Taurajo, The Barrens
            flightpaths.push_back(82); // Silvermoon City
            flightpaths.push_back(83); // Tranquillien, Ghostlands
            flightpaths.push_back(384); // The Bulwark, Tirisfal Glades
        }
        break;
    case EXPANSION_THE_BURNING_CRUSADE:
        flightpaths.push_back(122); // Area 52, Netherstorm
        flightpaths.push_back(128); // Shattrath City
        flightpaths.push_back(139); // The Stormspire, Netherstorm
        flightpaths.push_back(140); // Altar of Sha'tar, Shadowmoon Valley
        flightpaths.push_back(150); // Cosmowrench, Netherstorm
        flightpaths.push_back(159); // Sanctum of the Stars, Shadowmoon Valley
        flightpaths.push_back(160); // Evergrove, Blade's Edge Mountains
        flightpaths.push_back(213); // Sun's Reach Harbor, Isle of Quel'Danas

        if (player->GetTeamId() == TEAM_ALLIANCE)
        {
            flightpaths.push_back(100); // Honor Hold, Hellfire Peninsula
            flightpaths.push_back(101); // Temple of Telhamat, Hellfire Peninsula
            flightpaths.push_back(117); // Telredor, Zangarmarsh
            flightpaths.push_back(119); // Telaar, Nagrand
            flightpaths.push_back(124); // Wildhammer Stronghold, Shadowmoon Valley
            flightpaths.push_back(125); // Sylvanaar, Blade's Edge Mountains
            flightpaths.push_back(129); // The Dark Portal, Hellfire Peninsula
            flightpaths.push_back(149); // Shatter Point, Hellfire Peninsula
            flightpaths.push_back(156); // Toshley's Station, Blade's Edge Mountains
            flightpaths.push_back(164); // Orebor Harborage, Zangarmarsh
        }
        else if (player->GetTeamId() == TEAM_HORDE)
        {
            flightpaths.push_back(99); // Thrallmar, Hellfire Peninsula
            flightpaths.push_back(102); // Falcon Watch, Hellfire Peninsula
            flightpaths.push_back(118); // Zabra'jin, Zangarmarsh
            flightpaths.push_back(120); // Garadar, Nagrand
            flightpaths.push_back(123); // Shadowmoon Village, Shadowmoon Valley
            flightpaths.push_back(126); // Thunderlord Stronghold, Blade's Edge Mountains
            flightpaths.push_back(127); // Stonebreaker Hold, Terokkar Forest
            flightpaths.push_back(130); // The Dark Portal, Hellfire Peninsula
            flightpaths.push_back(141); // Spinebreaker Ridge, Hellfire Peninsula
            flightpaths.push_back(142); // Reaver's Fall, Hellfire Peninsula
            flightpaths.push_back(151); // Swamprat Post, Zangarmarsh
            flightpaths.push_back(163); // Mok'Nathal Village, Blade's Edge Mountains
        }
        break;
    case EXPANSION_WRATH_OF_THE_LICH_KING:
        flightpaths.push_back(226); // Transitus Shield, Coldarra
        flightpaths.push_back(252); // Wyrmrest Temple, Dragonblight
        flightpaths.push_back(289); // Amber Ledge, Borean Tundra
        flightpaths.push_back(294); // Moa'ki, Dragonblight
        flightpaths.push_back(295); // Kamagua, Howling Fjord
        flightpaths.push_back(296); // Unu'pe, Borean Tundra
        flightpaths.push_back(304); // The Argent Stand, Zul'Drak
        flightpaths.push_back(305); // Ebon Watch, Zul'Drak
        flightpaths.push_back(306); // Light's Breach, Zul'Drak
        flightpaths.push_back(307); // Zim'Torga, Zul'Drak
        flightpaths.push_back(308); // River's Heart, Sholazar Basin
        flightpaths.push_back(309); // Nesingwary Base Camp, Sholazar Basin
        flightpaths.push_back(310); // Dalaran
        flightpaths.push_back(320); // K3, The Storm Peaks
        flightpaths.push_back(321); // The Frost Hold, The Storm Peaks
        flightpaths.push_back(325); // Death's Rise, Icecrown
        flightpaths.push_back(326); // Ulduar, The Storm Peaks
        flightpaths.push_back(327); // Bouldercrag's Refuge, The Storm Peaks
        flightpaths.push_back(331); // Dubra'Jin, Zul'Drak
        flightpaths.push_back(334); // The Argent Vanguard, Icecrown
        flightpaths.push_back(340); // Argent Tournament Grounds, Icecrown

        if (player->GetTeamId() == TEAM_ALLIANCE)
        {
            flightpaths.push_back(183); // Valgarde Port, Howling Fjord
            flightpaths.push_back(184); // Fort Wildervar, Howling Fjord
            flightpaths.push_back(185); // Westguard Keep, Howling Fjord
            flightpaths.push_back(244); // Wintergarde Keep, Howling Fjord
            flightpaths.push_back(245); // Valiance Keep, Borean Tundra
            flightpaths.push_back(246); // Fizzcrank Airstrip, Borean Tundra
            flightpaths.push_back(247); // Stars' Rest, Dragonblight
            flightpaths.push_back(251); // Fordragon Hold, Dragonblight
            flightpaths.push_back(253); // Amberpine Lodge, Grizzly Hills
            flightpaths.push_back(255); // Westfall Brigade, Grizzly Hills
            flightpaths.push_back(321); // Frosthold, The Storm Peaks
            flightpaths.push_back(336); // Windrunner's Overlook, Crystalsong Forest
        }
        else if (player->GetTeamId() == TEAM_HORDE)
        {
            flightpaths.push_back(190); // New Agamand, Howling Fjord
            flightpaths.push_back(191); // Vengeance Landing, Howling Fjord
            flightpaths.push_back(192); // Camp Winterhoof, Howling Fjord
            flightpaths.push_back(248); // Apothecary Camp, Howling Fjord
            flightpaths.push_back(249); // Camp Oneqwah, Grizzly Hills
            flightpaths.push_back(254); // Venomspite, Dragonblight
            flightpaths.push_back(256); // Agmar's Hammer, Dragonblight
            flightpaths.push_back(257); // Warsong Hold, Borean Tundra
            flightpaths.push_back(258); // Taunka'le Village, Borean Tundra
            flightpaths.push_back(259); // Bor'gorok Outpost, Borean Tundra
            flightpaths.push_back(260); // Kor'koron Vanguard, Dragonbligh
            flightpaths.push_back(323); // Grom'arsh Crash-Site, The Storm Peaks
            flightpaths.push_back(324); // Camp Tunka'lo, The Storm Peaks
            flightpaths.push_back(337); // Sunreaver's Command, Crystalsong Forest
        }
        break;
    }

    return flightpaths;
}

bool Assistant::HasAvailableFlightPaths(Player* player, uint8 expansion)
{
    std::vector<int> flightpaths = GetAvailableFlightPaths(player, expansion);

    if (flightpaths.empty())
    {
        return false;
    }

    for (auto& flightpath : flightpaths)
    {
        if (!player->m_taxi.IsTaximaskNodeKnown(flightpath))
        {
            return true;
        }
    }

    return false;
}

void Assistant::UnlockFlightPaths(Player* player, uint8 expansion)
{
    uint32 cost = FlightPathsCost[expansion];

    std::vector<int> flightpaths = GetAvailableFlightPaths(player, expansion);

    if (flightpaths.empty())
    {
        return;
    }

    for (auto& flightpath : flightpaths)
    {
        player->GetSession()->SendDiscoverNewTaxiNode(flightpath);
    }

    player->ModifyMoney(-cost);
}

void Assistant::ListProfession(Player* player, uint32 id)
{
    if (IsValidProfession(player, id))
    {
        std::string name;
        uint32 menu = 0;
        uint32 cost = GetProfessionCost(player, id);

        switch (id)
        {
        case SKILL_FIRST_AID:
            name = GOSSIP_PROFESSIONS_FIRST_AID;
            menu = ASSISTANT_GOSSIP_PROFESSIONS + 1;
            break;
        case SKILL_BLACKSMITHING:
            name = GOSSIP_PROFESSIONS_BLACKSMITHING;
            menu = ASSISTANT_GOSSIP_PROFESSIONS + 2;
            break;
        case SKILL_LEATHERWORKING:
            name = GOSSIP_PROFESSIONS_LEATHERWORKING;
            menu = ASSISTANT_GOSSIP_PROFESSIONS + 3;
            break;
        case SKILL_ALCHEMY:
            name = GOSSIP_PROFESSIONS_ALCHEMY;
            menu = ASSISTANT_GOSSIP_PROFESSIONS + 4;
            break;
        case SKILL_HERBALISM:
            name = GOSSIP_PROFESSIONS_HERBALISM;
            menu = ASSISTANT_GOSSIP_PROFESSIONS + 5;
            break;
        case SKILL_COOKING:
            name = GOSSIP_PROFESSIONS_COOKING;
            menu = ASSISTANT_GOSSIP_PROFESSIONS + 6;
            break;
        case SKILL_MINING:
            name = GOSSIP_PROFESSIONS_MINING;
            menu = ASSISTANT_GOSSIP_PROFESSIONS + 7;
            break;
        case SKILL_TAILORING:
            name = GOSSIP_PROFESSIONS_TAILORING;
            menu = ASSISTANT_GOSSIP_PROFESSIONS + 8;
            break;
        case SKILL_ENGINEERING:
            name = GOSSIP_PROFESSIONS_ENGINEERING;
            menu = ASSISTANT_GOSSIP_PROFESSIONS + 9;
            break;
        case SKILL_ENCHANTING:
            name = GOSSIP_PROFESSIONS_ENCHANTING;
            menu = ASSISTANT_GOSSIP_PROFESSIONS + 10;
            break;
        case SKILL_FISHING:
            name = GOSSIP_PROFESSIONS_FISHING;
            menu = ASSISTANT_GOSSIP_PROFESSIONS + 11;
            break;
        case SKILL_SKINNING:
            name = GOSSIP_PROFESSIONS_SKINNING;
            menu = ASSISTANT_GOSSIP_PROFESSIONS + 12;
            break;
        case SKILL_INSCRIPTION:
            name = GOSSIP_PROFESSIONS_INSCRIPTION;
            menu = ASSISTANT_GOSSIP_PROFESSIONS + 13;
            break;
        case SKILL_JEWELCRAFTING:
            name = GOSSIP_PROFESSIONS_JEWELCRAFTING;
            menu = ASSISTANT_GOSSIP_PROFESSIONS + 14;
            break;
        }

        AddGossipItemFor(player, GOSSIP_ICON_TRAINER, Acore::StringFormat("{} {}", GOSSIP_PROFESSIONS_CHOOSE, name), GOSSIP_SENDER_MAIN, menu, GOSSIP_CONTINUE_TRANSACTION, cost, false);
    }
}

void Assistant::SetProfession(Player* player, uint32 id)
{
    uint16 maxSkillValue = player->GetPureMaxSkillValue(id);
    uint32 cost = GetProfessionCost(player, id);
    player->SetSkill(id, 0, maxSkillValue, maxSkillValue);
    player->ModifyMoney(-cost);
}

bool Assistant::HasValidProfession(Player* player)
{
    if (IsValidProfession(player, SKILL_FIRST_AID) || IsValidProfession(player, SKILL_BLACKSMITHING) || IsValidProfession(player, SKILL_LEATHERWORKING) || IsValidProfession(player, SKILL_ALCHEMY) || IsValidProfession(player, SKILL_HERBALISM) || IsValidProfession(player, SKILL_COOKING) || IsValidProfession(player, SKILL_MINING) || IsValidProfession(player, SKILL_TAILORING) || IsValidProfession(player, SKILL_ENGINEERING) || IsValidProfession(player, SKILL_ENCHANTING) || IsValidProfession(player, SKILL_FISHING) || IsValidProfession(player, SKILL_SKINNING) || IsValidProfession(player, SKILL_INSCRIPTION) || IsValidProfession(player, SKILL_JEWELCRAFTING))
    {
        return true;
    }

    return false;
}

bool Assistant::IsValidProfession(Player* player, uint32 id)
{
    if (player->HasSkill(id) && ((player->GetPureSkillValue(id) < PROFESSION_LEVEL_APPRENTICE && player->GetPureMaxSkillValue(id) == PROFESSION_LEVEL_APPRENTICE && ApprenticeProfessionEnabled) || (player->GetPureSkillValue(id) < PROFESSION_LEVEL_JOURNEYMAN && player->GetPureMaxSkillValue(id) == PROFESSION_LEVEL_JOURNEYMAN && JourneymanProfessionEnabled) || (player->GetPureSkillValue(id) < PROFESSION_LEVEL_EXPERT && player->GetPureMaxSkillValue(id) == PROFESSION_LEVEL_EXPERT && ExpertProfessionEnabled) || (player->GetPureSkillValue(id) < PROFESSION_LEVEL_ARTISAN && player->GetPureMaxSkillValue(id) == PROFESSION_LEVEL_ARTISAN && ArtisanProfessionEnabled) || (player->GetPureSkillValue(id) < PROFESSION_LEVEL_MASTER && player->GetPureMaxSkillValue(id) == PROFESSION_LEVEL_MASTER && MasterProfessionEnabled) || (player->GetPureSkillValue(id) < PROFESSION_LEVEL_GRAND_MASTER && player->GetPureMaxSkillValue(id) == PROFESSION_LEVEL_GRAND_MASTER && GrandMasterProfessionEnabled)))
    {
        return true;
    }

    return false;
}

uint32 Assistant::GetProfessionCost(Player* player, uint32 id)
{
    if (player->GetPureMaxSkillValue(id) == PROFESSION_LEVEL_APPRENTICE)
    {
        return ApprenticeProfessionCost;
    }
    else if (player->GetPureMaxSkillValue(id) == PROFESSION_LEVEL_JOURNEYMAN)
    {
        return JourneymanProfessionCost;
    }
    else if (player->GetPureMaxSkillValue(id) == PROFESSION_LEVEL_EXPERT)
    {
        return ExpertProfessionCost;
    }
    else if (player->GetPureMaxSkillValue(id) == PROFESSION_LEVEL_ARTISAN)
    {
        return ArtisanProfessionCost;
    }
    else if (player->GetPureMaxSkillValue(id) == PROFESSION_LEVEL_MASTER)
    {
        return MasterProfessionCost;
    }
    else if (player->GetPureMaxSkillValue(id) == PROFESSION_LEVEL_GRAND_MASTER)
    {
        return GrandMasterProfessionCost;
    }

    return 0;
}

bool Assistant::CanResetInstances(Player* player)
{
    if ((HasSavedInstances(player, INSTANCE_TYPE_HEROIC) && HeroicInstanceEnabled) || (HasSavedInstances(player, INSTANCE_TYPE_RAID) && RaidInstanceEnabled))
    {
        return true;
    }

    return false;
}

bool Assistant::HasSavedInstances(Player* player, uint8 type)
{
    for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
    {
        BoundInstancesMap const& instances = sInstanceSaveMgr->PlayerGetBoundInstances(player->GetGUID(), Difficulty(i));
        for (BoundInstancesMap::const_iterator itr = instances.begin(); itr != instances.end(); ++itr)
        {
            InstanceSave* save = itr->second.save;

            if ((save->GetMapEntry()->IsRaid() && type == INSTANCE_TYPE_RAID) || (save->GetMapEntry()->IsNonRaidDungeon() && save->GetDifficulty() == DUNGEON_DIFFICULTY_HEROIC && type == INSTANCE_TYPE_HEROIC))
            {
                return true;
            }
        }
    }

    return false;
}

void Assistant::ResetInstances(Player* player, uint8 type)
{
    for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
    {
        BoundInstancesMap const& instances = sInstanceSaveMgr->PlayerGetBoundInstances(player->GetGUID(), Difficulty(i));
        for (BoundInstancesMap::const_iterator itr = instances.begin(); itr != instances.end(); ++itr)
        {
            InstanceSave* save = itr->second.save;

            if ((save->GetMapEntry()->IsRaid() && type == INSTANCE_TYPE_RAID) || (save->GetMapEntry()->IsNonRaidDungeon() && save->GetDifficulty() == DUNGEON_DIFFICULTY_HEROIC && type == INSTANCE_TYPE_HEROIC))
            {
                sInstanceSaveMgr->PlayerUnbindInstance(player->GetGUID(), itr->first, Difficulty(i), true, player);
            }
        }
    }
}
