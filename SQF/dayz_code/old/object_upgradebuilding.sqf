/*
    Simple class system to use this script.
    class Upgrade {
        requiredTools[] = {"ItemToolbox"};
        requiredParts[] = {"equip_crate","PartWoodPile"};
        create = "TentStorage1";
    };
*/

private ["_nearByChoppers","_cursorTarget","_type","_class","_requiredTools","_requiredParts","_upgradeType","_producedParts","_randomCreate",
	"_upgradeClass","_onLadder","_isWater","_ok","_missing","_upgradeParts","_dis","_characterID","_playerNear",
	"_ownerArray","_ownerPasscode","_dir","_vector","_object","_puid","_clanArray","_wh","_variables","_finished"];

_cursorTarget = _this;

if ((isNil "_cursorTarget") or {(isNull _cursorTarget)}) then {
    _cursorTarget = nearestObjects [player modelToWorld [0,1.5,0] , ["DZ_buildables","BuiltItems"], 1.5];
    _cursorTarget = if (count _cursorTarget == 0) then {objNull} else {_cursorTarget select 0};
};
if (isNull _cursorTarget) exitWith {};

_nearByChoppers = _cursorTarget nearObjects ["Helicopter", 10];
if (count _nearByChoppers > 1) exitwith {localize "str_upgradevehctooClose" call dayz_rollingMessages;};

_type = typeof _cursorTarget;
_class = configFile >> "CfgVehicles" >> _type;
_requiredTools = getArray (_class >> "Upgrade" >> "requiredTools");
_requiredParts = getArray (_class >> "Upgrade" >> "requiredParts");
_upgradeType = getText (_class >> "Upgrade" >> "create");
_producedParts = getArray (_class >> "Upgrade" >> "produce");

if (isArray(configFile >> "CfgVehicles" >> _type >> "Upgrade" >> "randomcreate")) then { 
    _randomCreate = getArray (_class >> "Upgrade" >> "randomcreate");
    _upgradeType = _randomCreate call BIS_fnc_selectRandom;
};

_upgradeClass = configFile >> "CfgVehicles" >> _upgradeType;
if (!isClass _upgradeClass) exitWith {localize "str_upgradeNoOption" call dayz_rollingMessages;};

_onLadder = (getNumber (configFile >> "CfgMovesMaleSdr" >> "States" >> (animationState player) >> "onLadder")) == 1;
_isWater = (surfaceIsWater (getPosATL player)) or dayz_isSwimming;
if (_isWater or _onLadder) exitWith {localize "str_water_ladder_cant_do" call dayz_rollingMessages;};

_playerNear = {isPlayer _x} count (([_cursorTarget] call fnc_getPos) nearEntities ["CAManBase", 12]) > 1;
if (_playerNear) exitWith {localize "str_pickup_limit_5" call dayz_rollingMessages;};

_ok = true;
_missing = "";
{
    if (!(_x in items player)) exitWith {
        _missing = getText (configFile >> "CfgWeapons" >> _x >> "displayName");
        _ok = false;
    };
} count _requiredTools;

if (!_ok) exitWith {format [localize "str_upgradeMissingTool", _missing] call dayz_rollingMessages;};

_ok = true;
_upgradeParts = [];
{
    if (!(_x in magazines player)) exitWith {
        _missing = getText (configFile >> "CfgMagazines" >> _x >> "displayName");
        _ok = false;
    };
    if (_x in magazines player) then {
        _upgradeParts set [count _upgradeParts, _x];
        player removeMagazine _x;
    };
} count _requiredParts;

if (!_ok) exitWith {
    {player addMagazine _x;} foreach _upgradeParts;
	format [localize "str_upgradeMissingPart", _missing] call dayz_rollingMessages;
};

if (dayz_actionInProgress) exitWith {
	{player addMagazine _x;} forEach _upgradeParts;
	localize "str_player_actionslimit" call dayz_rollingMessages;
};
dayz_actionInProgress = true;

_dis=20;
[player,"tentpack",0,false,_dis] call dayz_zombieSpeak;
[player,_dis,true,(getPosATL player)] call player_alertZombies;

_finished = ["Medic",1] call fn_loopAction;

if (!_finished) exitWith {
	{player addMagazine _x;} forEach _upgradeParts;
	dayz_actionInProgress = false;
};

["Working",0,[100,15,5,0]] call dayz_NutritionSystem;

_characterID = _cursorTarget getVariable ["characterID","0"];
_ownerArray = _cursorTarget getVariable ["ownerArray",[]];
_ownerPasscode = _cursorTarget getVariable ["padlockCombination",[]];
_dir = round getDir _cursorTarget;
_vector = [vectorDir _cursorTarget,vectorUp _cursorTarget];
_pos = getposATL _cursorTarget;

if (abs(((_vector select 1) select 2) - 1) > 0.001) then {_pos set [2,0];};


_object = createVehicle [_upgradeType, getMarkerpos "respawn_west", [], 0, "CAN_COLLIDE"];
//if (_object isKindOf "DZ_buildables") then { _object allowDamage false; };
_object setVectorDirAndUp _vector;
_object setPosATL _pos;
_puid = getPlayerUID player;

/*
if (!(_puid in _clanArray)) then {
    _clanArray set [ count _clanArray, _puid ];
};
*/

_object setVariable ["ownerArray",_ownerArray,true];
_object setVariable ["padlockCombination",_ownerPasscode,true];
_object setVariable ["characterID",_characterID,true];

PVDZ_obj_Destroy = [netID player,netID _cursorTarget,dayz_authKey];
publicVariableServer "PVDZ_obj_Destroy";

_wh = "WeaponHolder" createVehicle (getPosATL player);
{
    if (isClass (configFile >> "CfgMagazines" >> _x)) then {
		_wh addMagazineCargoGlobal [_x, 1];
	} else {
		_wh addWeaponCargoGlobal [_x, 1];
	};
} forEach _producedParts;

_variables = [["ownerArray", _ownerArray],["padlockCombination", _ownerPasscode]];
PVDZ_obj_Publish = [dayz_characterID,_object,[_dir,_pos],_variables,player,dayz_authKey];
publicVariableServer "PVDZ_obj_Publish";
diag_log [diag_ticktime, __FILE__, "New Networked object, request to save to hive. PVDZ_obj_Publish:", PVDZ_obj_Publish];

/*
//Send maintenance info
PVDZ_veh_Save = [_object,"maintenance"];
publicVariableServer "PVDZ_veh_Save";
if (isServer) then {
    PVDZ_veh_Save call server_updateObject;
};*/

player reveal _object;

localize "str_upgradeDone" call dayz_rollingMessages;
dayz_actionInProgress = false;