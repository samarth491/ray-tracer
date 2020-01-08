#include <bits/stdc++.h>
#include "include/vec3.hpp"

// vec3 color(const ray &r, hitable *world, int depth)
// {
// 	hit_record rec;

// 	if(world->hit(r, 0.001, MAXFLOAT, rec)) {
// 		ray scattered;
// 		vec3 attenuation;
		
// 		if(depth < 50 && rec.mat_ptr -> scatter(r, rec, attenuation, scattered)) {
// 			return attenuation * color(scattered, world, depth + 1);
// 		}
// 		else {
// 			return vec3(0, 0, 0);
// 		}
// 	} 
// 	else {
// 		vec3 unit = unit_vector(r.direction());
// 		float t = 0.5 * (unit.y() + 1);
// 		return (1-t) * vec3(1,1,1) + t * vec3(0.5,0.7,1.0);
// 	}
// }

int main(void)
{
	// int nx=1200,ny=800,ns=10;

	// std::cout<<"P3\n";
	// std::cout<<nx<<" "<<ny<<"\n255\n";

	// vec3 look_from = vec3(13, 2, 3);
	// vec3 look_at = vec3(0, 0, 0);
	// float dist_to_focus = 11;
	// float aperture = 0.1;

	// camera cam(look_from, look_at, vec3(0, 1, 0), 20, float(nx) / float(ny), aperture, dist_to_focus);

	// hitable *world = random_scene();

	// for(int j=ny-1;j>=0;j--)
	// {
	// 	for(int i=0;i<nx;i++)
	// 	{
	// 		vec3 col(0,0,0);
	// 		for(int k=0;k<ns;k++)
	// 		{
	// 			float u = float(i+random_double()) / float(nx);
	// 			float v = float(j+random_double()) / float(ny);
	// 			ray R = cam.get_ray(u,v);
	// 			col += color(R, world, 0);	
	// 		}

	// 		col /= float(ns);
	// 		col = vec3(sqrt(col[0]), sqrt(col[1]), sqrt(col[2]));

	// 		int r=255.99*col[0];
	// 		int g=255.99*col[1];
	// 		int b=255.99*col[2];

	// 		std::cout<<r<<" "<<g<<" "<<b<<'\n';
	// 	}
	// }

	vec3 v1(1,2,3), v2(2,3,4);
	float f = vec3::dot(v1,v2);
	std::cout<<f;
}