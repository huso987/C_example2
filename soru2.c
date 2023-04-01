#include<stdio.h>
#include <limits.h>
#include <stdlib.h>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int largestRectangleArea(int *heights, int heightsSize){
  int i, j, k, max = 0;
	int *stack = malloc(sizeof(int) * heightsSize);
	int top = -1;

	for (i = 0; i < heightsSize; i++) {
		if (top == -1 || *(heights+i) >= *(heights+*(stack+top))) {
			*(stack+(++top)) = i;
		} else {
			while (top != -1 && *(heights+i) < *(heights+*(stack+top))) {
				int h = *(heights+*(stack+(top--)));
				int w = (top == -1) ? i : (i - *(stack+top) - 1);
				max = (max < h * w) ? h * w : max;
			}
			*(stack+(++top)) = i;
		}
	}

	while (top != -1) {
		int h = *(heights+*(stack+(top--)));
		int w = (top == -1) ? i : (i - *(stack+top) - 1);
		max = (max < h * w) ? h * w : max;
	}

	free(stack);
	return max;
}


int main()
{ 
  int heSize;
  printf("Heightsize= ");
  scanf("%d",&heSize);
  int Heightss[heSize];
  printf("******************************\n");
  for (int i = 0; i < heSize; i++)
  {
    printf("%d ci elemanı gir:",i+1);
    scanf("%d",&Heightss[i]);
  }
  printf("alan:%d birimdir\n",largestRectangleArea(&Heightss,heSize));
   return 0;
}
