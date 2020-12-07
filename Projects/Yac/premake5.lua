project "Yac"

	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin/intermediates/" .. outputdir .. "/%{prj.name}")

	files
	{
		"**.h",
		"**.cpp"
	}

	includedirs
	{
		"./",
		"%{wks.location}/third-party/Console/project",
	}

	filter "system:windows"
		systemversion "latest"

	filter "system:linux"
		systemversion "latest"