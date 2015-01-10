/*
 * LUALoader.cpp
 *
 *  Created on: 2013-10-28
 *      Author: Bidou
 */

#include "LuaResource.h"
#include <iostream>

namespace Util
{

LuaResource::LuaResource()
{
	mFile = luaL_newstate();
}

LuaResource::~LuaResource()
{
	close();
}

bool LuaResource::load(const std::string& filename)
{
	lua_gc(mFile, LUA_GCSTOP, 0);
	luaL_openlibs(mFile);
	lua_gc(mFile, LUA_GCRESTART, 0);

	// execute config file
	int ret = luaL_dofile(mFile, filename.c_str());
	if (ret != 0)
	{
		const char * msg = lua_tostring(mFile, -1);
		if (msg)
		{
			std::cerr << "Error: " << msg << std::endl;
		}
		else
		{
			std::cerr << "Error: (error object is not a string)\n";
		}
	}

	return true;
}

int LuaResource::getIntValue(const std::string& valueName)
{
	int value = 0;

	lua_getglobal(mFile, valueName.c_str());
	value = lua_tointeger(mFile, -1);

	return value;
}

std::string LuaResource::getStringValue(const std::string& valueName)
{
	std::string value = "";

	lua_getglobal(mFile, valueName.c_str());
	value = lua_tostring(mFile, -1);

	return value;
}

void LuaResource::close(void)
{
	lua_close(mFile);
}

} /* namespace grg */
