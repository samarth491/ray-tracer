#include "include/vec3.hpp"

CHD vec3 operator+(const vec3 v1, const vec3 v2) {
	return vec3(v1[0] + v2[0],
				v1[1] + v2[1],
				v1[2] + v2[2]);
}

CHD vec3 operator-(const vec3 v1, const vec3 v2) {
	return vec3(v1[0] - v2[0],
				v1[1] - v2[1],
				v1[2] - v2[2]);
}

CHD vec3 operator*(const vec3 v1, const vec3 v2) {
	return vec3(v1[0] * v2[0],
				v1[1] * v2[1],
				v1[2] * v2[2]);
}

CHD vec3 operator/(const vec3 v1, const vec3 v2) {
	return vec3(v1[0] / v2[0],
				v1[1] / v2[1],
				v1[2] / v2[2]);
}

CHD vec3 operator*(const vec3 v1, const float f) {
	return vec3(v1[0] * f,
				v1[1] * f,
				v1[2] * f);
}

CHD vec3 operator*(const float f, const vec3 v1) {
	return vec3(v1[0] * f,
				v1[1] * f,
				v1[2] * f);
}

CHD vec3 operator/(const vec3 v, const float f) {
	float k = 1 / f;

	return vec3(v[0] * k,
				v[1] * k,
				v[2] * k);
}

CHD vec3& vec3::operator+=(const vec3 &v) {
	val[0] += v[0];
	val[1] += v[1];
	val[2] += v[2];
	return *this;
}

CHD vec3& vec3::operator-=(const vec3 &v) {
	val[0] -= v[0];
	val[1] -= v[1];
	val[2] -= v[2];
	return *this;
}

CHD vec3& vec3::operator*=(const vec3 &v) {
	val[0] *= v[0];
	val[1] *= v[1];
	val[2] *= v[2];
	return *this;
}

CHD vec3& vec3::operator/=(const vec3 &v) {
	val[0] /= v[0];
	val[1] /= v[1];
	val[2] /= v[2];
	return *this;
}

CHD vec3& vec3::operator*=(const float f) {
	val[0] *= f;
	val[1] *= f;
	val[2] *= f;
	return *this;
}

CHD vec3& vec3::operator/=(const float f) {
	float k = 1 / f;

	val[0] *= k;
	val[1] *= k;
	val[2] *= k;
	return *this;
}

CH std::istream& operator>>(std::istream &is, vec3 &v) {
	is >> v.val[0] >> v.val[1] >> v.val[2];
	return is;
}

CH std::ostream& operator<<(std::ostream &os, vec3 &v) {
	os << v.val[0] << " " << v.val[1] << " " << v.val[2];
	return os;
}

CHD float vec3::dot(const vec3 &v1, const vec3 &v2) {
	return v1.val[0] * v2.val[0] + v1.val[1] * v2.val[1] + v1.val[2] * v2.val[2];
}

CHD vec3 vec3::cross(const vec3 &v1, const vec3 &v2) {
	return vec3( (v1.val[1] * v2.val[2] - v1.val[2] * v2.val[1]),
				 (v1.val[2] * v2.val[0] - v1.val[0] * v2.val[2]),
				 (v1.val[0] * v2.val[1] - v1.val[1] * v2.val[0]) );
}

CHD vec3 vec3::unit_vector(const vec3 &v) {
	return v / v.length();
}