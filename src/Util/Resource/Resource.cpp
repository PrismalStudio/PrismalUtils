/** 
 *  @file		Resource.cpp
 *  @brief     
 *  @details   
 *  @author    	Emile
 *  @date      	2013-05-15
 *  @pre       
 *  @bug       
 *  @warning   
 *  @copyright 	Prismal Studio 2008-2013 www.prismalstudio.com
 */

#include "Util/Resource/Resource.h"

namespace Util {

Resource::Resource() :
				mFilename(),
				mLoaded(false) {
}

Resource::~Resource() {
}

bool Resource::reload() {
	return (getFilename() != "") ? load(getFilename()) : false;
}

std::string Resource::getFilename() const {
	return mFilename;
}

void Resource::setFilename(const std::string& filename) {
	mFilename = filename;
}

bool Resource::isLoaded() const {
	return mLoaded;
}

void Resource::setLoaded(bool loaded) {
	mLoaded = loaded;
}

}

