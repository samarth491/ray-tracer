#include "include/hitable_list.hpp"

CD bool hitable_list::hit(const ray &r, float tmin, float tmax, hit_record &rec) const {
	hit_record tmp;
	bool did_hit = false;
	double closest = tmax;

	for(int i=0;i<size;i++) {
		if(list[i]->hit(r, tmin, closest, tmp)) {
			closest = tmp.t;
			rec = tmp;
			did_hit = true;
		}
	}
	return did_hit;
}