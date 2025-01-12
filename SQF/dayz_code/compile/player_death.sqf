if (deathHandled) exitWith {};
deathHandled = true;

private ["_humankill","_ammo","_body","_distance","_infected","_killed","_playerID","_sourceName","_sourceWeapon","_sourceVehicleType","_humanityBody","_humanitySource","_humanityHit","_kills","_killsV","_display","_myGroup","_camera","_deathPos","_animState","_animStateArray","_animCheck","_source","_method","_realSource","_sourceID"];

// Get reference to player object before respawn into new unit (respawnDelay=0 in description.ext)
if (typeName (_this select 0) == "ARRAY") then {
	_body = (_this select 0) select 0;
	_source = (_this select 0) select 1;
	diag_log format["Player_Death called from 'killed' event handler %1",_this];
	_killed = true;
} else {
	_body = player;
	_source = _this select 0;
	diag_log format["Player_Death called from script %1",_this];
	_killed = false;
};

_deathPos = getPosATL _body;
_playerID = getPlayerUID player;
_sourceID = "0";

//Switch view to camera so player does not see debug plains at respawn_west
_camera = "camera" camCreate _deathPos;
_camera camSetDir 0;
_camera camSetFOV 1;
_camera cameraEffect ["Internal","TOP"];
_camera camSetTarget _deathPos;
_camera camSetPos [_deathPos select 0, (_deathPos select 1) + 2, (_deathPos select 2) + 5];
_camera camCommit 0;

if (!_killed) then {
	//Kill only if killed event handler has not already fired (respawnDelay=0 in description.ext)
	player setDamage 1;
};

if (dayz_onBack != "") then {
	if (dayz_onBack in weapons _body) then {
		//Prevent duplicate weapon error
		[dayz_onBack,2,1,[_deathPos select 0,_deathPos select 1,0]] call fn_dropItem;
	} else {
		_body addWeapon dayz_onBack;
	};
};

//Get killer information immediately. Weapon, distance or vehicle can change in seconds.
_infected = [0, 1] select (r_player_infected && DZE_PlayerZed);
_sourceName = "unknown";
_sourceWeapon = "";
_distance = 0;

_method = call {
	if (_this select 1 != "find") exitwith {_this select 1}; //Manually passed method
	if (dayz_lastDamageSource != "none" && {diag_tickTime - dayz_lastDamageTime < 30}) exitwith {dayz_lastDamageSource}; //Major event takes priority for cause of death (zombie, melee, shot, fell, etc.)
	if (dayz_lastMedicalSource != "none" && {diag_tickTime - dayz_lastMedicalTime < 10}) exitwith {dayz_lastMedicalSource}; //Starve, Dehyd, Sick
	"bled"; //No other damage sources in last 30 seconds
};

_ammo = ["", _this select 2] select (count _this > 2);

if (!isNull _source) then {
	if (!isNull _body) then {
		_distance = round (_deathPos distance _source);
	};

	_sourceVehicleType = typeOf (vehicle _source);
	_sourceWeapon = currentWeapon _source;
	_sourceWeapon = call {
		if (_ammo in ["PipeBomb","Mine","MineE"]) exitwith {_ammo};
		if ({_sourceVehicleType isKindOf _x} count ["LandVehicle","Air","Ship"] > 0) exitwith {_sourceVehicleType};
		if (_sourceWeapon == "Throw") exitwith {(weaponState _source) select 3};
		_sourceWeapon;
	};

	if (alive _source) then {
		if (isPlayer _source) then {
			_sourceName = name _source;
			_sourceID = getPlayerUID _source;
		} else {
			_sourceName = "AI";
		};
	} else {
		if (_source == _body) then {_sourceName = dayz_playerName;};
	};
};

//Send Death Notice
diag_log format["Player_Death: Body:%1 BodyName:%2 Infected:%3 SourceName:%4 SourceWeapon:%5 Distance:%6 Method:%7",_body,dayz_playerName,_infected,_sourceName,_sourceWeapon,_distance,_method];
PVDZ_plr_Death = [dayz_characterID,0,_body,_playerID,toArray dayz_playerName,_infected,toArray _sourceName,_sourceWeapon,_distance,_method,_sourceID]; //Send name as array to avoid publicVariable value restrictions
publicVariableServer "PVDZ_plr_Death";

_body setVariable ["deathType", if (_method == "suicide") then {"shot"} else {_method}, true];

if (!local _source && {isPlayer _source} && {!(_body isKindOf "PZombie_VB")}) then { //If corpse is a player zombie do not give killer a human or bandit kill

	//Values like humanity which were setVariabled onto player before death remain on corpse.
	_humankill = false;
	_humanityHit = 0;
	_humanityBody = _body getVariable["humanity",0];
	_realSource = effectiveCommander vehicle _source;
	_humanitySource = _realSource getVariable ["humanity",0];

	call {
		if (_humanitySource <= DZE_Bandit) exitwith {//Killer is Bandit
			if (_humanityBody <= DZE_Bandit) exitwith {//Body is Bandit
				_killsV = _realSource getVariable ["banditKills",0];
				_realSource setVariable ["banditKills",(_killsV + 1),true];
				_humanityHit = -250;
			};

			_kills = _realSource getVariable ["humanKills",0];
			_realSource setVariable ["humanKills",(_kills + 1),true];
			_humankill = true;

			if (_humanityBody >= DZE_Hero) exitwith {//Body is Hero
				_humanityHit = -1000;
			};
			_humanityHit = -500; //Body is Survivor
		};
		if (_humanitySource >= DZE_Hero) exitwith {//Killer is Hero
			if (_humanityBody <= DZE_Bandit) exitwith {//Body is Bandit
				_killsV = _realSource getVariable ["banditKills",0];
				_realSource setVariable ["banditKills",(_killsV + 1),true];
				_humanityHit = 1000;
			};

			_kills = _realSource getVariable ["humanKills",0];
			_realSource setVariable ["humanKills",(_kills + 1),true];
			_humankill = true;

			if (_humanityBody >= DZE_Hero) exitwith {//Body is Hero
				_humanityHit = -1000;
			};
			_humanityHit = -500; //Body is Survivor
		};

		//Killer is Survivor
		if (_humanityBody <= DZE_Bandit) exitwith {//Body is Bandit
			_killsV = _realSource getVariable ["banditKills",0];
			_realSource setVariable ["banditKills",(_killsV + 1),true];
			_humanityHit = 500;
		};

		_kills = _realSource getVariable ["humanKills",0];
		_realSource setVariable ["humanKills",(_kills + 1),true];
		_humankill = true;

		if (_humanityBody >= DZE_Hero) exitwith {//Body is Hero
			_humanityHit = -500;
		};
		_humanityHit = -250; //Body is Survivor
	};

	PVDZ_send = [_realSource,"Humanity",[_humanityHit]];
	publicVariableServer "PVDZ_send";

	//Setup for study bodys.
	_body setVariable ["KillingBlow",[_realSource,_humankill],true];

	call {
		if (_humanityBody >= DZE_Hero) exitwith {_body addMagazine "ItemDogTagHero";};
		if (_humanityBody <= DZE_Bandit) exitwith {_body addMagazine "ItemDogTagBandit";};
	};
};

disableSerialization;

//Prevent client freezes
_display = findDisplay 49;
if (!isNull _display) then {_display closeDisplay 0;};
if (dialog) then {closeDialog 0;};
if (visibleMap) then {openMap false;};

disableUserInput true;

[_body,20,true,_deathPos] call player_alertZombies;
if (dayz_soundMuted) then {call player_toggleSoundMute;}; // hide icon before fadeSound
0.1 fadeSound 0;

r_player_unconscious = false;
r_player_cardiac = false;
dayz_autoRun = false;

terminate dayz_musicH;
terminate dayz_slowCheck;
terminate dayz_monitor1;

//Reset (just in case)
//deleteVehicle dayz_playerTrigger;
//disableUserInput false;
r_player_dead = true;

//Player is dead!
3 fadeSound 0;

dayz_originalPlayer enableSimulation true;
addSwitchableUnit dayz_originalPlayer;
setPlayable dayz_originalPlayer;
selectPlayer dayz_originalPlayer;

_myGroup = group _body;
[_body] joinSilent dayz_firstGroup;
deleteGroup _myGroup;

8 cutText ["","PLAIN"]; //Clear group tags
3 cutRsc ["default", "PLAIN",3];
4 cutRsc ["default", "PLAIN",3];

_animState = toLower (animationState _body);
_animStateArray = toArray _animState;
_animCheck = toString ([(_animStateArray select 0),(_animStateArray select 1),(_animStateArray select 2),(_animStateArray select 3)]);
if ((_body == (vehicle _body)) && {_animState != "deadstate" && {_animCheck != "adth"}}) then { //fix running corpses - death anims begin with Adth
	[nil, _body, rSWITCHMOVE, ""] call RE;
	_body SWITCHMOVE "";
	PVDZ_plr_SwitchMove = [_body,""];
	publicVariableServer "PVDZ_plr_SwitchMove";
};

[_body,_camera,_deathPos] spawn {
	_body = _this select 0;
	_camera = _this select 1;
	_deathPos = _this select 2;

	waitUntil {camCommitted _camera};
	_camera camSetPos [_deathPos select 0, (_deathPos select 1) + 2, (_deathPos select 2) + 15];
	_camera camCommit 4;
	uiSleep 5;

	1 cutRsc [if (DZE_DeathScreen) then {"DeathScreen_DZE"} else {"DeathScreen_DZ"},"BLACK OUT",3];
	playMusic "dayz_track_death_1";
	uiSleep 2;

	for "_x" from 5 to 1 step -1 do {
		titleText [format[localize "str_return_lobby", _x], "PLAIN DOWN", 1];
		uiSleep 1;
	};

	PVDZ_Server_Simulation = [_body, false];
	publicVariableServer "PVDZ_Server_Simulation";

	_camera cameraEffect ["Terminate","BACK"];
	camDestroy _camera;

	endMission "END1";
};
