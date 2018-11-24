/*
	Author: Chris(tian) "infiSTAR" Lorenzen
	Contact: infiSTAR23@gmail.com // www.infiSTAR.de
	Copyright infiSTAR. All rights reserved.
	
	Description:
	Arma AntiHack & AdminTools - infiSTAR.de
	
	licensed to:
	'nathan.lloyd1983@googlemail.com'
	
	Last download was on:
	'03-07-2018 10-04-18';
*/
class Cfg_infiSTAR_settings {
/*
	"serverCommandPassword" is serverCommandPassword - in your servers config.cfg
	if your config.cfg does not have serverCommandPassword yet, simply add it in a new line:
	serverCommandPassword = "changeme";
	
	This is   VERY IMPORTANT   as it is needed to KICK & BAN people.
	
	It will try to get this password from "@ExileServer\addons\exile_server_config" first. If you did not set a password there (config.cpp),
	then it will take what you put here.
*/
serverCommandPassword = "changeme";

/*
	"passwordAdmin" is passwordAdmin - in your servers config.cfg, needed for servercommands from client
	
	This is used to be able to use the "login" function ingame. Will log you in as Arma "Admin".
*/
passwordAdmin = "changeme";
/* serverCommandPassword and passwordAdmin should always be different passwords or it could cause problems! */



HIDE_FROM_PLAYERS = "false";				/* So no normal can see it :)! */
announce_adminstate_changed = "false";	/* whenever you type !admin as an admin it will announce that you logged out or in to all players on the server! */

LogAdminActions = "true";	/* "LogAdminActions": Sends actions done by each admin to the server to log it to the .txt file (if infiSTAR dlls are used) and .rpt file + sends it back to all other admins. */
enableIngameLogs = "true";	/* These logs are shown in the admin menu (disabling it might lower performance cost, since it sends a lot of big strings through the network) */

MY_LOG_FOLDER = "";	/* MY_LOG_FOLDER = "infiSTAR Logs"; - would create a folder named "infiSTAR Logs" */



/* 
	if you set "useAdminNameTag" to "true",
	each admin uid can have an individual AdminTag which needs to be a part of the admins name.
	Without it, the admin will not get access to the admin menu.
	
	example names: "[Admin] PlayerName" or "PlayerName [Admin]"
	note: this is case sensitive as well, meaning "PlayerName [admin]" would not work as we set our example to "[Admin]"
*/
class adminNameTags {
	useAdminNameTag = "false";
	tags[] = {
		{"[Admin]","UID1"},
		{"[Owner]","UID2"},
		{"[Slave]","UID3"},
		{"[Admin]","UID4"},
		{"[Admin]","UID5"}
	};
};


/* "startAsNormal": if you add admin UIDs in here as well, they will start as almost "normal" player instead of with admin menu and such. */
startAsNormal[] =
{
	"UID1","UID2","UID3","..."
};

/* "hiddenSuperAdmin": These admins are seen as normal players by normal admins, their actions are not logged either (to keep an eye out on your admins) */
hiddenSuperAdmin[] =
{
	"UID1","UID2","UID3","..."
};

adminUIDandAccess[] =
{
	{
		{"UID1","UID2","UID3","..."},	/* Admins with UIDs in this Array have their Access defined in the array below. */
		{
			"Territory Management",
			"Teleport On Map Click","Teleport - Target To Me","Teleport - Me To Target",
			"Teleport In Facing Direction (10m steps)","Drag and drop units on the map",
			"spectating","Delete Vehicle","FlyUp","ShowGear","Show Server Information",
			"HealSelf","HealRepairNear","AdminLog","Freeze","UnFreeze","Restrain","UnRestrain",
			"==== Loadouts ====","==== Base Deleter ====","Items spawn menu",
			"Remove Gear","Revive","Heal","Restore","Flip Vehicle","Move In My Vehicle","Move In Target Vehicle","Parachute Target","Eject","Eject Crew",
			"Player ESP","Player ESP (safezone style)","AI ESP","Dead ESP","Loot ESP",
			"Vehicle Marker","Flag Marker (with radius)","Box/Safe/Container Marker","DeadPlayer Marker",
			"God Mode","God Mode (no stats change)","Vehicle God Mode","Lower Terrain","Vehboost","UnlimAmmo","noRecoil","FastFire","Stealth / Invisible",
			"Disable Announces","Mass Message","Change Time","Spawn Support-Boxes","Create Billboard","Change ViewDistance",
			"Spawn Ammo","Login as Arma Admin","BIS FreeRoam Cam (works with ESP)","FreeRoam Cam (does not work with ESP)",
			"Request Steam Name","showinfo",
			"UnlockLockVehicle","Copy Worldspace(coords) to RPT & Chat",
			
			"Spawn Vehicles","Spawn Persistent Vehicles","Trader Menu",
			
			"Kill","Explode","Force Disconnect",
			"Kick (Silent)","Kick (Announce)","Ban (Silent)","Ban (Announce)","TempBan (Silent)","TempBan (Announce)",
			
			"AdminConsole",
			"DebugConsole",
			"Execute code on server (DebugConsole)","Execute code global (DebugConsole)","Execute code local (DebugConsole)",
			"Lock Server (DebugConsole)","UnLock Server (DebugConsole)","Ban (DebugConsole)","Kick (DebugConsole)",
			
			"Change Money on Player","Change Money on Bank","Change Respect",
			
			"MapIcons",
			"MapIcons: Buildings","MapIcons: Flags",
			"MapIcons: Player","MapIcons: DeadPlayer","MapIcons: Vehicles",
			"MapIcons: Vehicle Types","MapIcons: Vehicle lockstate","MapIcons: DeadVehicles",
			"MapIcons: AI",
			"Arsenal",	// Adds Arsenal to the mousewheel actions if you press "," on the Numpad!
			"Unconscious","Remove Unconscious",
			"Light",	// Zeus like Lighting from the Air strikes down at selected player / target / location - use ctrl+1 or the menu to use it!
			
			"Spawn Zombie on Target Location!",	// This only works when you are using ExilZ / RyanZombies
			
			""
		}
	},
	{
		{"UID1","UID2","UID3","..."},
		{
			"Teleport On Map Click","Teleport - Target To Me","Teleport - Me To Target",
			"Teleport In Facing Direction (10m steps)","Drag and drop units on the map",
			"spectating","Delete Vehicle","FlyUp","ShowGear","Show Server Information",
			"HealSelf","HealRepairNear","AdminLog","Freeze","UnFreeze","Restrain","UnRestrain",
			"==== Loadouts ====","==== Base Deleter ====","Items spawn menu",
			"Remove Gear","Revive","Heal","Restore","Flip Vehicle","Move In My Vehicle","Move In Target Vehicle","Parachute Target","Eject","Eject Crew",
			"Player ESP","Player ESP (safezone style)","AI ESP","Dead ESP","Loot ESP",
			"Vehicle Marker","Flag Marker (with radius)","Box/Safe/Container Marker","DeadPlayer Marker",
			"God Mode","God Mode (no stats change)","Vehicle God Mode","Lower Terrain","Vehboost","UnlimAmmo","noRecoil","FastFire","Stealth / Invisible",
			"Disable Announces","Mass Message","Change Time","Spawn Support-Boxes","Create Billboard","Change ViewDistance",
			"Spawn Ammo","Login as Arma Admin","BIS FreeRoam Cam (works with ESP)","FreeRoam Cam (does not work with ESP)",
			"Request Steam Name","showinfo",
			"UnlockLockVehicle","Copy Worldspace(coords) to RPT & Chat",
			
			"Spawn Vehicles","Spawn Persistent Vehicles","Trader Menu",
			
			"Kill","Explode","Force Disconnect",
			"Kick (Silent)","Kick (Announce)","Ban (Silent)","Ban (Announce)","TempBan (Silent)","TempBan (Announce)",
			
			"AdminConsole",
			"DebugConsole",
			"Execute code on server (DebugConsole)","Execute code global (DebugConsole)","Execute code local (DebugConsole)",
			"Lock Server (DebugConsole)","UnLock Server (DebugConsole)","Ban (DebugConsole)","Kick (DebugConsole)",
			
			"Change Money on Player","Change Money on Bank","Change Respect",
			
			"MapIcons",
			"MapIcons: Buildings","MapIcons: Flags",
			"MapIcons: Player","MapIcons: DeadPlayer","MapIcons: Vehicles",
			"MapIcons: Vehicle Types","MapIcons: Vehicle lockstate","MapIcons: DeadVehicles",
			"MapIcons: AI",
			"Arsenal",
			"Unconscious","Remove Unconscious",
			"Light",
			
			"Spawn Zombie on Target Location!",
			
			""
		}
	},
	{
		{"UID1","UID2","UID3","..."},
		{
			"Teleport On Map Click","Teleport - Target To Me","Teleport - Me To Target",
			"Teleport In Facing Direction (10m steps)","Drag and drop units on the map",
			"spectating","Delete Vehicle","FlyUp","ShowGear","Show Server Information",
			"HealSelf","HealRepairNear","AdminLog","Freeze","UnFreeze","Restrain","UnRestrain",
			"==== Loadouts ====","==== Base Deleter ====","Items spawn menu",
			"Remove Gear","Revive","Heal","Restore","Flip Vehicle","Move In My Vehicle","Move In Target Vehicle","Parachute Target","Eject","Eject Crew",
			"Player ESP","Player ESP (safezone style)","AI ESP","Dead ESP","Loot ESP",
			"Vehicle Marker","Flag Marker (with radius)","Box/Safe/Container Marker","DeadPlayer Marker",
			"God Mode","God Mode (no stats change)","Vehicle God Mode","Lower Terrain","Vehboost","UnlimAmmo","noRecoil","FastFire","Stealth / Invisible",
			"Disable Announces","Mass Message","Change Time","Spawn Support-Boxes","Create Billboard","Change ViewDistance",
			"Spawn Ammo","Login as Arma Admin","BIS FreeRoam Cam (works with ESP)","FreeRoam Cam (does not work with ESP)",
			"Request Steam Name","showinfo",
			"UnlockLockVehicle","Copy Worldspace(coords) to RPT & Chat",
			
			"Spawn Vehicles","Spawn Persistent Vehicles","Trader Menu",
			
			"Kill","Explode","Force Disconnect",
			"Kick (Silent)","Kick (Announce)","Ban (Silent)","Ban (Announce)","TempBan (Silent)","TempBan (Announce)",
			
			"AdminConsole",
			"DebugConsole",
			"Execute code on server (DebugConsole)","Execute code global (DebugConsole)","Execute code local (DebugConsole)",
			"Lock Server (DebugConsole)","UnLock Server (DebugConsole)","Ban (DebugConsole)","Kick (DebugConsole)",
			
			"Change Money on Player","Change Money on Bank","Change Respect",
			
			"MapIcons",
			"MapIcons: Buildings","MapIcons: Flags",
			"MapIcons: Player","MapIcons: DeadPlayer","MapIcons: Vehicles",
			"MapIcons: Vehicle Types","MapIcons: Vehicle lockstate","MapIcons: DeadVehicles",
			"MapIcons: AI",
			"Arsenal",
			"Unconscious","Remove Unconscious",
			"Light",
			
			"Spawn Zombie on Target Location!",
			
			""
		}
	}
};


/*
	Noficiations shown to all players on the server. Could be used to replace BEC messages.
	dynamic format:
		{
			first occurrence after x min,
			show again after x min,
			show message for x seconds / delay until next message is shown,
			font size (recommended is 0.6),
			xpos,
			ypos,
			text color,
			font,
			text (<br/> is a linebreak)
		}
	systemchat format:
		{
			first occurrence after x min,
			show again after x min,
			show message for x seconds / delay until next message is shown,
			text
		}

	if you want the client to see a message only once when logging in, you put the first and second entry in the array to -1.
	Example:	
		{-1, -1, 4, 0.6, 0, 0, "#ff0000", "OrbitronLight", "Welcome to our server"}
	
	xpos and ypos need to be within your monitor. to high numbers and you simply won't see the text..
		~ x-range is between -0.7 to +1
		~ y-range is between -0.4 to +1
	
	Arma Fonts:
		PuristaLight
		PuristaMedium
		PuristaSemiBold
		PuristaBold
		LucidaConsoleB
		EtelkaMonospacePro
		EtelkaMonospaceProBold
		EtelkaNarrowMediumPro
		TahomaB

	Exile Fonts:
		OrbitronLight
		OrbitronMedium
		PressStart2P
		RobotoMedium
		RobotoRegular
NOTE: do not use " within the text.
*/
ENABLE_NOTIFICATION_MESSAGES = "true";
NOTIFY_MSG_ARRAY[] =
{
	{-1, -1, 3, "Welcome"},
	{-1, -1, 3, "Enjoy your stay!"},
	{-1, -1, 6, 0.36, -0.7, 0.84, "#e5e5e5", "PuristaMedium", "Welcome<br/>Enjoy your stay!"},
	{-1, 20, 10, 0.36, -0.7, 0.84, "#e5e5e5", "PuristaMedium", "Protected and administrated by<br/>infiSTAR.de AdminTools, AntiHack and more!"}
};


/*
	{chatCommand (text typed in chat), color, size, font, text shown to player}
	only triggers if the EXACT text is typed!
NOTE: do not use " within the text.
*/
chatCommands[] =
{
	{"!ts","#2784D6","1","OrbitronMedium","ts.mycommunity.com"},
	{"!website","#2784D6","1","OrbitronMedium","www.mycommunity.com"},
	{"!admin","#2784D6","1","OrbitronMedium","please visit ts.mycommunity.com"}
};

/*
	{chatCommand (text typed in chat) partitial, color, size, font, text shown to player}
	"Hello, why is there no loot on this map?" <- will trigger the example below!
NOTE: do not use " within the text.
*/
chatCommandsP[] =
{
	{"no loot","#2784D6","1","OrbitronMedium","You cannot loot from non arma buildings in this map, you must move around - check the shipping yards for best loot"}
};

/*
	adds Exile Devs to your AdminList - makes it easier for them to debug their mod live
*/
ExileDevFriendlyMode = "true";

/*
	If admin has rights to "Create Billboard", he will have new options to create a Billboard ingame with one of the following textures
	{"name shown in adminmenu","path to texture"}
	
	should be looking somewhat like this:
	{"example picture","\mpmissions\Exile.Altis.pbo\example.paa"}
	
	the picture has to be available on EACH client AND the server.
	So you either need a client-side mod for it or you need to put it in the MPMission
*/
pathToCustomBillBoardTextures[] =
{
	{"Doggy","exile_assets\texture\flag\flag_mate_21dmd_co.paa"},
	{"Spawny","exile_assets\texture\flag\flag_mate_spawny_co.paa"},
	{"Dickbutt","exile_assets\texture\flag\flag_misc_dickbutt_co.paa"},
	{"Vish","exile_assets\texture\flag\flag_mate_vish_co.paa"}
};

/*
	You can allow clients to execute functions on the server by adding them like this:
	infiSTAR_RE_LIST[] =
	{
		"fn_infiSTAR_antiDupeServer","fn_infiSTAR_antiVehicleTheft","fn_infiSTAR_serverOwner"
	};
	
	make sure that those functions can't be abused to to any harm.
*/
infiSTAR_RE_LIST[] =
{
	
};
/****************************************************************************************************/
/********************OPTIONS BELOW REQUIRE CHANGES TO YOUR EXILE SERVER DATABASE!********************/
/****************************************************************************************************/
/*
	"customDatabaseQueries"
	To use any of the below, you need to do some changes to the exile.ini! 
	I've added these changes here:
		"infiSTAR.de_Exile\SERVER_ARMA3_FOLDER\db_related_changes"
*/
class customDatabaseQueries {
	/*
		if "USE_DATABASE_WHITELIST = "true";", UIDs that are not whitelisted in your exile server database, will be kicked on connect.
		exile.ini needs [getAccountWhitelisted]
	*/
	USE_DATABASE_WHITELIST = "false";

	/*
		if "USE_LOG_TO_DATABASE = "true";", infiSTAR will log to your exile server database! (yes I know this is great!)
		exile.ini needs [insert_infiSTARLog]
	*/
	USE_LOG_TO_DATABASE = "false";

	/*
		if "USE_GET_TOTAL_CONNECTIONS = "true";", infiSTAR can log how often a player has been connected to your server before.
		exile.ini needs [getTotalConnections]
	*/
	USE_GET_TOTAL_CONNECTIONS = "false";
};
/*
	if "USE_ANNOUNCE_NEW_PLAYER = "true";", infiSTAR will announce a "New Player: NAME" to the whole server!
*/
USE_ANNOUNCE_NEW_PLAYER = "true";
/****************************************************************************************************/
/********************OPTIONS ABOVE REQUIRE CHANGES TO YOUR EXILE SERVER DATABASE!********************/
/****************************************************************************************************/
/*
	Use UID WhiteList?
	if "USE_UID_WHITELIST = "true";", UIDs that are not in "UID_WHITELIST" array, will be kicked on connect.
	This even counts for Admins!
*/
USE_UID_WHITELIST = "false";
UID_WHITELIST[] =
{
	"UID1","UID2","UID3","..."
};


/*
	What is this?
	infiSTAR has a global ban system so hackers don't jump around servers and learn how to bypass infiSTAR.

	There was a situation where a group of people asked why their friend could not join the server.
	Well he was globally banned for hacking.. anyways - if you as a server admin want him to get in even tho he is globally banned,
	just ask for his UID and add the UID in the array below.
*/
USE_GLOBAL_BAN_CHECK = "true";			/* if false, it can not kick or ban global banned people but it will still "log" them. So you know a globally banned person joined your server. */
UID_SKIP_GLOBAL_BAN_CHECK[] =
{
	"UID1","UID2","UID3","..."
};
CHECK_BattlEye_GLOBALBANS = "false";	/* if you don't have BE enabled on your server, this can still check if a player has been banned globally on BattlEye */


/* What ESCAPE Menu shows */
ESCMNUTOP = "AntiHack & AdminTools";
ESCMNUBOT = "by infiSTAR.de";
BRIEFING_MSG = "false";	/* use mission briefing message: if   "BRIEFING_MSG = "false";"   then the message will be replaced by infiSTAR */
HTML_LOAD_URL = "";		/* HTML_LOAD_URL = ""; == disabled and if you set a url it will be shown in ESCAPE menu. HTML in Arma/this is limited. Try it :) example: "http://goo.gl/gb0o7b" */
ENABLE_PRIVATE_CHAT_MENU = "true";		/* players can open it by typing !chat in chat or by  custom controls -> "Use Action 3" */
PRIVATE_CHAT_MENU_8GNETWORK = "false";	/* if this is "true" - players will only be able to use private chat if they enable 8GNetwork in their xm8 */



class infiSTAR_RESTART_SYSTEM {
	enableSystem = "true";

	/*
		Locks the server when it starts, adds an eventhandler that kciks all players "on join" until the mpmission is initiated.
		That was the server can start up more properly and "build" all bases before the first players get in..
	*/
	LOCK_ON_RESTART = "false";

	/*
		I would recommend to use USE_RESTART_TIME_IN_M = "true"; instead of USE_RESTART_FIXED_TIME_ARRAY
	*/
	USE_RESTART_TIME_IN_M = "true";

	/*
		Restart time in minutes (default: 180min == 3 hours)
	*/
	RESTART_TIME_IN_M = 180;

	/*
		diag_tickTime (starts with arma3server.exe), time (starts with mpmission init)
	*/
	TIME_FUNCTION_USED = "diag_tickTime";

	USE_RESTART_FIXED_TIME_ARRAY = "false";
	RESTART_TIMES[] = {	/* {hour,minute} .. put in the times when your server is supposed to restart (real time). */
		{00,00},
		{02,00},
		{04,00},
		{06,00},
		{08,00},
		{10,00},
		{12,00},
		{14,00},
		{16,00},
		{18,00},
		{20,00},
		{22,00}
	};

	USE_SHUTDOWN = "true";
	SERVER_END_FUNCTION = "#shutdown";	/* SERVER_END_FUNCTION -> #shutdown or #restartserver */
	RESTART_WARNING_SOUND = "air_raid";	/* for example: Alarm or air_raid */

	LOCK_MIN_BEFORE_SHUTDOWN = 5;				/* Locks the server x min before it gets shutdown */
	RESTART_IN_X_ARRAY[] = {15,10,5,4,3,2,1};	/* Announce the a restart x mins before it happens (x stands for each number) */
};




/* Allow Player to vote Day/Night by typing vote day / vote night in Chat*/
DayNightVote = "true";
MRV = 0.3;	/* if "DayNightVote = "true";" - Minimum votes required. Percentage of players needed to pass the vote. */
MVP = 0.51;	/* if "DayNightVote = "true";" - Minimum vote percentage. A setting that dictates the minimum vote percentage that needs to be reached for the vote to pass. */
VCT = 900;	/* if "DayNightVote = "true";" - Time (in seconds) to wait until nex vote is possible. */


/* Enable jumping instead of GetOver function (infiSTAR jumping is a custom jump animation :P) */
enableJump = "true";


/* Allow players to type !pee (or !piss) to start peeing */
allowPee = "true";


/*
	How does this work?
	
	chatAnimationCommands[] = {
		{{"command1 for animation1","command2 for animation1"}, "animation1", animation time before it will be forced to be stopped},
		{{"command3 for animation2","command4 for animation2"}, "animation2", animation time of 0 means it will do the animation "forever" till the end unless it gets stops by the user manually.}
	};
*/
chatAnimationCommands[] = {
	{{"!finger","!fuck"},"acts_briefing_sb_in",7}, //shows fuck you finger
	{{"!surrender","!giveup","!hands"},"AmovPercMstpSsurWnonDnon",0}, //surrender animation (hands behind the head) 
	{{"!dab"},"Exile_Funny_Dab01",0} //Exile Dab animation (doing the dab)
};



/*
	The following 4 options can be disabled by putting the value to -1. For example "TGV = -1;"
*/
TGV = 40;	/* Terrain Grid Value - TGV: if set to 50 grass will be very low for better client FPS.. default is 12.5 ~35 is good performance and grass :) */
VDV = 750;	/* ViewDistance Value   */
VOV = 750;	/* ObjectViewDistance   */
SVD = 50;	/* ShadowViewDistance   */

/*
	checks if the terraingrid is different from default or TGV (12.5 or what you set in TGV). If you are using things that can change the grid, put this to false!
*/
CHECK_TERRAIN_GRID = "false";	// you should have this on false if you allow people to change their terrain in the xm8apps


/*
	*readded new old uniform and vest check since some people asked for it.
	http://www.exilemod.com/topic/14179-miss-uniform_and_vest_check/
	the game is still broken and sometimes you can see people naked when they are not.
	I did not add the old check back in, I made a new one making use of new functions :)
*/
fix_uniform_and_vest = "true";


/*
	checks if player tries to dupe using the "disconnect trick" -> sends a ping to the server whenever a player opens the escape menu
*/
disconnect_dupe_check = "true";


/*
	There is a way for players to dupe items if they drive a vehicle close to a trader, open the trader menu and then have a friend sit in the driver of the vehicle.
	Now they can sell the same item unlimited times and it won't vanish from the vehicle..
	That issue is fixed with this check!
*/
fix_trader_dupe = "true";

/*
	server side check for the famous "wastedump dupe" as well as client side cooldown
	the timer can not be lower than 120 seconds. if it was lower the check would not be working.
*/
fix_wastedump_dupe = "true";



class lagSwitchCheck {
	/*
		checks if the client connection to the server is established and not lagged out. Might cause a lot of server / network power
		after 25 seconds, the client will be kicked to lobby.
	*/
	enable = "false";

	warn_delay = 3.5; 			/* When a lag of 2.5 seconds was registered, the player is warned and won't be able to open any GUI (Gear, Tradermenu [..]) */
	log_delay = 10; 			/* server side log entry, when a lagswitch was detected that took longer than x seconds */
	kick_and_log_delay =  15; 	/* KICK and server side log entry, when a lagswitch was detected that took longer than x seconds */
};


class infiSTAR_blocked_glitch_actions {
	/*
		if a player is near a flag where he has no buildrights, he can't use the listed inputs close to buildingparts (to prevent glitching!)
	*/
	block_glitch_actions_enabled = "true";

	inputs[] = {"GetOver","leanLeft","leanLeftToggle","leanRight","leanRightToggle","LookAround","LookAroundToggle",
	"ActionFreeLook","Prone","ZoomOut","ZoomOutToggle","ZoomContOut","LookUp","LookLeft","LookRight","FreeHeadMove","AimHeadUp",
	"Cheat1","Cheat2"};

	/* this should also be enabled to prevent freelook (people simply use it to sneak through walls..) */
	block_ALT_key = "true";
	block_ALT_key_all = "false";	// also blocking ALT key for the Territory owner (so they can't peak through walls to defend easier)
};


/*
	checks if a players tries to glitch through a wall (if player is allowed to build in that territory, it will not be logged.)
*/
wall_glitch_object = "true";	//	This checks if the Player Object is glitching through a wall/base part
wall_glitch_revert = "true";	//	Teleport player back to last "safe" postion if a glitch was detected. Needs: wall_glitch_object = "true";
/*
	If a player model intersects with a wall, the player will be teleport back to where he was before he intersected with it..

extra punishments possible:
	0 - no punishment
	1 - knockout for 60 seconds
	2 - kill

	hardcore punishments
	3 - handcuff
	4 - kick
	5 - ban (not recommended)
*/
wall_glitch_punish = 0;



/*
	stops players from glitching into bases using "eject" or "getout" of a vehicle..
*/
wall_glitch_vehicle = "true";



class infiSTAR_safeZoneOptions {
	/*
		In a safeZone, only you or somebody from your group/clan can drive (or sell) your vehicle
		(after a server restart, the first one who gets into a vehicle becomes the "owner" of it (default Exile settings))
	*/
	enable = "true";
	kick_from_driver_only = "false";	// if "true", only thieves who get in driver seat will be kicked from vehicle. if "false", they will be kicked from all seats
};



class infiSTAR_handleDamage {
	/*
		This whole handleDamage does not effect admins!
	*/
	enable = "false";

	/*
		PvP_ReflectDamage option should reflect damage from player vs player (the player still takes damage)
	*/
	PvP_ReflectDamage = "false";

	/*
		PvP_BlockDamage option should block damage from player vs player
	*/
	PvP_BlockDamage = "false";

	/*
		PvP_useZones will load PvP_ReflectDamage and PvP_BlockDamage only if people are not within a range of the given xyz coordinates!
		{{X,Y,Z},RADIUS}
	*/
	PvP_useZones = "false";
	zones[] = {
		{{0,0,0},1},
		{{1,1,1},1},
		{{2,2,2},1}
	};

	/*
		block damage completely if the source of the damage is NULL
		(for example if you crash into a bush the source is NULL)
	*/
	BlockNullSource = "false";
};


/*
	Checks player Actions (mousewheel actions, userinterface actions and inputactions)
*/
BlockHoldActions = "false";	/* STRONGLY recommended! */



KCM = "true";		/* Just close ALL CommandingMenus */
CMC = "false";		/* Check for CommandingMenus that are not in the allowedCommandingMenus array */
allowedCommandingMenus[] = {"#user:example","#user:example2"};


reset_inGameUIEventHandler = "false";	/* reset inGameUIEventHandler */
checkFilePatchingEnabled = "true";		/* checks if filepatching is enabled on the client (if it is, the client could inject any script based hack easily) */
onEventsCheck = "false";				/* checks server side on Events vs Client side */
checkCfgPatches = "false";				/* checks server side Cfg Patches vs Client side (logs as "Bad Class found in CfgPatches >> xxx") */
check_Notifications = "false";			/* checks if BIS_fnc_showNotification was used, as it is used with many hacks - some custom addons however use them too. */
check_doors_n_gates = "true";			/* Fixes Hatches (so when they are locked, they stay closed..) and closes every door that's locked + keeps closing it in case somebody tries to hack open it! */
attach_to_check = "false";				/* logs and detaches attached vehicles that are close.. basically completely disallow attaching of vehicles! */
INVISIBLE_PLAYER_check = "false";		/* checks if a player object is invisible (hidden). None admins only. LOGS LIKE: INVISIBLE PLAYER-OBJECT   @X Y */
MAIN_LOOP_CHECK = "true";				/* "false", if you have too many log entries with "MAIN LOOP STOPPED!" */


checkPopTabIncrease = "true";
LogPopTabIncrease = 15000;			/* Only if checkPopTabIncrease = "true"; logs if PopTabs increased by x within ~50 seconds */
BanPopTabIncrease = 500000;			/* Only if checkPopTabIncrease = "true"; bans a player if PopTabs increase by more than x within ~50 seconds */

checkRespectIncrease = "true";
LogRespectIncrease = 5000;			/* Only if checkRespectIncrease = "true"; logs if respect increased by x within ~50 seconds */
BanRespectIncrease = 50000;			/* Only if checkRespectIncrease = "true"; bans a player if respect increases by more than x within ~50 seconds */



/* Check for Map Menu & Map Sub-Menu */
CMM = "false";
maxMapMenuEntries = 6;	/* "Map Menu has been changed x entries found - Texts: y" incase you want to add some briefing to your map menu. Only matters if you have CMM = "true"; */

/* if steam api.steampowered.com is working, this might be a nice feature */
check_steam_ban = "false";	/* will announce and log steambanned players - using GetPlayerBans v1 */
ban_for_steam_ban = "false";	/* if "check_steam_ban = "true";" then steambanned players will get banned from your Arma server! */


MPH = "false";			/* This set to "true" will create a log of players being hit on your server */
GodModeCheck = "false";	/* This will check from serverside if a playerobject received damage but did not take it */


/*
	Anti Teleport
	AntiTeleport = "false"; To disable Anti Teleport
	Arrays below show position & radius where Teleporting is allowed.
	Mainly for the Traders (because when you purchase a vehicle, it teleports you into the vehicle)
	
	You can white-list "Teleport Zones" by adding them like below.
	
	XtoYposition allow players to teleport from pos1 to pos2 or pos2 to pos1 (order doesn't matter).
	The idea is to allow scripts like "FastTravel"
	
	class AntiTeleport {
		enable = "true";

		allowedZones[] = {
			{{0,0,0},1},
			{{1,1,1},1},
			{{2,2,2},1}
		};

		XtoYpositions[] = {
		//	{ AAC, Gravia}
		//	{{11590.1,11964.4,0}, {14541.7,17555,0}}
		};
	};
	Trading zones are white-listed by default.
*/
class AntiTeleport {
	enable = "true";

	allowedZones[] = {};

	XtoYpositions[] = {
	//	{ AAC, Gravia}
	//	{{11590.1,11964.4,0}, {14541.7,17555,0}}

	//	This can have as many positons as you want. Allows teleporting within each subarray of XtoYpositions
	//	{{11590.1,11964.4,0}, {14541.7,17555,0}, {0,0,0}, {2500,5000,0}}
	};
};



/*  Check Drawing on the Map (global channel) */
//	CHECK_DRAWING = "false";	/* logs & deletes global drawing */
//	Removed! - Arma3 can now disable map drawing by putting
//	disableMapDrawing = 1; into your mission config

CHECK_RECOIL = "false";		/* checks weapon recoil */



/*  Check Local Markers  */
CLM = "false";	/* "false" if you do not want LocalMarker to be checked. */

/*  Use aLocalM array    */
UMW = "false";	/* use allowed marker array from below (for example AltisLife uses house_ and others in there) or A.I. Missions */
/* aLocalM: if "CLM" && UMW - this array of names will be allowed */
aLocalM[] = {"MissionMarker"};


/*
	Not allowed Chat words on server.
	Example:
		badkickChat[] = {"blue"}; or badbanChat[] = {"blue"};
	will log and kick or ban if somebody writes "blue goat" or "blues" in the chat (not case sensitive).
	
	Example 2:
	This will most likely stop people from writing Cyrillic (Russian) (I've been asked for this)
	badkickChat[] = {"й","д","и","б","ь","т"};
*/
badWarnChat[] = {};
badkickChat[] = {};
badbanChat[] = {};


/* Not allowed Names on server. Example: badNamesFull[] = {"THE"}; would kick all players that are named "THE", it would NOT kick players named "THE CAR" (not case sensitive) */
badNamesFull[] = {};

/* Not allowed Names on server. Example: badNamesPartial[] = {"THE"}; would kick all players with names like "the car" as it includes "THE" (not case sensitive) */
badNamesPartial[] = {"admin"};


/* Not allowed Group Names on server. Example: badGroupNames[] = {"THE"}; would rename all groups with names like "the car" as it includes "THE" (not case sensitive) */
badGroupNames[] = {"admin"};



/*
	if somebody talks on one of the following channels, his channel will be switched to "direct" channel
	0 = Global
	1 = Side
	2 = Command
	3 = Group
	4 = Vehicle
	5 = Direct <-- this is where people get switched too if they talk in one of the blacklisted channels!
	6-15 = Custom Radio (see radioChannelCreate)
*/
disAllowVon[] = {1,2};

/* badIDDsToKick will be checked before badIDDsToClose, badIDDsToClose will be checked before allowedIDDs */
/* badIDDsToKick: Forbidden Idds that will get you Kicked by the AH */
badIDDsToKick[] =
{
	-1338,-1337,-1341,17,19,30,32,45,56,59,62,64,69,71,110,125,
	132,133,155,156,165,166,167,312,313,
	1320,1321,1340,1341,1342,1343,1344,1345,1346,1347,
	2727,2928,2929,3030,316000,9899,0110,
	6900,552266
};

/* badIDDsToClose: Forbidden Idds that will get closed by the AH */
badIDDsToClose[] =
{
	-1,2,3,7,17,19,25,26,27,28,29,30,31,32,37,40,41,43,44,45,51,52,53,56,74,85,
	106,126,127,132,146,147,150,151,152,153,154,155,159,162,164,262,
	314,632,1320,2121,148,163,129,157,69,156,165,166,167,312,1321,2727,
	-1341,1341
};

/* Use IDD White-List ? */ UDW = "true";
/* allowedIDDs: Insert IDDs here to prevent them from being closed! */
allowedIDDs[] =
{
	/* default idds */
	-1,0,4,5,6,8,12,15,18,24,49,54,55,70,72,101,160,174,177,999,131,63,602,301,

	/* exile idds */
	24001,24002,20023,24005,24004,24010,24025,20021,20017,24012,24027,
	20019,20016,24007,20024,20018,24008,24011,24015,24000,24006,24014,
	20020,24026,4002,4000,4001,4003,1500,

	24033,24030,24029,24028,24031,24034,

	4004,21000,	// Bounty system and MarXet
	8457,	// http://www.exilemod.com/topic/9040-xm8-apps/
	65431,	// r3f menu fix
	6666,	// Paintshop
	0711,	// Advanced Banking
	0720,24036,	// Virtual Garage
	5501,5502,5503,5504,5505,5506,5507,	// BRAma Cookbook
	-1339,-1340,	// custom infiSTAR dialogs (some editor & a private chat menu)

	/* main idd - never delete it */
	46
};



/*
	important check to make sure certain variables are set and have the correct type!
*/
variableTypeChecks[] =
{
	{'ExileIsPlayingRussianRoulette',"false"},
	{'ExileClientIsHandcuffed',"false"},
	{'ExilePlayerInSafezone',"false"},
	{'ExileClientIsAutoRunning',"false"},
	{'ExileCurrentBreachingObject',objNull},
	{'ExileClientInteractionObject',objNull},
	{'HTML_LOAD_URL3',''},
	{'infiSTAR_lastJumptime',0},
	{'PLAYER_IN_VEHICLE',"false"},
	{'ExileSystemSpawnThread',[]}
};


/*
	it is highly recommended to have this check turned on (useBlacklistedVariableCheck = "true";)
	shows "BadVariable in xxxxxxxx " in the logs.
*/
useBlacklistedVariableCheck = "false";
blacklistedVariables[] =
{
	"bis_debug_cam",
	"arsenalopened","bis_fnc_arsenal_fullarsenal","babecore_escm_mousepos","RANDOMVAR",
	"bis_fnc_dbg_reminder_value","bis_fnc_dbg_reminder","bis_menu_groupcommunication","bis_fnc_addcommmenuitem_menu",
	"rscspectator","rscspectator_hints","rscspectator_display","rscspectator_playericon",
	"rscspectator_view","rscspectator_map","rscspectator_vision","rscspectator_keys",
	"rscspectator_interface","bis_fnc_camera_target","andy_loopz","initfileone","finie_s_p",
	"time","servertime","myplayeruid","hhahaaaaar","charliesheenkeybinds","kickoff","yolo","runonce","notakeybind","action1","supa_licenses","autokick","wallaisseikun","mainmenu",
	"gefclose","gefwhite","gefred","gefgreen","gefcyan","firsthint","new_queued","fn_exec","fnd_fnc_select","fnx3","antihackkick","tele","dmap","goldens_global_shit_yeah","glass911_run",
	"geardialog_create","lystokeypress","thirtysix","ly_swaggerlikeus","jkeyszz","n2","boxofmagic","mainscripts","dmc_fnc_4danews","infistarbypass","exec_text","vehicle_dblclick","init_main",
	"esp_count","nute_dat_bomber","s_cash100k","xposplayer","ly_re_onetime","skar_checka","mainscriptsv4","viewdistance","check_load","already_load","meins","f1","dummy","plane_jump",
	"c_player","mouseclickeh","distp","nec2","menu_i_run_color_lp","glassv1nce_bindhandler","thecar","fastanimes","getinpassenger","iaimon","dmc_re_onetime","func_execonserver","fnc_serverkicknice",
	"kick_admins","dasmokeon","hovering","r_kelly_be_flying","vincelol_altislife","life_fnc_byassskaroah","ah_fnc_mp","jayre","fn_newsbanner","hack_news","trollfuncs",
	"fanatic_infipass","keybindings_xxx","andysclosed","userfuncs","altisfuncs","remexe","bb_nofatigue","bis_fnc_diagkey_var_code","first_page","get_in_d","i_t_s__m_e_o","smissles","whippy_esp",
	"targetfuncs2","life_fnc_antifreeeeze","ly_keyforward","ty_re_onetime","life_fnc_xaaxaa","mein1","goddamnvehiclesxd","mystic_fnc_esp_distance","esp_id_setter","dummymen","whipbut","userfuncs",
	"krohdofreedom","selectedplayer","lmenu1","ggplayer","throx_menu_item","lvl1","init_menu_slew","d_b_r_t_y_slew","v6_gef","xasfjisisafudmmyx","kekse","updated_re_36","first","second",
	"sni_prz_zzz_targetplayer","healit","o_fnc_arma","mlrn_exec","running_threads","catchemall12282","killtarget","gmtoggle","t1","fuck_me_keyp","cheatcurator"
};

/*
	due to new hacking methods it is necessary to check variables on objects.. 
	since most server have 50.000+ objects this can cost a lot client fps but it should still be used.. for the greater good!
*/
useObjectVariableCheck = "false";



UVC_adminspawn = "false";	/* use vehicle check(s) on vehicles spawned by infiSTAR.de admin? */
/*
	Use vehicle white list? (everything not on white-list will be flagged as BadVehicle and deleted!)
	"EXILE" vehicles are white-listed by default!
*/
VehicleWhiteList_check = "false";
VehicleWhiteList[] =
{
	"B_Parachute","B_Parachute_02_F","O_Parachute_02_F","Steerable_Parachute_F",
	"I_UAV_01_F","B_HMG_01_high_F","O_HMG_01_F","B_Heli_Transport_01_F","B_Heli_Transport_01_camo_F","O_MRAP_02_gmg_F","O_static_AT_F","Land_Camping_Light_F"
};

/*
	Use forbidden vehicle check? (everything in the ForbiddenVehicles will be flagged as BadVehicle and deleted (even when it is on the white-list)!)
*/
ForbiddenVehicles_check = "false";
ForbiddenVehicles[] =
{
	"B_MBT_01_arty_F","B_Truck_01_ammo_F"
};

/*
	If you use VehicleWhiteList_check or ForbiddenVehicles_check then the vehicle check automatically checks for locally created vehicles.
	Locally created vehicles are these that get created by a player and not the server. E.g. when a player assambles a UAV or a static weapon!
	Also some public posted scripts for example the "bike script" are creating the vehicle (the bike) locally (so the type of the vehicle needs to get added to the array below!).
*/
LocalWhitelist[] =
{
	"O_HMG_01_weapon_F","O_HMG_01_F","O_HMG_01_support_F","I_UavTerminal","I_UAV_01_backpack_F",
	"Exile_Bike_OldBike","B_HMG_01_F","B_HMG_01_high_F","O_HMG_01_high_F","B_Mortar_01_F"
};




UFI = "false";	/* Use "ForbiddenItems"/Item Check(s) */
UIW = "false";	/* if "UIW = "true";" then it checks if the items the individual player has are in "ItemWhiteList" */
KICK_ON_DETECTION = "false";	// kick when a bad or not whitelisted item was found
ItemWhiteList[] =
{
	"AllowThisItem1","AllowThisItem2"
};
ForbiddenItems[] =
{
	"autocannon_Base_F","autocannon_30mm","autocannon_35mm","autocannon_40mm_CTWS","autocannon_30mm_CTWS","Bomb_04_Plane_CAS_01_F",
	"Bomb_03_Plane_CAS_02_F","cannon_105mm","cannon_120mm","cannon_120mm_long","cannon_125mm","Cannon_30mm_Plane_CAS_02_F","gatling_20mm",
	"gatling_25mm","gatling_30mm","Gatling_30mm_Plane_CAS_01_F","GBU12BombLauncher","GMG_20mm","GMG_40mm","GMG_UGV_40mm","HMG_127_MBT",
	"HMG_127","HMG_127_APC","HMG_01","HMG_M2","HMG_NSVT","LMG_Minigun2","LMG_RCWS","LMG_M200","LMG_Minigun","LMG_Minigun_heli","LMG_coax",
	"Missile_AGM_02_Plane_CAS_01_F","Missile_AA_04_Plane_CAS_01_F","Missile_AA_03_Plane_CAS_02_F","Missile_AGM_01_Plane_CAS_02_F","missiles_DAGR",
	"missiles_DAR","missiles_ASRAAM","missiles_SCALPEL","missiles_titan","missiles_titan_static","missiles_Zephyr","Mk82BombLauncher","mortar_82mm",
	"mortar_155mm_AMOS","rockets_Skyfire","rockets_230mm_GAT","Rocket_04_HE_Plane_CAS_01_F","Rocket_04_AP_Plane_CAS_01_F","Rocket_03_HE_Plane_CAS_02_F",
	"Rocket_03_AP_Plane_CAS_02_F","Twin_Cannon_20mm"
};



/*
	custom Box content:
	just an item like it is in the example with   "ItemMap"   will put the item once in the box.
	if an array is used like the   {"ItemGPS",5}   example, well I assume you could guess what it will do.
	
	You can just define as many as you want.
	{
		"BOX NAME",	// function name in the admin menu
		{
			"Item1","Item2",	// one per just item in a string
			{"Item1",5},{"Item2",10}	// second entry in each array defiens how many of items of the first entry are wanted.
		}
	}
	
	The last closing bracket in an array can not have a "," afterwards. So make sure to have no syntax errors here.
*/
allSupportBoxes[] =
{
	{
		"Support-Box1",
		{
			"Exile_Item_Flag","Exile_Item_CookingPot",
			{"Exile_Item_Codelock",5},{"Exile_Item_DuctTape",10},{"Exile_Item_InstaDoc",10},
			{"Exile_Item_Energydrink",10},{"Exile_Item_ExtensionCord",5},{"Exile_Item_FloodLightKit",5},
			{"Exile_Item_FortificationUpgrade",5},{"Exile_Item_FuelCanisterFull",5},{"Exile_Item_GloriousKnakworst_Cooked",10},
			{"Exile_Item_LightBulb",5},{"Exile_Item_Matches",5},{"Exile_Item_MetalBoard",5},
			{"Exile_Item_MetalPole",5},{"Exile_Item_PlasticBottleFreshWater",10},{"Exile_Item_PortableGeneratorKit",5},
			{"Exile_Item_Rope",15},{"Exile_Item_SafeKit",15},{"Exile_Magazine_Battery",15}
		}
	},
	{
		"Support-Box2",
		{
			"Exile_Item_Flag",
			{"Exile_Item_WoodDoorKit",15},{"Exile_Item_WoodDoorwayKit",15},{"Exile_Item_WoodDrawBridgeKit",15},
			{"Exile_Item_WoodFloorKit",15},{"Exile_Item_WoodFloorPortKit",15},{"Exile_Item_WoodGateKit",15},
			{"Exile_Item_WoodLog",15},{"Exile_Item_WoodPlank",15},{"Exile_Item_WoodStairsKit",15},
			{"Exile_Item_WoodSupportKit",15},{"Exile_Item_WoodWallHalfKit",15},{"Exile_Item_WoodWallKit",15},
			{"Exile_Item_WoodWindowKit",15},{"Exile_Item_WorkBenchKit",15}
		}
	},
	{
		"Support-Box3",
		{
			{"Exile_Item_Flag",5},{"Exile_Item_WoodDoorKit",15},{"Exile_Item_WoodWallKit",15},
			{"Exile_Item_WoodWindowKit",15},{"Exile_Item_WoodFloorKit",15},{"Exile_Item_SafeKit",5}
		}
	},
	{
		"Support-Box4",
		{
			"ItemMap",{"ItemGPS",5},"ItemWatch"
		}
	}
};
};
