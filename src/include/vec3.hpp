#ifndef VEC3H
#define VEC3H

#include <iostream>
#include <cmath>

#include "definitions.hpp"

class vec3 {
public:
	float val[3];

	CHD vec3(){}
	CHD vec3(float x,float y, float z) {
		val[0]=x,
		val[1]=y,
		val[2]=z;
	}

	//returning values

	CHD inline float x() const { return val[0]; }
	CHD inline float y() const { return val[1]; }
	CHD inline float z() const { return val[2]; }

	CHD inline float r() const { return val[0]; }
	CHD inline float g() const { return val[1]; }
	CHD inline float b() const { return val[2]; }

	//basic operations of +v, -v, v[i]

	CHD inline const vec3& operator+() const { return *this; }
	CHD inline vec3 operator-() const { return vec3(-val[0], -val[1], -val[2]); }
	CHD inline float operator[](int i) const { return val[i]; }	
	CHD inline float& operator[](int i) { return val[i]; }

	// io

	CH friend std::istream& operator>>(std::istream&, vec3&);
	CH friend std::ostream& operator<<(std::ostream&, vec3&);

	// operations on vectors

	CHD friend vec3 operator+(const vec3, const vec3);
	CHD friend vec3 operator-(const vec3, const vec3);
	CHD friend vec3 operator*(const vec3, const vec3);
	CHD friend vec3 operator/(const vec3, const vec3);
	CHD friend vec3 operator*(const vec3, const float);
	CHD friend vec3 operator/(const vec3, const float);
	CHD friend vec3 operator*(const float, const vec3);

	// shorthands

	CHD vec3& operator+=(const vec3&);
	CHD vec3& operator-=(const vec3&);
	CHD vec3& operator*=(const vec3&);
	CHD vec3& operator/=(const vec3&);
	CHD vec3& operator*=(const float);
	CHD vec3& operator/=(const float);

	//utils on vectors

	CHD inline float squared_length() const { return (val[0] * val[0] + val[1] * val[1] + val[2] * val[2]);}
	CHD inline float length() const { return sqrt(squared_length());}	
	CHD inline void make_unit_vector() { *this /= this->length();}

	CHD static vec3 unit_vector(const vec3&);
	CHD static float dot(const vec3&, const vec3&);
	CHD static vec3 cross(const vec3&, const vec3&);


};

#endif