--Automatically generated by SWGEmu Spawn Tool v0.12 loot editor.

carbine_dh17_snubnose = {
	minimumLevel = 0,
	maximumLevel = -1,
	customObjectName = "",
	directObjectTemplate = "object/weapon/ranged/carbine/carbine_dh17_snubnose.iff",
	craftingValues = {
		{"mindamage",28,52,0},
		{"maxdamage",81,150,0},
		{"attackspeed",4.5,3.1,1},
		{"woundchance",6,12,0},
		{"roundsused",30,54,0},
		{"hitpoints",750,1500,0},
		{"zerorangemod",-25,-25,0},
		{"maxrangemod",-80,-80,0},
		{"midrange",25,25,0},
		{"midrangemod",-5,5,0},
		{"attackhealthcost",29,15,0},
		{"attackactioncost",31,17,0},
		{"attackmindcost",16,8,0},
	},
	customizationStringNames = {},
	customizationValues = {},

	-- randomDotChance: The chance of this weapon object dropping with a random dot on it. Higher number means less chance. Set to 0 to always have a random dot.
	randomDotChance = 800,
	junkDealerTypeNeeded = JUNKWEAPONS,
	junkMinValue = 25,
	junkMaxValue = 45

}

addLootItemTemplate("carbine_dh17_snubnose", carbine_dh17_snubnose)
