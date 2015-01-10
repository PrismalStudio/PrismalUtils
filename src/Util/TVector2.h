/**
 *  @file		TVector2.h
 *  @brief     
 *  @details   
 *  @author    	E. B. (inspired from Daniel Soltyka www.danielsoltyka.com)
 *  @date      	Feb 11, 2013
 *  @pre       
 *  @bug       
 *  @warning   
 *  @copyright 	Prismal Studio 2008-2013 www.prismalstudio.com
 */

#ifndef TVector2_H_
#define TVector2_H_

#define _USE_MATH_DEFINES

#include <math.h>
//#include <iostream>
//#include <stdio.h>

namespace Util {
template<typename T>
class TVector2 {

public:
	TVector2(T x = 0, T y = 0);
	~TVector2() {
	}

	// Useful methods
	TVector2<T> rotate(const float& angle) const;
	TVector2<T> scale(const float& scalar) const;
	float magnitude() const;
	float normalize();
	float dotProduct(const TVector2<T>& v2) const;
	float crossProduct(const TVector2<T>& v2) const;
	float distance(const TVector2<T>& v2) const;

	TVector2<T> getVectorTo(const TVector2<T>& v2) const;
	TVector2<T> getMidPoint(const TVector2<T>& v2) const;
	TVector2<T> getMidPoint(const TVector2<T>& v2, const TVector2<T>& v3) const;

	// GETTER
	T getX() const;
	T getY() const;

	// SETTER
	void setX(T newX);
	void setY(T newY);

	// OPERATOR OVERLOAD
	TVector2<T>& operator=(const TVector2<T>& v2);

	TVector2<T>& operator+=(const TVector2<T>& v2);
	TVector2<T>& operator-=(const TVector2<T>& v2);
	TVector2<T>& operator*=(const float scalar);
	TVector2<T>& operator/=(const float scalar);

	const TVector2<T> operator+(const TVector2<T> &v2) const;
	const TVector2<T> operator-(const TVector2<T> &v2) const;
	const TVector2<T> operator*(const float scalar) const;
	const TVector2<T> operator/(const float scalar) const;

	bool operator==(const TVector2<T>& v2) const;
	bool operator!=(const TVector2<T>& v2) const;

protected:
	T x;
	T y;
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
inline TVector2<T>::TVector2(T x, T y) {
	this->x = x;
	this->y = y;
}

/**
 * rotate a vector
 * @param angle an angle in degrees
 * @return a new TVector2
 */
template<typename T>
inline TVector2<T> TVector2<T>::rotate(const float& angle) const {
	// in degrees
	float xt = (x * cosf(angle * M_PI / 180)) - (y * sinf(angle * M_PI / 180));
	float yt = (y * cosf(angle * M_PI / 180)) + (x * sinf(angle * M_PI / 180));
	// uncomment to have it in radians
//	float xt = (x * cosf(angle)) - (y * sinf(angle));
//	float yt = (y * cosf(angle)) + (x * sinf(angle));
	return TVector2<T>(xt, yt);
}

template<typename T>
inline TVector2<T> TVector2<T>::scale(const float & scalar) const {
	return *this * scalar;
}

//-----------------------------------------------------------------------------
// Purpose: Get vector magnitude
//-----------------------------------------------------------------------------
template<typename T>
inline float TVector2<T>::magnitude() const {
	return sqrtf(x * x + y * y);
}

//-----------------------------------------------------------------------------
// Purpose: Convert vector to a unit vector and return previous magnitude
//-----------------------------------------------------------------------------
template<typename T>
inline float TVector2<T>::normalize() {
	float mag = magnitude();

	if (mag != 0.0) {
		x /= mag;
		y /= mag;
	}

	return mag;
}

/**
 * Dot Product
 * @param v2 the vector to use in the dot product
 * @return a floating point value
 */
template<typename T>
inline float TVector2<T>::dotProduct(const TVector2<T> &v2) const {
	return (x * v2.x) + (y * v2.y);
}

//-----------------------------------------------------------------------------
// Purpose: Cross Product
//-----------------------------------------------------------------------------
template<typename T>
inline float TVector2<T>::crossProduct(const TVector2<T> &v2) const {
	return (x * v2.y) - (y * v2.x);
}

//-----------------------------------------------------------------------------
// Purpose: Return an empty vector
//-----------------------------------------------------------------------------
//template<typename T>
//TVector2<T> TVector2<T>::Zero() {
//	return TVector2<T>(0, 0);
//}

/**
 * get the distance between two vectors.
 * @param v2 a point/vector.
 * @return the distance as a floating point value.
 */
template<typename T>
inline float TVector2<T>::distance(const TVector2<T>& v2) const {
	return sqrtf(pow((v2.x - x), 2) + pow((v2.y - y), 2));
}

/**
 * getVectorTo gives you a vector to the point provided
 * @param v2 a vector/point to where you want the vector to point.
 * @return a new TVector2 going from "this" vector to the v2 vector.
 */
template<typename T>
inline TVector2<T> TVector2<T>::getVectorTo(const TVector2<T> & v2) const {
	return v2 - *this;
}

/**
 * getMidPoint return a vector that is between 2 points.
 * @param v2 a vector.
 * @return a new vector that is between this and v2.
 */
template<typename T>
inline TVector2<T> TVector2<T>::getMidPoint(const TVector2<T> & v2) const {
	return (*this + v2) / 2;
}

/**
 * getMidPoint return a vector that is between 3 points.
 * @param v2 a first vector.
 * @param v3 a second vector.
 * @return a new vector that is between this, v2 and v3.
 */
template<typename T>
inline TVector2<T> TVector2<T>::getMidPoint(const TVector2<T> & v2,
		const TVector2<T> & v3) const {
	return ((*this + v2) + v3) / 3;
}

/********************
 * OPERATORs OVERLOADING
 *
 */
template<typename T>
inline TVector2<T>& TVector2<T>::operator=(const TVector2<T>& v2) {
	if (this == &v2)
		return *this;

	x = v2.x;
	y = v2.y;

	return *this;
}

template<typename T>
inline TVector2<T>& TVector2<T>::operator+=(const TVector2<T>& v2) {
	x += v2.x;
	y += v2.y;

	return *this;
}

template<typename T>
inline TVector2<T>& TVector2<T>::operator-=(const TVector2<T>& v2) {
	x -= v2.x;
	y -= v2.y;

	return *this;
}

template<typename T>
inline TVector2<T>& TVector2<T>::operator*=(const float scalar) {
	x *= scalar;
	y *= scalar;

	return *this;
}

template<typename T>
inline TVector2<T>& TVector2<T>::operator/=(const float scalar) {
	x /= scalar;
	y /= scalar;

	return *this;
}

template<typename T>
inline const TVector2<T> TVector2<T>::operator+(const TVector2<T> &v2) const {
	return TVector2<T>(*this) += v2;
}

template<typename T>
inline const TVector2<T> TVector2<T>::operator-(const TVector2<T> &v2) const {
	return TVector2<T>(*this) -= v2;
}

template<typename T>
inline const TVector2<T> TVector2<T>::operator*(const float scalar) const {
	return TVector2<T>(*this) *= scalar;
}

template<typename T>
inline const TVector2<T> TVector2<T>::operator/(const float scalar) const {
	return TVector2<T>(*this) /= scalar;
}

template<typename T>
inline bool TVector2<T>::operator==(const TVector2<T>& v2) const {
	return ((x == v2.x) && (y == v2.y));
}

template<typename T>
inline bool TVector2<T>::operator!=(const TVector2<T>& v2) const {
	return !((x == v2.x) && (y == v2.y));
}

template<typename T>
inline T TVector2<T>::getX() const {
	return this->x;
}

template<typename T>
inline T TVector2<T>::getY() const {
	return this->y;
}

template<typename T>
inline void TVector2<T>::setX(T newX) {
	this->x = newX;
}

template<typename T>
inline void TVector2<T>::setY(T newY) {
	this->y = newY;
}
} // namespace Util
#endif /* TVector2_H_ */
