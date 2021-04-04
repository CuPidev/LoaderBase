#include "menu.h"
#include "settings.h"
#include "functions.h"

void Menu::Render()
{
	auto Width = ImGui::GetWindowWidth();
	auto Height = ImGui::GetWindowHeight();
	auto RegionW = ImGui::GetContentRegionAvailWidth();

	Functions::LineEx("##MainBar");

	ImGui::BeginChild("##LeftSide", ImVec2(Width / 2.5, Height - 60), true);

	ImGui::SetCursorPosX((ImGui::GetContentRegionAvailWidth() / 2.2));
	ImGui::Text("xo1337");
	ImGui::Separator();

	ImGui::PushStyleColor(ImGuiCol_Button, IM_COL32(30, 30, 30, 255));
	ImGui::SetCursorPosY(ImGui::GetWindowHeight() - 270);
	ImGui::SetCursorPosX((ImGui::GetContentRegionAvailWidth() / 2.6));
	if (ImGui::Button("Home", ImVec2(110, 30))) { Settings::Tab = 1; }
	ImGui::SetCursorPosX((ImGui::GetContentRegionAvailWidth() / 2.6));
	if (ImGui::Button("Settings", ImVec2(110, 30))) { Settings::Tab = 0; }
	ImGui::PopStyleColor();

	ImGui::EndChild();

	ImGui::SameLine();
	Functions::LineVertical();
	ImGui::SameLine();

	ImGui::BeginChild("##RightSide", ImVec2(ImGui::GetContentRegionAvailWidth(), Height - 60), true);
	ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(24, 24, 24, 255));
	if (ImGui::BeginChild("##PanelParent", ImVec2(ImGui::GetContentRegionAvailWidth(), Height - 80))) {
		if (Settings::Tab == 1) {
			ImGui::PushItemWidth(ImGui::GetContentRegionAvailWidth());
			ImGui::ListBox("##GamesBox", &Settings::SelectedGame, Settings::Games.data(), Settings::Games.size());
			ImGui::PopItemWidth();
		}
		else
		{
			ImGui::BeginChild("##SettingsTab", ImVec2(ImGui::GetContentRegionAvailWidth(), Height - 80));
			
			ImGui::SetCursorPosX(ImGui::GetContentRegionAvailWidth() / 2.9);
			ImGui::Text("Auto Injection");
			ImGui::SameLine(); 
			Functions::Helpmarker("Auto Injection will auto matically inject into the selected game.", 
				ImColor(255, 0, 0, 255));

			ImGui::Separator();
			ImGui::PushStyleColor(ImGuiCol_FrameBg, IM_COL32(34, 34, 34, 255));
			ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, IM_COL32(34, 34, 34, 255));
			ImGui::Checkbox("##AutoInjection", &Settings::AutoInject);
			ImGui::PopStyleColor(2);
			ImGui::SameLine();
			ImGui::Text("Enabled");
			ImGui::Separator();
			ImGui::EndChild();
		}
		ImGui::EndChild();
	}
	ImGui::PopStyleColor();
	ImGui::EndChild();

	ImGui::PushStyleColor(ImGuiCol_Button, IM_COL32(30, 30, 30, 255));
	if (ImGui::Button("Load", ImVec2(ImGui::GetContentRegionAvailWidth(), 32))) {
		Functions::Inject("");
	}
	ImGui::PopStyleColor();
	
}

void Menu::Theme()
{
	ImGuiStyle& Style = ImGui::GetStyle();
	auto Color = Style.Colors;
	
	Style.WindowMinSize     = ImVec2(700, 450);
	Style.WindowBorderSize  = 0;

	Style.ChildRounding     = 0;
	Style.FrameRounding     = 0;
	Style.ScrollbarRounding = 0;
	Style.GrabRounding		= 0;
	Style.PopupRounding		= 0;
	Style.WindowRounding	= 0;


	Color[ImGuiCol_WindowBg]            = ImColor(18, 18, 18, 255);
	
	Color[ImGuiCol_FrameBg]		        = ImColor(24, 24, 24, 255);
	Color[ImGuiCol_FrameBgActive]       = ImColor(24, 24, 24, 255);
	Color[ImGuiCol_FrameBgHovered]      = ImColor(24, 24, 24, 255);

	Color[ImGuiCol_Button]	            = ImColor(29, 29, 29, 255);
	Color[ImGuiCol_ButtonActive]        = ImColor(32, 32, 32, 255);
	Color[ImGuiCol_ButtonHovered]       = ImColor(36, 36, 36, 255);

	Color[ImGuiCol_Border]              = ImColor(0, 0, 0, 0);
	Color[ImGuiCol_Separator]           = ImColor(36, 36, 36, 255);

	Color[ImGuiCol_ResizeGrip]		    = ImColor(30, 30, 30, 255);
	Color[ImGuiCol_ResizeGripActive]    = ImColor(30, 30, 30, 255);
	Color[ImGuiCol_ResizeGripHovered]   = ImColor(30, 30, 30, 255);

	Color[ImGuiCol_ChildBg]			    = ImColor(26, 26, 26, 255);

	Color[ImGuiCol_ScrollbarBg]         = ImColor(24, 24, 24, 255);
	Color[ImGuiCol_ScrollbarGrab]       = ImColor(24, 24, 24, 255);
	Color[ImGuiCol_ScrollbarGrabActive] = ImColor(24, 24, 24, 255);
	Color[ImGuiCol_ScrollbarGrabActive] = ImColor(24, 24, 24, 255);

	Color[ImGuiCol_Header]			    = ImColor(39, 39, 39, 255);
	Color[ImGuiCol_HeaderActive]	    = ImColor(39, 39, 39, 255);
	Color[ImGuiCol_HeaderHovered]       = ImColor(39, 39, 39, 255);
	Color[ImGuiCol_CheckMark]		    = ImColor(255, 255, 255, 255);
}