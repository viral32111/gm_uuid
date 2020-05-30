-- Store operating system string
local osName = os.target()

-- Store the absolute path to the repository root
local repoRoot = string.sub( os.getcwd(), 0, -9 ) -- Substring to remove "/scripts" from the end

-- Define the solution & project
workspace ( "UUID" )
	-- Set the file name
	filename ( "uuid" )

	-- Generated project files directory
	location ( "../project/" .. osName .. "/" )

	-- Configurations
	configurations {
		"Release"
	}

	project ( "UUID" )
		-- Set the file name
		filename ( "uuid" )

		-- Misc C++ stuff
		language ( "C++" )

		-- This is a shared library (.dll/.so)
		kind ( "SharedLib" )

		-- No debug settings
		symbols ( "Off" )
		optimize ( "Speed" )
		staticruntime ( "On" )

		-- x64 only
		architecture ( "x86_64" )

		-- Generated project files directory
		location ( "../project/" .. osName .. "/" )

		-- Build/output directory
		objdir ( "../build/" .. osName .. "/obj/" )
		targetdir ( "../build/" .. osName .. "/" )

		-- Output name & extension
		targetname ( "gm_uuid" )
		targetextension ( ".dll" )

		-- Additional include directories
		includedirs {
			"../include/"
		}

		-- Source files
		files {
			"../source/**.*"
		}
		
		-- Per-OS module suffix & extension
		if ( osName == "windows" ) then
			targetsuffix ( "_win64" )
		elseif ( osName == "linux" ) then
			targetprefix ( "" ) -- Linux defaults to lib prefix
			targetsuffix ( "_linux64" )
		end

		-- Commands to run after a successful build
		postbuildcommands {
			"{MKDIR} \"" .. repoRoot .. "/deploy\"", -- Create deploy directory
			"{MOVE} \"%{cfg.buildtarget.abspath}\" \"" .. repoRoot .. "/deploy/%{cfg.buildtarget.name}\"", -- Move DLL to deploy directory
		}