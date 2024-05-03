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
@FlagsExtra := 16777218,
@Script     := "npc_assistant";

-- Creature template
DELETE FROM `creature_template` WHERE `entry`=@Entry;
INSERT INTO `creature_template` (`entry`, `modelid1`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `unit_class`, `unit_flags`, `type`, `type_flags`, `RegenHealth`, `flags_extra`, `ScriptName`) VALUES
(@Entry, @Model, @Name, @Title, @Icon, @GossipMenu, @MinLevel, @MaxLevel, @Faction, @NPCFlag, 1, 1, @Scale, @Rank, 1, 2, @Type, @TypeFlags, 1, @FlagsExtra, @Script);

-- Spawn points
DELETE FROM `creature` WHERE `id1`=@Entry;
INSERT INTO `creature` (`id1`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES (@Entry, 0, -8824.65, 649.467, 94.5585, 4.47955); -- Stormwind
INSERT INTO `creature` (`id1`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES (@Entry, 0, -4978.68, -947.674, 501.66, 5.0182); -- Ironforge
INSERT INTO `creature` (`id1`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES (@Entry, 1, 9949.92, 2498.44, 1317.8, 4.44686); -- Darnassus
INSERT INTO `creature` (`id1`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES (@Entry, 530, -3911.11, -11606.3, -138.326, 4.73595); -- Exodar
INSERT INTO `creature` (`id1`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES (@Entry, 1, 1675.72, -4424.67, 18.8421, 2.39778); -- Orgrimmar
INSERT INTO `creature` (`id1`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES (@Entry, 1, -1271.36, 132.402, 132.023, 4.57086); -- Thunder Bluff
INSERT INTO `creature` (`id1`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES (@Entry, 0, 1555.03, 246.513, -43.1027, 0.073205); -- Undercity
INSERT INTO `creature` (`id1`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES (@Entry, 530, 9469.83, -7294.44, 14.3078, 0.105431); -- Silvermoon City
INSERT INTO `creature` (`id1`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES (@Entry, 530, -1832.44, 5389.19, -12.4279, 2.3428); -- Shattrath
INSERT INTO `creature` (`id1`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES (@Entry, 571, 5792.65, 636.492, 647.39, 0.00637221); -- Dalaran

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
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43412, 43413, 43414, 43415, 43416, 43417, 43418, 43419, 43420, 43421, 43422, 43423, 43424, 43425, 43426, 43427, 43428, 43429, 43430, 43431, 43432, 45790, 45792, 45793, 45794, 45795, 45797);
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
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (41092, 41094, 41095, 41096, 41097, 41098, 41099, 41100, 41101, 41102, 41103, 41104, 41105, 41106, 41107, 41108, 41109, 41110, 43867, 43868, 43869, 45741, 45742, 45743, 45744, 45745, 45746, 45747);
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
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42897, 42898, 42899, 42900, 42901, 42902, 42903, 42904, 42905, 42906, 42907, 42908, 42909, 42910, 42911, 42912, 42913, 42914, 42915, 42916, 42917, 45625, 45731, 45732, 45733, 45734, 45735);
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
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42954, 42955, 42956, 42957, 42958, 42959, 42960, 42961, 42962, 42963, 42964, 42965, 42966, 42967, 42968, 42969, 42970, 42971, 42972, 42973, 42974, 45761, 45762, 45764, 45766, 45767, 45768, 45769);
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
-- Glyph: Priest (Major)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42396, 42397, 42398, 42399, 42400, 42401, 42402, 42403, 42404, 42405, 42406, 42407, 42408, 42409, 42410, 42411, 42412, 42414, 42415, 42416, 42417, 45753, 45755, 45756, 45757, 45758, 45760);
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
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43533, 43534, 43536, 43537, 43538, 43541, 43542, 43543, 43545, 43546, 43547, 43548, 43549, 43550, 43551, 43552, 43553, 43554, 43825, 43826, 43827, 45799, 45800, 45803, 45804, 45805, 45806);
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
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 45799);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 45800);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 45803);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 45804);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 45805);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 45806);
-- Glyph: Shaman (Major)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (41517, 41518, 41524, 41526, 41527, 41529, 41530, 41531, 41532, 41533, 41534, 41535, 41536, 41537, 41538, 41539, 41540, 41541, 41542, 41547, 41552, 45770, 45771, 45772, 45775, 45776, 45777, 45778);
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
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42734, 42735, 42736, 42737, 42738, 42739, 42740, 42741, 42742, 42743, 42744, 42745, 42746, 42747, 42748, 42749, 42750, 42751, 42752, 42753, 42754, 44684, 44955, 45736, 45737, 45738, 45739, 45740, 50045);
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
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42453, 42454, 42455, 42456, 42457, 42458, 42459, 42460, 42461, 42462, 42463, 42464, 42465, 42466, 42467, 42468, 42469, 42470, 42471, 42473, 45779, 45780, 45781, 45782, 45783, 45785, 45789, 50077);
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
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 45779);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 45780);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 45781);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 45782);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 45783);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 45785);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 45789);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 50077);
-- Glyph: Druid (Major)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40896, 40897, 40899, 40900, 40901, 40902, 40903, 40906, 40908, 40909, 40912, 40913, 40914, 40915, 40916, 40919, 40920, 40921, 40922, 40923, 40924, 44928, 45601, 45602, 45603, 45604, 45622, 45623, 46372, 48720, 50125);
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
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43395, 43396, 43397, 43398, 43399, 43400, 49084);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+13;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+13, 43395);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+13, 43396);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+13, 43397);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+13, 43398);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+13, 43399);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+13, 43400);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+13, 49084);
-- Glyph: Paladin (Minor)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43340, 43365, 43366, 43367, 43368, 43369);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+14;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+14, 43340);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+14, 43365);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+14, 43366);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+14, 43367);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+14, 43368);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+14, 43369);
-- Glyph: Hunter (Minor)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43338, 43350, 43351, 43354, 43355, 43356);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+15;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+15, 43338);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+15, 43350);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+15, 43351);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+15, 43354);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+15, 43355);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+15, 43356);
-- Glyph: Rogue (Minor)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43343, 43376, 43377, 43378, 43379, 43380);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+16;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+16, 43343);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+16, 43376);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+16, 43377);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+16, 43378);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+16, 43379);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+16, 43380);
-- Glyph: Priest (Minor)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43342, 43370, 43371, 43372, 43373, 43374);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+17;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+17, 43342);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+17, 43370);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+17, 43371);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+17, 43372);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+17, 43373);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+17, 43374);
-- Glyph: Death Knight (Minor)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43535, 43539, 43544, 43671, 43672, 43673);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+18;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+18, 43535);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+18, 43539);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+18, 43544);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+18, 43671);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+18, 43672);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+18, 43673);
-- Glyph: Shaman (Minor)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43344, 43381, 43385, 43386, 43388, 43725, 44923);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+19;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+19, 43344);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+19, 43381);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+19, 43385);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+19, 43386);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+19, 43388);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+19, 43725);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+19, 44923);
-- Glyph: Mage (Minor)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43339, 43357, 43359, 43360, 43361, 43362, 43364, 44920);
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
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43389, 43390, 43391, 43392, 43393, 43394);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+21;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+21, 43389);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+21, 43390);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+21, 43391);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+21, 43392);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+21, 43393);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+21, 43394);
-- Glyph: Druid (Minor)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43316, 43331, 43332, 43334, 43335, 43674, 44922);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+22;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+22, 43316);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+22, 43331);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+22, 43332);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+22, 43334);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+22, 43335);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+22, 43674);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+22, 44922);

-- Gem: Meta
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (41285, 41307, 41333, 41335, 41339, 41375, 41376, 41377, 41378, 41379, 41380, 41381, 41382, 41385, 41389, 41395, 41396, 41397, 41398, 41400, 41401);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+23;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41285);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41307);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41333);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41335);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41339);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41375);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41376);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41377);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41378);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41379);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41380);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41381);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41382);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41385);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41389);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41395);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41396);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41397);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41398);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41400);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41401);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 44076);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 44078);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 44081);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 44082);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 44084);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 44087);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 44088);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 44089);
-- Gem: Red
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40111, 40112, 40113, 40114, 40115, 40116, 40117, 40118, 45862, 45879, 45883);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+24;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+24, 40111);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+24, 40112);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+24, 40113);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+24, 40114);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+24, 40115);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+24, 40116);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+24, 40117);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+24, 40118);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+24, 45862);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+24, 45879);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+24, 45883);
-- Gem: Blue
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40119, 40120, 40121, 40122, 45880, 45881);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+25;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 40119);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 40120);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 40121);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 40122);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 45880);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 45881);
-- Gem: Yellow
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40123, 40124, 40125, 40126, 40127, 40128, 45882, 45987);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+26;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+26, 40123);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+26, 40124);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+26, 40125);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+26, 40126);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+26, 40127);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+26, 40128);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+26, 45882);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+26, 45987);
-- Gem: Purple
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40129, 40130, 40131, 40132, 40133, 40134, 40135, 40136, 40137, 40138, 40139, 40140, 40141);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+27;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+27, 40129);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+27, 40130);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+27, 40131);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+27, 40132);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+27, 40133);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+27, 40134);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+27, 40135);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+27, 40136);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+27, 40137);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+27, 40138);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+27, 40139);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+27, 40140);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+27, 40141);
-- Gem: Green
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40164, 40165, 40166, 40167, 40168, 40169, 40170, 40171, 40172, 40173, 40174, 40175, 40176, 40177, 40178, 40179, 40180, 40181, 40182);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+28;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40164);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40165);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40166);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40167);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40168);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40169);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40170);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40171);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40172);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40173);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40174);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40175);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40176);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40177);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40178);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40179);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40180);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40181);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40182);
-- Gem: Orange
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40142, 40143, 40144, 40145, 40146, 40147, 40148, 40149, 40150, 40151, 40152, 40153, 40154, 40155, 40156, 40157, 40158, 40159, 40160, 40161, 40162, 40163);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+29;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40142);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40143);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40144);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40145);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40146);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40147);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40148);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40149);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40150);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40151);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40152);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40153);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40154);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40155);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40156);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40157);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40158);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40159);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40160);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40161);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40162);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40163);

-- Container
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (1729, 3604, 3605, 22243);
UPDATE `item_template` SET `maxcount`=0 WHERE `entry`=1729;
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+30;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+30, 1729);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+30, 3604);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+30, 3605);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+30, 22243);
