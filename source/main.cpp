#include <string>
using namespace std;

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
using namespace boost::uuids;

#include <boost/lexical_cast.hpp>
using namespace boost;

#include "GarrysMod/Lua/Interface.h"
using namespace GarrysMod::Lua;

random_generator randomUUIDGenerator;

LUA_FUNCTION(generate){
	try {
		bool includeDashes = true;
		if (LUA->IsType(1, Type::BOOL))includeDashes = LUA->GetBool(1);

		string uuid = lexical_cast<string>(randomUUIDGenerator());
		if (includeDashes == false)std::replace(uuid.begin(), uuid.end(), '-', '\0');

		LUA->PushString(uuid.c_str());
	} catch (const std::exception & ex) {
		LUA->ThrowError(ex.what());
		LUA->PushNil();
	}

	return 1;
}

GMOD_MODULE_OPEN(){
	randomUUIDGenerator=random_generator();

	LUA->PushSpecial(SPECIAL_GLOB);
		LUA->CreateTable();
			LUA->PushCFunction(generate);
			LUA->SetField(-2,"generate");
		LUA->SetField(-2,"uuid");
	LUA->Pop();

	return 1;
}

GMOD_MODULE_CLOSE(){
	return 0;
}