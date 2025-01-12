private ["_display","_timeout","_inCombat","_playerCheck","_zedCheck","_lastPing"];
disableSerialization;
waitUntil {
	_display = findDisplay 49;
	!isNull _display;
};
_btnRespawn = _display displayCtrl 1010;
_btnAbort = _display displayCtrl 104;
_btnRespawn ctrlEnable false;
_btnAbort ctrlEnable false;
_btnAbortText = ctrlText _btnAbort;
_isPZombie = player isKindOf "PZombie_VB";
_testTime = diag_tickTime;
PVDZE_PingSend = player;
publicVariableServer "PVDZE_PingSend";
_lastPing = diag_tickTime;

if (r_fracture_legs or _isPZombie) then {_btnRespawn ctrlEnable true;};

//force gear save
if (diag_tickTime - dayz_lastSave > 10) then {
	call player_forceSave;
};

while {(!isNull _display) && !r_player_dead} do {
	_timeout = player getVariable["combatTimeout", 0];
	_inCombat = (_timeout >= diag_tickTime) || (player getVariable["combatNoTimeout", 0] == 1);
	_playerCheck = ({isPlayer _x} count (player nearEntities ["AllVehicles",5]) > 1);
	_zedCheck = ((count (player nearEntities ["zZombie_Base",10]) > 0) && !_isPZombie);
	_gearDisplay = findDisplay 106;
	if (!isNull _gearDisplay) then {
		_gearDisplay closeDisplay 0;
	};
	if (diag_tickTime - _lastPing > 2) then {
		PVDZE_PingSend = player;
		publicVariableServer "PVDZE_PingSend";
		_lastPing = diag_tickTime;
	};
	switch true do {
		case (diag_tickTime - DZE_LastPingResp > 4) : {
			_btnAbort ctrlEnable false;
			_btnAbort ctrlSetText format["%1 (in 10)", _btnAbortText];
			if (TimeOutDisplayed) then {
				_display closeDisplay 2;
				closeDialog 2;
			};
		};
		case (_playerCheck) : {
			_btnAbort ctrlEnable false;
			_btnAbort ctrlSetText format["%1 (in 10)", _btnAbortText];
			[localize "str_abort_playerclose",1] call dayz_rollingMessages;
			if (TimeOutDisplayed) then {
				_display closeDisplay 2;
				closeDialog 2;
			};
		};
		case (_zedCheck) : {
			_btnAbort ctrlEnable false;
			_btnAbort ctrlSetText format["%1 (in 10)", _btnAbortText];
			[localize "str_abort_zedsclose",1] call dayz_rollingMessages;
			if (TimeOutDisplayed) then {
				_display closeDisplay 2;
				closeDialog 2;
			};
		};
		case (DZE_EVRStormRunning) : {
			_btnAbort ctrlEnable false;
			[localize "STR_EPOCH_PLAYER_12_1",1] call dayz_rollingMessages;
		};		
		case (_inCombat) : {
			_btnAbort ctrlEnable false;
			_btnAbort ctrlSetText format["%1 (in %2)", _btnAbortText,[DZE_CombatTimer,ceil (_timeout - diag_tickTime)] select ((player getVariable["combatNoTimeout", 0] == 0))];
			[localize "str_abort_playerincombat",1] call dayz_rollingMessages;
			if (TimeOutDisplayed) then {
				_display closeDisplay 2;
				closeDialog 2;
			};
		};
		case (isInTraderCity) : {
			_btnAbort ctrlEnable false;
			[localize "str_epoch_player_12",1] call dayz_rollingMessages;
		};
		case (((diag_tickTime - _testTime) < 10) && !TimeOutDisplayed) : {
			_btnAbort ctrlEnable false;
			_btnAbort ctrlSetText format["%1 (in %2)",_btnAbortText, str(ceil (((_testTime + 10) - diag_tickTime)*10)/10)];
		};
		default {
			if (!TimeOutDisplayed && (!isNull _display)) then {
				TimeOutDisplayed = true;
			};
			_btnAbort ctrlEnable true;
			_btnAbort ctrlSetText _btnAbortText;
		};
	};
	if (isNull _display) then { //this prevents the timeout from being skipped if the menu is quickly re-opened
		TimeOutDisplayed = false;
	};
	uiSleep 0.1;
};

TimeOutDisplayed = false;
if (r_player_dead) then {_btnAbort ctrlEnable true;};