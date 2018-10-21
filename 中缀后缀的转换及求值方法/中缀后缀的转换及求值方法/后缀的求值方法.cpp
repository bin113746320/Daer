#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

typedef double ElemType;

typedef struct stack
{
	ElemType element;
	struct stack * next;
}Stack;

void Init(Stack* top)
{
	top->next = NULL;
}

void Push(Stack* top, ElemType data)
{
	Stack* temp = (Stack*)malloc(sizeof(Stack));
	temp->element = data;
	temp->next = top->next;
	top->next = temp;
}

bool IsEmpty(Stack* top)
{
	return top->next == NULL;
}

bool Top(Stack* top, ElemType *data)
{
	if (IsEmpty(top))
	{
		return false;
	}
	*data=top->next->element;
	return true;
}

bool Top(Stack* top, char *data)
{
	if (IsEmpty(top))
	{
		return false;
	}
	*data = top->next->element;
	return true;
}

void Pop(Stack* top)
{
	Stack* p;
	p = top->next;
	top->next = p->next;
	free(p);
}

void Show(Stack* top)
{
	Stack* p;
	p = top->next;
	while (p)
	{
		printf("%d ", p->element);
		p = p->next;
	}
	printf("\n");
}

void Destroy(Stack* top)
{
	Stack* p;
	while (top->next)
	{
		p = top->next;
		top->next = p->next;
		free(p);
	}
}

int icp(char c)
{
	int priority;
	switch (c)
	{
	case '+':
	case '-':
		priority = 2;
		break;
	case '*':
	case '/':
		priority = 4;
		break;
	case '^':
		priority = 6;
		break;
	case '(':
		priority = 8;
		break;
	case ')':
		priority = 1;
		break;
	case '#':
		priority = 0;
		break;
	}
	return priority;
}

int isp(char c)
{
	int priority;
	switch (c)
	{
	case '+':
	case '-':
		priority = 3;
		break;
	case '*':
	case '/':
		priority = 5;
		break;
	case '^':
		priority = 7;
		break;
	case '(':
		priority = 1;
		break;
	case ')':
		priority = 8;
		break;
	case '#': 
		priority = 0;
		break;
	}
   return priority;
}

void InfixToPostfix(Stack* S)
{
	char ch, y;
	Push(S,'#');
	ch = getchar();
	while (ch!='#')
	{
		if (isdigit(ch) || isalpha(ch))
		{
			//Push(S_1,ch);
			//Push(S_1,' ');
			printf("%c", ch);
		}
		else if (ch==')')
		{
			for (Top(S, &y), Pop(S); y != '('&&!IsEmpty(S); Top(S, &y), Pop(S))
			{
				printf("%c", y);
			}
			printf(" ");
		}
		else
		{	
			for (Top(S, &y), Pop(S); icp(ch) <= isp(y); Top(S, &y), Pop(S))
			{
				printf("%c", y);
			}
			printf(" ");
			Push(S, y);
			Push(S, ch);

			//Push(S_1,' ');
			//Push(S_1,y);
			//Push(S_1, ch);
		}
		ch = getchar();
	}
	while (!IsEmpty(S))
	{
		Top(S,&y);
		Pop(S);
		if (y != '#')
		{
			printf("%c", y);
		}
	}
	printf("#\n");
}

bool GetOperands(Stack *S, double *op1, double *op2)
{
	if (!Top(S, op1))
	{
		printf("Missing oeprand!");
		return false;
	}
	Pop(S);
	if (!Top(S, op2))
	{
		printf("Missing oeprand!");
		return false;
	}
	Pop(S);
	return true;
}

void DoOperator(Stack *s,char oper)
{
	bool result;
	double oper1, oper2;
	result = GetOperands(s, &oper1, &oper2);
	if (!result)
	{
		Destroy(s);//Clear(s);
	}
	else
	{
		switch (oper)
		{
		case '+':
			Push(s, oper2 + oper1);
			break;
		case '-':
			Push(s, oper2 - oper1);
			break;
		case '*':
			Push(s, oper2*oper1);
			break;
		case '/':
			if (fabs(oper1)<1e-6)
			{
				printf("Divide by 0!\n");
				Destroy(s);
			}
			else
			{
				Push(s, oper2 / oper1);
			}
			break;
		case '^':
			Push(s, pow(oper2, oper1));
			break;
		}
	}
}

int main()
{
	Stack *stack = (Stack*)malloc(sizeof(Stack));
	//Stack* S_1 = (Stack*)malloc(sizeof(Stack));
	char c;
	double newop;
	Init(stack);
	//Init(S_1);
	InfixToPostfix(stack);
//	Top(S_1,&c);
//	Pop(S_1);
	c = getchar();
	while (c != '#')
	{
		switch (c)
		{
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
			DoOperator(stack, c);
			break; 
		case ' ':
			break;
		default:
			ungetc(c, stdin);
			scanf("%d", &c);
			Push(stack, c);
		}
		c = getchar();
		/*Top(S_1, &c);
		Pop(S_1);*/
	}
	if (Top(stack, &newop))
		printf("%f", newop);
	Destroy(stack);
	system("pause");
	return 0;
}
