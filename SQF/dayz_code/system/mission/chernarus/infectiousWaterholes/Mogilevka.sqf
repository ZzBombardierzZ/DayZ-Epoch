[
	["Body1",[7688.604,5947.6357,4.5776367e-005],0],
	["Body1",[7688.8301,5927.563,-3.0517578e-005],0],
	["Body2",[7692.501,5935.375,-4.5776367e-005],-157.49536],
	["Body2",[7700.9634,5931.4126,-4.5776367e-005],7.0104899],
	["Body2",[7858.001,5657.7495,1.5258789e-005],-128.94524],
	["Body2",[7852.356,5674.4395,-4.5776367e-005],-8.1682386],
	["Body1",[7857.3604,5665.8076,1.5258789e-005],0]
] call {
	private ["_object"];
	_object = (_x select 0) createVehicleLocal [0,0,0];
	_object setVariable ["", true];
	_object setDir (_x select 2);
	_object setPos (_x select 1);
} count _this;