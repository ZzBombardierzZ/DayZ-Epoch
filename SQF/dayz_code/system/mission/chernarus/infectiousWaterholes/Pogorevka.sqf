[
	["Body2",[4212.3784,6755.0444,6.1035156e-005],-228.21346],
	["Body2",[4220.8774,6743.3584,-9.1552734e-005],-281.87775],
	["Body1",[4220.0347,6739.5332,3.0517578e-005],0],
	["Body1",[4215.8643,6759.1436,3.0517578e-005],0],
	["Body1",[4232.8799,6753.3657,-0.00018310547],0],
	["Body1",[4230.6279,6744.4331,3.0517578e-005],0]
] call {
	private ["_object"];
	_object = (_x select 0) createVehicleLocal [0,0,0];
	_object setVariable ["", true];
	_object setDir (_x select 2);
	_object setPos (_x select 1);
} count _this;