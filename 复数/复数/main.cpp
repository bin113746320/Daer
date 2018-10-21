//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct complex
//{
//	int real;//实部
//	int imag;//虚部
//}COMPLEX;
//
//COMPLEX operator + (COMPLEX, COMPLEX);
//COMPLEX operator - (COMPLEX, COMPLEX);
//COMPLEX operator * (COMPLEX, COMPLEX);
//
//void show(COMPLEX);
//
//int main()
//{
//	COMPLEX complex1, complex2,result;
//	char  I1, I2;
//	scanf("%d%d%c", &complex1.real, &complex1.imag, &I1);
//	scanf("%d%d%c", &complex2.real, &complex2.imag, &I2);
//	result = complex1 + complex2;
//	printf("复数相加结果：");
//	show(result);
//	result = complex1 - complex2;
//	printf("复数相减结果：");
//    show(result);
//	result = complex1 * complex2;
//	printf("复数相乘结果：");
//	show(result);
//	system("pause");
//	return 0;
//}
//
//COMPLEX operator + (COMPLEX complex1, COMPLEX complex2)
//{
//	COMPLEX result;
//	result.real = complex1.real + complex2.real;
//	result.imag = complex1.imag + complex2.imag;
//	return result;
//}
//
//COMPLEX operator - (COMPLEX complex1, COMPLEX complex2)
//{
//	COMPLEX result;
//	result.real = complex1.real - complex2.real;
//	result.imag = complex1.imag - complex2.imag;
//	return result;
//}
//
//COMPLEX operator * (COMPLEX complex1, COMPLEX complex2)
//{
//	COMPLEX result;
//	result.real = complex1.real*complex2.real-complex1.imag*complex2.imag;
//	result.imag = complex1.real*complex2.imag + complex1.imag*complex2.real;
//	return result;
//}
//
//void show(COMPLEX complex)
//{
//	if (complex.real == 0)
//	{
//		if (complex.imag != 0)
//		{
//			if (complex.imag == 1)
//			{
//				printf("%c\n",'i');
//			}
//			else if (complex.imag == -1)
//			{
//				printf("%c\n",'i');
//			}
//			else
//			    printf("%di\n", complex.imag);
//		}
//		else
//		{
//			printf("%d\n",0);
//		}
//	}
//	else
//	{ 
//		printf("%d", complex.real);
//		if (complex.imag != 0)
//		{
//			if (complex.imag>0)
//			{
//				if (complex.imag == 1)
//				{
//					printf("%c%c\n",'+','i');
//				}
//				else
//				   printf("%c%di\n", '+',complex.imag);
//			}
//			else
//			{
//				if (complex.imag == -1)
//				{
//					printf("%c%c\n",'-','i');
//				}
//				else
//				   printf("%di\n", complex.imag);
//			}
//		}
//		else
//		{
//			printf("\n");
//		}
//	}
//}



//#include <stdio.h>
////#include <stdlib.h>
////
////typedef struct complex
////{
////	int real;//实部
////	int imag;//虚部
////}COMPLEX;
////
////COMPLEX PLUS(COMPLEX, COMPLEX);
////COMPLEX MINUS (COMPLEX, COMPLEX);
////COMPLEX MULTI (COMPLEX, COMPLEX);
////COMPLEX DIVIDE(COMPLEX, COMPLEX);
////
////void show(COMPLEX);
////
////int main()
////{
////	COMPLEX complex1, complex2,result;
////	char  I1, I2;
////	scanf("%d%d%c", &complex1.real, &complex1.imag, &I1);
////	scanf("%d%d%c", &complex2.real, &complex2.imag, &I2);
////	result = PLUS(complex1, complex2);;
////	printf("复数相加结果：");
////	show(result);
////	result = MINUS(complex1, complex2);
////	printf("复数相减结果：");
////    show(result);
////	result = MULTI(complex1, complex2);
////	printf("复数相乘结果：");
////	show(result);
////	result = DIVIDE(complex1, complex2);
////	printf("复数相除结果：");
////	show(result);
////	system("pause");
////	return 0;
////}
////
////COMPLEX PLUS(COMPLEX complex1, COMPLEX complex2)
////{
////	COMPLEX result;
////	result.real = complex1.real + complex2.real;
////	result.imag = complex1.imag + complex2.imag;
////	return result;
////}
////
////COMPLEX MINUS(COMPLEX complex1, COMPLEX complex2)
////{
////	COMPLEX result;
////	result.real = complex1.real - complex2.real;
////	result.imag = complex1.imag - complex2.imag;
////	return result;
////}
////
////COMPLEX MULTI(COMPLEX complex1, COMPLEX complex2)
////{
////	COMPLEX result;
////	result.real = complex1.real*complex2.real-complex1.imag*complex2.imag;
////	result.imag = complex1.real*complex2.imag + complex1.imag*complex2.real;
////	return result;
////}
////
////COMPLEX DIVIDE(COMPLEX complex1, COMPLEX complex2)
////{
////	COMPLEX result;
////	result.real = (complex1.real*complex2.real + complex1.imag*complex2.imag) / (complex2.real*complex2.real + complex2.imag*complex2.imag);
////	result.imag = (complex1.imag*complex2.real - complex1.real*complex2.imag) / (complex2.real*complex2.real + complex2.imag*complex2.imag);
////	return result;
////}
////
////
////
////void show(COMPLEX complex)
////{
////	if (complex.real == 0)
////	{
////		if (complex.imag != 0)
////		{
////			if (complex.imag == 1)
////			{
////				printf("%c\n",'i');
////			}
////			else if (complex.imag == -1)
////			{
////				printf("%c\n",'i');
////			}
////			else
////			    printf("%.2fi\n", double(complex.imag));
////		}
////		else
////		{
////			printf("%.2f\n",0);
////		}
////	}
////	else
////	{ 
////		printf("%.2f", double(complex.real));
////		if (complex.imag != 0)
////		{
////			if (complex.imag>0)
////			{
////				if (complex.imag == 1)
////				{
////					printf("%c%c\n",'+','i');
////				}
////				else
////				   printf("%c%.2fi\n", '+',double(complex.imag));
////			}
////			else
////			{
////				if (complex.imag == -1)
////				{
////					printf("%c%c\n",'-','i');
////				}
////				else
////					printf("%.2fi\n", double(complex.imag));
////			}
////		}
////		else
////		{
////			printf("\n");
////		}
////	}
////}

#include <stdio.h>
#include <stdlib.h>

typedef struct complex
{
	double real;//实部
	double imag;//虚部
}COMPLEX;

COMPLEX PLUS(COMPLEX, COMPLEX);
COMPLEX MINUS(COMPLEX, COMPLEX);
COMPLEX MULTI(COMPLEX, COMPLEX);
COMPLEX DIVIDE(COMPLEX, COMPLEX);

void show(COMPLEX);

int main()
{
	COMPLEX complex1, complex2, result;
	
	scanf("%lf%lf", &complex1.real, &complex1.imag);
	scanf("%lf%lf", &complex2.real, &complex2.imag);
	result = PLUS(complex1, complex2);;
	printf("复数相加结果：");
	show(result);
	result = MINUS(complex1, complex2);
	printf("复数相减结果：");
	show(result);
	result = MULTI(complex1, complex2);
	printf("复数相乘结果：");
	show(result);
	result =  DIVIDE(complex1, complex2);
	printf("复数相除结果：");
	show(result);
	system("pause");
	return 0;
}

COMPLEX PLUS(COMPLEX complex1, COMPLEX complex2)
{
	COMPLEX result;
	result.real = complex1.real + complex2.real;
	result.imag = complex1.imag + complex2.imag;
	return result;
}

COMPLEX MINUS(COMPLEX complex1, COMPLEX complex2)
{
	COMPLEX result;
	result.real = complex1.real - complex2.real;
	result.imag = complex1.imag - complex2.imag;
	return result;
}

COMPLEX MULTI(COMPLEX complex1, COMPLEX complex2)
{
	COMPLEX result;
	result.real = complex1.real*complex2.real - complex1.imag*complex2.imag;
	result.imag = complex1.real*complex2.imag + complex1.imag*complex2.real;
	return result;
}

COMPLEX DIVIDE(COMPLEX complex1, COMPLEX complex2)
{
	COMPLEX result;
	result.real = (complex1.real*complex2.real + complex1.imag*complex2.imag) / (complex2.real*complex2.real + complex2.imag*complex2.imag);
	result.imag = (complex1.imag*complex2.real - complex1.real*complex2.imag) / (complex2.real*complex2.real + complex2.imag*complex2.imag);
	return result;
}



void show(COMPLEX complex)
{
	if (complex.real == 0)
	{
		if (complex.imag != 0)
		{
			if (complex.imag == 1)
			{
				printf("%c\n", 'i');
			}
			else if (complex.imag == -1)
			{
				printf("%c%c\n", '-','i');
			}
			else
				printf("%.2fi\n", complex.imag);
		}
		else
		{
			printf("%.2f\n", 0);
		}
	}
	else
	{
		printf("%.2f", complex.real);
		if (complex.imag != 0)
		{
			if (complex.imag>0)
			{
				if (complex.imag == 1)
				{
					printf("%c%c\n", '+', 'i');
				}
				else
					printf("%c%.2fi\n", '+',complex.imag);
			}
			else
			{
				if (complex.imag == -1)
				{
					printf("%c%c\n", '-', 'i');
				}
				else
					printf("%.2fi\n", complex.imag);
			}
		}
		else
		{
			printf("\n");
		}
	}
}
