#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int Comp(const void* a, const void* b)
{
	return ((int**)a)[0][0] - ((int**)b)[0][0];
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize)
{
	int ans = 0;
	int i = 0;
	int j = 0;
	int tmpMax = 0;
	int* dp = NULL;

	if(NULL == intervals || intervalsSize <= 0) {
		return 0;
	}

	qsort(intervals, intervalsSize, sizeof(intervals[0]), Comp);
	dp = (int*)malloc(sizeof(int) * intervalsSize);
	if(dp == NULL) {
		return 0;
	}
	memset(dp, 0, sizeof(int) * intervalsSize);
	dp[0] = 1;

	for(i = 1; i < intervalsSize; i++) {
		for(j = 0; j < i; j++) {
			if(intervals[j][1] <= intervals[i][0]) {
				tmpMax = (tmpMax < dp[j]) ? dp[j] : tmpMax;
			}
		}
		dp[i] = tmpMax + 1;
		tmpMax = 0;
	}

	tmpMax = 0;
	for(i = 0; i < intervalsSize; i++) {
		tmpMax = (tmpMax < dp[i]) ? dp[i] : tmpMax;
	}

	return intervalsSize - tmpMax;
}

