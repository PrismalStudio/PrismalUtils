/**
 *  @file		TSingleton.h
 *  @brief     	Easily make your class a singleton
 *  			by inheriting from this class.
 *
 *  @details	To use it, first make the constructor and destructor private.
 *  			Then, inherit from this class like this:
 *
 *  			class YourClass: public TSingleton< YourClass > {
 *  				friend class TSingleton< YourClass > ;
 *
 *  			It's important to make it a friend class to have access to
 *  			the constructor and destructor.
 *
 *  @author    	E. Bergeron
 *  @date      	2011-12-26
 *  @pre		inherit from this class in a subclass that you want it to
 *  			be a singleton.
 *  @copyright 	Prismal Studio 2008-2014 www.prismalstudio.com
 */
#ifndef SINGLETON_H_
#define SINGLETON_H_

namespace Util
{

template<typename T>
class TSingleton
{
	protected:
		/**
		 * Protected Constructor and destructor
		 * You don't want anyone to create an
		 * instance of T except T which derive
		 * from the TSingleton template.
		 */
		TSingleton();
		virtual ~TSingleton();

	public:
		/**
		 * Global access, create the instance if not already done.
		 * @return a T pointer of the single instance
		 */
		static T *getInstance();

		/**
		 * Kills the only instance
		 */
		static void kill();

	private:
		static T *_instance; /**< unique instance static T pointer */
};

/**
 * initialize it to null
 */
template<typename T>
T *TSingleton<T>::_instance = 0;

// Implementation
template<typename T>
inline TSingleton<T>::TSingleton()
{
	// left empty on purpose
}
template<typename T>
inline TSingleton<T>::~TSingleton()
{
	// left empty on purpose
}
template<typename T>
inline T *TSingleton<T>::getInstance()
{
	if (0 == _instance)
	{
		_instance = new T;
	}

	return (static_cast<T*>(_instance));
}

template<typename T>
inline void TSingleton<T>::kill()
{
	if (0 != _instance)
	{
		delete _instance;
		_instance = 0;
	}
}

} // namespace

#endif /* SINGLETON_H_ */
