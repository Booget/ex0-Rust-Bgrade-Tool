#pragma once

class globals
{
public:
	// Menu vars
	bool active = true;
	int selectedTab = 1;
	bool enableRainbowBar = true;
	float rainbowSpeed = 0.001;
	int rainbowBlend = 800;
	ImVec4 generalColor = ImColor(255, 48, 48, 255);
	ImVec4 inactiveBtn = ImColor(255, 255, 255);
	ImVec4 activeBtn;


	// Config vars
	float user_sens = 1;
	int user_fov = 90;

	// Bgrade vars
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

	// Code enterer vars
	bool enableCodeEnterer = false;
	int selectedCodeEnterType = 0;
	int codeNum1 = 1;
	int codeNum2 = 2;
	int codeNum3 = 3;
	int codeNum4 = 4;
	int delayBetweenKeypress = 5;


} globals;