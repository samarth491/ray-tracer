#ifndef HITABLELISTH
#define HITABLELISTH

#include "hitable.hpp"

class hitable_list: public hitable {
public:
	CD hitable_list() {}
	CD hitable_list(hitable **l, int n) {
		list = l;
		size = n;
	}

	CD virtual bool hit(const ray &r, float tmin, float tmax, hit_record &rec) const;

	hitable **list;
	int size;
};

#endif