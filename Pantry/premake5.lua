project "Pantry"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"
	
	sourcedir = "src"
	pchheader "PantryPCH.h"
	pchsource(sourcedir.."/PantryPCH.cpp")
	
	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/intermediates/" .. outputdir .. "/%{prj.name}")
	
	files 
	{
		"include/**.h",
		"src/**.cpp"
	}
	
	includedirs
	{
		"include",
		"%{wks.location}/../renaissance/Renaissance/include",
		"%{IncludeDir.cereal}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.IconFonts}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.spdlog}"
	}
	
	links
	{
		"Renaissance"
	}

	defines
	{
		"YAML_CPP_STATIC_DEFINE"
	}
	
	filter "files:%{wks.location}/../renaissance/Renaissance/externals/spdlog/include/**.h"
		warnings "Off"

	filter "system:windows"
		systemversion "latest"
	
	filter "configurations:Debug"
		defines "REN_DEBUG"
		symbols "on"
	
	filter "configurations:Release"
		defines "REN_RELEASE"
		optimize "on"
	
	filter "configurations:Shipping"
		defines "REN_SHIPPING"
		optimize "on"