local _obj = _this select 0;

if (isServer) then {
	local _objectID = _obj getVariable ["ObjectID","0"];
	local _objectUID = _obj getVariable ["ObjectUID","0"];

	[_objectID,_objectUID,_obj] call server_deleteObjDirect;
} else {
	if (count _this == 2) then {
		//single use trap triggered, remove with no animation
		//For normal remove let object_pickup.sqf perform deletion to ensure player has room in gear first, no others remove at same time and animation runs
		PVDZ_obj_Destroy = [netID player,netID _obj,dayz_authKey];
		publicVariableServer "PVDZ_obj_Destroy";
		//deleteVehicle _obj;
	};
};
