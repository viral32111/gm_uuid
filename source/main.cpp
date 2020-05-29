/*
UUID - Generate UUID strings in Garry's Mod
Copyright (C) 2020 viral32111

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program. If not, see https://www.gnu.org/licenses.
*/

// Standard headers
#include <algorithm>
#include <string>

// Boost headers
#include <boost/lexical_cast.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

// Garry's Mod headers
#include <GarrysMod/Lua/Interface.h>

// Global random UUID generator
boost::uuids::random_generator randomUUIDGenerator;

// Generate function
LUA_FUNCTION( GenerateUUID ) {
	// Include dashes by default
	bool includeDashes = true;
	
	// Check for the include dashes argument
	if ( LUA->IsType( 1, GarrysMod::Lua::Type::BOOL ) == true ) {
		// Set include dashes to what the user provides
		includeDashes = LUA->GetBool( 1 );
	}

	// Try-catch statement for catching any exceptions from Boost
	try {
		// Create the UUID string
		std::string uuid = boost::lexical_cast<std::string>( randomUUIDGenerator() );

		// Remove dashes if specified
		if ( includeDashes == false ) {
			uuid.erase( std::remove( uuid.begin(), uuid.end(), '-' ), uuid.end() );
		}

		// Return the UUID as a char string
		LUA->PushString( uuid.c_str() );
	} catch ( const std::exception & ex ) {
		// Throw a Lua error containing the error message
		LUA->ThrowError( ex.what() );

		// Return nil
		LUA->PushNil();
	}

	// Return a single argument
	return 1;
}

// Runs when the module is required for the first time
GMOD_MODULE_OPEN() {
	// Set the random UUID generator global
	randomUUIDGenerator = boost::uuids::random_generator();

	// Push the generate function to the global table
	LUA->PushSpecial( GarrysMod::Lua::SPECIAL_GLOB );
		LUA->PushCFunction( GenerateUUID );
		LUA->SetField( -2, "GenerateUUID" );
	LUA->Pop();

	// Return a single argument
	return 1;
}

// Runs on environment shutdown
GMOD_MODULE_CLOSE() {
	// Return zero arguments
	return 0;
}