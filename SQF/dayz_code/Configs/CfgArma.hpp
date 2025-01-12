
class CfgActions {
	class None; // External class reference
	class Rearm : None { show = 0; };
	class Heal : None { show = 0; };
	class HealSoldier : None { show = 0; };
	class FirstAid : None { show = 0; };
	class TakeBag : None { show = 0; };
	class Take : None { show = 0; };
	//class LoadMagazine : None { show = 0; };
	//class LoadOtherMagazine : LoadMagazine { show = 0; };
	//class LoadEmptyMagazine : LoadMagazine { show = 0; };
	class FireInflame : None { show = 0; };
	class FirePutDown : None { show = 0; };
	class Repair : None { show = 0; };
	class Refuel : None { show = 0; };
	class TakeWeapon : None { show = 0; };
	//class TakeMagazine : None { show = 0; };
	//class OpenBag : None { show = 0; };
	class PutBag : None { show = 0; };
	class DropBag : None { show = 0; };
	class AddBag : None { show = 0; };
	class TakeMine : None { show = 0; };
	class DropWeapon : None { show = 0; };
	class PutWeapon : None { show = 0; };
	class DropMagazine : None { show = 0; };
	class PutMagazine : None { show = 0; };
	class DeactivateMine : None { show = 0; };
	class RepairVehicle: None { show = 0; };
	class HideBody: None { show = 0; }; //Moved to fn_selfactions to allow editing
/*
"None"
"GetInCommander"
"GetInDriver"
"GetInPilot"
"GetInGunner"
"GetInCargo"
"GetInTurret"
"Heal"
"HealSoldier"
"RepairVehicle"
"FirstAid"
"Repair"
"Refuel"
"Rearm"
"GetOut"
"LightOn"
"LightOff"
"GunLightOn"
"GunLightOff"
"ArtilleryComputer"
"EngineOn"
"EngineOff"
"SwitchWeapon"
"SwitchMagazine"
"HideWeapon"
"UseWeapon"
"LoadMagazine"
"LoadOtherMagazine"
"LoadEmptyMagazine"
"TakeWeapon"
"TakeDropWeapon"
"TakeMagazine"
"TakeDropMagazine"
"TakeFlag"
"ReturnFlag"
"TurnIn"
"TurnOut"
"WeaponInHand"
"WeaponOnBack"
"SitDown"
"Land"
"CancelLand"
"Eject"
"MoveToDriver"
"MoveToPilot"
"MoveToGunner"
"MoveToCommander"
"MoveToCargo"
"MoveToTurret"
"HideBody"
"TouchOff"
"SetTimer"
"StartTimer"
"Deactivate"
"NVGoggles"
"NVGogglesOff"
"ManualFire"
"ManualFireCancel"
"AutoHover"
"AutoHoverCancel"
"StrokeFist"
"StrokeGun"
"LadderUp"
"LadderDown"
"LadderOnDown"
"LadderOnUp"
"LadderOff"
"FireInflame"
"FirePutDown"
"LandGear"
"LandGearUp"
"FlapsDown"
"FlapsUp"
"Salute"
"ScudLaunch"
"ScudStart"
"ScudCancel"
"User"
"DropWeapon"
"PutWeapon"
"DropMagazine"
"PutMagazine"
"UserType"
"HandGunOn"
"HandGunOnStand"
"HandGunOff"
"HandGunOffStand"
"TakeMine"
"DeactivateMine"
"UseMagazine"
"IngameMenu"
"CancelTakeFlag"
"CancelAction"
"MarkEntity"
"MarkWeapon"
"TeamSwitch"
"Gear"
"OpenBag"
"TakeBag"
"PutBag"
"DropBag"
"AddBag"
"IRLaserOn"
"IRLaserOff"
"Assemble"
"DisAssemble"
"Talk"
"Tell"
"Surrender"
"GetOver"
"Take"
*/
};
class CfgAISkill {
	aimingaccuracy[] = {0, 0, 1, 1};
	aimingshake[] = {0, 0, 1, 1};
	aimingspeed[] = {0, 0, 1, 1};
	commanding[] = {0, 0, 1, 1};
	courage[] = {0, 0, 1, 1};
	endurance[] = {0, 0, 1, 0.1};
	general[] = {0, 0, 1, 1};
	reloadspeed[] = {0, 0, 1, 1};
	spotdistance[] = {0, 0, 1, 1};
	spottime[] = {0, 0, 1, 1};
};

class CfgLoadingTexts {
	titlesDefault[] = {""};
};

class CfgInGameUI
{
    class PeripheralVision
    {
        cueColor[] = {0,0,0,0};
        cueFriendlyColor[] = {0,0,0,0};
        cueEnemyColor[] = {0,0,0,0};
    };
	
    class IslandMap
    {
        colorFriendly[] = {0,0.5,0,0}; //{0,0.5,0,1}; 
        colorEnemy[] = {0.5,0,0,0};    //{0.5,0,0,1};	  
        colorNeutral[] = {1.0,0.5,0,0};//{1.0,0.5,0,1};
        colorCivilian[] = {0,0,1,0};   //{0,0,1,0};
        colorUnknown[] = {1.0,0.5,0,0};//{1.0,0.5,0,0.8};
        shadow = 2;
        iconPlayer = "\ca\ui\data\map_player_ca.paa";
        iconPlayerDirection = "\ca\ui\data\map_dir_ca.paa";
        iconCheckpoint = "\ca\ui\data\map_target_ca.paa";
        iconCamera = "\ca\ui\data\map_camera_ca.paa";
        iconSelect = "\ca\ui\data\map_select_ca.paa";
        iconSensor = "\ca\ui\data\map_trigger_ca.paa";
        sizeLeader = 24;
        size = 26;
        sizePlayer = 26;
        colorTracks[] = {0.2,0.13,0,1};
        colorRoads[] = {0.2,0.13,0,1};
        colorMainRoads[] = {0,0,0,1};
        colorTracksFill[] = {0,0,0,0};
        colorRoadsFill[] = {1,0.88,0.65,1};
        colorMainRoadsFill[] = {0.94,0.69,0.2,1};
        cursorLineWidth = 1;
        colorGrid[] = {0.05,0.1,0,0.6};
        colorGridMap[] = {0.05,0.1,0,0.4};
    };
    	
	
	class MPTable
	{
		color[] = {0,0,0,0}; //{0.7,0.7,0.7,1};
		colorTitleBg[] = {0,0,0,0}; //{0.1,0.15,0.15,1};
		colorBg[] = {0,0,0,0}; //{0.1,0.15,0.1,0.9};
		colorSelected[] = {0,0,0,0}; //{0.7,0.7,0.7,0.4};
		colorWest[] = {0,0,0,0}; //{0.7,0.95,0.7,1};
		colorEast[] = {0,0,0,0}; //{0.95,0.7,0.7,1};
		colorCiv[] = {0,0,0,0}; //{0.8,0.8,0.8,1};
		colorRes[] = {0,0,0,0}; //{0.7,0.7,0.95,1};
		font = "EtelkaNarrowMediumPro";
		size = "0"; //"( 21 / 408 )";
		class Columns
		{
			class Order
			{
				width = 0; //0.046;
				colorBg[] = {0,0,0,0}; //{0.1,0.27,0.1,0.8};
				doubleLine = 0;
			};
			class Player
			{
				width = 0; //0.25;
				colorBg[] = {0,0,0,0}; //{0.1,0.23,0.1,0.8};
				doubleLine = 0;
			};
			class KillsInfantry
			{
				width = 0; //0.11;
				doubleLine = 0;
				colorBg[] = {0,0,0,0}; //{0.1,0.15,0.1,0.8};
				picture = ""; //"\ca\ui\data\stats_infantry_ca.paa";
			};
			class KillsSoft
			{
				width = 0; //0.1;
				doubleLine = 0;
				colorBg[] = {0,0,0,0}; //{0.1,0.15,0.1,0.8};
				picture = ""; //"\ca\ui\data\stats_soft_ca.paa";
			};
			class KillsArmor
			{
				width = 0; //0.11;
				doubleLine = 0;
				colorBg[] = {0,0,0,0}; //{0.1,0.15,0.1,0.8};
				picture = ""; //"\ca\ui\data\stats_armored_ca.paa";
			};
			class KillsAir
			{
				width = 0; //0.1;
				doubleLine = 0;
				colorBg[] = {0,0,0,0}; //{0.1,0.15,0.1,0.8};
				picture = ""; //"\ca\ui\data\stats_air_ca.paa";
			};
			class Killed
			{
				width = 0; //0.1;
				doubleLine = 0;
				colorBg[] = {0,0,0,0}; //{0.1,0.15,0.1,0.8};
				picture = ""; //"\ca\ui\data\stats_killed_ca.paa";
			};
			class KillsTotal
			{
				width = 0; //0.1;
				doubleLine = 0;
				colorBg[] = {0,0,0,0}; //{0.1,0.35,0.1,0.9};
				picture = ""; //"\ca\ui\data\stats_total_ca.paa";
			};
		};
	};
	// Hide group hotbar
	class CommandBar {
		left = "-0.032 + SafeZoneX";
		top = "(SafeZoneH + SafeZoneY) - (1 - 0.851)";
		width = 0;
		height = 0;
		imageDefaultWeapons = "ca\ui\data\clear_empty.paa";
		imageNoWeapons = "ca\ui\data\clear_empty.paa";
		imageCommander = "ca\ui\data\clear_empty.paa";
		imageDriver = "ca\ui\data\clear_empty.paa";
		imageGunner = "ca\ui\data\clear_empty.paa";
		imageCargo = "ca\ui\data\clear_empty.paa";
		dimm = 0.3;
		colorRedTeam[] = {0,0,0,0};
		colorBlueTeam[] = {0,0,0,0};
		colorGreenTeam[] = {0,0,0,0};
		colorYellowTeam[] = {0,0,0,0};
		colorWhiteTeam[] = {0,0,0,0};	
		class prevPage {
			x = 0;
			y = 0;
			w = 0;
			h = 0;
			color[] = {0,0,0,0};
			texture = "ca\ui\data\clear_empty.paa";
		};	
		class nextPage {
			x = 0;
			y = 0;
			w = 0;
			h = 0;
			color[] = {0,0,0,0};
			texture = "ca\ui\data\clear_empty.paa";
		};
		class UnitInfo {
			class GroupIcon {
				x = 0;
				y = 0;
				w = 0;
				h = 0;
			};
			class HcGroupText {
				x = 0;
				y = 0;
				w = 0;
				h = 0;
				font = "Zeppelin32";
				SizeEx = 0;
			};
			class UnitBackground {
				x = 0;
				y = 0;
				w = 0;
				h = 0;
				textureNormal = "ca\ui\data\clear_empty.paa";
				textureSelected = "ca\ui\data\clear_empty.paa";
				texturePlayer = "ca\ui\data\clear_empty.paa";
				textureFocus = "ca\ui\data\clear_empty.paa";
			};
			class UnitFocus {
				x = 0;
				y = 0;
				w = 0;
				h = 0;
				color[] = {0,0,0,0};
				texture = "ca\ui\data\clear_empty.paa";
			};
			class UnitIcon {
				x = 0;
				y = 0;
				w = 0;
				h = 0;
				color[] = {0,0,0,0};
				colorPlayer[] = {0,0,0,0};
				colorNoAmmo[] = {0,0,0,0};
				colorWounded[] = {0,0,0,0};
				colorWoundedFade[] = {0,0,0,0};
				colorNoFuel[] = {0,0,0,0};
			};
			class Semaphore {
				x = 0;
				y = 0;
				w = 0;
				h = 0;
				color[] = {0,0,0,0};
				texture = "ca\ui\data\clear_empty.paa";
			};
			class CommandBackground {
				x = 0;
				y = 0;
				w = 0;
				h = 0;
				color[] = {0,0,0,0};
				texture = "ca\ui\data\clear_empty.paa";
			};
			class CommandText {
				x = 0;
				y = 0;
				w = 0;
				h = 0;
				color[] = {0,0,0,0};
				font = "Zeppelin32";
				SizeEx = 0;
			};
			class UnitSpecialRole {
				x = 0;
				y = 0;
				w = 0;
				h = 0;
				color[] = {0,0,0,0};
			};
			class VehicleNumberBackground {
				x = 0;
				y = 0;
				w = 0;
				h = 0;
				color[] = {0,0,0,0};
				texture = "ca\ui\data\clear_empty.paa";
			};
			class VehicleNumberText {
				x = 0;
				y = 0;
				w = 0;
				h = 0;
				colorText[] = {0,0,0,0};
				font = "Zeppelin32";
				SizeEx = 0;
			};
			class UnitRole {
				x = 0;
				y = 0;
				w = 0;
				h = 0;
				color[] = {0,0,0,0};
			};
			class UnitNumberBackground {
				x = 0;
				y = 0;
				w = 0;
				h = 0;
				color[] = {0,0,0,0};
				texture = "ca\ui\data\clear_empty.paa";
			};
			class UnitNumberText {
				x = 0;
				y = 0;
				w = 0;
				h = 0;
				colorText[] = {0,0,0,0};
				font = "Zeppelin32";
				SizeEx = 0;
			};
			class CombatMode {
				x = 0;
				y = 0;
				w = 0;
				h = 0;
				textureMCareless = "ca\ui\data\clear_empty.paa";
				textureMSafe = "ca\ui\data\clear_empty.paa";
				textureMAware = "ca\ui\data\clear_empty.paa";
				textureMCombat = "ca\ui\data\clear_empty.paa";
				textureMStealth = "ca\ui\data\clear_empty.paa";
			};
		};
	};
};

class CfgVoice {
	class NoVoice {
		protocol = "RadioProtocolBase";
		variants[] = {1};
		directories[] = {"", ""};
		identityTypes[] = {"Default", "Zombie1", "Zombie2", "Zombie3"};
	};
};

class CfgIdentities {
	class PZombie1
	{
		name = "PZombie";
		face = "PZombieFace1";
		glasses = "None";
		speaker = "NoVoice";
		pitch = 1;
	};
	class Zombie1 {
		name = "Zombie";
		face = "Zombie1";
		glasses = "None";
		speaker = "NoVoice";
		pitch = 1;
	};
	
	class Zombie2 {
		name = "Zombie";
		face = "Zombie2";
		glasses = "None";
		speaker = "NoVoice";
		pitch = 1;
	};
	
	class Zombie3 {
		name = "Zombie";
		face = "Zombie3";
		glasses = "None";
		speaker = "NoVoice";
		pitch = 1;
	};
};

class CfgMissions
{
	 class Cutscenes
	 {
	  class DayZModIntro1
		  {
			directory = "z\addons\dayz_code\Configs\CfgWorlds\intro.dayzmod";
		  };
	 };
};

class CfgSurvival {
	class Inventory {
		class Default {
			RandomMagazines = 3;
			//weapons[] = {"Makarov"};
			//GuaranteedMagazines[] = {"ItemBandage","8Rnd_9x18_Makarov","8Rnd_9x18_Makarov","HandRoadFlare"};
			GuaranteedMagazines[] = {"ItemBandage","HandRoadFlare"};
			RandomPossibilitieMagazines[] = {"ItemBandage","ItemPainkiller"};
			backpackWeapon = "";
			//backpack = "DZ_Patrol_Pack_EP1";
		};
	};
	class Meat {
		class Default {
			yield = 2;
			//rawfoodtype = "FoodmeatRaw"; //This magazine does not exist
		};
		class Cow: Default {
			yield = 6;
			rawfoodtype = "FoodbeefRaw";
		};
		class Cow01: Cow {};
		class Cow02: Cow {};
		class Cow03: Cow {};
		class Cow04: Cow {};
		class Cow01_EP1: Cow {};
		class Goat: Default {
			yield = 4;
			rawfoodtype = "FoodgoatRaw";
		};
		class Goat01_EP1: Goat {};
		class Goat02_EP1: Goat {};
		class Sheep: Default {
			yield = 4;
			rawfoodtype = "FoodmuttonRaw";
		};
		class Sheep01_EP1: Sheep {};
		class Sheep02_EP1: Sheep {};
		class WildBoar: Default {
			yield = 4;
			rawfoodtype = "FoodbaconRaw";
		};
		class Hen: Default {
			yield = 2;
			rawfoodtype = "FoodchickenRaw";
		};
		class Cock: Hen {};
		class Fin: Default {
			rawfoodtype = "FoodDogRaw";
		};
		class Pastor: Fin {};
		class Rabbit: Default {
			yield = 2;
			rawfoodtype = "FoodrabbitRaw";
		};
	};
	class Plants {
		class Plant_Pumpkin_DZE {
			qty = 4;
		};
		class Plant_Sunflower_DZE {
			qty = 3;
		};
		class Plant_Potato_DZE {
			qty = 7;
		};
		class Plant_Carrot_DZE {
			qty = 7;
		};
		class Plant_Hemp_DZE {
			qty = 2;
		};
		class Plant_Tea_DZE {
			qty = 3;
		};
		class Plant_Tobacco_DZE {
			qty = 2;
		};
		class Plant_Garlic_DZE {
			qty = 7;
		};	
		class Plant_Comfrey_DZE {
			qty = 3;
		};		
	};
};
