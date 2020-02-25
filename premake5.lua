workspace "Yac"
	architecture "x86_64"
	startproject "Yac"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
    }
    
    platforms 
    {
        "Win32",
        "Win64",
        "Linux32",
        "Linux64",
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

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin/intermediates/" .. outputdir .. "/%{prj.name}")

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
        
	filter "platforms:Win32"
		system "windows"
        defines "Win32"
        architecture "x32"

	filter "platforms:Win64"
		system "windows"
        defines "Win64"
        architecture "x64"

	filter "platforms:Linux32"
		system "linux"
        defines "Linux32"
        architecture "x32"

	filter "platforms:Linux64"
		system "linux"
        defines "Linux64"
        architecture "x64"