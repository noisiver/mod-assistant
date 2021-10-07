SET @Entry := 9000000;
DELETE FROM `creature_template` WHERE `entry`=@Entry;
DELETE FROM `creature` WHERE `id`=@Entry;

DELETE FROM `npc_vendor` WHERE `entry`=@Entry;
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+1;
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+2;
