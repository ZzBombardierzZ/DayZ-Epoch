[
	["Body1",[8294.6152,12149.16,3.0517578e-005],0],
	["Body1",[8287.1045,12132.071,-0.00047302246],0],
	["Body1",[8264.8877,12148.402,0.00038146973],0],
	["Body2",[8268.8555,12156.784,-0.00012207031],-128.94524],
	["Body2",[8278.6172,12133.853,0.00077819824],34.286942]
] call {
	private ["_object"];
	_object = (_x select 0) createVehicleLocal [0,0,0];
	_object setVariable ["", true];
	_object setDir (_x select 2);
	_object setPos (_x select 1);
} count _this;