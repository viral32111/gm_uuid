workspace "gm_uuid"
	configurations {"Release"}
	location ("project")

project "gm_uuid"
	kind "SharedLib"
	architecture "x86"
	language "C++"
	includedirs "include"
	targetdir "build"
	symbols "On"

	if (os.is("windows")) then targetsuffix "_win32" end
	if (os.is("macosx")) then targetsuffix "_osx" end
	if (os.is("linux")) then targetsuffix "_linux" end

	configuration "Release"
		optimize "Speed"
		flags "StaticRuntime"

	files {
		"source/**.*",
		"include/**.*",
	}