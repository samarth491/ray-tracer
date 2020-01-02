#include <bits/stdc++.h>
#include "include/sphere.hpp"
#include "include/hitable_list.hpp"
#include "include/camera.hpp"
#include "include/material.hpp"

hitable *random_scene() {
	int n = 500;

	hitable **list = new hitable*[n+1];
	list[0] = new sphere(vec3(0, -1000, 0), 1000, new lambertian(vec3(0.5, 0.5, 0.5)));
	int i=1;

	for(int a = -11; a < 11; a++)
	{
		for(int b = -11; b < 11; b++)
		{
			float mat = random_double();
			vec3 center(a + 0.9 * random_double(), 0.2, b + 0.9 * random_double());

			if((center - vec3(4,0.2,0)).length() > 0.9) {
				if(mat < 0.8) {
					list[i++] = new sphere(center, 0.2, new lambertian(vec3(random_double() * random_double(), random_double() * random_double(), random_double() * random_double())));
				}
				else if(mat < 0.95) {
					list[i++] = new sphere(center, 0.2,
						new metal(vec3(0.5 * (1 + random_double()), 0.5 * (1 + random_double()), 0.5 * (1 + random_double())), 0.5 * random_double()));
				}
				else {
					list[i++] = new sphere(center, 0.2, new dielectric(1.5));
				}
			}
		}
	}

	list[i++] = new sphere(vec3(0, 1, 0), 1.0, new dielectric(1.5));
	list[i++] = new sphere(vec3(-4, 1, 0), 1.0, new lambertian(vec3(0.4, 0.2, 0.1)));
	list[i++] = new sphere(vec3(4, 1, 0), 1.0, new metal(vec3(0.7, 0.6, 0.5), 0.0));

	return new hitable_list(list, i);
}

vec3 color(const ray &r, hitable *world, int depth)
{
	hit_record rec;

	if(world->hit(r, 0.001, MAXFLOAT, rec)) {
		ray scattered;
		vec3 attenuation;
		
		if(depth < 50 && rec.mat_ptr -> scatter(r, rec, attenuation, scattered)) {
			return attenuation * color(scattered, world, depth + 1);
		}
		else {
			return vec3(0, 0, 0);
		}
	} 
	else {
		vec3 unit = unit_vector(r.direction());
		float t = 0.5 * (unit.y() + 1);
		return (1-t) * vec3(1,1,1) + t * vec3(0.5,0.7,1.0);
	}
}

int main(void)
{
	int nx=1200,ny=800,ns=10;

	std::cout<<"P3\n";
	std::cout<<nx<<" "<<ny<<"\n255\n";

	vec3 look_from = vec3(13, 2, 3);
	vec3 look_at = vec3(0, 0, 0);
	float dist_to_focus = 11;
	float aperture = 0.1;

	camera cam(look_from, look_at, vec3(0, 1, 0), 20, float(nx) / float(ny), aperture, dist_to_focus);

	hitable *world = random_scene();

	for(int j=ny-1;j>=0;j--)
	{
		for(int i=0;i<nx;i++)
		{
			vec3 col(0,0,0);
			for(int k=0;k<ns;k++)
			{
				float u = float(i+random_double()) / float(nx);
				float v = float(j+random_double()) / float(ny);
				ray R = cam.get_ray(u,v);
				col += color(R, world, 0);	
			}

			col /= float(ns);
			col = vec3(sqrt(col[0]), sqrt(col[1]), sqrt(col[2]));

			int r=255.99*col[0];
			int g=255.99*col[1];
			int b=255.99*col[2];

			std::cout<<r<<" "<<g<<" "<<b<<'\n';
		}
	}
}