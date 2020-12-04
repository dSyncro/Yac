workspace "Yac"

	architecture "x86_64"
	startproject "Yac"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
    }
	
	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.architecture}/%{cfg.system}/%{cfg.buildcfg}"

project "Yac"

	location "Projects/Yac"

	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin/intermediates/" .. outputdir .. "/%{prj.name}")

	files
	{
		"Projects/%{prj.name}/**.h",
		"Projects/%{prj.name}/**.cpp"
	}

	includedirs
	{
		"Projects/%{prj.name}",
	}

	filter "system:windows"
		systemversion "latest"

	filter "system:linux"
		systemversion "latest"
		
	filter "configurations:Debug"
		defines "YAC_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "YAC_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "YAC_DIST"
		runtime "Release"
        optimize "on"