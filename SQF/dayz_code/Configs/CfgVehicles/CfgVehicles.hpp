#include "CommonActions.hpp"
class WeaponFireGun;    // External class reference
class WeaponCloudsGun;  // External class reference
class WeaponFireMGun;   // External class reference
class WeaponCloudsMGun;

class CfgVehicles 
{
	class ALL;
	class AllVehicles : ALL
	{
		class NewTurret;
		class ViewPilot;
		class ViewOptics;
		class Sounds { class Engine; class Movement;};
		class DefaultEventhandlers;
		class EventHandlers: DefaultEventhandlers
		{
			killed = "_this call BIS_Effects_EH_Killed;";
		};
	};
	class Air : AllVehicles
	{
		class NewTurret;
		class ViewPilot;
		class AnimationSources;
	};
	class Helicopter : Air
	{
		class HitPoints
		{
			class HitHull {
				armor = 1;
				material = 51;
				name = "NEtrup";
				visual = "trup";
				passThrough = 1;
			};
			class HitEngine {
				armor = 0.25;
				material = 51;
				name = "motor";
				visual = "motor";
				passThrough = 1;
			};
			class HitAvionics {
				armor = 0.15;
				material = 51;
				name = "elektronika";
				visual = "elektronika";
				passThrough = 1;
			};
			class HitVRotor {
				armor = 0.3;
				material = 51;
				name = "mala vrtule";
				visual = "mala vrtule staticka";
				passThrough = 0.3;
			};
			class HitHRotor {
				armor = 0.2;
				material = 51;
				name = "velka vrtule";
				visual = "velka vrtule staticka";
				passThrough = 0.1;
			};
			class HitMissiles {
				armor = 0.1;
				material = 51;
				name = "munice";
				visual = "munice";
				passThrough = 0.5;
			};
			class HitRGlass {
				convexComponent = "sklo predni P";
				armor = 0.1;
				material = 51;
				name = "sklo predni P";
				visual = "sklo predni P";
				passThrough = 0;
			};
			class HitLGlass {
				convexComponent = "sklo predni L";
				armor = 0.1;
				material = 51;
				name = "sklo predni L";
				visual = "sklo predni L";
				passThrough = 0;
			};
			class HitGlass1 {
				armor = 2;
				material = -1;
				name = "glass1";
				visual = "glass1";
				passThrough = 0;
			};
			class HitGlass2 {
				armor = 2;
				material = -1;
				name = "glass2";
				visual = "glass2";
				passThrough = 0;
			};
			class HitGlass3 {
				armor = 2;
				material = -1;
				name = "glass3";
				visual = "glass3";
				passThrough = 0;
			};
			class HitGlass4 {
				armor = 2;
				material = -1;
				name = "glass4";
				visual = "glass4";
				passThrough = 0;
			};
			class HitGlass5 {
				armor = 2;
				material = -1;
				name = "glass5";
				visual = "glass5";
				passThrough = 0;
			};
			class HitGlass6 {
				armor = 2;
				material = -1;
				name = "glass6";
				visual = "glass6";
				passThrough = 0;
			};
		};
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class Turrets;
				class ViewOptics;
			};
		};
	};
	class Plane: Air
	{
		class ViewPilot;
		class ViewOptics;
		class AirplaneHUD;
		class HitPoints
		{
			class HitHull;
		};
		class AnimationSources;
		class UserActions
		{
			class PushPlane {ACTION_PUSH;};
		};
	};
	class Land;	// External class reference
	class LandVehicle : Land
	{
		class NewTurret;
		class Sounds;
		class ViewOptics;
		class ViewPilot;
		class AnimationSources;
		class EventHandlers;
		class Reflectors
		{
			class Left
			{
				angle = 120;
				color[] = {0.9,0.8,0.8,1};
				ambient[] = {0.1,0.1,0.1,1};
				position = "L svetlo";
				direction = "konec L svetla";
				hitpoint = "L svetlo";
				selection = "L svetlo";
				size = 0.5;
				brightness = 0.5;
			};
			class Right
			{
				angle = 120;
				color[] = {0.9,0.8,0.8,1};
				ambient[] = {0.1,0.1,0.1,1};
				position = "P svetlo";
				direction = "konec P svetla";
				hitpoint = "P svetlo";
				selection = "P svetlo";
				size = 0.5;
				brightness = 0.5;
			};
		};
	};
	class Car : LandVehicle {
		class HitPoints
		{
			class HitEngine;
			class HitRGlass;
			class HitLGlass;
			class HitBody;
			class HitFuel;			
			class HitLFWheel;
			class HitRFWheel;
			class HitLF2Wheel;
			class HitRF2Wheel;
			class HitLMWheel;
			class HitRMWheel;
			class HitLBWheel;
			class HitRBWheel;
			class HitGlass1;
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;
		};
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class Turrets;
				class ViewOptics;
			};
		};
		class Sounds : Sounds
		{
			class Engine;
			class Movement;
		};
	};
	
	class epoch_car: Car
	{
		vehicleClass = "DayZ Epoch Vehicles";
		side = 1;
		faction = "USMC";
		selectionBackLights = "brzdove svetlo";
		selectionBrakeLights = "zadni svetlo";
		crew = "";
		typicalCargo[] = {};
		class TransportMagazines {};
		class TransportWeapons {};
		
		class Turrets {};
		
		class AnimationSources
		{
			class HitLFWheel
			{
				source="Hit";
				hitpoint="HitLFWheel"; // name of hitpoints class
				raw = 1;
			};
			class HitRFWheel:HitLFWheel
			{
				hitpoint="HitRFWheel";
			};
			class HitLBWheel:HitLFWheel
			{
				hitpoint="HitLBWheel";
			};
			class HitRBWheel:HitLFWheel
			{
				hitpoint="HitRBWheel";
			};
			class HitLF2Wheel:HitLFWheel
			{
				hitpoint="HitLF2Wheel";
			};
			class HitRF2Wheel:HitLFWheel
			{
				hitpoint="HitRF2Wheel";
			};
			class HitLMWheel:HitLFWheel
			{
				hitpoint="HitLMWheel";
			};
			class HitRMWheel:HitLFWheel
			{
				hitpoint="HitRMWheel";
			};
			class HitGlass1
			{
				source="Hit";
				hitpoint="HitGlass1"; // name of hitpoints class
				raw = 1;
			};
			class HitGlass2: HitGlass1
			{
				hitpoint="HitGlass2";
			};
			class HitGlass3: HitGlass1
			{
				hitpoint="HitGlass3";
			};
			class HitGlass4: HitGlass1
			{
				hitpoint="HitGlass4";
			};			
		};
		class HitPoints : HitPoints
		{
			class HitRGlass {armor=0.3;material=-1;name="sklo predni P";passThrough=0;};
			class HitLGlass {armor=0.3;material=-1;name="sklo predni L";passThrough=0;};
			class HitGlass1 {armor=0.1;material=-1;name="glass1";visual="glass1";passThrough=0;};
			class HitGlass2 {armor=0.1;material=-1;name="glass2";visual="glass2";passThrough=0;};
			class HitGlass3 {armor=0.1;material=-1;name="glass3";visual="glass3";passThrough=0;};
			class HitGlass4 {armor=0.1;material=-1;name="glass4";visual="glass4";passThrough=0;};
			class HitBody {armor=1;material=-1;name="karoserie";visual="";passThrough=1;}; //disabled points from model
			class HitFuel {armor=0.3;material=-1;name="palivo";visual="";passThrough=0.5;};
			class HitLFWheel {armor=0.15;material=-1;name="wheel_1_1_steering";visual="";passThrough=0.3;};
			class HitLBWheel {armor=0.15;material=-1;name="wheel_1_2_steering";visual="";passThrough=0.3;};
			class HitLMWheel {armor=0.15;material=-1;name="wheel_1_3_steering";visual="";passThrough=0.3;};
			class HitLF2Wheel {armor=0.15;material=-1;name="wheel_1_4_steering";visual="";passThrough=0.3;};

			class HitRFWheel {armor=0.15;material=-1;name="wheel_2_1_steering";visual="";passThrough=0.3;};
			class HitRBWheel {armor=0.15;material=-1;name="wheel_2_2_steering";visual="";passThrough=0.3;};
			class HitRMWheel {armor=0.15;material=-1;name="wheel_2_3_steering";visual="";passThrough=0.3;};
			class HitRF2Wheel {armor=0.15;material=-1;name="wheel_2_4_steering";visual="";passThrough=0.3;};
			class HitEngine {armor=0.4;material=-1;name="motor";visual="";passThrough=0.2;};

		};	
		class damage
		{
			tex[]={};
			mat[]={};
		};

		class nvgmarkers
		{
			class nvgmarker01
			{
				name = "nvg_marker";
				color[] = {0.03, 0.003, 0.003, 1};
				ambient[] = {0.003, 0.0003, 0.0003, 1};
				brightness = 0.001;
				blinking = 1;
			};
		};
		outsidesoundfilter=true;
		insidesoundcoef = 0.8;
		soundgear[]={,db-85,1};
		soundgetin[]={"ca\sounds_e\wheeled_e\suv\suv_ext_door",db-5, 1};
		soundgetout[]={"ca\sounds_e\wheeled_e\suv\suv_ext_door",db-5, 1, 20};
		soundengineonint[] = {"ca\sounds_e\wheeled_e\suv\suv_int_start", db-15, 1.0};
		soundengineonext[] = {"ca\sounds_e\wheeled_e\suv\suv_ext_start", db-15, 1.0, 100};
		soundengineoffint[] ={"ca\sounds_e\wheeled_e\suv\suv_int_stop", db-15, 1.0};
		soundengineoffext[] ={"ca\sounds_e\wheeled_e\suv\suv_ext_stop", db-15, 1.0, 100};

		buildcrash0[]={"ca\sounds\vehicles\crash\crash_building_01", db-3, 1,200};
		buildcrash1[]={"ca\sounds\vehicles\crash\crash_building_02", db-3, 1,200};
 		buildcrash2[]={"ca\sounds\vehicles\crash\crash_building_03", db-3, 1,200};
 		buildcrash3[]={"ca\sounds\vehicles\crash\crash_building_04", db-3, 1,200};
 		soundbuildingcrash[]={buildcrash0, 0.25, buildcrash1, 0.25, buildcrash2, 0.25, buildcrash3, 0.25};

		woodcrash0[]={"ca\sounds\vehicles\crash\crash_mix_wood_01", db-3, 1,200};
		woodcrash1[]={"ca\sounds\vehicles\crash\crash_mix_wood_02", db-3, 1,200};
		woodcrash2[]={"ca\sounds\vehicles\crash\crash_mix_wood_03", db-3, 1,200};
		woodcrash3[]={"ca\sounds\vehicles\crash\crash_mix_wood_04", db-3, 1,200};
		woodcrash4[]={"ca\sounds\vehicles\crash\crash_mix_wood_05", db-3, 1,200};
		woodcrash5[]={"ca\sounds\vehicles\crash\crash_mix_wood_06", db-3, 1,200};
		soundwoodcrash[]={woodcrash0, 0.166, woodcrash1, 0.166, woodcrash2, 0.166, woodcrash3, 0.166,woodcrash4, 0.166,woodcrash5, 0.166};

		armorcrash0[]={"ca\sounds\vehicles\crash\crash_vehicle_01", db-3, 1,200};
		armorcrash1[]={"ca\sounds\vehicles\crash\crash_vehicle_02", db-3, 1,200};
		armorcrash2[]={"ca\sounds\vehicles\crash\crash_vehicle_03", db-3, 1,200};
		armorcrash3[]={"ca\sounds\vehicles\crash\crash_vehicle_04", db-3, 1,200};
		soundarmorcrash[]={armorcrash0, 0.25, armorcrash1, 0.25, armorcrash2, 0.25, armorcrash3, 0.25};

		class soundevents
		{
			class accelerationin
			{
				sound[] = {"ca\sounds_e\wheeled_e\suv\suv_int_accelerate_3_x", db-5, 1.0};
				limit = "0.4";
				expression = "(engineon*(1-campos))*gmeterz";
			};
			class accelerationout
			{
				sound[] = {"ca\sounds_e\wheeled_e\suv\suv_ext_accelerate_3", db-5, 1.0, 200};
				limit = "0.4";
				expression = "(engineon*campos)*gmeterz";
			};
		};

		class sounds
		{
			class engine
			{
				sound[] =  {"ca\sounds_e\wheeled_e\suv\suv_ext_low", db-15, 1.4, 100};
				frequency = "(randomizer*0.05+0.95)*rpm";
				volume = "campos*engineon*((rpm factor[0.3, 0.4]) min (rpm factor[0.7, 0.5]))";
			};
			class enginehighout
			{
				sound[] = {"ca\sounds_e\wheeled_e\suv\suv_ext_high", db0, 0.8, 300};
				frequency = "(randomizer*0.05+0.95)*rpm";
				volume = "campos*engineon*(rpm factor[0.5, 0.8])";
			};
			class idleout
			{
				sound[] = {"ca\sounds_e\wheeled_e\suv\suv_ext_idle", db-5, 1.0, 100};
				frequency = "1";
				volume = "engineon*campos*(rpm factor[0.4, 0])";
			};
			class tiresrockout
			{
				sound[] = {"\ca\sounds\vehicles\wheeled\tires\ext\ext-tires-rock2", db-10, 1.0, 30};
				frequency = "1";
				volume = "campos*rock*(speed factor[2, 20])";
			};
			class tiressandout
			{
				sound[] = {"\ca\sounds\vehicles\wheeled\tires\ext\ext-tires-sand2", db-10, 1.0, 30};
				frequency = "1";
				volume = "campos*sand*(speed factor[2, 20])";
			};
			class tiresgrassout
			{
				sound[] = {"\ca\sounds\vehicles\wheeled\tires\ext\ext-tires-grass2", db-10, 1.0, 30};
				frequency = "1";
				volume = "campos*grass*(speed factor[2, 20])";
			};
			class tiresmudout
			{
				sound[] = {"\ca\sounds\vehicles\wheeled\tires\ext\ext-tires-mud2", db-10, 1.0, 30};
				frequency = "1";
				volume = "campos*mud*(speed factor[2, 20])";
			};
			class tiresgravelout
			{
				sound[] = {"\ca\sounds\vehicles\wheeled\tires\ext\ext-tires-gravel2", db-10, 1.0, 30};
				frequency = "1";
				volume = "campos*gravel*(speed factor[2, 20])";
			};
			class tiresasphaltout
			{
				sound[] = {"\ca\sounds\vehicles\wheeled\tires\ext\ext-tires-asphalt3", db-10, 1.0, 30};
				frequency = "1";
				volume = "campos*asphalt*(speed factor[2, 20])";
			};
			class noiseout
			{
				sound[] = {"\ca\sounds\vehicles\wheeled\noises\ext\noise2", db-20, 1.0, 30};
				frequency = "1";
				volume = "campos*(damper0 max 0.03)*(speed factor[0, 8])";
			};
			class enginelowin
			{
				sound[] = {"ca\sounds_e\wheeled_e\suv\suv_int_low_x", db-10, 1.4};
				frequency = "(randomizer*0.05+0.95)*rpm";
				volume = "(1-campos)*engineon*((rpm factor[0.3, 0.4]) min (rpm factor[0.7, 0.45]))";
			};
			class enginehighin
			{
				sound[] = {"ca\sounds_e\wheeled_e\suv\suv_int_high_x", db0, 0.8};
				frequency = "(randomizer*0.05+0.95)*rpm";
				volume = "(1-campos)*engineon*(rpm factor[0.5, 0.8])";
			};
			class idlein
			{
				sound[] = {"ca\sounds_e\wheeled_e\suv\suv_int_idle_x", db-10, 1.0};
				frequency = "1";
				volume = "engineon*(rpm factor[0.4, 0])*(1-campos)";
			};
			class tiresrockin
			{
				sound[] = {"\ca\sounds\vehicles\wheeled\tires\int\int-tires-rock2", db-10, 1.0};
				frequency = "1";
				volume = "(1-campos)*rock*(speed factor[2, 20])";
			};
			class tiressandin
			{
				sound[] = {"\ca\sounds\vehicles\wheeled\tires\int\int-tires-sand2", db-10, 1.0};
				frequency = "1";
				volume = "(1-campos)*sand*(speed factor[2, 20])";
			};
			class tiresgrassin
			{
				sound[] = {"\ca\sounds\vehicles\wheeled\tires\int\int-tires-grass2", db-10, 1.0};
				frequency = "1";
				volume = "(1-campos)*grass*(speed factor[2, 20])";
			};
			class tiresmudin
			{
				sound[] = {"\ca\sounds\vehicles\wheeled\tires\int\int-tires-mud2", db-10, 1.0};
				frequency = "1";
				volume = "(1-campos)*mud*(speed factor[2, 20])";
			};
			class tiresgravelin
			{
				sound[] = {"\ca\sounds\vehicles\wheeled\tires\int\int-tires-gravel2", db-10, 1.0};
				frequency = "1";
				volume = "(1-campos)*gravel*(speed factor[2, 20])";
			};
			class tiresasphaltin
			{
				sound[] = {"\ca\sounds\vehicles\wheeled\tires\int\int-tires-asphalt3", db-10, 1.0};
				frequency = "1";
				volume = "(1-campos)*asphalt*(speed factor[2, 20])";
			};
			class noisein
			{
				sound[] = {"\ca\sounds\vehicles\wheeled\noises\int\noise2", db-15, 1.0};
				frequency = "1";
				volume = "(damper0 max 0.03)*(speed factor[0, 8])*(1-campos)"; //definice inside zvuku
			};
		};
		
	};
	
	class Tank: LandVehicle {
		class HitPoints
		{
			class HitEngine;
			class HitHull;
			class HitLTrack;
			class HitRTrack;
		};
		class ViewPilot;
		class ViewOptics;
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class Turrets;
				class HitPoints
				{
					class HitTurret;
					class HitGun;
				};
			};
		};

		class CargoLight;
		class Sounds: Sounds
		{
			class Engine;
			class Movement;
		};
		class SpeechVariants
		{
			class Default;
			class EN;
			class CZ;
			class CZ_Akuzativ;
			class RU;
		};
		class Eventhandlers;
	};


	//External Class

	class Motorcycle : LandVehicle
	{
		class Reflectors
		{
			class Right
			{
				angle = 90;
			};
		};
	};
	
	class Truck: Car
	{
		class HitPoints: HitPoints
		{
			class HitLFWheel;
			class HitLBWheel;
			class HitLMWheel;
			class HitRFWheel;
			class HitRBWheel;
			class HitRMWheel;
			class HitGlass1;
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;
		};
		class DestructionEffects;
		class Turrets;
	};	

	class SUV_Base_EP1 : Car
	{
		class HitPoints : HitPoints
		{
			class HitLFWheel;
			class HitLBWheel;
			class HitRFWheel;
			class HitRBWheel;
			class HitFuel;
			class HitEngine;
			class HitGlass1;
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;

		};
	};
	class BRDM2_Base;
	class HouseBase;
	class Ruins: HouseBase {};
	class House : HouseBase
	{
		class DestructionEffects;
	};
	class House_EP1;
	class Land_HouseV_1I2;
	class SpawnableWreck : House {};
	class Strategic;
	class NonStrategic;
	class Thing;
	class BuiltItems;
	class Building;
	class ReammoBox;
	class Land_A_tent;

	#include "RepairParts.hpp"
	//ZEDS
	#include "Zeds\Zeds.hpp" //All type zeds
	#include "Zeds\ViralZeds.hpp" //Viral type zeds
	#include "Zeds\WildZeds.hpp" //Wild type zeds
	#include "Zeds\SwarmZeds.hpp" //Swarm type zeds
	#include "Zeds\PlayerZeds.hpp" //Player type zeds
	#include "Zeds\Bloodsuckers.hpp" //NS Bloodsuckers
	//Skins	
	#include "Skins\Male.hpp"
	#include "Skins\Female.hpp"
	//Bags
	#include "Bags.hpp"	// Backpacks
	//DZAnimal and DZ_Fin
	#include "Animal.hpp"

	//Includes all DayZ Vehilces
	//Cars
	#include "Car\HMMWV.hpp"
	#include "Car\ArmoredSUV.hpp"
	#include "Car\BTR40.hpp"	
	#include "Car\BTR60.hpp"
	#include "Car\BTR90.hpp"
	#include "Car\datsun.hpp"
	#include "Car\Gaz_Vodnik.hpp"
	#include "Car\hilux.hpp"
	#include "Car\Ikarus.hpp"
	#include "Car\Kamaz.hpp"
	#include "Car\Lada.hpp"
	#include "Car\LandRover.hpp"
	#include "Car\LAV25.hpp"
	#include "Car\M113.hpp"
	#include "Car\Mtvr.hpp"
	#include "Car\S1203.hpp"
	#include "Car\Tractor.hpp"
	#include "Car\UAZ_MG.hpp"
	#include "Car\UAZ_AGS.hpp"
	#include "Car\UAZ_SPG.hpp"
	#include "Car\Volha.hpp"
	#include "Car\VWGolf.hpp"
	#include "Car\Skoda.hpp"
	#include "Car\CAR_HATCHBACK.hpp"
	#include "Car\UAZ.hpp"
	#include "Car\CAR_SEDAN.hpp"
	#include "Car\V3S_Civ.hpp"
	#include "Car\SUV_DZ.hpp"
	#include "Car\Pickup_PK_INS.hpp"
	#include "Car\Offroad_DSHKM_INS.hpp"
	#include "Car\Offroad_SPG9.hpp"
	#include "Car\UralCivil_DZ.hpp"
	#include "Car\BRDM2_DZ.hpp"
	#include "Car\Jackal.hpp"
	#include "Car\Dingo.hpp"
	#include "Car\Octavia.hpp"
	#include "Car\Tatra_T810.hpp"
	#include "Car\BMP2.hpp"
	#include "Car\T72.hpp"
	#include "Car\Jeep.hpp"
	#include "Car\MiniCooper.hpp"
	#include "Car\Nissan.hpp"
	#include "Car\ScrapAPC.hpp"
	#include "Car\AAV.hpp"
	//Helicopters
	#include "Helicopter\MI17.hpp"
	#include "Helicopter\UH1H.hpp"
	#include "Helicopter\UH1Y.hpp"
	#include "Helicopter\AH6.hpp"
	#include "Helicopter\MH6J_DZ.hpp"
	#include "Helicopter\CH53.hpp"
	#include "Helicopter\UH60.hpp"
	#include "Helicopter\CH47.hpp"
	#include "Helicopter\BAF_Merlin.hpp"
	#include "Helicopter\AH1Z.hpp"
	#include "Helicopter\Pook.hpp"
	#include "Helicopter\CSJ_GyroAC.hpp"
	#include "Helicopter\KA60.hpp"
	#include "Helicopter\AW159.hpp"
	#include "Helicopter\MTVRBird.hpp"
	#include "CrashSite.hpp"
	//Planes
	#include "Plane\AN2_DZ.hpp"
	#include "Plane\MV22.hpp"
	#include "Plane\C130.hpp"
	#include "Plane\Cessna_DZ.hpp"
	#include "Plane\Camel.hpp"
	//Bikes
	#include "Bikes\ATVs.hpp"
	#include "Bikes\Bikes.hpp"
	#include "Bikes\Motorbikes.hpp"

	//Boat
	#include "Boat\RHIB.hpp"
	#include "Boat\PBX.hpp"
	#include "Boat\Fishing_Boat.hpp"
	#include "Boat\smallboat.hpp"
	#include "Boat\JetSkiYanahui.hpp"
	#include "Boat\Seafox.hpp"
	#include "Boat\Submarine.hpp"

	//Includes all Building Stuff
	//Houses
	#include "Buildings\Land_A_Crane_02b.hpp"
	#include "Buildings\Land_A_TVTower_Mid.hpp"
	#include "Buildings\Land_A_TVTower_Top.hpp"
	#include "Buildings\Land_Farm_WTower.hpp"
	#include "Buildings\Land_HouseB_Tenement.hpp"
	#include "Buildings\Land_Ind_MalyKomin.hpp"
	#include "Buildings\Land_komin.hpp"
	#include "Buildings\Land_majak.hpp"
	#include "Buildings\Land_Mil_ControlTower.hpp"
	#include "Buildings\Land_NAV_Lighthouse.hpp"
	#include "Buildings\Land_NavigLight.hpp"
	#include "Buildings\Land_Rail_Semafor.hpp"
	#include "Buildings\Land_Rail_Zavora.hpp"
	#include "Buildings\Land_runway_edgelight.hpp"
	#include "Buildings\Land_Stoplight.hpp"
	#include "Buildings\Land_telek1.hpp"
	#include "Buildings\Land_VASICore.hpp"
	#include "Buildings\Land_Vysilac_FM.hpp"
	#include "Buildings\WarfareBBaseStructure.hpp"	
	#include "Buildings\Land_houseV_2T2.hpp"
	#include "Buildings\Land_Ind_Oil_Pump_EP1_DZE.hpp"	//Oil Pump without sound
	#include "Buildings\Fuelstations.hpp"
	#include "Buildings\land_ibr_hangar.hpp" //Works only if Lingor is loaded
	#include "Buildings\Land_Shed_M01.hpp" // Animated door and interior, made by Helion4
	
	#include "Land_Fire.hpp"	
	#include "WaterSources.hpp"	
	#include "Blood_Trail_DZ.hpp"
	#include "DebugBox.hpp"
	#include "Graves.hpp" // GraveDZE, Massgrave, dead bodies
	#include "Veins.hpp" //Veins and Wrecks
	#include "SupplyCrate.hpp" //Supply Crate and Wreck
	#include "InfectedCamps.hpp"		
	#include "Rubbish.hpp"	
	
	//Buildables
	class DZ_storage_base : Land_A_tent {
		scope = 0;
		armor = 5;
		displayname = $STR_VEH_NAME_STASH;
		icon = "";
		mapsize = 3;
		transportMaxMagazines = 0;
		transportMaxWeapons = 0;
		transportMaxBackpacks = 0;	
		constructioncount = 1;
		requireplot = 0;
		nounderground = 0;
		offset[] = {0,3,0};
	};
	
	#include "Buildables\Stashes.hpp"
	#include "Buildables\Tents.hpp"
	#include "Buildables\Storage.hpp"
	#include "Buildables\LockableStorage.hpp"
	#include "Buildables\Traps.hpp"	
	#include "Buildables\Generator.hpp"	
	#include "Buildables\Doors.hpp"
	#include "Buildables\Bridges.hpp"
	#include "Buildables\ModularBuild.hpp"		
	#include "Buildables\FencesWood.hpp"
	#include "Buildables\FencesMetal.hpp"
	#include "Buildables\FencesGates.hpp"
	#include "Buildables\CamoNets.hpp"
	#include "Buildables\Sandbags.hpp"
	#include "Buildables\Billboards.hpp"
	#include "Buildables\Misc.hpp"
	#include "Buildables\StaticWeapons.hpp"
	
	//Loot Container
	#include "LootContainer\AmmoCrates.hpp"
	#include "LootContainer\CardboardBox.hpp"
	
	//WeaponHolder	
	class WeaponHolder;	// External class reference
	#include "WeaponHolder.hpp"
	#include "Plants.hpp"	

	//Antihack
	#include "AntiHack\antihack_logic.hpp"
	#include "AntiHack\antihack_plants.hpp"
	
	class Land_CncBlock_AntiHack: NonStrategic
	{
		scope = 2;
		vehicleClass = "DayZ Epoch Buildings";
		model = "z\addons\dayz_communityassets\models\CncBlock_D.p3d";
		Icon = "\Ca\misc3\Data\Icons\icon_cnc_con_barrier_CA.paa";
		mapSize = 4;
		displayName = $STR_MISC_CNCBLOCK_D;
		armor = 150;
	};
	
	class waterHoleProxy: House {
		model = "z\addons\dayz_communityassets\models\waterHoleProxy.p3d";
	};	

	class ThingEffect;
	class FxCartridge_Mp7: ThingEffect
	{
		model = "\C1987_Mp7\cartridge\46_30.p3d";
		displayName = "4.6x30mm Cartridge";
		submerged = 0;
		submergeSpeed = 0;
		timeToLive = 5;
		disappearAtContact = 1;
		airRotation = 1.0;
	};
	
	#include "HiddenGearContainer.hpp"
	#include "Helper.hpp"	
};