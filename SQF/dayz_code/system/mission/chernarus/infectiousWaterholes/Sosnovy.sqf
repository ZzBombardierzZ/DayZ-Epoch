[
	["Mass_grave",[3343.3696,6476.2764,-0.00012207031],-127.91888],
	["Body2",[3346.2217,6479.2134],-163.78368],
	["Body2",[3349.7419,6476.9492],-266.83978],
	["Body1",[3348.4307,6479.6782,0],0],
	["Body1",[3345.9199,6471.7793,6.1035156e-005],0],
	["Body2",[3341.0183,6479.5151],-194.82481]
] call {
	private ["_object"];
	_object = (_x select 0) createVehicleLocal [0,0,0];
	_object setVariable ["", true];
	_object setDir (_x select 2);
	_object setPos (_x select 1);
} count _this;