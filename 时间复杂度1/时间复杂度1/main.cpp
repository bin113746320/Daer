#include <stdio.h>
#include <stdlib.h>

#define n 100

int main()
{
	int i = 1, k = 0;//i���ڼ���
	do
	{
		k = k + 10 * i;
		i++;
	} while (i <= n);
	printf("��һ���ִ�д�����%d\n", i);

	int j = 1, x = 0;//x���ڼ���
	do
	{
		x++;
		j = 3 * j;
	} while (j<n);
	printf("�ڶ����ִ�д�����%d\n", x);

	int a[n][n];
	int count = 0;//count���ڼ���
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			a[i][j] = 0;
			count++;
		}
	}
	printf("�������ִ�д�����%d\n", count);

	int y = 0;
	while (n >= y*y)
	{
		y++;
	}
	printf("�������ִ�д�����%d\n",y);
	getchar();
	return 0;
}