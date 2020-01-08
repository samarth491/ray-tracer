#ifndef SPHEREH
#define SPHEREH

#include "hitable.hpp"

class sphere: public hitable {
public:
	CD sphere() {}
	CD sphere(vec3 cen, float r/*, material *m*/): center(cen), radius(r)/*, mat_ptr(m)*/ {};
	CD virtual bool hit(const ray &r, float tmin, float tmax, hit_record &rec) const;
	vec3 center;
	float radius;
	// material *mat_ptr;
};

#endif