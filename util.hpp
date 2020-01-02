#ifndef UTILH
#define UTILH


#include<random>
#include "vec3.hpp"

float random_double() {
	std::mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
	std::uniform_real_distribution<double> dist(0.0, 1.0);
	return dist(rng32);
}

vec3 random_in_disk() {
	vec3 p;
	do {
		p = 2 * vec3(random_double(), random_double(), 0) - vec3(1, 1, 0);
	} while(dot(p, p) >= 1.0);
	return p;
}

vec3 random_in_sphere() {
	vec3 p;
	do {
		 p = 2 * vec3(random_double(), random_double(), random_double()) - vec3(1, 1, 1);
	} while(p.squared_length() >= 1.0);
	return p;
}

vec3 reflect(const vec3 &v, const vec3 &n) {
	return v - 2 * dot(v,n) * n;
}

bool refract(const vec3 &v, const vec3 &n, float mu, vec3 &refracted) {
	vec3 uv = unit_vector(v);
	float dt = dot(uv, n);

	float del = 1- mu * mu * (1 - dt * dt);
	if(del > 0) {
		refracted = mu * (uv - n * dt) - n * sqrt(del);
		return true;
	}

	return false;
}

float schlick(float cosine, float ref_ind) {
	float r0 = (1 - ref_ind) / (1 + ref_ind);
	r0 *= r0;
	return r0 + (1 - r0) * pow((1 - cosine), 5);
}

#endif