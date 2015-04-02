/**
 *  @file		StringExt.cpp
 *  @brief     	Generic free functions and function templates.
 *  @details   	Makes easy access and are name safe in their namespace
 *
 *  Call them this way:
 *  #include "Util.h"
 *  [... your code ...]
 *
 *  string yourStrOfAnumber = Util::numToStr(yourIntValue);
 *  yourStrOfAnumber += " + " + Util::numToStr(yourFloatValue);
 *
 *  @author    	E. Bergeron
 *  @date      	2013-01-15
 *  @pre		include Util.h, that's it!
 *  @copyright 	Prismal Studio 2008-2013 www.prismalstudio.com
 *
 *  Changelog:
 *  2013-08-10 renamed Util to StringExt.
 */

#include "Util/StringExt.h"
#include <algorithm>

/**
 * Split a string "s" at each "delim" char and push the tokens into the vector "elems"
 * @param s a constant string reference to be split
 * @param delim the character used to split the string "s"
 * @param elems a string vector reference used to store the tokens
 * @return the "elems" vector reference
 */
std::vector<std::string> & Util::split(const std::string & s, char delim,
		std::vector<std::string> & elems, bool skipEmptyToken)
{
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim))
	{
		if (skipEmptyToken && (item.size() <= 0))
		{
			continue;
		}
		elems.push_back(item);
	}
	return elems;
}

/**
 * Split a string "s" at each "delim" char and push the tokens into the created vector "elems"
 * @param s a constant string reference to be split
 * @param delim the character used to split the string "s"
 * @return the "elems" vector reference
 */
std::vector<std::string> Util::split(const std::string & s, char delim,
		bool skipEmptyToken)
{
	std::vector<std::string> elems;
	return split(s, delim, elems, skipEmptyToken);
}

/**
 * formatTime
 *
 * @return a readable time format string from a milisec value
 */
std::string Util::formatTime(long int total)
{
	int minute = total / 60000;
	int second = (total % 60000) / 1000;
	int milisec = (total % 60000) - (second * 1000);

	return toStr(minute) + ":" + toStr(second) + "." + toStr(milisec);
}

/**
 * @param boolValue a boolean value that you want to turn into a string.
 * @return a boolean value string.
 */
std::string Util::toStr(bool boolValue)
{
	return (boolValue ? "true" : "false");
}

std::string Util::toLowercase(const std::string& str)
{
	std::string data = str;
	std::transform(data.begin(), data.end(), data.begin(), ::tolower);
	return data;
}

/**
 * Takes a line of text and wrap it to the lenght provided.
 * @param text the line to be wrapped.
 * @param lineLenght the max number of character in a single line.
 * @return a string wrapped at the right lenght
 */
std::string Util::lineWrap(std::string text, unsigned int lineLenght)
{
	std::string line;

	// until the text isn't longer than the desired line lenght
	while (text.length() > lineLenght)
	{

		// search for the last space of the line
		unsigned pos = text.rfind(' ', lineLenght);

		// if there is a space
		if (pos != std::string::npos)
		{
			// replace it by a line break
			text.replace(pos, 1, "\n");
		}
		else
		{
			// in case there isn't any space in the line
			// split a the last char
			pos = lineLenght;
			text.insert(pos, "\n");
		}

		line += text.substr(0, pos);
		text.erase(0, pos);
	}
	line += text;
	return line;
}
