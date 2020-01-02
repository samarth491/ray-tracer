#ifndef CAMERAH
#define CAMERAH

#include "ray.hpp"
#include "util.hpp"

class camera {
public:
	camera(vec3 look_from, vec3 look_at, vec3 vup, float vfov, float aspect, float aperture, float focus_dist) {
		lens_radius = aperture / 2;

		float theta = vfov * M_PI / 180;
		float half_height = tan(theta/2);
		float half_width = aspect * half_height;

		origin = look_from;
		w = unit_vector(look_from - look_at);
		u = unit_vector(cross(vup, w));
		v = cross(w, u);

		left = origin - half_width * u * focus_dist - half_height * v * focus_dist - w * focus_dist;
		horizontal = 2 * half_width * u * focus_dist;
		vertical = 2 * half_height * v * focus_dist;
	}

	ray get_ray(float s, float t) {
		vec3 rd = lens_radius * random_in_disk();
		vec3 offset = u * rd.x() + v * rd.y();

		return ray(origin + offset, left + s * horizontal + t * vertical - origin - offset);
	}

	vec3 left,horizontal,vertical,origin;
	vec3 u, v, w;
	float lens_radius;
};

#endif