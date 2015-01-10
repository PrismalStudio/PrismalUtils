/**
 * @file	FileHelper.cpp
 * @date	2015-01-09
 * @author	Emile
 * @brief	
 */

#include "FileHelper.h"
#include <sys/stat.h> /* stat function in fileExist */
#include <fstream> /* readFile uses ifstream */

bool Util::fileExist(const std::string& filename)
{
	struct stat buffer;
	return (stat(filename.c_str(), &buffer) == 0);
}

bool Util::readFile(const std::string& filename, std::string& outContent)
{
	// check if file exist
	if (!fileExist(filename))
	{
		return false; // file does not exist
	}

	// open the file
	std::ifstream t(filename.c_str());
	if (t.fail())
	{
		return false; // can't open file
	}

	// efficient reading by Jerry Coffin, see:  http://stackoverflow.com/a/2602258/1218980
	t.seekg(0, std::ios::end);
	size_t size = t.tellg();
	//std::string buffer(size, ' ');
	outContent = std::string(size, ' ');
	t.seekg(0);
	t.read(&outContent[0], size);
	return true;
}
