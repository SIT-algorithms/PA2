#include <stdio.h>
#include <math.h>
#include <float.h>

typedef float vec1_t;

typedef struct vec2 {
	float x, y;
} vec2_t;

typedef struct vec3 {
	float x, y, z;
} vec3_t;

float get_closest_pair_1d_naive(vec1_t* a, vec1_t* b,
		const vec1_t* points, const int n_points);

float get_closest_pair_2d_naive(vec2_t* a, vec2_t* b,
		const vec2_t* points, const int n_points);

float get_closest_pair_3d_naive(vec3_t* a, vec3* b,
		const vec3_t* points, const int n_points);

int main(int argc, char** argv)
{
	return 0;
}

float get_closest_pair_1d_naive(vec1_t* a, vec1_t* b,
		const vec1_t* points, const int n_points) {
	float min_distance = FLT_MAX;

	for (int i = 0; i < n_points - 1; ++i) {
		float diff = points[i+1] - points[i];

		if (fabs(diff) < min_distance) {
			*a = points[i];
			*b = points[i+1];

			min_distance = diff;
		}
	}
}

float get_closest_pair_2d_naive(vec2_t* a, vec2_t* b,
		const vec2_t* points, const int n_points) {
}

float get_closest_pair_3d_naive(vec3_t* a, vec3_t* b,
		const vec3_t* points, const int n_points) {
}
