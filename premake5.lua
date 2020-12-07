include "./third-party/Premaker/customization/solution_items.lua"

workspace "Yac"

	startproject "Yac"

	include "./third-party/Premaker/configurations.lua"
	
	flags
	{
		"MultiProcessorCompile"
	}

	outputdir = "%{cfg.architecture}/%{cfg.system}/%{cfg.buildcfg}"

include "third-party/Premaker"

group "Dependencies"
	include "third-party/Console/project"

group ""
	include "Projects/Yac"