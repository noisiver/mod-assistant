SET
@Entry := 9000000,
@Model := 27822,
@Name  := "Gabriella",
@Title := "The Assistant",
@Icon  := "Speak",
@GossipMenu := 0,
@MinLevel := 30,
@MaxLevel := 30,
@Faction  := 35,
@NPCFlag  := 129,
@Scale    := 1.0,
@Rank     := 0,
@Type     := 7,
@TypeFlags := 0,
@FlagsExtra := 2,
@AIName     := "SmartAI",
@Script     := "npc_assistant";

-- Creature template
DELETE FROM `creature_template` WHERE `entry`=@Entry;
INSERT INTO `creature_template` (`entry`, `modelid1`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `unit_class`, `unit_flags`, `type`, `type_flags`, `InhabitType`, `RegenHealth`, `flags_extra`, `AiName`, `ScriptName`) VALUES
(@Entry, @Model, @Name, @Title, @Icon, @GossipMenu, @MinLevel, @MaxLevel, @Faction, @NPCFlag, 1, 1, @Scale, @Rank, 1, 2, @Type, @TypeFlags, 3, 1, @FlagsExtra, @AIName, @Script);

-- Spawn points for Stormwind, Orgrimmar and Dalaran
DELETE FROM `creature` WHERE `id`=@Entry;
INSERT INTO `creature` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES (@Entry, @Entry, 0, -8825.05, 649.331, 94.5545, 4.6664); -- Stormwind City
INSERT INTO `creature` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES (@Entry+1, @Entry, 1, 1676.62, -4423.69, 18.9152, 2.64126); -- Orgrimmar
INSERT INTO `creature` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES (@Entry+2, @Entry, 571, 5784.29, 623.186, 647.71, 5.75156); -- Dalaran

-- Heirloom: Weapon
DELETE FROM `npc_vendor` WHERE `entry`=@Entry;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 42943);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 42944);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 42945);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 42946);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 42947);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 42948);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 44091);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 44092);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 44093);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 44094);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 44095);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 44096);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 48716);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 48718);

-- Heirloom: Armor
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+1;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 42949);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 42950);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 42951);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 42952);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 42984);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 42985);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 42991);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 42992);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 44097);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 44098);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 44099);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 44100);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 44101);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 44102);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 44103);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 44105);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 44107);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 48677);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 48683);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 48685);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 48687);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 48689);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 48691);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 50255);

-- Heirloom: Other
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+2;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 49177);

-- Glyph: Warrior (Major)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+3;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43412);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43413);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43414);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43415);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43416);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43417);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43418);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43419);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43420);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43421);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43422);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43423);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43424);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43425);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43426);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43427);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43428);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43429);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43430);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43431);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43432);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 45790);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 45792);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 45793);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 45794);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 45795);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 45797);

-- Glyph: Paladin (Major)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+4;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41092);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41094);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41095);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41096);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41097);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41098);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41099);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41100);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41101);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41102);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41103);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41104);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41105);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41106);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41107);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41108);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41109);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41110);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 43867);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 43868);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 43869);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 45741);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 45742);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 45743);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 45744);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 45745);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 45746);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 45747);

-- Glyph: Hunter (Major)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+5;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42897);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42898);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42899);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42900);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42901);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42902);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42903);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42904);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42905);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42906);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42907);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42908);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42909);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42910);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42911);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42912);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42913);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42914);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42915);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42916);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42917);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 45625);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 45731);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 45732);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 45733);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 45734);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 45735);

-- Glyph: Rogue (Major)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+6;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42954);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42955);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42956);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42957);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42958);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42959);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42960);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42961);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42962);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42963);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42964);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42965);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42966);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42967);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42968);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42969);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42970);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42971);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42972);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42973);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42974);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 45761);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 45762);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 45764);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 45766);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 45767);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 45768);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 45769);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 45908);

-- Glyph: Priest (Major)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+7;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42396);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42397);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42398);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42399);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42400);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42401);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42402);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42403);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42404);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42405);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42406);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42407);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42408);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42409);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42410);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42411);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42412);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42414);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42415);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42416);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42417);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 45753);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 45755);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 45756);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 45757);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 45758);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 45760);

-- Glyph: Death Knight (Major)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+8;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43533);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43534);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43536);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43537);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43538);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43541);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43542);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43543);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43545);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43546);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43547);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43548);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43549);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43550);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43551);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43552);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43553);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43554);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43825);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43826);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43827);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 44432);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 45799);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 45800);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 45803);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 45804);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 45805);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 45806);

-- Glyph: Shaman (Major)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+9;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41517);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41518);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41524);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41526);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41527);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41529);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41530);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41531);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41532);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41533);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41534);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41535);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41536);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41537);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41538);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41539);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41540);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41541);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41542);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41547);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41552);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 45770);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 45771);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 45772);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 45775);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 45776);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 45777);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 45778);

-- Glyph: Mage (Major)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+10;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42734);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42735);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42736);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42737);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42738);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42739);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42740);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42741);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42742);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42743);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42744);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42745);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42746);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42747);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42748);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42749);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42750);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42751);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42752);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42753);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42754);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 44684);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 44955);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 45736);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 45737);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 45738);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 45739);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 45740);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 50045);

-- Glyph: Warlock (Major)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+11;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42453);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42454);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42455);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42456);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42457);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42458);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42459);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42460);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42461);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42462);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42463);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42464);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42465);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42466);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42467);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42468);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42469);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42470);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42471);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42473);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42742);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 45779);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 45780);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 45781);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 45782);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 45783);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 45785);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 45789);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 50077);

-- Glyph: Druid (Major)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+12;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40896);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40897);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40899);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40900);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40901);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40902);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40903);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40906);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40908);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40909);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40912);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40913);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40914);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40915);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40916);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40919);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40920);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40921);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40922);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40923);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40924);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 44928);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 45601);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 45602);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 45603);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 45604);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 45622);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 45623);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 46372);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 48720);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 50125);

-- Glyph: Warrior (Minor)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+13;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+13, 43395);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+13, 43396);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+13, 43397);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+13, 43398);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+13, 43399);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+13, 43400);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+13, 49084);

-- Glyph: Paladin (Minor)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+14;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+14, 43340);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+14, 43365);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+14, 43366);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+14, 43367);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+14, 43368);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+14, 43369);

-- Glyph: Hunter (Minor)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+15;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+15, 43338);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+15, 43350);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+15, 43351);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+15, 43354);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+15, 43355);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+15, 43356);

-- Glyph: Rogue (Minor)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+16;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+16, 43343);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+16, 43376);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+16, 43377);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+16, 43378);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+16, 43379);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+16, 43380);

-- Glyph: Priest (Minor)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+17;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+17, 43342);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+17, 43370);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+17, 43371);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+17, 43372);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+17, 43373);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+17, 43374);

-- Glyph: Death Knight (Minor)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+18;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+18, 43535);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+18, 43539);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+18, 43544);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+18, 43671);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+18, 43672);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+18, 43673);

-- Glyph: Shaman (Minor)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+19;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+19, 43344);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+19, 43381);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+19, 43385);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+19, 43386);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+19, 43388);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+19, 43725);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+19, 44923);

-- Glyph: Mage (Minor)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+20;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+20, 43339);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+20, 43357);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+20, 43359);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+20, 43360);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+20, 43361);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+20, 43362);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+20, 43364);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+20, 44920);

-- Glyph: Warlock (Minor)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+21;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+21, 43389);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+21, 43390);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+21, 43391);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+21, 43392);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+21, 43393);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+21, 43394);

-- Glyph: Druid (Minor)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+22;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+22, 43316);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+22, 43331);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+22, 43332);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+22, 43334);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+22, 43335);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+22, 43674);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+22, 44922);
