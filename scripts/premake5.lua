-- Store operating system string
local os = os.target()

-- Define the solution & project
workspace ( "UUID" )
	-- Set the file name
	filename ( "uuid" )

	-- Generated project files directory
	location ( "../project/" .. os .. "/" )

	-- Configurations
	configurations {
		"Release"
	}

	project ( "UUID" )
		-- Set the file name
		filename ( "uuid" )

		-- Misc C++ stuff
		language ( "C++" )
		kind ( "SharedLib" )
		staticruntime ( "On" )
		symbols ( "On" )
		optimize ( "Speed" )
		architecture ( "x86_64" )

		-- Generated project files directory
		location ( "../project/" .. os .. "/" )

		-- Build/output directory
		objdir ( "../build/" .. os .. "/obj/" )
		targetdir ( "../build/" .. os .. "/" )

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
		if ( os == "windows" ) then
			targetsuffix ( "_win64" )
		elseif ( os == "linux" ) then
			targetprefix ( "" ) -- Linux defaults to lib prefix
			targetsuffix ( "_linux64" )
		end