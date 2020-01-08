#ifdef __CUDACC__
#define CG __global__
#define CH __host__
#define CD __device__
#define CHD __host__ __device__
#else
#define CG
#define CH
#define CD
#define CHD
#endif