fn_infiSTAR_keyBinds_defaults = {[
["infiSTAR KeyBinds Menu", 15, false, false, false, "fn_infiSTAR_keyBinds_init", {true}],
["Private Chat", 77, false, false, false, "fn_infiSTAR_PrivChat_init", {true}],

["", 0],
["EXILE KeyBinds:", 0],
["Lock / Unlock", 0, false, false, false, { if!(ExileClientIsHandcuffed)then{call ExileClient_object_vehicle_interaction_keyLock;}; }, {true}],
["Place 3D Group Marker", 0, false, false, false, { if!(ExileClientIsHandcuffed)then{if(ExileClientAllowPartyMarkers && !(ExileClientPartyID isEqualTo -1))then{call ExileClient_system_party_updateMyMarker;};}; }, {true}],
["Clear Map Markers", 0, false, false, false, { ExileClientWaypoints = []; }, {true}],
["Switch Party ESP mode", 0xDB],
["Toggle stats", 0x29],
["Auto running toggle", 0x0B],
["Auto running stop", 0x20],
["Primary weapon", 0x02],
["Handgun", 0x03],
["Secondary weapon", 0x04],
["(Un-)Holster weapon", 0x05],
["Earplugs toggle", 0x06],
["Open XM8", 0x07],
["Funny Dab", 0x08],

["", 0, {!isNil "ADMINLEVELACCESS"}],
["Admin KeyBinds:", 0, {!isNil "ADMINLEVELACCESS"}],
["Open infiSTAR Admin Menu", 0x3B, false, false, false, { FILLMAINSTATE=0;[] call fnc_FULLinit; }, {!isNil "fnc_FULLinit"}],
["Territory Management", 0x3C, false, false, false, "fn_TM_init", {!isNil "fnc_FULLinit"}],
["Admin Console", 0x3D, false, false, false, "infiSTAR_adminConsoleInit", {!isNil "infiSTAR_adminConsoleInit"}],
["Attach/Detach CursorTarget", 0x3D, true, false, false, {[""] call fnc_ATTACH_TO;}, {!isNil "ADMINLEVELACCESS"}],
["Open Arsenal", 0x3E, false, false, false, {["Open",true] call BIS_fnc_arsenal;}, {"Items spawn menu" call ADMINLEVELACCESS}],
["Change Weather + View Distance", 0x3F, false, false, false, "FN_CHANGE_VIEWDISTANCE", {"Change ViewDistance" call ADMINLEVELACCESS}],
["Heal Cameraon (and self)", 0x40, false, false, false, "infiSTAR_A3Heal", {"HealSelf" call ADMINLEVELACCESS}],
["Repair + Refuel near camera", 0x41, false, false, false, "infiSTAR_A3RestoreNear", {"HealRepairNear" call ADMINLEVELACCESS}],
["Flip Target Vehicle", 0x42, false, false, false, {[""] call fnc_flipVeh;}, {"Flip Vehicle" call ADMINLEVELACCESS}],
["Show Gear of Spectated Target", 0x43, false, false, false, "admin_showGear", {"ShowGear" call ADMINLEVELACCESS}],
["Toggle Spectate Overlay", 0x43, true, false, false, "fn_infiSTAR_admin_ToggleSpectateOverlay", {!isNil "ADMINLEVELACCESS"}],
["Stop spectating", 0x44, false, false, false, "fn_infiSTAR_admin_endSpectate", {!isNil "ADMINLEVELACCESS"}],
["Spawn Ammo", 0x57, false, false, false, "infiSTAR_A3addAmmo", {"Spawn Ammo" call ADMINLEVELACCESS}],
["Lightning on Target", 0x02, false, true, false, {[""] call fnc_Light_selected;}, {"Light" call ADMINLEVELACCESS}],
["Kill / Destroy Target", 0x03, false, true, false, {[""] call fnc_Kill_selected;}, {"Kill" call ADMINLEVELACCESS}],
["Fly Down", 0x2F, false, true, false, "infiSTAR_go_down", {!isNil "ADMINLEVELACCESS"}],
["Fly Up", 0x05, true, false, false, "infiSTAR_FlyUp", {"FlyUp" call ADMINLEVELACCESS}],
["Tp Up", 0x05, false, true, false, "infiSTAR_TpUp", {"FlyUp" call ADMINLEVELACCESS}],
["Teleport 10m in facing direction", 0x06, true, false, false, "infiSTAR_Tpdirection", {!isNil "ADMINLEVELACCESS"}],
["Teleport 1m in facing direction", 0x2F, true, false, false, "infiSTAR_shortTP", {!isNil "ADMINLEVELACCESS"}],
["Unlock/Lock vehicle or Open/Close Doors", 0x09, false, false, false, "infiSTAR_A3Togglelock", {"UnlockLockVehicle" call ADMINLEVELACCESS}],
["Hover", 0x30, true, false, false, "fnc_Hover", {!isNil "ADMINLEVELACCESS"}],
["Show Info (Like Codes of Vehicles and Doors)", 0x17, true, false, false, "admin_showinfo", {"showinfo" call ADMINLEVELACCESS}],
["Delete Target", 0xD3, false, false, false, {[""] call fnc_deleteVeh_selected;}, {"Delete Vehicle" call ADMINLEVELACCESS}],
["Open Map", 0x0F, true, false, false, {openMap true;}, {"Teleport On Map Click" call ADMINLEVELACCESS}]
]};
profileNamespace setVariable ["infiSTAR_keyBinds",nil];saveprofileNamespace;
infiSTAR_keyBinds_array = call compile(profileNamespace getVariable ["infiSTAR_keyBinds_saved",str (call fn_infiSTAR_keyBinds_defaults)]);
fn_infiSTAR_keyBinds_Ids = {
	infiSTAR_keyBindIds_array = [];
	{ infiSTAR_keyBindIds_array pushBackUnique (_x select 1); } forEach infiSTAR_keyBinds_array;
};
call fn_infiSTAR_keyBinds_Ids;
fn_infiSTAR_keyBinds_edit_KeyDown = {
	_selection = lbCurSel (uiNamespace getVariable ["infiSTAR_keyBinds_ListBox",controlNull]);
	_lnbText = (uiNamespace getVariable ["infiSTAR_keyBinds_ListBox",controlNull]) lnbText [_selection,0];
	if!(_lnbText isEqualTo "")then
	{
		params ["_keycontrol", "_keycode", "_keyshift", "_keyctrl", "_keyalt"];
		_keyName = keyName _keycode;
		if!(_keyName isEqualTo "")then
		{
			if(_keycode < 2)exitWith{};
			_infiSTAR_keyBinds_edit = uiNamespace getVariable ["infiSTAR_keyBinds_edit",controlNull];
			_infiSTAR_keyBinds_edit ctrlSetText ([controlNull, _keycode, _keyshift, _keyctrl, _keyalt] call fn_infiSTAR_keyBinds_getKeyText);
			
			{
				if(_x select 0 == _lnbText)then
				{
					_curArray = infiSTAR_keyBinds_array param [_forEachIndex, [], [[]]];
					if(count _curArray isEqualTo 7)then
					{
						_curArray set[1, _keycode];
						_curArray set[2, _keyshift || _keycode in [0x2A,0x36]];
						_curArray set[3, _keyctrl || _keycode in [0x1D,0x9D]];
						_curArray set[4, _keyalt || _keycode in [0x38,0xB8]];
						infiSTAR_keyBinds_array set[_forEachIndex, _curArray];
						
						_keyIdText = [controlNull, _curArray select 1, _curArray select 2, _curArray select 3, _curArray select 4] call fn_infiSTAR_keyBinds_getKeyText;
						(uiNamespace getVariable ["infiSTAR_keyBinds_ListBox",controlNull]) lnbSetText [ [_selection,1], _keyIdText];
					};
				};
			} forEach infiSTAR_keyBinds_array;
		};
	};
	false
};
fn_infiSTAR_keyBinds_btnSave = {
	profileNamespace setVariable ["infiSTAR_keyBinds_saved",str infiSTAR_keyBinds_array];saveprofileNamespace;
	call fn_infiSTAR_keyBinds_Ids;
	call fn_infiSTAR_keyBinds_initListbox;
};
fn_infiSTAR_keyBinds_btnReset = {
	disableSerialization;
	_selection = lbCurSel (uiNamespace getVariable ["infiSTAR_keyBinds_ListBox",controlNull]);
	_lnbText = (uiNamespace getVariable ["infiSTAR_keyBinds_ListBox",controlNull]) lnbText [_selection,0];
	if!(_lnbText isEqualTo "")then
	{
		_defaultArray = call fn_infiSTAR_keyBinds_defaults;
		
		{
			if(_x select 0 == _lnbText)then
			{
				_curArray = _defaultArray param [_forEachIndex, [], [[]]];
				if(count _curArray isEqualTo 7)then
				{
					infiSTAR_keyBinds_array set[_forEachIndex, _curArray];
					profileNamespace setVariable ["infiSTAR_keyBinds_saved",str infiSTAR_keyBinds_array];saveprofileNamespace;
					call fn_infiSTAR_keyBinds_Ids;
					
					_keyIdText = [controlNull, _curArray select 1, _curArray select 2, _curArray select 3, _curArray select 4] call fn_infiSTAR_keyBinds_getKeyText;
					(uiNamespace getVariable ["infiSTAR_keyBinds_ListBox",controlNull]) lnbSetText [ [_selection,1], _keyIdText];
				};
			};
		} forEach _defaultArray;
	};
};
fn_infiSTAR_keyBinds_btnResetAll = {
	disableSerialization;
	infiSTAR_keyBinds_array = call fn_infiSTAR_keyBinds_defaults;
	profileNamespace setVariable ["infiSTAR_keyBinds_saved",str infiSTAR_keyBinds_array];saveprofileNamespace;
	call fn_infiSTAR_keyBinds_Ids;
	
	closeDialog 0;
	uiSleep 0.1;
	createDialog "infiSTAR_KeyBinds";
	systemChat "Your infiSTAR KeyBinds have been reset..!";
};
fn_infiSTAR_keyBinds_lbSelChanged = {
	_data = (_this select 0) lnbData [_this select 1,1];

	_ctrlEdit = uiNamespace getVariable ["infiSTAR_keyBinds_edit",controlNull];
	_ctrlBtnSave = (ctrlParent _ctrlEdit) displayCtrl 105;
	_ctrlBtnReset = (ctrlParent _ctrlEdit) displayCtrl 106;

	if(_data isEqualTo "+")then{
		{_x ctrlEnable true;} forEach [_ctrlEdit,_ctrlBtnSave,_ctrlBtnReset];
	} else {
		{_x ctrlEnable false;} forEach [_ctrlEdit,_ctrlBtnSave,_ctrlBtnReset];
	};

	_lnbText = (_this select 0) lnbText [_this select 1,1];
	_infiSTAR_keyBinds_edit = uiNamespace getVariable ["infiSTAR_keyBinds_edit",controlNull];
	_infiSTAR_keyBinds_edit ctrlSetText _lnbText;
};
fn_infiSTAR_keyBinds_getKeyText = {
	params ["_keycontrol", "_keycode", "_keyshift", "_keyctrl", "_keyalt"];
	_ret = keyName _keycode;
	_ret = _ret select [1,(count _ret)-2];
	if(_keyshift && !(_keycode in [0x2A,0x36]))then{ _ret = "Shift + " + _ret;};
	if(_keyctrl && !(_keycode in [0x1D,0x9D]))then{ _ret = "Ctrl + " + _ret;};
	if(_keyalt && !(_keycode in [0x38,0xB8]))then{ _ret = "Alt + " + _ret;};
	_ret
};
fn_infiSTAR_keyBinds_initListbox = {
	_keyBindsCtrl = uiNamespace getVariable ["infiSTAR_keyBinds_ListBox",controlNull];
	_textSearchKeyBinds = ctrlText (uiNamespace getVariable ["infiSTAR_KeyBinds_searchKeyBind",controlNull]);
	if(_textSearchKeyBinds isEqualTo "search..")then{_textSearchKeyBinds = "";};
	
	
	_lnbIndex = 0;
	lnbClear _keyBindsCtrl;
	
	_lnbIndex = _keyBindsCtrl lnbAddRow ["ACTION", "ASSIGNED KEY"];
	_keyBindsCtrl lnbSetColor [[_lnbIndex,0],[0.6,0,0,1]];
	_keyBindsCtrl lnbSetColor [[_lnbIndex,1],[0.6,0,0,1]];
	_lnbIndex = _keyBindsCtrl lnbAddRow ["",""];
	
	{
		_keyName = _x param [0, "unknown", [""]];
		_KeyDownID = _x param [1, 0, [0]];
		if((toLower _keyName) find (toLower _textSearchKeyBinds) > -1 || _textSearchKeyBinds isEqualTo "")then
		{
			if(count _x < 7)then
			{
				_keyAccess = _x param [2, {true}, [{}]];
				if(call _keyAccess)then
				{
					_keyIdText = [controlNull, _KeyDownID, false, false, false] call fn_infiSTAR_keyBinds_getKeyText;
					_lnbIndex = _keyBindsCtrl lnbAddRow [_keyName, _keyIdText];
					_keyBindsCtrl lnbSetData [[_lnbIndex,0], keyName _KeyDownID];
					_keyBindsCtrl lnbSetData [[_lnbIndex,1], keyName _KeyDownID];
					
					_keyBindsCtrl lnbSetColor [[_lnbIndex,0],[0.6,0,0,1]];
					_keyBindsCtrl lnbSetColor [[_lnbIndex,1],[0.6,0,0,1]];
				};
			}
			else
			{
				_keyAccess = _x param [6, {true}, [{}]];
				if(call _keyAccess)then
				{
					_KeyDownShift = _x param [2, false, [false]];
					_KeyDownCtrl = _x param [3, false, [false]];
					_KeyDownAlt = _x param [4, false, [false]];
					
					_keyIdText = [controlNull, _KeyDownID, _KeyDownShift, _KeyDownCtrl, _KeyDownAlt] call fn_infiSTAR_keyBinds_getKeyText;
					_lnbIndex = _keyBindsCtrl lnbAddRow [_keyName, _keyIdText];
					_keyBindsCtrl lnbSetData [[_lnbIndex,0], "+"];
					_keyBindsCtrl lnbSetData [[_lnbIndex,1], "+"];
					
					if(_keyIdText isEqualTo "")then{_keyBindsCtrl lnbSetColor [[_lnbIndex,0],[1,1,0,.8]];};
				};
			};
		};
	} forEach infiSTAR_keyBinds_array;
};
fn_infiSTAR_keyBinds_KeyDown = {
	params ["_keycontrol", "_keycode", "_keyshift", "_keyctrl", "_keyalt"];
	if(_keycode in infiSTAR_keyBindIds_array)then{
		{
			_x params ["_keyName","_KeyDownID","_KeyDownShift","_KeyDownCtrl","_KeyDownAlt","_keyFnc","_keyAccess"];
			if(_keycode isEqualTo _KeyDownID)then{
				if(_keyshift isEqualTo _KeyDownShift && _keyctrl isEqualTo _KeyDownCtrl && _keyalt isEqualTo _KeyDownAlt)then{
					if(_keyFnc isEqualType "")then{ _keyFnc = missionNamespace getVariable [_keyFnc,{}]; };
					if(call _keyAccess)then{call _keyFnc;};
				};
			};
		} forEach infiSTAR_keyBinds_array;
	};
	false
};
if(!isNil "infiSTAR_keyBinds_startThread")then{terminate infiSTAR_keyBinds_startThread;};
infiSTAR_keyBinds_startThread = [] spawn {
	waitUntil {
		uiSleep 1;
		if(!isNil "infiSTAR_keyBinds_KeyDown_ID")then{(findDisplay 46) displayRemoveEventHandler ["KeyDown",infiSTAR_keyBinds_KeyDown_ID];};
		infiSTAR_keyBinds_KeyDown_ID = (finddisplay 46) displayAddEventHandler ["KeyDown","call fn_infiSTAR_keyBinds_KeyDown"];
		getClientStateNumber >= 10 && !isNull findDisplay 46 && {!((getPlayerUID player) isEqualTo "")}
	};
	uiSleep 3;
	systemChat "Some keybinds are hardcoded within the mod or game and can not be changed!";
};
fn_infiSTAR_keyBinds_init = {
	_reset = false;
	_allAssigned = [];{_allAssigned pushBackUnique (_x select 0);} forEach infiSTAR_keyBinds_array;
	_allAssignedDefault = [];{_allAssignedDefault pushBackUnique (_x select 0);} forEach (call fn_infiSTAR_keyBinds_defaults);
	{if!(_x in _allAssigned)exitWith{_reset = true;};} forEach _allAssignedDefault;
	if(_reset)then{systemChat "There are new Keybinds, you need to press the Reset All button so they are shown within the infiSTAR Keybinds Menu!";};

	if(isNull (uiNamespace getVariable ["infiSTAR_keyBinds_ListBox",controlNull]))then{ createDialog "infiSTAR_KeyBinds"; };
};
