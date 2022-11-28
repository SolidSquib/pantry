#include "PantryPCH.h"

#include "Pantry/PantryLayer.h"
#include "Renaissance/Core/FileSystem.h"

#include <imgui.h>

namespace Pantry
{

	void PantryLayer::OnAttached()
	{
		Renaissance::FileSystem::GetAppContentDirectory();
		Renaissance::FileSystem::GetEngineContentDirectory();

		std::ifstream input("config/pantry-layout.json");
		if (input.fail())
		{
			CreateDefaultWindowLayout();
		}
		else
		{
			std::vector<std::string> windows;
			{
				cereal::JSONInputArchive archive(input);
				archive(windows);
			}

			uint32_t numViewports = 0;
			uint32_t numContentBrowsers = 0;
			for (auto& windowData : windows)
			{
// 				if (windowData == EditorToolbarWindow::GetWindowClassNameStatic() && GetWindowCount<EditorToolbarWindow>() == 0)
// 				{
// 					CreateNewWindow<EditorToolbarWindow>();
// 				}
// 				else if...
			}
		}
	}

	void PantryLayer::OnDetached()
	{
		
	}

	void PantryLayer::OnUpdate(float deltaTime)
	{
		
	}

	void PantryLayer::OnUIRender()
	{
		static bool showEditor = true;
		static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

		// We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
		// because it would be confusing to have two docking targets within each others.
		ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
		ImGuiViewport* viewport = ImGui::GetMainViewport();
		ImGui::SetNextWindowPos(viewport->WorkPos);
		ImGui::SetNextWindowSize(viewport->WorkSize);
		ImGui::SetNextWindowViewport(viewport->ID);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
		window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
		window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;

		// When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background
		// and handle the pass-thru hole, so we ask Begin() to not render a background.
		if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
			window_flags |= ImGuiWindowFlags_NoBackground;

		// Important: note that we proceed even if Begin() returns false (aka window is collapsed).
		// This is because we want to keep our DockSpace() active. If a DockSpace() is inactive,
		// all active windows docked into it will lose their parent and become undocked.
		// We cannot preserve the docking relationship between an active window and an inactive docking, otherwise
		// any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.

		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
		ImGui::Begin("Renaissance Editor", &showEditor, window_flags);
		ImGui::PopStyleVar();

		ImGui::PopStyleVar(2);

		// DockSpace
		ImGuiIO& io = ImGui::GetIO();
		if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
		{
			ImGuiID dockspace_id = ImGui::GetID("EditorDockspace");
			ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
		}
		else
		{
			REN_CORE_WARN("Dear ImGui docking disabled.");
		}

		ImGui::BeginMenuBar();
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("New"))
			{
				
			}

			if (ImGui::MenuItem("Open...", "Ctrl+O"))
			{
				
			}

			if (ImGui::MenuItem("Save As...", "Ctrl+Shift+S"))
			{
				
			}

			ImGui::Separator();
			if (ImGui::MenuItem("Exit", nullptr, false, true))
			{
				Renaissance::Application::Get().Close();
			}
			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu("Windows"))
		{

#if REN_DEBUG
			ImGui::Separator();
			if (ImGui::MenuItem("ImGui Demo Window", nullptr, false, !mShowDemoWindow))
			{
				mShowDemoWindow = true;
			}
#endif


			ImGui::EndMenu();
		}
		ImGui::EndMenuBar();

		ImGui::End();

#if REN_DEBUG
		if (mShowDemoWindow)
			ImGui::ShowDemoWindow(&mShowDemoWindow);
#endif

		for (auto it = mPanels.begin(); it != mPanels.end(); ++it)
		{
			(*it)->OnUIRender();
		}
	}

	void PantryLayer::OnEvent(Renaissance::Events::Event& e)
	{
		
	}

	void PantryLayer::CreateDefaultWindowLayout()
	{
	}

}