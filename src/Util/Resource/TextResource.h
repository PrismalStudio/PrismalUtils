/*
 * @file	TextResource.h
 * @date	2015-01-09
 * @author	Emile
 * @brief	
 */

#ifndef TEXTRESOURCE_H_
#define TEXTRESOURCE_H_

#include "Resource.h"

namespace Util
{

class TextResource: public Resource
{
	public:
		TextResource();
		virtual ~TextResource();

		/**
		 * Load text file.
		 * @param filename
		 * @return true if it loaded correctly, false otherwise.
		 */
		virtual bool load(const std::string& filename);

	private:
		std::string mFileText;
};

} /* namespace xover */

#endif /* TEXTRESOURCE_H_ */
