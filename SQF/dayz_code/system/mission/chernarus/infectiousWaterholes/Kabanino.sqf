[
	["Body1",[5626.4521,8577.7822,0],0],
	["Body1",[5653.271,8565.1514,-3.0517578e-005],0],
	["Body2",[5631.9009,8564.624,9.1552734e-005],120.97764],
	["Body2",[5626.8066,8571.2871],-6.9082727],
	["Body2",[5624.5215,8586.6445,-3.0517578e-005],-10.941958]
] call {
	private ["_object"];
	_object = (_x select 0) createVehicleLocal [0,0,0];
	_object setVariable ["", true];
	_object setDir (_x select 2);
	_object setPos (_x select 1);
} count _this;