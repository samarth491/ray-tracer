#include <bits/stdc++.h>
#include "include/ray.hpp"

CD vec3 color(const ray &r)
{
	vec3 u_d = vec3::unit_vector(r.direction());
	float t = 0.5 * (u_d.y() + 1.0);
	return (1 - t) * vec3(1,1,1) + t * vec3(0.5,0.7,1);
}

CG void paint(float *d_pixels, int nx, int ny, vec3 left, vec3 origin, vec3 horizontal, vec3 vertical) {
	int idx = threadIdx.x + blockIdx.x * blockDim.x;

	if(idx % 3) return;

	if(idx < nx * ny * 3) {
		int j = (idx / 3) / nx;
		int i = (idx / 3) % nx;j = ny - 1 - j;
	
		float u = float(i) / float(nx);
		float v = float(j) / float(ny);

		ray R(origin, left + u*horizontal + v*vertical);
		vec3 col = color(R);

		d_pixels[idx] = col[0]; 
		d_pixels[idx + 1] = col[1]; 
		d_pixels[idx + 2] = col[2]; 
	} 
}

int main(void)
{
	int nx=200,ny=100,ns=1;
	const int BLK = 4096, SZ = 256;

	std::cout<<"P3\n";
	std::cout<<nx<<" "<<ny<<"\n255\n";

	vec3 left(-2,-1,-1);
	vec3 horizontal(4,0,0);
	vec3 vertical(0,2,0);
	vec3 origin(0,0,0);

	float *d_pixels,*pixels;

	pixels = new float[nx * ny * 3];

	cudaMalloc((void **)&d_pixels, sizeof(float) * (nx*ny*3));

	paint<<<BLK,SZ>>>(d_pixels, nx, ny, left, origin, horizontal, vertical);

	cudaMemcpy(pixels, d_pixels, sizeof(float) * (nx*ny*3), cudaMemcpyDeviceToHost); 

	for(int i = 0; i < nx*ny*3; i+=3) {
		std::cout << (int) (255.99*pixels[i]) << ' ' << (int) (255.99*pixels[i + 1]) << ' ' << (int) (255.99*pixels[i + 2]) << '\n';
	}
}