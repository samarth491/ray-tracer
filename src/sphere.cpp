#include "include/sphere.hpp"

CD bool sphere::hit(const ray &r, float tmin, float tmax, hit_record &rec) const {
	vec3 oc = r.origin() - center;

	float a = vec3::dot(r.direction(), r.direction());
	float b = vec3::dot(oc, r.direction());
	float c = vec3::dot(oc, oc) - radius * radius;
	float del = b*b - a*c;

	if(del > 0) {
		
		float temp = (-b - sqrt(del)) / (a);

		if(tmin < temp && temp <tmax) {
			rec.t = temp;
			rec.p = r.point_at_param(temp);
			rec.normal = (rec.p - center)/radius;
			// rec.mat_ptr = mat_ptr;
			return true;
		}

		temp = (-b + sqrt(del)) / (a);

		if(tmin < temp && temp <tmax) {
			rec.t = temp;
			rec.p = r.point_at_param(rec.t);
			rec.normal = (rec.p - center)/radius;
			// rec.mat_ptr = mat_ptr;
			return true;
		}

	}
	return false;
}