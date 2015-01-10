/**
 *  @file		StringExt.h
 *  @brief     	Generic free functions and function templates.
 *  @details   	Makes easy access and are name safe in their namespace
 *
 *  Call them this way:
 *  #include "Util.h"
 *  [... your code ...]
 *
 *  string yourStrOfAnumber = Util::toStr(yourIntValue);
 *  yourStrOfAnumber += " + " + Util::toStr(yourFloatValue);
 *
 *  @author    	E. Bergeron
 *  @date      	2013-01-15
 *  @pre		include Util.h, that's it!
 *  @copyright 	Prismal Studio 2008-2013 www.prismalstudio.com
 */

#ifndef STRINGEXT_H_
#define STRINGEXT_H_

#include <string>
#include <sstream>
#include <vector>
//#include <math.h>

/**
 * Utility functions
 */
namespace Util
{

std::vector<std::string> & split(const std::string & s, char delim,
		std::vector<std::string> & elems, bool skipEmptyToken = true);
std::vector<std::string> split(const std::string & s, char delim,
		bool skipEmptyToken = true);

std::string formatTime(long int total);

std::string lineWrap(std::string text, unsigned int lineLenght);

std::string toStr(bool boolValue);

std::string toLowercase(const std::string& str);


/**
 * toStr cast any number T to a string. Use that one for outputting numbers.
 * @param number anything in fact that can be outputed to a string
 * @return an std::string with the passed argument
 */
template<typename T>
std::string toStr(T number)
{
	std::stringstream ss; //create a stringstream
	ss << number; //add number to the stream
	return ss.str(); //return a string with the contents of the stream
}

/**
 * cast any string to a specify T number. Use that one for inputs.
 * @param Text that you whant to cast to a number
 * @return a T number or Zero if not castable
 */
template<typename T>
T strToNbr(const std::string &Text)
{
	std::istringstream ss(Text);
	T result;
	return ss >> result ? result : 0; // return zero if not castable
}

} // end of namespace
#endif /* STRINGEXT_H_ */
