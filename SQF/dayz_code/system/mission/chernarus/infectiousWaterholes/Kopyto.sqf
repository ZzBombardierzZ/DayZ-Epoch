[
	["Mass_grave",[7698.6094,3984.0344,5.3405762e-005],-127.91888],
	["Body1",[7696.6646,3979.2568,6.1035156e-005],0],
	["Body1",[7705.2397,3986.8789,-7.6293945e-006],0],
	["Body2",[7701.4297,3987.833,4.5776367e-005],-260.24319],
	["Body2",[7693.4331,3985.4343,0.00016784668],-259.017],
	["Body2",[7737.8218,3956.1387,3.8146973e-005],-261.63678],
	["Body2",[7701.2686,3978.0706,1.9073486e-005],-256.70078],
	["Body2",[7705.8154,3981.1963,7.2479248e-005],-98.922691],
	["Body2",[7705.1436,3975.3965,-8.392334e-005],-205.44472],
	["Body1",[7703.9932,3978.3486,-2.2888184e-005],0]
] call {
	private ["_object"];
	_object = (_x select 0) createVehicleLocal [0,0,0];
	_object setVariable ["", true];
	_object setDir (_x select 2);
	_object setPos (_x select 1);
} count _this;