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