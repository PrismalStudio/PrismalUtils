/**
 * @file		TMatrix.h
 *
 * @date 		2012-07-10
 * @author		E. Bergeron
 * @copyright 	Prismal Studio 2008-2013 www.prismalstudio.com
 *
 *
 * Template of a dynamic 2D array or TMatrix of object T.
 *
 *      	unsigned int (unsigned integer) are used to get sure
 *      	every var is positive.
 *
 *      	IMPORTANT: it must be filled with a default value
 *      	to get initialised and then be used.
 */

#ifndef TMatrix_H_
#define TMatrix_H_

//#include <cassert>
//#include <algorithm>
//#include <iostream>

namespace Util {
/*
 *
 */
template<typename T>
class TMatrix {
public:
	/**
	 * Must call Fill(T value) to use the TMatrix
	 * it will fill it by default with "value"
	 * and init it.
	 */
	TMatrix(unsigned int rows, unsigned int cols);
	virtual ~TMatrix();

	// Dimensions retrieval
	unsigned int rows() const;
	unsigned int cols() const;
	unsigned int size() const;
	unsigned int bytes() const;

	/**
	 * Fill "mArray" with "val"
	 *
	 */
	void fill(T val);

	/**
	 * get value AT (x, y)
	 */
	T at(unsigned int x, unsigned int y) const;

	/**
	 * Get value AT "key", if you know the key
	 */
	T at(unsigned int key) const;

	/**
	 * set value "element" AT (x, y)
	 */
	void set(unsigned int x, unsigned int y, T element);

	/**
	 * set value "element" AT (key)
	 */
	void set(unsigned int key, T element);

	/**
	 * @return the key of the 1 dimensionnal array mArray
	 */
	unsigned int getKey(unsigned int x, unsigned int y) const;

	bool isInsideBounds(unsigned int key) const;
	bool isInsideBounds(unsigned int x, unsigned int y) const;

private:

	unsigned int mRows;
	unsigned int mCols;
	unsigned int mSize;
	T * mArray;

};

/**
 * Must call Fill(T value) to use the TMatrix
 * it will fill it by default with "value"
 * and init it.
 */
template<typename T>
inline TMatrix<T>::TMatrix(unsigned int rows, unsigned int cols) :
				mRows(rows),
				mCols(cols),
				mSize(mRows * mCols) {
	mArray = new T[mRows * mCols];
}
template<typename T>
inline TMatrix<T>::~TMatrix() {
	delete[] mArray;
}

// Dimensions retrieval
template<typename T>
inline unsigned int TMatrix<T>::rows() const {
	return mRows;
}
template<typename T>
inline unsigned int TMatrix<T>::cols() const {
	return mCols;
}
template<typename T>
inline unsigned int TMatrix<T>::size() const {
	return rows() * cols();
}
template<typename T>
inline unsigned int TMatrix<T>::bytes() const {
	return size() * sizeof(T);
}

/**
 * Fill "mArray" with "val"
 *
 */
template<typename T>
inline void TMatrix<T>::fill(T val) {
	//std::uninitialized_fill_n(mArray, Size(), val);
	std::fill_n(mArray, size(), val);
}

/**
 * get value AT (x, y)
 */
template<typename T>
inline T TMatrix<T>::at(unsigned int x, unsigned int y) const {
	return mArray[getKey(x, y)];
}

/**
 * Get value AT "key", if you know the key
 */
template<typename T>
inline T TMatrix<T>::at(unsigned int key) const {
	return mArray[key];
}

/**
 * set value "element" AT (x, y)
 */
template<typename T>
inline void TMatrix<T>::set(unsigned int x, unsigned int y, T element) {
	if (isInsideBounds(x, y)) {
		mArray[getKey(x, y)] = element;
	}
}

/**
 * set value "element" AT (key)
 */
template<typename T>
inline void TMatrix<T>::set(unsigned int key, T element) {
	if (isInsideBounds(key)) {
		mArray[key] = element;
	}
}

/**
 * delete value AT (x, y)
 */
//template<typename T>
//inline void TMatrix<T>::Delete(unsigned int x, unsigned int y) {
//	if (!mIsInitialised) {
//		return;
//	}
//	if (GetKey(x, y) < size()) {
//		delete mArray[GetKey(x, y)];
//	}
//}
//
///**
// * delete value AT (key)
// */
//template<typename T>
//inline void TMatrix<T>::Delete(unsigned int key) {
//	if (!mIsInitialised) {
//		return;
//	}
//	if (key < size()) {
//		delete mArray[key];
//	}
//}
/**
 * Returns the key of the 1 dimensionnal array mArray
 * returns -1 on OOB.
 */
template<typename T>
inline unsigned int TMatrix<T>::getKey(unsigned int x, unsigned int y) const {
	return x * cols() + y;
}
template<typename T>
inline bool TMatrix<T>::isInsideBounds(unsigned int key) const {
	return key < size();
}

template<typename T>
inline bool TMatrix<T>::isInsideBounds(unsigned int x, unsigned int y) const {
	return isInsideBounds(getKey(x, y));
}

} // namespace Util

#endif /* TMatrix_H_ */
