IncludeDir = {}
IncludeDir["cereal"] =		"%{wks.location}/../renaissance/Renaissance/externals/cereal/include"
IncludeDir["entt"] =		"%{wks.location}/../renaissance/Renaissance/externals/entt/include"
IncludeDir["Glad"] =		"%{wks.location}/../renaissance/Renaissance/externals/Glad/include"
IncludeDir["GLFW"] =		"%{wks.location}/../renaissance/Renaissance/externals/GLFW/include"
IncludeDir["glm"] =			"%{wks.location}/../renaissance/Renaissance/externals/glm"
IncludeDir["IconFonts"] =	"%{wks.location}/../renaissance/Renaissance/externals/IconFontCppHeaders"
IncludeDir["ImGui"] =		"%{wks.location}/../renaissance/Renaissance/externals/ImGui/"
IncludeDir["ImGuizmo"] =	"%{wks.location}/../renaissance/RenaissanceEditor/externals/ImGuizmo"
IncludeDir["spdlog"] =		"%{wks.location}/../renaissance/Renaissance/externals/spdlog/include"
IncludeDir["stb_image"] =	"%{wks.location}/../renaissance/Renaissance/externals/stb_image"
IncludeDir["yamlcpp"] =		"%{wks.location}/../renaissance/Renaissance/externals/yaml-cpp/include"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

workspace "Pantry"
	architecture "x64"
	startproject "Pantry"

	configurations
	{
		"Debug",
		"Release",
		"Shipping"
	}

	flags
	{
		"MultiProcessorCompile"
	}

	group("Application")
		include "Pantry"

	group("Engine")
		include "../renaissance/Renaissance"

	group("Externals")
		include "../renaissance/Renaissance/externals/GLFW"
		include "../renaissance/Renaissance/externals/Glad"
		include "../renaissance/Renaissance/externals/ImGui"
		include "../renaissance/Renaissance/externals/yaml-cpp"
		include "../renaissance/Renaissance/externals/cereal"