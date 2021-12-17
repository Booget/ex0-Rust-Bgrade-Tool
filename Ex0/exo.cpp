#include "includes.h"


void exo::exoThread()
{
    while (!GetAsyncKeyState(PANIC_KEY))
    {

        if (globals.enableBgrade)
        {
            if (globals.selectedUpgradeType == 0) 
            {
                globals.x_wood = 50;
                globals.y_wood = -100;

                globals.x_stone = 100;
                globals.y_stone = 0;

                globals.x_metal = -10;
                globals.y_metal = 100;

                globals.x_hqm = -200;
                globals.y_hqm = 0;
            }
            else if (globals.selectedUpgradeType == 1)
            {
                globals.upgradeDelay = 0;
                globals.upgradeSpeed = 0;
            }

            if (GetAsyncKeyState(VK_RBUTTON) & 1)
            {

                switch (globals.selectedBgradeMaterial)
                {
                case 0: // Wood
                    Sleep(globals.upgradeDelay);
                    functions::move_mouse(globals.upgradeSpeed, functions::convert(globals.user_sens, globals.user_fov, globals.x_wood), functions::convert(globals.user_sens, globals.user_fov, globals.y_wood));
                    functions::sendKeyPress();
                    break;
                case 1: // Stone
                    Sleep(globals.upgradeDelay);
                    functions::move_mouse(globals.upgradeSpeed, functions::convert(globals.user_sens, globals.user_fov, globals.x_stone), functions::convert(globals.user_sens, globals.user_fov, globals.y_stone));
                    functions::sendKeyPress();
                    break;
                case 2: // Metal
                    Sleep(globals.upgradeDelay);
                    functions::move_mouse(globals.upgradeSpeed, functions::convert(globals.user_sens, globals.user_fov, globals.x_metal), functions::convert(globals.user_sens, globals.user_fov, globals.y_metal));
                    functions::sendKeyPress();
                    break;
                case 3: // HQM
                    Sleep(globals.upgradeDelay);
                    functions::move_mouse(globals.upgradeSpeed, functions::convert(globals.user_sens, globals.user_fov, globals.x_hqm), functions::convert(globals.user_sens, globals.user_fov, globals.y_hqm));
                    functions::sendKeyPress();
                    break;
                }
            }
        }
    }
}