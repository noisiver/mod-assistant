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
INSERT INTO `creature` (`id1`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES
(@Entry, 0, -8824.65, 649.467, 94.5585, 4.47955), -- Stormwind City
(@Entry, 0, -4956.91, -932.369, 501.66, 4.77523), -- City of Ironforge
(@Entry, 0, 1590.66, 272.521, -55.3428, 0.361283), -- Undercity
(@Entry, 1, 9929.71, 2507.59, 1318.17, 4.78701), -- Darnassus
(@Entry, 1, 1619.08, -4443.65, 10.869, 1.73804), -- Orgrimmar
(@Entry, 1, -1292.12, 116.913, 131.175, 5.78446), -- Thunder Bluff
(@Entry, 530, -3955.07, -11670, -138.757, 3.29082), -- The Exodar
(@Entry, 530, 9469.83, -7294.44, 14.3078, 0.105431), -- Silvermoon City
(@Entry, 530, -1814.49, 5425.97, -12.4281, 2.87456), -- Shattrath City
(@Entry, 571, 5791.71, 560.464, 650.657, 1.79314); -- Dalaran

-- Heirloom: Weapon
DELETE FROM `npc_vendor` WHERE `entry`=@Entry;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES
(@Entry, 42943),
(@Entry, 42944),
(@Entry, 42945),
(@Entry, 42946),
(@Entry, 42947),
(@Entry, 42948),
(@Entry, 44091),
(@Entry, 44092),
(@Entry, 44093),
(@Entry, 44094),
(@Entry, 44095),
(@Entry, 44096),
(@Entry, 48716),
(@Entry, 48718);
-- Heirloom: Armor
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+1;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES
(@Entry+1, 42949),
(@Entry+1, 42950),
(@Entry+1, 42951),
(@Entry+1, 42952),
(@Entry+1, 42984),
(@Entry+1, 42985),
(@Entry+1, 42991),
(@Entry+1, 42992),
(@Entry+1, 44097),
(@Entry+1, 44098),
(@Entry+1, 44099),
(@Entry+1, 44100),
(@Entry+1, 44101),
(@Entry+1, 44102),
(@Entry+1, 44103),
(@Entry+1, 44105),
(@Entry+1, 44107),
(@Entry+1, 48677),
(@Entry+1, 48683),
(@Entry+1, 48685),
(@Entry+1, 48687),
(@Entry+1, 48689),
(@Entry+1, 48691),
(@Entry+1, 50255);
-- Heirloom: Other
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+2;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES
(@Entry+2, 49177);

-- Glyph: Warrior (Major)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43412, 43413, 43414, 43415, 43416, 43417, 43418, 43419, 43420, 43421, 43422, 43423, 43424, 43425, 43426, 43427, 43428, 43429, 43430, 43431, 43432, 45790, 45792, 45793, 45794, 45795, 45797);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+3;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES
(@Entry+3, 43412),
(@Entry+3, 43413),
(@Entry+3, 43414),
(@Entry+3, 43415),
(@Entry+3, 43416),
(@Entry+3, 43417),
(@Entry+3, 43418),
(@Entry+3, 43419),
(@Entry+3, 43420),
(@Entry+3, 43421),
(@Entry+3, 43422),
(@Entry+3, 43423),
(@Entry+3, 43424),
(@Entry+3, 43425),
(@Entry+3, 43426),
(@Entry+3, 43427),
(@Entry+3, 43428),
(@Entry+3, 43429),
(@Entry+3, 43430),
(@Entry+3, 43431),
(@Entry+3, 43432),
(@Entry+3, 45790),
(@Entry+3, 45792),
(@Entry+3, 45793),
(@Entry+3, 45794),
(@Entry+3, 45795),
(@Entry+3, 45797);
-- Glyph: Paladin (Major)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (41092, 41094, 41095, 41096, 41097, 41098, 41099, 41100, 41101, 41102, 41103, 41104, 41105, 41106, 41107, 41108, 41109, 41110, 43867, 43868, 43869, 45741, 45742, 45743, 45744, 45745, 45746, 45747);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+4;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES
(@Entry+4, 41092),
(@Entry+4, 41094),
(@Entry+4, 41095),
(@Entry+4, 41096),
(@Entry+4, 41097),
(@Entry+4, 41098),
(@Entry+4, 41099),
(@Entry+4, 41100),
(@Entry+4, 41101),
(@Entry+4, 41102),
(@Entry+4, 41103),
(@Entry+4, 41104),
(@Entry+4, 41105),
(@Entry+4, 41106),
(@Entry+4, 41107),
(@Entry+4, 41108),
(@Entry+4, 41109),
(@Entry+4, 41110),
(@Entry+4, 43867),
(@Entry+4, 43868),
(@Entry+4, 43869),
(@Entry+4, 45741),
(@Entry+4, 45742),
(@Entry+4, 45743),
(@Entry+4, 45744),
(@Entry+4, 45745),
(@Entry+4, 45746),
(@Entry+4, 45747);
-- Glyph: Hunter (Major)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42897, 42898, 42899, 42900, 42901, 42902, 42903, 42904, 42905, 42906, 42907, 42908, 42909, 42910, 42911, 42912, 42913, 42914, 42915, 42916, 42917, 45625, 45731, 45732, 45733, 45734, 45735);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+5;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES
(@Entry+5, 42897),
(@Entry+5, 42898),
(@Entry+5, 42899),
(@Entry+5, 42900),
(@Entry+5, 42901),
(@Entry+5, 42902),
(@Entry+5, 42903),
(@Entry+5, 42904),
(@Entry+5, 42905),
(@Entry+5, 42906),
(@Entry+5, 42907),
(@Entry+5, 42908),
(@Entry+5, 42909),
(@Entry+5, 42910),
(@Entry+5, 42911),
(@Entry+5, 42912),
(@Entry+5, 42913),
(@Entry+5, 42914),
(@Entry+5, 42915),
(@Entry+5, 42916),
(@Entry+5, 42917),
(@Entry+5, 45625),
(@Entry+5, 45731),
(@Entry+5, 45732),
(@Entry+5, 45733),
(@Entry+5, 45734),
(@Entry+5, 45735);
-- Glyph: Rogue (Major)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42954, 42955, 42956, 42957, 42958, 42959, 42960, 42961, 42962, 42963, 42964, 42965, 42966, 42967, 42968, 42969, 42970, 42971, 42972, 42973, 42974, 45761, 45762, 45764, 45766, 45767, 45768, 45769);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+6;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES
(@Entry+6, 42954),
(@Entry+6, 42955),
(@Entry+6, 42956),
(@Entry+6, 42957),
(@Entry+6, 42958),
(@Entry+6, 42959),
(@Entry+6, 42960),
(@Entry+6, 42961),
(@Entry+6, 42962),
(@Entry+6, 42963),
(@Entry+6, 42964),
(@Entry+6, 42965),
(@Entry+6, 42966),
(@Entry+6, 42967),
(@Entry+6, 42968),
(@Entry+6, 42969),
(@Entry+6, 42970),
(@Entry+6, 42971),
(@Entry+6, 42972),
(@Entry+6, 42973),
(@Entry+6, 42974),
(@Entry+6, 45761),
(@Entry+6, 45762),
(@Entry+6, 45764),
(@Entry+6, 45766),
(@Entry+6, 45767),
(@Entry+6, 45768),
(@Entry+6, 45769);
-- Glyph: Priest (Major)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42396, 42397, 42398, 42399, 42400, 42401, 42402, 42403, 42404, 42405, 42406, 42407, 42408, 42409, 42410, 42411, 42412, 42414, 42415, 42416, 42417, 45753, 45755, 45756, 45757, 45758, 45760);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+7;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES
(@Entry+7, 42396),
(@Entry+7, 42397),
(@Entry+7, 42398),
(@Entry+7, 42399),
(@Entry+7, 42400),
(@Entry+7, 42401),
(@Entry+7, 42402),
(@Entry+7, 42403),
(@Entry+7, 42404),
(@Entry+7, 42405),
(@Entry+7, 42406),
(@Entry+7, 42407),
(@Entry+7, 42408),
(@Entry+7, 42409),
(@Entry+7, 42410),
(@Entry+7, 42411),
(@Entry+7, 42412),
(@Entry+7, 42414),
(@Entry+7, 42415),
(@Entry+7, 42416),
(@Entry+7, 42417),
(@Entry+7, 45753),
(@Entry+7, 45755),
(@Entry+7, 45756),
(@Entry+7, 45757),
(@Entry+7, 45758),
(@Entry+7, 45760);
-- Glyph: Death Knight (Major)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43533, 43534, 43536, 43537, 43538, 43541, 43542, 43543, 43545, 43546, 43547, 43548, 43549, 43550, 43551, 43552, 43553, 43554, 43825, 43826, 43827, 45799, 45800, 45803, 45804, 45805, 45806);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+8;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES
(@Entry+8, 43533),
(@Entry+8, 43534),
(@Entry+8, 43536),
(@Entry+8, 43537),
(@Entry+8, 43538),
(@Entry+8, 43541),
(@Entry+8, 43542),
(@Entry+8, 43543),
(@Entry+8, 43545),
(@Entry+8, 43546),
(@Entry+8, 43547),
(@Entry+8, 43548),
(@Entry+8, 43549),
(@Entry+8, 43550),
(@Entry+8, 43551),
(@Entry+8, 43552),
(@Entry+8, 43553),
(@Entry+8, 43554),
(@Entry+8, 43825),
(@Entry+8, 43826),
(@Entry+8, 43827),
(@Entry+8, 45799),
(@Entry+8, 45800),
(@Entry+8, 45803),
(@Entry+8, 45804),
(@Entry+8, 45805),
(@Entry+8, 45806);
-- Glyph: Shaman (Major)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (41517, 41518, 41524, 41526, 41527, 41529, 41530, 41531, 41532, 41533, 41534, 41535, 41536, 41537, 41538, 41539, 41540, 41541, 41542, 41547, 41552, 45770, 45771, 45772, 45775, 45776, 45777, 45778);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+9;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES
(@Entry+9, 41517),
(@Entry+9, 41518),
(@Entry+9, 41524),
(@Entry+9, 41526),
(@Entry+9, 41527),
(@Entry+9, 41529),
(@Entry+9, 41530),
(@Entry+9, 41531),
(@Entry+9, 41532),
(@Entry+9, 41533),
(@Entry+9, 41534),
(@Entry+9, 41535),
(@Entry+9, 41536),
(@Entry+9, 41537),
(@Entry+9, 41538),
(@Entry+9, 41539),
(@Entry+9, 41540),
(@Entry+9, 41541),
(@Entry+9, 41542),
(@Entry+9, 41547),
(@Entry+9, 41552),
(@Entry+9, 45770),
(@Entry+9, 45771),
(@Entry+9, 45772),
(@Entry+9, 45775),
(@Entry+9, 45776),
(@Entry+9, 45777),
(@Entry+9, 45778);
-- Glyph: Mage (Major)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42734, 42735, 42736, 42737, 42738, 42739, 42740, 42741, 42742, 42743, 42744, 42745, 42746, 42747, 42748, 42749, 42750, 42751, 42752, 42753, 42754, 44684, 44955, 45736, 45737, 45738, 45739, 45740, 50045);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+10;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES
(@Entry+10, 42734),
(@Entry+10, 42735),
(@Entry+10, 42736),
(@Entry+10, 42737),
(@Entry+10, 42738),
(@Entry+10, 42739),
(@Entry+10, 42740),
(@Entry+10, 42741),
(@Entry+10, 42742),
(@Entry+10, 42743),
(@Entry+10, 42744),
(@Entry+10, 42745),
(@Entry+10, 42746),
(@Entry+10, 42747),
(@Entry+10, 42748),
(@Entry+10, 42749),
(@Entry+10, 42750),
(@Entry+10, 42751),
(@Entry+10, 42752),
(@Entry+10, 42753),
(@Entry+10, 42754),
(@Entry+10, 44684),
(@Entry+10, 44955),
(@Entry+10, 45736),
(@Entry+10, 45737),
(@Entry+10, 45738),
(@Entry+10, 45739),
(@Entry+10, 45740),
(@Entry+10, 50045);
-- Glyph: Warlock (Major)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42453, 42454, 42455, 42456, 42457, 42458, 42459, 42460, 42461, 42462, 42463, 42464, 42465, 42466, 42467, 42468, 42469, 42470, 42471, 42473, 45779, 45780, 45781, 45782, 45783, 45785, 45789, 50077);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+11;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES
(@Entry+11, 42453),
(@Entry+11, 42454),
(@Entry+11, 42455),
(@Entry+11, 42456),
(@Entry+11, 42457),
(@Entry+11, 42458),
(@Entry+11, 42459),
(@Entry+11, 42460),
(@Entry+11, 42461),
(@Entry+11, 42462),
(@Entry+11, 42463),
(@Entry+11, 42464),
(@Entry+11, 42465),
(@Entry+11, 42466),
(@Entry+11, 42467),
(@Entry+11, 42468),
(@Entry+11, 42469),
(@Entry+11, 42470),
(@Entry+11, 42471),
(@Entry+11, 42473),
(@Entry+11, 45779),
(@Entry+11, 45780),
(@Entry+11, 45781),
(@Entry+11, 45782),
(@Entry+11, 45783),
(@Entry+11, 45785),
(@Entry+11, 45789),
(@Entry+11, 50077);
-- Glyph: Druid (Major)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40896, 40897, 40899, 40900, 40901, 40902, 40903, 40906, 40908, 40909, 40912, 40913, 40914, 40915, 40916, 40919, 40920, 40921, 40922, 40923, 40924, 44928, 45601, 45602, 45603, 45604, 45622, 45623, 46372, 48720, 50125);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+12;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES
(@Entry+12, 40896),
(@Entry+12, 40897),
(@Entry+12, 40899),
(@Entry+12, 40900),
(@Entry+12, 40901),
(@Entry+12, 40902),
(@Entry+12, 40903),
(@Entry+12, 40906),
(@Entry+12, 40908),
(@Entry+12, 40909),
(@Entry+12, 40912),
(@Entry+12, 40913),
(@Entry+12, 40914),
(@Entry+12, 40915),
(@Entry+12, 40916),
(@Entry+12, 40919),
(@Entry+12, 40920),
(@Entry+12, 40921),
(@Entry+12, 40922),
(@Entry+12, 40923),
(@Entry+12, 40924),
(@Entry+12, 44928),
(@Entry+12, 45601),
(@Entry+12, 45602),
(@Entry+12, 45603),
(@Entry+12, 45604),
(@Entry+12, 45622),
(@Entry+12, 45623),
(@Entry+12, 46372),
(@Entry+12, 48720),
(@Entry+12, 50125);
-- Glyph: Warrior (Minor)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43395, 43396, 43397, 43398, 43399, 43400, 49084);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+13;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES
(@Entry+13, 43395),
(@Entry+13, 43396),
(@Entry+13, 43397),
(@Entry+13, 43398),
(@Entry+13, 43399),
(@Entry+13, 43400),
(@Entry+13, 49084);
-- Glyph: Paladin (Minor)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43340, 43365, 43366, 43367, 43368, 43369);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+14;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES
(@Entry+14, 43340),
(@Entry+14, 43365),
(@Entry+14, 43366),
(@Entry+14, 43367),
(@Entry+14, 43368),
(@Entry+14, 43369);
-- Glyph: Hunter (Minor)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43338, 43350, 43351, 43354, 43355, 43356);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+15;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES
(@Entry+15, 43338),
(@Entry+15, 43350),
(@Entry+15, 43351),
(@Entry+15, 43354),
(@Entry+15, 43355),
(@Entry+15, 43356);
-- Glyph: Rogue (Minor)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43343, 43376, 43377, 43378, 43379, 43380);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+16;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES
(@Entry+16, 43343),
(@Entry+16, 43376),
(@Entry+16, 43377),
(@Entry+16, 43378),
(@Entry+16, 43379),
(@Entry+16, 43380);
-- Glyph: Priest (Minor)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43342, 43370, 43371, 43372, 43373, 43374);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+17;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES
(@Entry+17, 43342),
(@Entry+17, 43370),
(@Entry+17, 43371),
(@Entry+17, 43372),
(@Entry+17, 43373),
(@Entry+17, 43374);
-- Glyph: Death Knight (Minor)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43535, 43539, 43544, 43671, 43672, 43673);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+18;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES
(@Entry+18, 43535),
(@Entry+18, 43539),
(@Entry+18, 43544),
(@Entry+18, 43671),
(@Entry+18, 43672),
(@Entry+18, 43673);
-- Glyph: Shaman (Minor)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43344, 43381, 43385, 43386, 43388, 43725, 44923);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+19;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES
(@Entry+19, 43344),
(@Entry+19, 43381),
(@Entry+19, 43385),
(@Entry+19, 43386),
(@Entry+19, 43388),
(@Entry+19, 43725),
(@Entry+19, 44923);
-- Glyph: Mage (Minor)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43339, 43357, 43359, 43360, 43361, 43362, 43364, 44920);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+20;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES
(@Entry+20, 43339),
(@Entry+20, 43357),
(@Entry+20, 43359),
(@Entry+20, 43360),
(@Entry+20, 43361),
(@Entry+20, 43362),
(@Entry+20, 43364),
(@Entry+20, 44920);
-- Glyph: Warlock (Minor)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43389, 43390, 43391, 43392, 43393, 43394);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+21;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES
(@Entry+21, 43389),
(@Entry+21, 43390),
(@Entry+21, 43391),
(@Entry+21, 43392),
(@Entry+21, 43393),
(@Entry+21, 43394);
-- Glyph: Druid (Minor)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43316, 43331, 43332, 43334, 43335, 43674, 44922);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+22;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES
(@Entry+22, 43316),
(@Entry+22, 43331),
(@Entry+22, 43332),
(@Entry+22, 43334),
(@Entry+22, 43335),
(@Entry+22, 43674),
(@Entry+22, 44922);

-- Gem: Meta
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (41285, 41307, 41333, 41335, 41339, 41375, 41376, 41377, 41378, 41379, 41380, 41381, 41382, 41385, 41389, 41395, 41396, 41397, 41398, 41400, 41401);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+23;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES
(@Entry+23, 41285),
(@Entry+23, 41307),
(@Entry+23, 41333),
(@Entry+23, 41335),
(@Entry+23, 41339),
(@Entry+23, 41375),
(@Entry+23, 41376),
(@Entry+23, 41377),
(@Entry+23, 41378),
(@Entry+23, 41379),
(@Entry+23, 41380),
(@Entry+23, 41381),
(@Entry+23, 41382),
(@Entry+23, 41385),
(@Entry+23, 41389),
(@Entry+23, 41395),
(@Entry+23, 41396),
(@Entry+23, 41397),
(@Entry+23, 41398),
(@Entry+23, 41400),
(@Entry+23, 41401),
(@Entry+23, 44076),
(@Entry+23, 44078),
(@Entry+23, 44081),
(@Entry+23, 44082),
(@Entry+23, 44084),
(@Entry+23, 44087),
(@Entry+23, 44088),
(@Entry+23, 44089);
-- Gem: Red
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40111, 40112, 40113, 40114, 40115, 40116, 40117, 40118, 45862, 45879, 45883);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+24;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES
(@Entry+24, 40111),
(@Entry+24, 40112),
(@Entry+24, 40113),
(@Entry+24, 40114),
(@Entry+24, 40115),
(@Entry+24, 40116),
(@Entry+24, 40117),
(@Entry+24, 40118),
(@Entry+24, 45862),
(@Entry+24, 45879),
(@Entry+24, 45883);
-- Gem: Blue
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40119, 40120, 40121, 40122, 45880, 45881);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+25;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES
(@Entry+25, 40119),
(@Entry+25, 40120),
(@Entry+25, 40121),
(@Entry+25, 40122),
(@Entry+25, 45880),
(@Entry+25, 45881);
-- Gem: Yellow
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40123, 40124, 40125, 40126, 40127, 40128, 45882, 45987);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+26;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES
(@Entry+26, 40123),
(@Entry+26, 40124),
(@Entry+26, 40125),
(@Entry+26, 40126),
(@Entry+26, 40127),
(@Entry+26, 40128),
(@Entry+26, 45882),
(@Entry+26, 45987);
-- Gem: Purple
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40129, 40130, 40131, 40132, 40133, 40134, 40135, 40136, 40137, 40138, 40139, 40140, 40141);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+27;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES
(@Entry+27, 40129),
(@Entry+27, 40130),
(@Entry+27, 40131),
(@Entry+27, 40132),
(@Entry+27, 40133),
(@Entry+27, 40134),
(@Entry+27, 40135),
(@Entry+27, 40136),
(@Entry+27, 40137),
(@Entry+27, 40138),
(@Entry+27, 40139),
(@Entry+27, 40140),
(@Entry+27, 40141);
-- Gem: Green
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40164, 40165, 40166, 40167, 40168, 40169, 40170, 40171, 40172, 40173, 40174, 40175, 40176, 40177, 40178, 40179, 40180, 40181, 40182);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+28;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES
(@Entry+28, 40164),
(@Entry+28, 40165),
(@Entry+28, 40166),
(@Entry+28, 40167),
(@Entry+28, 40168),
(@Entry+28, 40169),
(@Entry+28, 40170),
(@Entry+28, 40171),
(@Entry+28, 40172),
(@Entry+28, 40173),
(@Entry+28, 40174),
(@Entry+28, 40175),
(@Entry+28, 40176),
(@Entry+28, 40177),
(@Entry+28, 40178),
(@Entry+28, 40179),
(@Entry+28, 40180),
(@Entry+28, 40181),
(@Entry+28, 40182);
-- Gem: Orange
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40142, 40143, 40144, 40145, 40146, 40147, 40148, 40149, 40150, 40151, 40152, 40153, 40154, 40155, 40156, 40157, 40158, 40159, 40160, 40161, 40162, 40163);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+29;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES
(@Entry+29, 40142),
(@Entry+29, 40143),
(@Entry+29, 40144),
(@Entry+29, 40145),
(@Entry+29, 40146),
(@Entry+29, 40147),
(@Entry+29, 40148),
(@Entry+29, 40149),
(@Entry+29, 40150),
(@Entry+29, 40151),
(@Entry+29, 40152),
(@Entry+29, 40153),
(@Entry+29, 40154),
(@Entry+29, 40155),
(@Entry+29, 40156),
(@Entry+29, 40157),
(@Entry+29, 40158),
(@Entry+29, 40159),
(@Entry+29, 40160),
(@Entry+29, 40161),
(@Entry+29, 40162),
(@Entry+29, 40163);

-- Container
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (1729, 3604, 3605, 22243);
UPDATE `item_template` SET `maxcount`=0 WHERE `entry`=1729;
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+30;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES
(@Entry+30, 1729),
(@Entry+30, 3604),
(@Entry+30, 3605),
(@Entry+30, 22243);
