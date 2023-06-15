#include "mod_assistant.h"

bool Assistant::OnGossipHello(Player* player, Creature* creature)
{
    ClearGossipMenuFor(player);

    if (EnableHeirlooms)
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want heirlooms", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM);

    if (EnableGlyphs)
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want glyphs", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH);

    if (EnableGems)
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want gems", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GEM);

    if (EnableContainers)
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want containers", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_CONTAINER);

    if (EnableUtilities)
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want utilities", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_UTILITIES);

    if (CanUnlockFlightPaths(player))
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to unlock flight paths", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_FLIGHT_PATHS);

    if (HasValidProfession(player))
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want help with my professions", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_PROFESSIONS);

    SendGossipMenuFor(player, ASSISTANT_GOSSIP_TEXT, creature->GetGUID());
    return true;
}

bool Assistant::OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
{
    if (sender != GOSSIP_SENDER_MAIN)
        return false;

    if (action == 1)
    {
        OnGossipHello(player, creature);
    }
    else if (action == ASSISTANT_GOSSIP_HEIRLOOM)
    {
        ClearGossipMenuFor(player);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want weapons", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM + 1);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want armor", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM + 2);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want something else", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_HEIRLOOM + 3);
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, 1);
        SendGossipMenuFor(player, ASSISTANT_GOSSIP_TEXT, creature->GetGUID());
    }
    else if (action == ASSISTANT_GOSSIP_HEIRLOOM + 1)
    {
        player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_HEIRLOOM_WEAPON);
    }
    else if (action == ASSISTANT_GOSSIP_HEIRLOOM + 2)
    {
        player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_HEIRLOOM_ARMOR);
    }
    else if (action == ASSISTANT_GOSSIP_HEIRLOOM + 3)
    {
        player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_HEIRLOOM_OTHER);
    }
    else if (action == ASSISTANT_GOSSIP_GLYPH)
    {
        ClearGossipMenuFor(player);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want some major glyphs", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH + 1);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want some minor glyphs", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GLYPH + 2);
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, 1);
        SendGossipMenuFor(player, ASSISTANT_GOSSIP_TEXT, creature->GetGUID());
    }
    else if (action == ASSISTANT_GOSSIP_GLYPH + 1)
    {
        switch (player->getClass())
        {
        case CLASS_WARRIOR:
            player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH);
            break;
        case CLASS_PALADIN:
            player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH + 1);
            break;
        case CLASS_HUNTER:
            player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH + 2);
            break;
        case CLASS_ROGUE:
            player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH + 3);
            break;
        case CLASS_PRIEST:
            player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH + 4);
            break;
        case CLASS_DEATH_KNIGHT:
            player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH + 5);
            break;
        case CLASS_SHAMAN:
            player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH + 6);
            break;
        case CLASS_MAGE:
            player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH + 7);
            break;
        case CLASS_WARLOCK:
            player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH + 8);
            break;
        case CLASS_DRUID:
            player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH + 9);
            break;
        }
    }
    else if (action == ASSISTANT_GOSSIP_GLYPH + 2)
    {
        switch (player->getClass())
        {
        case CLASS_WARRIOR:
            player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH + 10);
            break;
        case CLASS_PALADIN:
            player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH + 11);
            break;
        case CLASS_HUNTER:
            player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH + 12);
            break;
        case CLASS_ROGUE:
            player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH + 13);
            break;
        case CLASS_PRIEST:
            player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH + 14);
            break;
        case CLASS_DEATH_KNIGHT:
            player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH + 15);
            break;
        case CLASS_SHAMAN:
            player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH + 16);
            break;
        case CLASS_MAGE:
            player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH + 17);
            break;
        case CLASS_WARLOCK:
            player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH + 18);
            break;
        case CLASS_DRUID:
            player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GLYPH + 19);
            break;
        }
    }
    else if (action == ASSISTANT_GOSSIP_GEM)
    {
        ClearGossipMenuFor(player);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want some meta gems", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GEM + 1);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want some red gems", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GEM + 2);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want some blue gems", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GEM + 3);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want some yellow gems", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GEM + 4);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want some purple gems", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GEM + 5);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want some green gems", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GEM + 6);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want some orange gems", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_GEM + 7);
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, 1);
        SendGossipMenuFor(player, ASSISTANT_GOSSIP_TEXT, creature->GetGUID());
    }
    else if (action == ASSISTANT_GOSSIP_GEM + 1)
    {
        player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GEM);
    }
    else if (action == ASSISTANT_GOSSIP_GEM + 2)
    {
        player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GEM + 1);
    }
    else if (action == ASSISTANT_GOSSIP_GEM + 3)
    {
        player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GEM + 2);
    }
    else if (action == ASSISTANT_GOSSIP_GEM + 4)
    {
        player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GEM + 3);
    }
    else if (action == ASSISTANT_GOSSIP_GEM + 5)
    {
        player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GEM + 4);
    }
    else if (action == ASSISTANT_GOSSIP_GEM + 6)
    {
        player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GEM + 5);
    }
    else if (action == ASSISTANT_GOSSIP_GEM + 7)
    {
        player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_GEM + 6);
    }
    else if (action == ASSISTANT_GOSSIP_CONTAINER)
    {
        player->GetSession()->SendListInventory(creature->GetGUID(), ASSISTANT_VENDOR_CONTAINER);
    }
    else if (action == ASSISTANT_GOSSIP_UTILITIES)
    {
        ClearGossipMenuFor(player);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want to change my name", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_UTILITIES + 1, "Do you wish to continue the transaction?", CostNameChange, false);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want to change my appearance", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_UTILITIES + 2, "Do you wish to continue the transaction?", CostCustomization, false);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want to change my race", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_UTILITIES + 3, "Do you wish to continue the transaction?", CostRaceChange, false);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I want to change my faction", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_UTILITIES + 4, "Do you wish to continue the transaction?", CostFactionChange, false);
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, 1);
        SendGossipMenuFor(player, ASSISTANT_GOSSIP_TEXT, creature->GetGUID());
    }
    else if (action == ASSISTANT_GOSSIP_UTILITIES + 1)
    {
        if (HasLoginFlag(player))
        {
            ChatHandler(player->GetSession()).PSendSysMessage("You have to complete the previously activated feature before trying to perform another.");
            OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_UTILITIES);
        }
        else
        {
            player->ModifyMoney(-CostNameChange);
            player->SetAtLoginFlag(AT_LOGIN_RENAME);
            ChatHandler(player->GetSession()).PSendSysMessage("You can now log out to apply the name change.");
            CloseGossipMenuFor(player);
        }
    }
    else if (action == ASSISTANT_GOSSIP_UTILITIES + 2)
    {
        if (HasLoginFlag(player))
        {
            ChatHandler(player->GetSession()).PSendSysMessage("You have to complete the previously activated feature before trying to perform another.");
            OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_UTILITIES);
        }
        else
        {
            player->ModifyMoney(-CostCustomization);
            player->SetAtLoginFlag(AT_LOGIN_CUSTOMIZE);
            ChatHandler(player->GetSession()).PSendSysMessage("You can now log out to apply the customization.");
            CloseGossipMenuFor(player);
        }
    }
    else if (action == ASSISTANT_GOSSIP_UTILITIES + 3)
    {
        if (HasLoginFlag(player))
        {
            ChatHandler(player->GetSession()).PSendSysMessage("You have to complete the previously activated feature before trying to perform another.");
            OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_UTILITIES);
        }
        else
        {
            player->ModifyMoney(-CostRaceChange);
            player->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
            ChatHandler(player->GetSession()).PSendSysMessage("You can now log out to apply the race change.");
            CloseGossipMenuFor(player);
        }
    }
    else if (action == ASSISTANT_GOSSIP_UTILITIES + 4)
    {
        if (HasLoginFlag(player))
        {
            ChatHandler(player->GetSession()).PSendSysMessage("You have to complete the previously activated feature before trying to perform another.");
            OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_UTILITIES);
        }
        else
        {
            player->ModifyMoney(-CostFactionChange);
            player->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
            ChatHandler(player->GetSession()).PSendSysMessage("You can now log out to apply the faction change.");
            CloseGossipMenuFor(player);
        }
    }
    else if (action == ASSISTANT_GOSSIP_FLIGHT_PATHS)
    {
        ClearGossipMenuFor(player);

        if (EnableFlightPaths[0] && player->GetLevel() >= RequiredLevelForFlightPaths[0])
        {
            if (CostFlightPaths[0] > 0)
            {
                AddGossipItemFor(player, GOSSIP_ICON_TAXI, "Kalimdor & Eastern Kingdoms", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_FLIGHT_PATHS + 1, "Do you wish to continue the transaction?", CostFlightPaths[0] * 10000, false);
            }
            else
            {
                AddGossipItemFor(player, GOSSIP_ICON_TAXI, "Kalimdor & Eastern Kingdoms", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_FLIGHT_PATHS + 1);
            }
        }

        if (EnableFlightPaths[1] && player->GetLevel() >= RequiredLevelForFlightPaths[1])
        {
            if (CostFlightPaths[1] > 0)
            {
                AddGossipItemFor(player, GOSSIP_ICON_TAXI, "Outland", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_FLIGHT_PATHS + 2, "Do you wish to continue the transaction?", CostFlightPaths[1] * 10000, false);
            }
            else
            {
                AddGossipItemFor(player, GOSSIP_ICON_TAXI, "Outland", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_FLIGHT_PATHS + 2);
            }
        }

        if (EnableFlightPaths[2] && player->GetLevel() >= RequiredLevelForFlightPaths[2])
        {
            if (CostFlightPaths[2] > 0)
            {
                AddGossipItemFor(player, GOSSIP_ICON_TAXI, "Northrend", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_FLIGHT_PATHS + 3, "Do you wish to continue the transaction?", CostFlightPaths[2] * 10000, false);
            }
            else
            {
                AddGossipItemFor(player, GOSSIP_ICON_TAXI, "Northrend", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_FLIGHT_PATHS + 3);
            }
        }

        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, 1);
        SendGossipMenuFor(player, ASSISTANT_GOSSIP_TEXT, creature->GetGUID());
    }
    else if (action == ASSISTANT_GOSSIP_FLIGHT_PATHS + 1)
    {
        ClearGossipMenuFor(player);

        UnlockFlightPaths(player, 0);

        if (CostFlightPaths[0] > 0)
            player->ModifyMoney(-(CostFlightPaths[0] * 10000));

        OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, 1);
    }
    else if (action == ASSISTANT_GOSSIP_FLIGHT_PATHS + 2)
    {
        ClearGossipMenuFor(player);

        UnlockFlightPaths(player, 1);

        if (CostFlightPaths[1] > 0)
            player->ModifyMoney(-(CostFlightPaths[1] * 10000));

        OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, 1);
    }
    else if (action == ASSISTANT_GOSSIP_FLIGHT_PATHS + 3)
    {
        ClearGossipMenuFor(player);

        UnlockFlightPaths(player, 2);

        if (CostFlightPaths[2] > 0)
            player->ModifyMoney(-(CostFlightPaths[2] * 10000));

        OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, 1);
    }
    else if (action == ASSISTANT_GOSSIP_PROFESSIONS)
    {
        ClearGossipMenuFor(player);

        if (IsValidProfession(player, SKILL_FIRST_AID))
        {
            uint32 cost = GetProfessionCost(player, SKILL_FIRST_AID);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "I want help with my skill in First Aid", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_PROFESSIONS + 1, "Do you wish to continue the transaction?", cost, false);
        }

        if (IsValidProfession(player, SKILL_BLACKSMITHING))
        {
            uint32 cost = GetProfessionCost(player, SKILL_BLACKSMITHING);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "I want help with my skill in Blacksmithing", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_PROFESSIONS + 2, "Do you wish to continue the transaction?", cost, false);
        }

        if (IsValidProfession(player, SKILL_LEATHERWORKING))
        {
            uint32 cost = GetProfessionCost(player, SKILL_LEATHERWORKING);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "I want help with my skill in Leatherworking", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_PROFESSIONS + 3, "Do you wish to continue the transaction?", cost, false);
        }

        if (IsValidProfession(player, SKILL_ALCHEMY))
        {
            uint32 cost = GetProfessionCost(player, SKILL_ALCHEMY);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "I want help with my skill in Alchemy", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_PROFESSIONS + 4, "Do you wish to continue the transaction?", cost, false);
        }

        if (IsValidProfession(player, SKILL_HERBALISM))
        {
            uint32 cost = GetProfessionCost(player, SKILL_HERBALISM);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "I want help with my skill in Herbalism", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_PROFESSIONS + 5, "Do you wish to continue the transaction?", cost, false);
        }

        if (IsValidProfession(player, SKILL_COOKING))
        {
            uint32 cost = GetProfessionCost(player, SKILL_COOKING);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "I want help with my skill in Cooking", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_PROFESSIONS + 6, "Do you wish to continue the transaction?", cost, false);
        }

        if (IsValidProfession(player, SKILL_MINING))
        {
            uint32 cost = GetProfessionCost(player, SKILL_MINING);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "I want help with my skill in Mining", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_PROFESSIONS + 7, "Do you wish to continue the transaction?", cost, false);
        }

        if (IsValidProfession(player, SKILL_TAILORING))
        {
            uint32 cost = GetProfessionCost(player, SKILL_TAILORING);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "I want help with my skill in Tailoring", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_PROFESSIONS + 8, "Do you wish to continue the transaction?", cost, false);
        }

        if (IsValidProfession(player, SKILL_ENGINEERING))
        {
            uint32 cost = GetProfessionCost(player, SKILL_ENGINEERING);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "I want help with my skill in Engineering", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_PROFESSIONS + 9, "Do you wish to continue the transaction?", cost, false);
        }

        if (IsValidProfession(player, SKILL_ENCHANTING))
        {
            uint32 cost = GetProfessionCost(player, SKILL_ENCHANTING);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "I want help with my skill in Enchanting", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_PROFESSIONS + 10, "Do you wish to continue the transaction?", cost, false);
        }

        if (IsValidProfession(player, SKILL_FISHING))
        {
            uint32 cost = GetProfessionCost(player, SKILL_FISHING);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "I want help with my skill in Fishing", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_PROFESSIONS + 11, "Do you wish to continue the transaction?", cost, false);
        }

        if (IsValidProfession(player, SKILL_SKINNING))
        {
            uint32 cost = GetProfessionCost(player, SKILL_SKINNING);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "I want help with my skill in Skinning", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_PROFESSIONS + 12, "Do you wish to continue the transaction?", cost, false);
        }

        if (IsValidProfession(player, SKILL_INSCRIPTION))
        {
            uint32 cost = GetProfessionCost(player, SKILL_INSCRIPTION);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "I want help with my skill in Inscription", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_PROFESSIONS + 13, "Do you wish to continue the transaction?", cost, false);
        }

        if (IsValidProfession(player, SKILL_JEWELCRAFTING))
        {
            uint32 cost = GetProfessionCost(player, SKILL_JEWELCRAFTING);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "I want help with my skill in Jewelcrafting", GOSSIP_SENDER_MAIN, ASSISTANT_GOSSIP_PROFESSIONS + 14, "Do you wish to continue the transaction?", cost, false);
        }

        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, 1);
        SendGossipMenuFor(player, ASSISTANT_GOSSIP_TEXT, creature->GetGUID());
    }
    else if (action == ASSISTANT_GOSSIP_PROFESSIONS + 1)
    {
        ClearGossipMenuFor(player);

        uint16 maxSkillValue = player->GetPureMaxSkillValue(SKILL_FIRST_AID);
        uint32 professionCost = GetProfessionCost(player, SKILL_FIRST_AID);

        player->SetSkill(SKILL_FIRST_AID, 0, maxSkillValue, maxSkillValue);
        player->ModifyMoney(-professionCost);

        OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, 1);
    }
    else if (action == ASSISTANT_GOSSIP_PROFESSIONS + 2)
    {
        ClearGossipMenuFor(player);

        uint16 maxSkillValue = player->GetPureMaxSkillValue(SKILL_BLACKSMITHING);
        uint32 professionCost = GetProfessionCost(player, SKILL_BLACKSMITHING);

        player->SetSkill(SKILL_BLACKSMITHING, 0, maxSkillValue, maxSkillValue);
        player->ModifyMoney(-professionCost);

        OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, 1);
    }
    else if (action == ASSISTANT_GOSSIP_PROFESSIONS + 3)
    {
        ClearGossipMenuFor(player);

        uint16 maxSkillValue = player->GetPureMaxSkillValue(SKILL_LEATHERWORKING);
        uint32 professionCost = GetProfessionCost(player, SKILL_LEATHERWORKING);

        player->SetSkill(SKILL_LEATHERWORKING, 0, maxSkillValue, maxSkillValue);
        player->ModifyMoney(-professionCost);

        OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, 1);
    }
    else if (action == ASSISTANT_GOSSIP_PROFESSIONS + 4)
    {
        ClearGossipMenuFor(player);

        uint16 maxSkillValue = player->GetPureMaxSkillValue(SKILL_ALCHEMY);
        uint32 professionCost = GetProfessionCost(player, SKILL_ALCHEMY);

        player->SetSkill(SKILL_ALCHEMY, 0, maxSkillValue, maxSkillValue);
        player->ModifyMoney(-professionCost);

        OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, 1);
    }
    else if (action == ASSISTANT_GOSSIP_PROFESSIONS + 5)
    {
        ClearGossipMenuFor(player);

        uint16 maxSkillValue = player->GetPureMaxSkillValue(SKILL_HERBALISM);
        uint32 professionCost = GetProfessionCost(player, SKILL_HERBALISM);

        player->SetSkill(SKILL_HERBALISM, 0, maxSkillValue, maxSkillValue);
        player->ModifyMoney(-professionCost);

        OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, 1);
    }
    else if (action == ASSISTANT_GOSSIP_PROFESSIONS + 6)
    {
        ClearGossipMenuFor(player);

        uint16 maxSkillValue = player->GetPureMaxSkillValue(SKILL_COOKING);
        uint32 professionCost = GetProfessionCost(player, SKILL_COOKING);

        player->SetSkill(SKILL_COOKING, 0, maxSkillValue, maxSkillValue);
        player->ModifyMoney(-professionCost);

        OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, 1);
    }
    else if (action == ASSISTANT_GOSSIP_PROFESSIONS + 7)
    {
        ClearGossipMenuFor(player);

        uint16 maxSkillValue = player->GetPureMaxSkillValue(SKILL_MINING);
        uint32 professionCost = GetProfessionCost(player, SKILL_MINING);

        player->SetSkill(SKILL_MINING, 0, maxSkillValue, maxSkillValue);
        player->ModifyMoney(-professionCost);

        OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, 1);
    }
    else if (action == ASSISTANT_GOSSIP_PROFESSIONS + 8)
    {
        ClearGossipMenuFor(player);

        uint16 maxSkillValue = player->GetPureMaxSkillValue(SKILL_TAILORING);
        uint32 professionCost = GetProfessionCost(player, SKILL_TAILORING);

        player->SetSkill(SKILL_TAILORING, 0, maxSkillValue, maxSkillValue);
        player->ModifyMoney(-professionCost);

        OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, 1);
    }
    else if (action == ASSISTANT_GOSSIP_PROFESSIONS + 9)
    {
        ClearGossipMenuFor(player);

        uint16 maxSkillValue = player->GetPureMaxSkillValue(SKILL_ENGINEERING);
        uint32 professionCost = GetProfessionCost(player, SKILL_ENGINEERING);

        player->SetSkill(SKILL_ENGINEERING, 0, maxSkillValue, maxSkillValue);
        player->ModifyMoney(-professionCost);

        OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, 1);
    }
    else if (action == ASSISTANT_GOSSIP_PROFESSIONS + 10)
    {
        ClearGossipMenuFor(player);

        uint16 maxSkillValue = player->GetPureMaxSkillValue(SKILL_ENCHANTING);
        uint32 professionCost = GetProfessionCost(player, SKILL_ENCHANTING);

        player->SetSkill(SKILL_ENCHANTING, 0, maxSkillValue, maxSkillValue);
        player->ModifyMoney(-professionCost);

        OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, 1);
    }
    else if (action == ASSISTANT_GOSSIP_PROFESSIONS + 11)
    {
        ClearGossipMenuFor(player);

        uint16 maxSkillValue = player->GetPureMaxSkillValue(SKILL_FISHING);
        uint32 professionCost = GetProfessionCost(player, SKILL_FISHING);

        player->SetSkill(SKILL_FISHING, 0, maxSkillValue, maxSkillValue);
        player->ModifyMoney(-professionCost);

        OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, 1);
    }
    else if (action == ASSISTANT_GOSSIP_PROFESSIONS + 12)
    {
        ClearGossipMenuFor(player);

        uint16 maxSkillValue = player->GetPureMaxSkillValue(SKILL_SKINNING);
        uint32 professionCost = GetProfessionCost(player, SKILL_SKINNING);

        player->SetSkill(SKILL_SKINNING, 0, maxSkillValue, maxSkillValue);
        player->ModifyMoney(-professionCost);

        OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, 1);
    }
    else if (action == ASSISTANT_GOSSIP_PROFESSIONS + 13)
    {
        ClearGossipMenuFor(player);

        uint16 maxSkillValue = player->GetPureMaxSkillValue(SKILL_INSCRIPTION);
        uint32 professionCost = GetProfessionCost(player, SKILL_INSCRIPTION);

        player->SetSkill(SKILL_INSCRIPTION, 0, maxSkillValue, maxSkillValue);
        player->ModifyMoney(-professionCost);

        OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, 1);
    }
    else if (action == ASSISTANT_GOSSIP_PROFESSIONS + 14)
    {
        ClearGossipMenuFor(player);

        uint16 maxSkillValue = player->GetPureMaxSkillValue(SKILL_JEWELCRAFTING);
        uint32 professionCost = GetProfessionCost(player, SKILL_JEWELCRAFTING);

        player->SetSkill(SKILL_JEWELCRAFTING, 0, maxSkillValue, maxSkillValue);
        player->ModifyMoney(-professionCost);

        OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, 1);
    }

    return true;
}
