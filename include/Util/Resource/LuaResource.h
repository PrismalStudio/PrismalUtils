/*
 * LUALoader.h
 *
 *  Created on: 2013-10-28
 *      Author: Bidou
 */

#ifndef LUA_RESOURCE_H_
#define LUA_RESOURCE_H_

#include "Resource.h"

extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include <string>


namespace Util
{
class LuaResource: public Resource
{
	public:
		LuaResource();
		virtual ~LuaResource();

		virtual bool load(const std::string& filename);
		void close(void);

		//value getters
		int getIntValue(const std::string& valueName);
		std::string getStringValue(const std::string& valueName);

	private:
		lua_State* mFile;
};

} /* namespace Util */
#endif /* LUA_RESOURCE_H_ */
