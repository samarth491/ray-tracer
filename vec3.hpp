#ifndef VEC3H
#define VEC3H

class vec3 {
public:
	float val[3];

	vec3(){}
	vec3(float x,float y, float z) {
		val[0]=x,
		val[1]=y,
		val[2]=z;
	}

	//returning values

	inline float x() const { return val[0]; }
	inline float y() const { return val[1]; }
	inline float z() const { return val[2]; }

	inline float r() const { return val[0]; }
	inline float g() const { return val[1]; }
	inline float b() const { return val[2]; }

	//basic operations of +v, -v, v[i]

	inline const vec3& operator+() const { return *this; }
	inline vec3 operator-() const { return vec3(-val[0], -val[1], -val[2]); }
	inline float operator[](int i) const { return val[i]; }	
	inline float& operator[](int i) { return val[i]; }

	//operators for add, subtract, multiply, divide and their shorthands

	inline vec3 operator+(const vec3 &v2) const {
		const vec3 v1 = *this;
		return vec3(v1.val[0] + v2.val[0], v1.val[1] + v2.val[1], v1.val[2] + v2.val[2]);
	}

	inline vec3 operator-(const vec3 &v2) const {
		const vec3 v1 = *this;
		return vec3(v1.val[0] - v2.val[0], v1.val[1] - v2.val[1], v1.val[2] - v2.val[2]);
	}

	inline vec3 operator*(const vec3 &v2) const {
		const vec3 v1 = *this;
		return vec3(v1.val[0] * v2.val[0], v1.val[1] * v2.val[1], v1.val[2] * v2.val[2]);
	}

	inline vec3 operator/(const vec3 &v2) const {
		const vec3 v1 = *this;
		return vec3(v1.val[0] / v2.val[0], v1.val[1] / v2.val[1], v1.val[2] / v2.val[2]);
	}

	inline vec3 operator*(float f) const {
		const vec3 v1 = *this;
		return vec3(v1.val[0] * f, v1.val[1] * f, v1.val[2] * f);
	}

	inline vec3 operator/(float f) const {
		const vec3 v1 = *this;
		float k = 1/f;
		return vec3(v1.val[0] * k, v1.val[1] * k, v1.val[2] * k);
	}

	inline vec3& operator+=(const vec3 v) {
		val[0] += v.val[0];
		val[1] += v.val[1];
		val[2] += v.val[2];
		return *this;
	}

	inline vec3& operator-=(const vec3 v) {
		val[0] -= v.val[0];
		val[1] -= v.val[1];
		val[2] -= v.val[2];
		return *this;
	}

	inline vec3& operator*=(const vec3 v) {
		val[0] *= v.val[0];
		val[1] *= v.val[1];
		val[2] *= v.val[2];
		return *this;
	}

	inline vec3& operator/=(const vec3 v) {
		val[0] /= v.val[0];
		val[1] /= v.val[1];
		val[2] /= v.val[2];
		return *this;
	}

	inline vec3& operator*=(const float f) {
		val[0] *= f;
		val[1] *= f;
		val[2] *= f;
		return *this;
	}

	inline vec3& operator/=(const float f) {
		float k = 1/f;

		val[0] *= k;
		val[1] *= k;
		val[2] *= k;
		return *this;
	}

	//utils on vectors

	inline float squared_length() const {
		return (val[0] * val[0] + val[1] * val[1] + val[2] * val[2]);
	}

	inline float length() const {
		return sqrt(squared_length());
	}	

	inline void unit_vector() {
		*this /= this->length();
	}
};

inline std::istream& operator>>(std::istream &is, vec3 &v) {
	is >> v.val[0] >> v.val[1] >> v.val[2];
	return is;
}

inline std::ostream& operator<<(std::ostream &os, const vec3 &v) {
	os << v.val[0] << " " << v.val[1] << " " << v.val[2];
	return os;
}

inline vec3 operator*(float f, vec3 v1) {
	return vec3(v1.val[0] * f, v1.val[1] * f, v1.val[2] * f);
}

inline float dot(const vec3 &v1, const vec3 &v2) {
	return v1.val[0] * v2.val[0] + v1.val[1] * v2.val[1] + v1.val[2] * v2.val[2];
}

inline vec3 cross(const vec3 &v1, const vec3 &v2) {
	return vec3( (v1.val[1] * v2.val[2] - v1.val[2] * v2.val[1]),
				 (v1.val[2] * v2.val[0] - v1.val[0] * v2.val[2]),
				 (v1.val[0] * v2.val[1] - v1.val[1] * v2.val[0]) );
}

inline vec3 unit_vector(vec3 v1) {
	v1.unit_vector();
	return v1;
}

#endif