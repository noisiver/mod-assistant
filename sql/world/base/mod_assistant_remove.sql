SET @Entry := 9000000;
-- Creature template
DELETE FROM `creature_template` WHERE `entry`=@Entry;
-- Spawn points for Stormwind, Orgrimmar and Dalaran
DELETE FROM `creature` WHERE `id`=@Entry;

-- Heirloom: Weapon
DELETE FROM `npc_vendor` WHERE `entry`=@Entry;
-- Heirloom: Armor
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+1;
-- Heirloom: Other
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+2;
-- Glyph: Warrior (Major)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+3;
-- Glyph: Paladin (Major)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+4;
-- Glyph: Hunter (Major)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+5;
-- Glyph: Rogue (Major)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+6;
-- Glyph: Priest (Major)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+7;
-- Glyph: Death Knight (Major)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+8;
-- Glyph: Shaman (Major)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+9;
-- Glyph: Mage (Major)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+10;
-- Glyph: Warlock (Major)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+11;
-- Glyph: Druid (Major)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+12;
-- Glyph: Warrior (Minor)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+13;
-- Glyph: Paladin (Minor)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+14;
-- Glyph: Hunter (Minor)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+15;
-- Glyph: Rogue (Minor)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+16;
-- Glyph: Priest (Minor)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+17;
-- Glyph: Death Knight (Minor)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+18;
-- Glyph: Shaman (Minor)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+19;
-- Glyph: Mage (Minor)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+20;
-- Glyph: Warlock (Minor)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+21;
-- Glyph: Druid (Minor)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+22;
-- Gem: Meta
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+23;
-- Gem: Red
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+24;
-- Gem: Blue
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+25;
-- Gem: Yellow
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+26;
-- Gem: Purple
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+27;
-- Gem: Green
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+28;
-- Gem: Orange
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+29;
-- Container
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+30;

-- Container
UPDATE `item_template` SET `BuyPrice`=250000, `SellPrice`=62500 WHERE `entry`=41597;
UPDATE `item_template` SET `BuyPrice`=150000, `SellPrice`=37500 WHERE `entry` IN (44447, 44448);
