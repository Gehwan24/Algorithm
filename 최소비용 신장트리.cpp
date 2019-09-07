#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#define MAX 9999


int main(void) {
	int edge[5][5] = { 0,  1,  3,MAX,MAX ,
						1,  0,  3,  6,MAX ,
						3,  3,  0,  4,  2,
					  MAX,  6,  4,  0,  5,
					  MAX,MAX,  2,  5,  0 };
	int nearest[5];
	int distance[5];
	for (int i = 1; i < 5; i++) {
		nearest[i] = 1;
		distance[i] = edge[0][i];
	}

}