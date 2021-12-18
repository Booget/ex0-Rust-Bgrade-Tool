#include "includes.h"

ImVec4 secondChildBorder = ImColor(55, 53, 49, 255);
ImVec4 secondChildColor = ImColor(17, 17, 17, 255);


ImVec4 thirdChildBorder = ImColor(55, 53, 49, 255);
ImVec4 thirdChildColor = ImColor(12, 12, 12, 255);

ImVec4 forthChildBorder = ImColor(45, 45, 45, 255);
ImVec4 forthChildColor = ImColor(10, 10, 10, 255);

ImVec4 secChildBorder = ImColor(55, 55, 55, 255);
ImVec4 secChildColor = ImColor(12, 12, 12, 255);

static const char* upgradeType[]{ "Default upgrade", "Upgrade if avaible" };
static const char* materials[]{ "Wood", "Stone", "Metal", "HQM" };

class initWindow {
public:
    const char* window_title = "exo";
    ImVec2 window_size{ 400, 450 };

    DWORD window_flags = ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollWithMouse;
} iw;


void loadStyles()
{
    ImVec4* colors = ImGui::GetStyle().Colors;
    {
        colors[ImGuiCol_WindowBg] = ImColor(28, 28, 28, 255);
        colors[ImGuiCol_Border] = ImColor(0, 0, 0, 255);

        colors[ImGuiCol_Button] = thirdChildColor;
        colors[ImGuiCol_ButtonHovered] = thirdChildColor;
        colors[ImGuiCol_ButtonActive] = thirdChildColor;

        colors[ImGuiCol_FrameBg] = ImVec4(0.21f, 0.21f, 0.21f, 0.54f);
        colors[ImGuiCol_FrameBgHovered] = ImVec4(0.21f, 0.21f, 0.21f, 0.54f);
        colors[ImGuiCol_FrameBgActive] = ImVec4(0.21f, 0.21f, 0.21f, 0.54f);
    }

    ImGuiStyle* style = &ImGui::GetStyle();
    {
        style->WindowPadding = ImVec2(4, 4);
    }
}

static bool doOnce = true;

void menu::render()
{
    // Only initialise once
    if (doOnce) {
        loadStyles();
    }

    // Colors to be in a loop for the color pickers
    ImVec4* colors = ImGui::GetStyle().Colors;
    {
        colors[ImGuiCol_CheckMark] = globals.generalColor;

        colors[ImGuiCol_SliderGrab] = globals.generalColor;
        colors[ImGuiCol_SeparatorHovered] = globals.generalColor;
        colors[ImGuiCol_SliderGrabActive] = globals.generalColor;
        colors[ImGuiCol_Header] = globals.generalColor;
        colors[ImGuiCol_HeaderHovered] = globals.generalColor;
        colors[ImGuiCol_HeaderActive] = globals.generalColor;

        globals.activeBtn = globals.generalColor;
    }

    if (globals.active)
    {
        ImGui::SetNextWindowSize(iw.window_size);
        ImGui::SetNextWindowBgAlpha(1.0f);
        ImGui::Begin(iw.window_title, &globals.active, iw.window_flags);
        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(6, 0));
        {
            if (globals.enableRainbowBar)
            {
                static float staticHue = 0;
                ImDrawList* draw_list = ImGui::GetWindowDrawList();
                ImVec2 panelPos = ImGui::GetWindowPos();
                staticHue -= globals.rainbowSpeed;
                if (staticHue < -1.f) staticHue += 1.f;
                for (int i = 0; i < globals.rainbowBlend; i++)
                {
                    float hue = staticHue + (1.f / (float)globals.rainbowBlend) * i;
                    if (hue < 0.f) hue += 1.f;
                    ImColor cRainbow = ImColor::HSV(hue, 1.f, 1.f);
                    draw_list->AddRectFilled(ImVec2(panelPos.x + i, panelPos.y), ImVec2(panelPos.x + i + 1, panelPos.y + 2), cRainbow);
                }
            }

            ImGui::PushStyleColor(ImGuiCol_Border, secondChildBorder);
            ImGui::PushStyleColor(ImGuiCol_ChildBg, secondChildColor);
            ImGui::BeginChild("##secondChild", ImVec2(ImGui::GetWindowWidth() - 9, ImGui::GetWindowHeight() - 9), true);
            {
                ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(10, 10));
                {
                    ImGui::PushStyleColor(ImGuiCol_Border, thirdChildBorder);
                    ImGui::PushStyleColor(ImGuiCol_ChildBg, thirdChildColor);
                    ImGui::BeginChild("##thirdChild", ImVec2(383, 433), true, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
                    {

                        ImGui::PushStyleColor(ImGuiCol_Text, globals.selectedTab == 1 ? globals.activeBtn : globals.inactiveBtn);
                        if (ImGui::Button("tools", ImVec2(175, 17)))
                        {
                            globals.selectedTab = 1;
                        }
                        ImGui::PopStyleColor();

                        ImGui::SameLine();

                        ImGui::PushStyleColor(ImGuiCol_Text, globals.selectedTab == 2 ? globals.activeBtn : globals.inactiveBtn);
                        if (ImGui::Button("settings", ImVec2(175, 17)))
                        {
                            globals.selectedTab = 2;
                        }
                        ImGui::PopStyleColor();

                        ImGui::PushStyleColor(ImGuiCol_Border, forthChildBorder);
                        ImGui::PushStyleColor(ImGuiCol_ChildBg, forthChildColor);
                        ImGui::BeginChild("##forthChild", ImVec2(363, 383), true);
                        {
                            switch (globals.selectedTab)
                            {
                            case 1:
                                ImGui::PushStyleColor(ImGuiCol_Border, secChildBorder);
                                ImGui::PushStyleColor(ImGuiCol_ChildBg, secChildColor);
                                ImGui::BeginChild("##bgrade", ImVec2(240, 90), true);
                                {
                                    ImGui::Checkbox(xorstr("Enable BGrade"), &globals.enableBgrade);
                                    ImGui::Combo(xorstr("Upgrade Type"), &globals.selectedUpgradeType, upgradeType, IM_ARRAYSIZE(upgradeType));
                                    if (globals.selectedUpgradeType == 0)
                                    {
                                        ImGui::Combo(xorstr("Meterial"), &globals.selectedBgradeMaterial, materials, IM_ARRAYSIZE(materials));
                                        ImGui::SliderInt(xorstr("Upgrade Speed"), &globals.upgradeSpeed, 30, 100, "%.06fms");
                                        ImGui::SliderInt(xorstr("Upgrade Delay"), &globals.upgradeDelay, 0, 500, "%.06fms");
                                    }
                                }
                                ImGui::EndChild();
                                ImGui::PopStyleColor(2);

                                ImGui::PushStyleColor(ImGuiCol_Border, secChildBorder);
                                ImGui::PushStyleColor(ImGuiCol_ChildBg, secChildColor);
                                ImGui::BeginChild("##codeEnter", ImVec2(290, 60), true);
                                {
                                    ImGui::Checkbox(xorstr("Enable Code Enterer [INSERT TO ENTER CODE]"), &globals.enableCodeEnterer);
                                    ImGui::Text("Your Code:");
                                    ImGui::PushItemWidth(18.f);
                                    {
                                        ImGui::SameLine();
                                        ImGui::InputInt(xorstr("##First"), &globals.codeNum1, 0, 9);
                                        ImGui::SameLine();
                                        ImGui::InputInt(xorstr("##Seconed"), &globals.codeNum2, 0, 9);
                                        ImGui::SameLine();
                                        ImGui::InputInt(xorstr("##Third"), &globals.codeNum3, 0, 9);
                                        ImGui::SameLine();
                                        ImGui::InputInt(xorstr("##Forth"), &globals.codeNum4, 0, 9);
                                    }
                                    ImGui::PopItemWidth();
                                    ImGui::SliderInt("Delay", &globals.delayBetweenKeypress, 5, 1000, "%.06fms");
                                }
                                ImGui::EndChild();
                                ImGui::PopStyleColor(2);
                                break;
                            case 2:
                                ImGui::PushStyleColor(ImGuiCol_Border, secChildBorder);
                                ImGui::PushStyleColor(ImGuiCol_ChildBg, secChildColor);
                                ImGui::BeginChild("##rgbSettings", ImVec2(195, 60), true);
                                {
                                    ImGui::Checkbox("Enable RGB bar", &globals.enableRainbowBar);
                                    ImGui::SliderFloat("RGB Speed", &globals.rainbowSpeed, 0.001, 0.010, NULL, ImGuiSliderFlags_NoInput);
                                    ImGui::SliderInt("RGB Fade", &globals.rainbowBlend, 400, 1600, NULL, ImGuiSliderFlags_NoInput);
                                }
                                ImGui::EndChild();
                                ImGui::PopStyleColor(2);

                                ImGui::SameLine();

                                ImGui::PushStyleColor(ImGuiCol_Border, secChildBorder);
                                ImGui::PushStyleColor(ImGuiCol_ChildBg, secChildColor);
                                ImGui::BeginChild("##colorSettings", ImVec2(135, 30), true);
                                {
                                    ImGui::ColorEdit3("Ascent", (float*)&globals.generalColor, ImGuiColorEditFlags_NoInputs);
                                }
                                ImGui::EndChild();
                                ImGui::PopStyleColor(2);

                                ImGui::PushStyleColor(ImGuiCol_Border, secChildBorder);
                                ImGui::PushStyleColor(ImGuiCol_ChildBg, secChildColor);
                                ImGui::BeginChild("##userSettings", ImVec2(195, 44), true);
                                {
                                    ImGui::SliderFloat(xorstr("Sensitivity"), &globals.user_sens, 0, 1);
                                    ImGui::SliderInt(xorstr("FOV"), &globals.user_fov, 65, 90);
                                }
                                ImGui::EndChild();
                                ImGui::PopStyleColor(2);
                                break;
                            }
                        }
                        ImGui::EndChild();
                        ImGui::PopStyleColor(2);
                        ImGui::TextDisabled("ex0 rust v1.0.0");
                    }
                    ImGui::EndChild();
                    ImGui::PopStyleColor(2);
                }
                ImGui::PopStyleVar();
            }
            ImGui::EndChild();
            ImGui::PopStyleColor(2);
        }
        ImGui::PopStyleVar();
        ImGui::End();
    }
    else
    {
        exit(0);
    }
}
