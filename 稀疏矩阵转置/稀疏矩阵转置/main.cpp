#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//#define Size  30
typedef struct node
{
	int row;
	int col;
	ElemType element;
}Node;

void Assignment(int i, int j, ElemType x , Node* data)
{
	data->row = i;
	data->col = j;
	data->element = x;
}

void Transposite(Node* data)
{
	int temp;
	temp =data->row;
	data->row = data->col;
	data->col = temp;
}

void Sort(Node* data)
{
	Node temp;
	for (int i = 0; i < 7 - 1; i++)
	{
		for (int j = 0; j < 7 - 1 - i; j++)
		{
			if (data[j].row>data[j + 1].row)
			{
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
			if (data[j].row==data[j + 1].row)
			{
				if (data[j].col > data[j + 1].col)
				{
					temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
				}
			}
		}
	}
}

void Show(Node* data)
{
	printf("%d %d %d\n",data->row,data->col,data->element);
}

int main()
{
	Node* arr = (Node*)malloc(sizeof(Node)*7);
	Assignment(0, 0, -5, &arr[0]);
	Assignment(0, 1, -2, &arr[1]);
	Assignment(1, 3, -6, &arr[2]);
	Assignment(3, 1, -3, &arr[3]);
	Assignment(4, 0, -7, &arr[4]);
	Assignment(4, 3, -4, &arr[5]);
	Assignment(5, 2, -1, &arr[6]);

	for (int i = 0; i < 7;i++)
	{
		Show(&arr[i]);
	}

	printf("×ªÖÃºó:\n");
	for (int i = 0; i < 7; i++)
	{
		Transposite(&arr[i]);
	}
	
	Sort(arr);

	for (int i = 0; i < 7; i++)
	{
		Show(&arr[i]);
	}
	system("pause");
	return 0;
}