#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <sys/time.h>

#include "kernel.h"

int main(int argc, char** argv)
{
	if (argc != 2) {
		fprintf(stderr, "usage: ./closest-pair <1d|2d|3d>\n");
		exit(1);
	}

	int dimension = 0;

	if (strcmp(argv[1], "1d") == 0) {
		dimension = 1;
	} else if (strcmp(argv[1], "2d") == 0) {
		dimension = 2;
	} else if (strcmp(argv[1], "3d") == 0) {
		dimension = 3;
	} else {
		fprintf(stderr, "Invalid running instance.\n");
		exit(1);
	}

	int n_points;
	scanf("%d", &n_points);

	float* points = malloc(sizeof(float) * dimension * n_points);

	srandom(0xdeadbeef);

	for (int i = 0; i < n_points; ++i) {
		for (int j = 0; j < dimension; ++j) {
			points[dimension*i + j] = (float)random() / RAND_MAX;
		}
	}

	// Run naive implementation
	{
		float a[3], b[3];
		float min_distance;

		struct timeval start;
		gettimeofday(&start, NULL);

		switch (dimension) {
		case 1:
			min_distance = get_closest_pair_1d_naive(
					(vec1_t*)a,
					(vec1_t*)b,
					(const vec1_t*)points,
					n_points);
			break;
		case 2:
			min_distance = get_closest_pair_2d_naive(
					(vec2_t*)a,
					(vec2_t*)b,
					(const vec2_t*)points,
					n_points);
			break;
		case 3:
			min_distance = get_closest_pair_3d_naive(
					(vec3_t*)a,
					(vec3_t*)b,
					(const vec3_t*)points,
					n_points);
			break;
		}

		struct timeval end;
		gettimeofday(&end, NULL);

		printf("Getting closest pair in the naive way\n");

		printf("a:");
		for (int i = 0; i < dimension; ++i) {
			printf(" %f", a[i]);
		}
		printf("\n");

		printf("b:");
		for (int i = 0; i < dimension; ++i) {
			printf(" %f", b[i]);
		}
		printf("\n");

		printf("min_distance: %f\n", min_distance);

		printf("elapsed time: %lf\n", ((end.tv_sec + end.tv_usec * 0.000001) - (start.tv_sec + start.tv_usec * 0.000001)));
	}

	// Run divide and conquer implementation
	{
		float a[3], b[3];
		float min_distance;

		struct timeval start;
		gettimeofday(&start, NULL);

		switch (dimension) {
		case 1:
			min_distance = get_closest_pair_1d_daq(
					(vec1_t*)a,
					(vec1_t*)b,
					(const vec1_t*)points,
					n_points);
			break;
		case 2:
			min_distance = get_closest_pair_2d_daq(
					(vec2_t*)a,
					(vec2_t*)b,
					(const vec2_t*)points,
					n_points);
			break;
		case 3:
			min_distance = get_closest_pair_3d_daq(
					(vec3_t*)a,
					(vec3_t*)b,
					(const vec3_t*)points,
					n_points);
			break;
		}

		struct timeval end;
		gettimeofday(&end, NULL);

		printf("Getting closest pair in the divide and conquer way\n");

		printf("a:");
		for (int i = 0; i < dimension; ++i) {
			printf(" %f", a[i]);
		}
		printf("\n");

		printf("b:");
		for (int i = 0; i < dimension; ++i) {
			printf(" %f", b[i]);
		}
		printf("\n");

		printf("min_distance: %f\n", min_distance);

		printf("elapsed time: %lf\n", ((end.tv_sec + end.tv_usec * 0.000001) - (start.tv_sec + start.tv_usec * 0.000001)));
	}


	free(points);

	return 0;
}

