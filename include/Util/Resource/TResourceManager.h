/**
 *  @file		TManager.h
 *  @brief     	Generic Template to manage Ressource sub-class.
 *  @details   	It protects you from loading a file twice.
 *
 *  NO NEED TO CREATE, IT'S A SINGLETON.
 *
 *  To have access to it:
 *  TManager<YourResourceSubClass>::getInstance();
 *
 *  To get a ressource:
 *  TManager<YourResourceSubClass>::getInstance()->loadResource("resourceFilePath");
 *
 *  The file path serves as a key, if you use loadResource with a file
 *  that has already been loaded, you'll get the pointer to that resource.
 *
 *  CHANGES:
 *  	24-02-2013 EB useless if inside isLoaded
 *
 *  @author    	E. Bergeron
 *  @date      	2012-02-13
 *  @pre		a class that inherit from Resource
 *  @copyright 	Prismal Studio 2008-2013 www.prismalstudio.com
 */

#ifndef TManager_H_
#define TManager_H_

#include "Util/TSingleton.h"
//#include "Resource.h"

#include <map>

namespace Util {

template<typename T>
class TResourceManager: public TSingleton<TResourceManager<T> > {
	friend class TSingleton<TResourceManager<T> > ;
public:

	/**
	 * Load the resource only if not already register in the map container.
	 * @param filename is the key in the map of ressource
	 * @return a pointer to the resource itself or NULL if it failed
	 */
	T * load(const std::string& filename);

	/**
	 * Clear the map
	 */
	void deleteAll();

	/**
	 * Reload all the ressource in the map
	 */
	void reloadAll();

	/**
	 * Check if a file is already in the map
	 * @param filename ...obvious
	 * @return true if filename is already loaded in the map
	 */
	bool isLoaded(std::string filename);

	/**
	 * If not already loaded, add the resource to the map
	 * @param resource of the sub-type to register
	 */
	void registerResource(T * resource);
	/**
	 * Removes a texture from management
	 * @param resource of the sub-type to unregister
	 */
	void unRegisterResource(T * resource);

	/**
	 * To get a string of all the keys (filename) in the map
	 * @return a string of all keys on a line each
	 */
	std::string listAllKey();

protected:
	TResourceManager();
	virtual ~TResourceManager();
private:
	std::map<std::string, T *> mResourceMap; /**< the map in which all the resource are stored */
};

template<typename T>
inline TResourceManager<T>::TResourceManager() {
}
template<typename T>
inline TResourceManager<T>::~TResourceManager() {
	deleteAll();
}

/**
 * Load the resource only if not already register in the map container.
 * @param filename is the key in the map of ressource
 * @return a pointer to the resource itself or NULL if it failed
 */
template<typename T>
inline T * TResourceManager<T>::load(const std::string& filename) {
	if (!isLoaded(filename)) {
		T * newResource = new T();
		newResource->setFilename(filename);

		// only register a loaded resource
		// load return false on failed attempt
		if (newResource->load(filename)) {
			registerResource(newResource);
			return newResource;
		}
	} else {
		return mResourceMap[filename];
	}
	return NULL;
}

/**
 * Clear the map
 */
template<typename T>
inline void TResourceManager<T>::deleteAll() {
	typename std::map<std::string, T*>::iterator pos = mResourceMap.begin();
	while (pos != mResourceMap.end()) {
		delete (*pos).second;
		pos++;
	}
	mResourceMap.clear();
}

/**
 * Reload all the ressource in the map
 */
template<typename T>
inline void TResourceManager<T>::reloadAll() {
	typename std::map<std::string, T*>::iterator pos = mResourceMap.begin();
	while (pos != mResourceMap.end()) {
		(*pos).second->reload();
		pos++;
	}
}

/**
 * Check if a file is already in the map
 * @param filename ...obvious
 * @return true if filename is already loaded in the map
 */
template<typename T>
inline bool TResourceManager<T>::isLoaded(std::string filename) {
	return (mResourceMap.find(filename) != mResourceMap.end());
}

/**
 * If not already loaded, add the resource to the map
 * @param resource of the sub-type to register
 */
template<typename T>
inline void TResourceManager<T>::registerResource(T * resource) {
	if (!isLoaded(resource->getFilename())) {
		mResourceMap[resource->getFilename()] = resource;
	}
}
/**
 * Removes a texture from management
 * @param resource of the sub-type to unregister
 */
template<typename T>
inline void TResourceManager<T>::unRegisterResource(T * resource) {
	if (isLoaded(resource->getFilename())) {
		mResourceMap.erase(resource->getFilename());
	}
}

/**
 * To get a string of all the keys (filename) in the map
 * @return a string of all keys on a line each
 */
template<typename T>
inline std::string TResourceManager<T>::listAllKey() {
	std::string listStr;
	typename std::map<std::string, T*>::iterator pos = mResourceMap.begin();
	while (pos != mResourceMap.end()) {
		listStr += (*pos).first + "\n";
		pos++;
	}
	return listStr;
}

} // namespace
#endif /* TManager_H_ */
