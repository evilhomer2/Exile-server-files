/*
	"sectorb" static mission for Altis.
	Created by eraser1
	Credits to "Darth Rogue" for creating the base.
*/

// For logging purposes
_num = DMS_MissionCount;


// Set mission side (only "bandit" is supported for now)
_side = "bandit";

_pos = [22698,19711,0];

if ([_pos,DMS_StaticMinPlayerDistance] call DMS_fnc_IsPlayerNearby) exitWith {"delay"};


// Set general mission difficulty
_difficulty = "difficult";


// Define spawn locations for AI Soldiers. These will be used for the initial spawning of AI as well as reinforcements.
// The center spawn location is added 3 times so at least 3 AI will spawn initially at the center location, and so that future reinforcements are more likely to spawn at the center.
_AISoldierSpawnLocations =
[
	_pos,
	_pos,
	_pos,
	[23025.751953,19293.861328,0.00143862],
	[22992.705078,19570.339844,0.00143862],
	[22968.332031,19947.615234,0.00143862],
	[22574.429688,20229.257813,0.00143862],
	[22480.148438,20027.519531,0.00143862],
	[22499.912109,19790.904297,0.00143862],
	[22461.966797,19478.164063,0.00143862],
	[22422.921875,19232.820313,0],
	[22655.435547,19070.40625,0],
	[22190.574219,19426.90625,0],
	[22226.789063,19679.146484,0],
	[22237.111328,19690.556641,0],
	[22218.667969,19857.771484,0],
	[22287.675781,20033.203125,0],
	[22764.445313,19287.0585938,0],
	[22765.0996094,19555.298828,0],
	[22768.619141,19810.292969,0]
];

// Create AI
_AICount = 20 + (round (random 5));


_group =
[
	_AISoldierSpawnLocations,
	_AICount,
	_difficulty,
	"random",
	_side
] call DMS_fnc_SpawnAIGroup_MultiPos;


_staticGuns =
[
	[
		_pos vectorAdd [5,0,0],			// 5 meters East of center pos
		_pos vectorAdd [-5,0,0],		// 5 meters West of center pos
		_pos vectorAdd [0,5,0],			// 5 meters North of center pos
		_pos vectorAdd [0,-5,0],		// 5 meters South of center pos
		[22892.841797,19841.365234,12.764622],			// Top of NorthWest Tower
		[22766.492188,19234.724609,0],			// Top of NorthEast Tower
		[22197.535156,19250.287109,0],			// Top of SouthEast Tower
		[22185.101563,19267.111328,0],			// Top of SouthWest Tower
		[22139.515625,19847.607422,0.00274658]			// Top of the concrete water tower thing.
	],
	_group,
	"assault",
	_difficulty,
	"bandit",
	"random"
] call DMS_fnc_SpawnAIStaticMG;



// Create Crate
_crateClassname = "I_CargoNet_01_ammo_F";
deleteVehicle (nearestObject [_pos, _crateClassname]);		// Make sure to remove any previous crate.

_crate = [_crateClassname, _pos] call DMS_fnc_SpawnCrate;


// Spawn the vehicle AFTER the base so that it spawns the vehicle in a (relatively) clear position.
_veh =
[
	[
		[_pos,100,random 360] call DMS_fnc_SelectOffsetPos,
		_pos
	],
	_group,
	"assault",
	_difficulty,
	_side
] call DMS_fnc_SpawnAIVehicle;


// Define mission-spawned AI Units
_missionAIUnits =
[
	_group 		// We only spawned the single group for this mission
];

// Define the group reinforcements
_groupReinforcementsInfo =
[
	[
		_group,			// pass the group
		[
			[
				10,		// Only 10 "waves" (5 vehicles can spawn as reinforcement)
				0
			],
			[
				-1,		// No need to limit the number of units since we're limiting "waves"
				0
			]
		],
		[
			300,		// At least a 5 minute delay between reinforcements.
			diag_tickTime
		],
		[
			[22992.705078,19570.339844,0.00143862],
			[22993.705078,19570.339844,0.00143862],
			[22994.705078,19572.339844,0.00143862],
			[22995.705078,19573.339844,0.00143862],
			[22996.705078,19574.339844,0.00143862],
			[22997.705078,19575.339844,0.00143862],
			[22998.705078,19576.339844,0.00143862],
			[22999.705078,19577.339844,0.00143862],
			[22300.705078,19578.339844,0.00143862]
		],
		"random",
		_difficulty,
		_side,
		"armed_vehicle",
		[
			15,			// Reinforcements will only trigger if there's fewer than 7 members left in the group
			"random"	// Select a random armed vehicle from "DMS_ArmedVehicles"
		]
	],
	[
		_group,			// pass the group (again)
		[
			[
				0,		// Let's limit number of units instead...
				0
			],
			[
				100,	// Maximum 100 units can be given as reinforcements.
				0
			]
		],
		[
			240,		// About a 4 minute delay between reinforcements.
			diag_tickTime
		],
		_AISoldierSpawnLocations,
		"random",
		_difficulty,
		_side,
		"reinforce",
		[
			10,			// Reinforcements will only trigger if there's fewer than 10 members left in the group
			7			// 7 reinforcement units per wave.
		]
	]
];

// Define mission-spawned objects and loot values
_missionObjs =
[
	_staticGuns+[_veh],			// armed AI vehicle and static gun(s). Note, we don't add the base itself because we don't want to delete it and respawn it if the mission respawns.
	[],
	[[_crate,[75,250,5]]]
];

// Define Mission Start message
_msgStart = ['#FFFF00', "A heavily guarded base has been located Sector B! There are reports they have a large weapon cache..."];

// Define Mission Win message
_msgWIN = ['#0080ff',"Convicts have successfully assaulted the base at Sector B and secured the cache!"];

// Define Mission Lose message
_msgLOSE = ['#FF0000',"Seems like the guards got bored and left the base, taking the cache with them..."];

// Define mission name (for map marker and logging)
_missionName = "AI Base";

// Create Markers
_markers =
[
	_pos,
	_missionName,
	_difficulty
] call DMS_fnc_CreateMarker;

(_markers select 1) setMarkerSize [1500,1500];

// Record time here (for logging purposes, otherwise you could just put "diag_tickTime" into the "DMS_AddMissionToMonitor" parameters directly)
_time = diag_tickTime;

// Parse and add mission info to missions monitor
_added =
[
	_pos,
	[
		[
			"kill",
			_group
		],
		[
			"playerNear",
			[_pos,100]
		]
	],
	_groupReinforcementsInfo,
	[
		_time,
		DMS_StaticMissionTimeOut call DMS_fnc_SelectRandomVal
	],
	_missionAIUnits,
	_missionObjs,
	[_missionName,_msgWIN,_msgLOSE],
	_markers,
	_side,
	_difficulty,
	[[],[]]
] call DMS_fnc_AddMissionToMonitor_Static;

// Check to see if it was added correctly, otherwise delete the stuff
if !(_added) exitWith
{
	diag_log format ["DMS ERROR :: Attempt to set up mission %1 with invalid parameters for DMS_fnc_AddMissionToMonitor_Static! Deleting mission objects and resetting DMS_MissionCount.",_missionName];

	_cleanup = [];
	{
		_cleanup pushBack _x;
	} forEach _missionAIUnits;

	_cleanup pushBack ((_missionObjs select 0)+(_missionObjs select 1));
	
	{
		_cleanup pushBack (_x select 0);
	} foreach (_missionObjs select 2);

	_cleanup call DMS_fnc_CleanUp;


	// Delete the markers directly
	{deleteMarker _x;} forEach _markers;


	// Reset the mission count
	DMS_MissionCount = DMS_MissionCount - 1;
};


// Notify players
[_missionName,_msgStart] call DMS_fnc_BroadcastMissionStatus;



if (DMS_DEBUG) then
{
	(format ["MISSION: (%1) :: Mission #%2 started at %3 with %4 AI units and %5 difficulty at time %6",_missionName,_num,_pos,_AICount,_difficulty,_time]) call DMS_fnc_DebugLog;
};