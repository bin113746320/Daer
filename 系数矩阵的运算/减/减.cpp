#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

static int length1 = 7;
static int length2 = 7;
typedef struct node
{
	int row;
	int col;
	ElemType element;

}Node;

void Assignment(int i, int j, ElemType x, Node* data)
{
	data->row = i;
	data->col = j;
	data->element = x;
}

void Transposite(Node* data)
{
	int temp;
	temp = data->row;
	data->row = data->col;
	data->col = temp;
}

void Sort(Node* data)
{
	Node temp;
	for (int i = 0; i < length1 - 1; i++)
	{
		for (int j = 0; j < length1 - 1 - i; j++)
		{
			if (data[j].row>data[j + 1].row)
			{
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
			if (data[j].row == data[j + 1].row)
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

void subtract(Node* arr, Node* Arr)
{
	for (int i = 0; i < length1; i++)
	{
		int k = 0;
		for (int j = 0; j < length2; j++)
		{
			if ((arr[i].col == Arr[j].col) && (arr[i].row == Arr[j].row))
			{
				arr[i].element -= Arr[j].element;
				if (arr[i].element == 0)
				{
					for (int t = i; t < length1 - 1; t++)
					{
						arr[t] = arr[t + 1];
					}
					length1--;
				}
				for (int t = j; t < length2 - 1; t++)
				{
					Arr[t] = Arr[t + 1];
				}
				k++;
				length2--;
				break;
			}
		}
	}
	
	//(Node*)realloc(arr, sizeof(Node)*length2);
	for (int x = 7, y = 0; y<length2; x++, y++)
	{
		Arr[y].element = -Arr[y].element;
		arr[x] = Arr[y];
	}
	length1 += length2;
}

void Show(Node* data)
{
	printf("%d %d %d\n", data->row, data->col, data->element);
}

int main()
{
	Node* arr = (Node*)malloc(sizeof(Node)* length1);
	Node* Arr = (Node*)malloc(sizeof(Node)* length2);
	Assignment(0, 0, -5, &arr[0]);
	Assignment(0, 1, -2, &arr[1]);
	Assignment(1, 3, -6, &arr[2]);
	Assignment(3, 1, -3, &arr[3]);
	Assignment(4, 0, -7, &arr[4]);
	Assignment(4, 3, -4, &arr[5]);
	Assignment(5, 2, -1, &arr[6]);

	Assignment(0, 0, 6, &Arr[0]);//0,0,-5  001
	Assignment(0, 1, 3, &Arr[1]);//0,4,-7  
	Assignment(1, 3, 7, &Arr[2]);//1,0,-2  134
	Assignment(3, 1, 4, &Arr[3]);//1,3,-3  31-2
	Assignment(4, 0, 8, &Arr[4]);//2,5,-1
	Assignment(4, 3, 5, &Arr[5]);//3,1,-6
	Assignment(5, 2, 2, &Arr[6]);//3,4,-4

	printf("矩阵1:\n");
	for (int i = 0; i < length1; i++)
	{
		Show(&arr[i]);
	}

	printf("转置后:\n");
	for (int i = 0; i < length1; i++)
	{
		Transposite(&arr[i]);
	}

	Sort(arr);

	for (int i = 0; i < length1; i++)
	{
		Show(&arr[i]);
	}

	printf("矩阵2:\n");
	for (int i = 0; i < length2; i++)
	{
		Show(&Arr[i]);
	}
	printf("相加后:\n");

	(Node*)realloc(arr, sizeof(Node)* 7);
	subtract(arr, Arr);
	for (int i = 0; i < length1; i++)
	{
		Show(&arr[i]);
	}
	printf("排序后:\n");
	Sort(arr);
	for (int i = 0; i < length1; i++)
	{
		Show(&arr[i]);
	}
	system("pause");
	return 0;
}