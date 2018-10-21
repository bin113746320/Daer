#include <stdio.h>
#include <stdlib.h>

#define n 100

int main()
{
	int i = 1, k = 0;//i用于计数
	do
	{
		k = k + 10 * i;
		i++;
	} while (i <= n);
	printf("第一题的执行次数：%d\n", i);

	int j = 1, x = 0;//x用于计数
	do
	{
		x++;
		j = 3 * j;
	} while (j<n);
	printf("第二题的执行次数：%d\n", x);

	int a[n][n];
	int count = 0;//count用于计数
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			a[i][j] = 0;
			count++;
		}
	}
	printf("第三题的执行次数：%d\n", count);

	int y = 0;
	while (n >= y*y)
	{
		y++;
	}
	printf("第四题的执行次数：%d\n",y);
	getchar();
	return 0;
}