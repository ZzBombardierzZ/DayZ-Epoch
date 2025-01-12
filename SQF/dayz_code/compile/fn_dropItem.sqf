private ["_amount","_item","_pos","_manualPos","_nearByPile","_holder","_type"];

//Radius to search for holder
#define PILE_SEARCH_RADIUS 2
//Location to offset the holder
#define PILE_OFFSET [0,0,0]

_item = _this select 0;
_type = _this select 1;
_amount = _this select 2;
_manualPos = count _this > 3;
_pos = if (_manualPos) then {_this select 3} else {player modeltoWorld PILE_OFFSET};
_holder = objNull;

//Check if a holder is close by the player.
_nearByPile= nearestObjects [_pos, ["WeaponHolder","WeaponHolderBase"],PILE_SEARCH_RADIUS];

if (count _nearByPile == 0) then {	
	["WeaponHolder",objNull] call fn_waitForObject;

	//No weapon holders found in the radius, spawn a new one
	_holder = "WeaponHolder" createVehicle [0,0,0];
	_holder setPosATL _pos;
} else {
	//Found a near by weapon holder lets select it.
	_holder = _nearByPile select 0;

	if (!_manualPos) then {
		private "_objects";

		//check to make sure the player can see the selected weapon holder.
		_objects = lineIntersectsWith [(_holder modeltoWorld PILE_OFFSET), _pos, player, _holder, true];

		//Can you see the current selected weapon holder
		if (count _objects > 0) then {			
			["WeaponHolder",objNull] call fn_waitForObject;

			//Unable to see the current selected weapon holder within the radius lets create a new one.
			_holder = createVehicle ["WeaponHolder", _pos, [], 0, "CAN_COLLIDE"];
		};
	};
};

//Add the item to the holder or to the newly created holder.
switch _type do {
	case 1: {_holder addMagazineCargoGlobal [_item,_amount];};
	case 2: {_holder addWeaponCargoGlobal [_item,_amount];};
	case 3: {_holder addBackpackCargoGlobal [_item,_amount];};
};