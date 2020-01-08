#ifndef RAYH
#define RAYH

#include "vec3.hpp"

class ray {
public:
	vec3 A, B;

	CD ray() {}
	CD ray(const vec3 &a, const vec3 &b) { A = a, B = b ;}
	
	CD vec3 origin() const { return A; }
	CD vec3 direction() const { return B; }

	CD vec3 point_at_param(float t) const { return A + t * B; }
};

#endif