/**
 *  @file		TRectangle.h
 *  @brief
 *  @details
 *  @author    	E. B. (inspired from Daniel Soltyka www.danielsoltyka.com)
 *  @date      	Feb 15, 2013
 *  @pre
 *  @bug
 *  @warning
 *  @copyright 	Prismal Studio 2008-2013 www.prismalstudio.com
 */

#ifndef TRectangle_H_
#define TRectangle_H_

#include "TVector2.h"

/**
 *
 */
#define ABS(x) (((x)>0)?(x):-(x))

namespace Util {

template<typename T>
class TRectangle {
public:
	TRectangle(T x = 0, T y = 0, T w = 0, T h = 0);
	~TRectangle(void) {
	}

	bool contains(TVector2<T>& vVec) const;
	bool contains(T x, T y) const;

	//static TRectangle Empty();

	// Static methods below are derived from the TRectangleExtensions class
	// written in C#, released under the MSPL
	TVector2<T> getIntersectionDepth(const TRectangle<T>& rectB) const;
	TVector2<T> getBottomCenter() const;
	TVector2<T> getBottomLeft() const;
	TVector2<T> getTopRight() const;
	TVector2<T> getCenter() const;
	float getDistance(const TRectangle<T>& rectB) const;
	TVector2<T> getDirection(const TRectangle<T>& rectB) const;

	TRectangle& operator=(const TRectangle& r2);

	bool operator==(const TRectangle& r2) const;
	bool operator!=(const TRectangle& r2) const;

	T getH() const;
	T getW() const;
	T getX() const;
	T getY() const;
	void setH(T h);
	void setW(T w);
	void setX(T x);
	void setY(T y);

//	inline T Left(void) const {
//		return x;
//	}
//	inline T Right(void) const {
//		return x + w;
//	}
//	inline T Top(void) const {
//		return y;
//	}
//	inline T Bottom(void) const {
//		return y + h;
//	}

protected:
	T x;
	T y;
	T w;
	T h;
};

/*******************************
 *
 * METHODs DEFINITIONS
 *
 */

//-----------------------------------------------------------------------------
// Purpose: Constructor
//-----------------------------------------------------------------------------
template<typename T>
inline TRectangle<T>::TRectangle(T x, T y, T w, T h) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

//-----------------------------------------------------------------------------
// Purpose: Check if TRectangle contains a 2D vector
//-----------------------------------------------------------------------------
template<typename T>
inline bool TRectangle<T>::contains(TVector2<T>& vVec) const {
	if ((vVec.getX() >= x) && (vVec.getX() <= x + w) && (vVec.getY() >= y)
			&& (vVec.getY() <= y + h)) {
		return true;
	} else {
		return false;
	}
}

//-----------------------------------------------------------------------------
// Purpose: Check if TRectangle contains a set of coords
//-----------------------------------------------------------------------------
template<typename T>
inline bool TRectangle<T>::contains(T x, T y) const {
	if ((x >= this->x) && (x <= this->x + this->w) && (y >= this->y)
			&& (x <= this->y + this->h)) {
		return true;
	} else
		return false;
}

//-----------------------------------------------------------------------------
// Purpose: Return an empty TRectangle
//-----------------------------------------------------------------------------
//template<typename T>
//inline TRectangle TRectangle<T>::Empty() {
//	return TRectangle();
//}

//-----------------------------------------------------------------------------
// Purpose: Get intersection depth between two TRectangles
//-----------------------------------------------------------------------------
template<typename T>
inline TVector2<T> TRectangle<T>::getIntersectionDepth(
		const TRectangle& rectB) const {
	// Calculate half sizes.
	float halfWidthA = this->getW() / 2.0f;
	float halfHeightA = this->getH() / 2.0f;
	float halfWidthB = rectB.getW() / 2.0f;
	float halfHeightB = rectB.getH() / 2.0f;

	// Calculate centers.
	TVector2<T> centerA(this->getX() + halfWidthA, this->getY() + halfHeightA);
	TVector2<T> centerB(rectB.getX() + halfWidthB, rectB.getY() + halfHeightB);

	// Calculate current and minimum-non-intersecting distances between centers.
	float distanceX = centerA.getX() - centerB.getX();
	float distanceY = centerA.getY() - centerB.getY();
	float minDistanceX = halfWidthA + halfWidthB;
	float minDistanceY = halfHeightA + halfHeightB;

	// If we are not intersecting at all, return (0, 0).
	if ((ABS(distanceX) >= minDistanceX) || (ABS(distanceY) >= minDistanceY)) {
		return TVector2<T>();
	}

	// Calculate and return intersection depths.
	float depthX =
			distanceX > 0 ?
					minDistanceX - distanceX : -minDistanceX - distanceX;
	float depthY =
			distanceY > 0 ?
					minDistanceY - distanceY : -minDistanceY - distanceY;
	return TVector2<T>((T) depthX, (T) depthY);
}

//-----------------------------------------------------------------------------
// Purpose: Gets the position of the center of the bottom edge of the TRectangle.
//-----------------------------------------------------------------------------
template<typename T>
inline TVector2<T> TRectangle<T>::getBottomCenter() const {
	return TVector2<T>((T) (getX() + getW() / 2.0f), getY());
}

//-----------------------------------------------------------------------------
// Purpose: Gets the position of the center point of a TRectangle
//-----------------------------------------------------------------------------
template<typename T>
inline TVector2<T> TRectangle<T>::getCenter() const {
	return TVector2<T>((T) (getX() + getW() / 2.0f),
			(T) (getY() + getH() / 2.0f));
}

//-----------------------------------------------------------------------------
// Purpose: Gets the floating point distance between the center point
//          of one TRectangle and the center point of another.
//-----------------------------------------------------------------------------
template<typename T>
inline float TRectangle<T>::getDistance(const TRectangle<T>& rectB) const {
	return getCenter().distance(rectB.getCenter());
}

//-----------------------------------------------------------------------------
// Purpose: Gets the unit vector from one TRectangle to another
//-----------------------------------------------------------------------------
template<typename T>
inline TVector2<T> TRectangle<T>::getDirection(const TRectangle<T>& rectB) const {
	TVector2<T> direction = getCenter() - rectB.getCenter();
	direction.normalize();
	return direction;
}

template<typename T>
inline TRectangle<T>& TRectangle<T>::operator=(const TRectangle& r2) {
	if (this == &r2)
		return *this;

	x = r2.x;
	y = r2.y;
	w = r2.w;
	h = r2.h;

	return *this;
}

template<typename T>
inline bool TRectangle<T>::operator==(const TRectangle& r2) const {
	return ((w == r2.w) && (h == r2.h));
}

template<typename T>
inline bool TRectangle<T>::operator!=(const TRectangle& r2) const {
	return !((w == r2.w) && (h == r2.h));
}

template<typename T>
inline T TRectangle<T>::getH() const {
	return h;
}

template<typename T>
inline T TRectangle<T>::getW() const {
	return w;
}

template<typename T>
inline T TRectangle<T>::getX() const {
	return x;
}

template<typename T>
inline T TRectangle<T>::getY() const {
	return y;
}

template<typename T>
inline void TRectangle<T>::setH(T h) {
	this->h = h;
}

template<typename T>
inline void TRectangle<T>::setW(T w) {
	this->w = w;
}

template<typename T>
inline void TRectangle<T>::setX(T x) {
	this->x = x;
}

template<typename T>
inline void TRectangle<T>::setY(T y) {
	this->y = y;
}

template<typename T>
inline TVector2<T> TRectangle<T>::getBottomLeft() const {
	return TVector2<T>(getX(), getY());
}

template<typename T>
inline TVector2<T> TRectangle<T>::getTopRight() const {
	return TVector2<T>(getX() + getW(), getY() + getH());
}

} // end of Util namespace
#endif /* TRectangle_H_ */
