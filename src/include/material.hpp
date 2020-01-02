#ifndef MATERIALH
#define MATERIALH


#include "ray.hpp"
#include "hitable.hpp"
#include "util.hpp"

struct hit_record;

class material {
public:
	virtual bool scatter(const ray &r, const hit_record &rec, vec3 &attenuation, ray &scattered) const = 0;
};

class lambertian : public material {
public: 
	lambertian(const vec3 &a) : albedo(a) {}

	virtual bool scatter(const ray &r, const hit_record &rec, vec3 &attenuation, ray &scattered) const {
		vec3 target = rec.p + rec.normal + random_in_sphere();
		scattered = ray(rec.p, target - rec.p);
		attenuation = albedo;
		return true;
	}

	vec3 albedo;
};

class metal : public material {
public:
	metal(const vec3 &a, float f) : albedo(a) { if(f<1) fuzz=f; else fuzz=1; }
	virtual bool scatter(const ray &r, const hit_record &rec, vec3 &attenuation, ray &scattered) const {
		vec3 reflected = reflect(unit_vector(r.direction()), rec.normal);
		scattered = ray(rec.p, reflected + fuzz * random_in_sphere());
		attenuation = albedo;
		return (dot(scattered.direction(), rec.normal) > 0);
	}

	vec3 albedo;
	float fuzz;
};

class dielectric : public material {
public:
	dielectric(float r) : ref_ind(r) {}

	virtual bool scatter(const ray &r, const hit_record &rec, vec3 &attenuation, ray & scattered) const {
		vec3 outward_normal;
		vec3 reflected = reflect(r.direction(), rec.normal);

		float mu,reflect_prob,cosine;
		vec3 refracted;
		attenuation = vec3(1, 1, 1);

		if(dot(r.direction(), rec.normal) > 0) {
			outward_normal = -rec.normal;
			mu = ref_ind;
			cosine = dot(r.direction(), rec.normal) / r.direction().length();
            cosine = sqrt(1 - ref_ind*ref_ind*(1-cosine*cosine));
		} else {
			outward_normal = rec.normal;
			mu = 1/ref_ind;
			cosine = -dot(r.direction(), rec.normal) / r.direction().length();
		}

		if(refract(r.direction(), outward_normal, mu, refracted)) {
			reflect_prob = schlick(cosine, ref_ind);
		} else {
			reflect_prob = 1;
		}

		if(random_double() < reflect_prob) {
			scattered = ray(rec.p, reflected);
		} else {
			scattered = ray(rec.p, refracted);
		}

		return true;
	}

	float ref_ind;
};

#endif