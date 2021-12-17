#pragma once

class globals
{
public:
	// Menu vars
	int bgradeBind = 1;


	// Config vars
	float user_sens = 1;
	int user_fov = 90;

	// Bgrade Vars
	bool enableBgrade = false;
	int selectedBgradeMaterial = 0;
	int selectedUpgradeType = 0;
	int upgradeSpeed = 50;
	int upgradeDelay = 0;
	int x_wood;
	int y_wood;
	int x_stone;
	int y_stone;
	int x_metal;
	int y_metal;
	int x_hqm;
	int y_hqm;

} globals;