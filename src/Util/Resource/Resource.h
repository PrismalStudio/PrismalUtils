/**
 *  @file		Resource.h
 *  @brief     	Pure virtual class to be used as a the parent class with the generic Manager template
 *  @details	You must implement load, which is the point of the Resource class.
 *
 *  @author    	E. Bergeron
 *  @date      	2012-02-13
 *  @pre		inherit from this class in a subclass that must be managed.
 *  @copyright 	Prismal Studio 2008-2013 www.prismalstudio.com
 */

#ifndef RESOURCE_H_
#define RESOURCE_H_

#include <string>

namespace Util {

class Resource {
public:

	/**
	 * Default constructor
	 */
	Resource();
	virtual ~Resource();

	/**
	 * Pure virtual function, MUST be implement in the sub-class
	 * @param filename
	 * @return true if it loaded correctly, false otherwise.
	 */
	virtual bool load(const std::string& filename) = 0;

	/**
	 * Reload the resource
	 * @return false on failed attempt
	 */
	virtual bool reload();

	/**
	 * GETTER / SETTER
	 */
	std::string getFilename() const;
	void setFilename(const std::string& filename);
	bool isLoaded() const;

protected:

	void setLoaded(bool loaded);

	std::string mFilename; /**< the filename and path if necessary to access the resource */
	bool mLoaded; /**< loading flag */
};

} // namespace Util
#endif /* RESOURCE_H_ */
