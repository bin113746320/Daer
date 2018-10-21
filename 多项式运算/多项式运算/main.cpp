#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int coef;//系数
	int exp;//指数
	struct node* next;
}Node, *pNode;

void Create(pNode head);
void Add(pNode head1, pNode head2);
void Minue(pNode head1, pNode head2);
void Show(pNode head);
void Destroy(pNode head);

int main()
{
	pNode head1 = (pNode)malloc(sizeof(Node));
	Create(head1);
	Show(head1);

	pNode head2 = (pNode)malloc(sizeof(Node));
	Create(head2);
	Show(head2);
	int choice;
	printf("输入运算法则：(加——1 减——2)");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
		Add(head1, head2);
		printf("相加后：\n");
		Show(head1);
		break;
	case 2:
		Minue(head1, head2);
		printf("相减后：\n");
		Show(head1);
	}

	Destroy(head1);
	Destroy(head2);

	system("pause");
	return 0;
}

void Create(pNode head)
{
	pNode pn, pre,q;
	head->next = NULL;
	head->exp = -1;
	head->coef = 0;
	for (;;)
	{
		pn = (pNode)malloc(sizeof(Node));
		printf("coef:");
		scanf("%d", &pn->coef);
		printf("exp:");
		scanf("%d",&pn->exp);
		pre = head;
		q = head->next;
		if (pn->exp < 0) break;
		while (q&&q->exp>pn->exp)
		{
			pre = q;
			q = q->next; 
		}
		pn->next = q;
		pre->next = pn;
	}
}

void Add(pNode head1, pNode head2)
{
	pNode p, q,temp1,temp2;
	p = head1;
	q = head2;
	while (q->next)
	{
		while (p->next!=NULL&&p->next->exp>q->next->exp)
		{
			p = p->next;
		}
		if (p->next != NULL && p->next->exp == q->next->exp)
		{
			p->next->coef = p->next->coef + q->next->coef;
			if (p->next->coef==0)
			{	
				temp1 = p->next;
				p->next = temp1->next;
				q = q->next;
			}
			else
			{
				p = p->next;
				q = q->next;
			}
		}
		else if (p->next == NULL)
		{
			p->next = q->next;
			break;
		}
		else
		{
			temp2 = q->next;
			q->next = temp2->next;
			temp2->next = p->next;
			p->next = temp2;
		}
	}
}

void Minue(pNode head1, pNode head2)
{
	pNode p, q, temp1, temp2;
	p = head1;
	q = head2;
	while (q->next)
	{
		while (p->next != NULL&&p->next->exp>q->next->exp)
		{
			p = p->next;
		}
		if (p->next != NULL && p->next->exp == q->next->exp)
		{
			p->next->coef = p->next->coef - q->next->coef;
			if (p->next->coef== 0)
			{
				temp1 = p->next;
				p->next = temp1->next;
				q = q->next;
			}
			else
			{
				p = p->next;
				q = q->next;
			}
		}
		else if (p->next == NULL)
		{
			p->next = q->next;
			break;
		}
		else
		{
			temp2 = q->next;
			q->next = temp2->next;
			temp2->next = p->next;
			p->next = temp2;
		}
	}
}

void Show(pNode head)
{
	pNode temp;
	temp = head->next;
	while (temp!=NULL)
	{
		printf("系数：%d 次幂：%d\n",temp->coef,temp->exp);
		temp = temp->next;
	}
}

void Destroy(pNode head)
{
	pNode temp = head->next;
	while (head->next != NULL)
	{
		pNode p;
		p = temp->next;
		free(temp);
		temp = p;
		head->next = p;
	}
	free(head);
}
