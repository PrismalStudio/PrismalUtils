/*
 * @file	FileHelper.h
 * @date	2015-01-09
 * @author	Emile
 * @brief	
 */

#include <string>

namespace Util
{

/**
 * Check for file existence using sys/stat.h
 * see http://stackoverflow.com/a/12774387/1218980
 */
bool fileExist(const std::string& filename);

bool readFile(const std::string& filename, std::string& outContent);

}

