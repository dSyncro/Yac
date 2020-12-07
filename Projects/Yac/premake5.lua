project "Yac"

	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin/intermediates/" .. outputdir .. "/%{prj.name}")

	YacIncludeDirs = {}
	YacIncludeDirs["Yac"] = "%{prj.location}"

	ConsolePath = "%{wks.location}/third-party/Console/"
	YacIncludeDirs["Console"] = ConsolePath .. "project"
	YacIncludeDirs["AnsiStyle"] = ConsolePath .. "third-party/AnsiStyle/project"
	YacIncludeDirs["Detective"] = ConsolePath .. "third-party/Detective/project"

	files
	{
		"**.h",
		"**.cpp"
	}

	includedirs
	{
		YacIncludeDirs
	}

	links 
	{
		"AnsiStyle",
		"Console",
	}