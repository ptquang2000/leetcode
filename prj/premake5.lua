workspace "leetcode"
	location "leetcode"
	configurations {"Debug"}
	startproject "array_string"

project "array_string"
	kind "ConsoleApp"
	language "C"
	targetdir "../release/%{cfg.buildcfg}"

	files 
	{ 
		"../src/array_string/**.h", 
		"../src/array_string/**.c"
	}

	includedirs 
	{
		"../libs/Unity/src/"
	}

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	links "Unity"

project "Unity"
	kind "StaticLib"
	language "C"
	targetdir "../release/%{cfg.buildcfg}"

	files 
	{ 
		"../libs/Unity/src/**.h", 
		"../libs/Unity/src/**.c" 
	}
