[
	["Body2",[5910.3682,7969.2676,-0.00033569336],-216.50493],
	["Body2",[5914.7852,7968.6514,-6.1035156e-005],-70.557304],
	["Body2",[5902.3218,7964.917,-0.00021362305],-146.58554],
	["Body1",[5917.2178,7968.6299,-0.00015258789],0],
	["Body1",[5905.082,7966.4629,-0.00015258789],0]
] call {
	private ["_object"];
	_object = (_x select 0) createVehicleLocal [0,0,0];
	_object setVariable ["", true];
	_object setDir (_x select 2);
	_object setPos (_x select 1);
} count _this;