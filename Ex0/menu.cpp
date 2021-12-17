#include "includes.h"

class initWindow {
public:
    bool active = true;

    const char* window_title = "ex0";
    ImVec2 window_size{ 330, 198 };

    DWORD window_flags = ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollWithMouse;
} iw;

static const char* upgradeType[]{ "Default upgrade", "Upgrade if avaible" };
static const char* materials[]{ "Wood", "Stone", "Metal", "HQM" };


bool do0nce = false;

void loadStyles()
{
    ImVec4* colors = ImGui::GetStyle().Colors;
    {
        colors[ImGuiCol_WindowBg] = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
        colors[ImGuiCol_Border] = ImVec4(0.00f, 0.00f, 0.00f, 0.50f);

        colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.10f, 0.10f, 0.54f);
        colors[ImGuiCol_FrameBgHovered] = ImVec4(0.10f, 0.10f, 0.10f, 0.54f);
        colors[ImGuiCol_FrameBgActive] = ImVec4(0.10f, 0.10f, 0.10f, 0.54f);

        colors[ImGuiCol_TitleBg] = ImVec4(0.02f, 0.02f, 0.02f, 1.00f);
        colors[ImGuiCol_TitleBgActive] = ImVec4(0.02f, 0.02f, 0.02f, 1.00f);
        colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.02f, 0.02f, 0.02f, 1.00f);

        colors[ImGuiCol_CheckMark] = ImVec4(1.00f, 0.41f, 0.41f, 1.00f);

        colors[ImGuiCol_SliderGrab] = ImVec4(1.00f, 0.41f, 0.41f, 1.00f);
        colors[ImGuiCol_SliderGrabActive] = ImVec4(1.00f, 0.41f, 0.41f, 1.00f);

        colors[ImGuiCol_Header] = ImVec4(1.00f, 0.41f, 0.41f, 1.00f);
        colors[ImGuiCol_HeaderHovered] = ImVec4(1.00f, 0.41f, 0.41f, 1.00f);
        colors[ImGuiCol_HeaderActive] = ImVec4(1.00f, 0.41f, 0.41f, 1.00f);

        colors[ImGuiCol_NavHighlight] = ImVec4(1.00f, 0.41f, 0.41f, 1.00f);

        colors[ImGuiCol_Button] = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
        colors[ImGuiCol_ButtonHovered] = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
        colors[ImGuiCol_ButtonActive] = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
    }

    ImGuiStyle* style = &ImGui::GetStyle();
    {
        style->WindowBorderSize = 1.0f;
        style->ChildBorderSize = 1.0f;

        style->FramePadding = ImVec2(4, 0);

        style->WindowTitleAlign = ImVec2(.5, .5);
    }
}

void menu::render()
{
    if (do0nce == false)
    {
        loadStyles();
        do0nce == false;
    }

    if (iw.active)
    {
        ImGui::SetNextWindowSize(iw.window_size);
        ImGui::SetNextWindowBgAlpha(1.0f);
        ImGui::Begin(iw.window_title, &iw.active, iw.window_flags);
        {
            ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.05f, 0.05f, 0.05f, 1.00f));
            ImGui::BeginChild("##container", ImVec2(315, 170), true);
            {
                ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.05f, 0.05f, 0.05f, 1.00f));
                ImGui::BeginChild("##configSec", ImVec2(300, 47), true);
                {
                    ImGui::SliderFloat(xorstr("Sensitivity"), &globals.user_sens, 0, 1);
                    ImGui::SliderInt(xorstr("FOV"), &globals.user_fov, 65, 90);
                }
                ImGui::PopStyleColor();
                ImGui::EndChild();

                ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.05f, 0.05f, 0.05f, 1.00f));
                ImGui::BeginChild("##bgradeSec", ImVec2(300, 100), true);
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
                ImGui::PopStyleColor();
                ImGui::EndChild();
            }
            ImGui::PopStyleColor();
            ImGui::EndChild();
        }
        ImGui::End();
    }
    else
    {
        exit(3);
    }
}