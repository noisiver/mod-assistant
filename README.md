# Assistant
The assistant is a module for [AzerothCore](https://github.com/azerothcore/azerothcore-wotlk).

The module incorporates all the features I want added to the core. I am aware that there are modules that include some of these features, however it gave me an excuse to learn more about C++ and SQL.

# Features
* The assistant is a npc spawned in the world and lets a player obtain heirlooms, glyphs, gems, utilities like faction change and race change, and totems for the shaman class. All items obtained from the Assistant are free to purchase, however users can easily add a cost by modifying the values of the item template table.
* The spawn point allow users to automatically teleport new characters to certain locations in the world when entering the world for the first time. It does, currently, not set the location for hearthstone.
* The weekend bonus allow players to gain twice the experience and reputation when exploring the world, completing quests and killing creatures on weekends.
* The spell handler allow players to learn new class spells, talent ranks, weapon and defense skills, setting weapon skills to their max value and riding skill and mounts when leveling up or entering into the world.

All the features listed above are enabled, or disabled, through the configuration - allowing a user to only use the features they want.
