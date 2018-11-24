/*
	Author: Chris(tian) "infiSTAR" Lorenzen
	EMail: admin@infiSTAR.de
	Homepage: https://infiSTAR.de

	Copyright infiSTAR. All rights reserved.
*/
#include "EXILE_AHAT_CONFIG.hpp"
class CfgPatches
{
	class a3_infiSTAR_Exile
	{
		requiredVersion = 0.12265;
		requiredAddons[] = {};
		units[] = {};
		weapons[] = {};
		magazines[] = {};
		ammo[] = {};
		author[]= {"Chris(tian) 'infiSTAR' Lorenzen"};
		website[]= {"https://infiSTAR.de"};
		contact[]= {"admin@infiSTAR.de","infiSTAR23@gmail.com"};
		version = 'v93';
		licensed = "nathan.lloyd1983@googlemail.com";
	};
};
class CfgFunctions
{
	class a3_infiSTAR_Exile
	{
		class main
		{
			file = "a3_infiSTAR_Exile";
			class preInit { preInit = 1; };
			class postInit { postInit = 1; };
		};
	};
};
#include "CUSTOM_FUNCTIONS.hpp"
