#include <stdio.h>

typedef struct {
	int coef;		//계수
	char variable;
	int degree;
}mono;	//단항에 대한 구조체

typedef struct {
	int count; //항의 개수
	mono arr[10];
}poly;

int max(int a, int b)
{
	if (a >= b) return a;
	else return b;
}

int main(void)
{
	poly f = { 3, { { 5, 'y', 1000}, {3, 'y', 100}, {4, 'y', 6} } };
	poly g = { 4, { { 3, 'y', 99}, {4, 'y', 50}, {6, 'y', 6}, {5, 'y', 0} } };
	poly result;
	result.count = 0;

	int i = 0, j = 0;
	while ((i < f.count) && (j < g.count))
	{
		if (f.arr[i].degree > g.arr[j].degree)		//더 큰 차수를 가지고 있는걸 result에 추가 (f의 차수가 더 큰경우)
		{
			result.arr[i + j] = f.arr[i];
			result.count++;
			i++;
		}
		else if (g.arr[j].degree > f.arr[i].degree)	//더 큰 차수를 가지고 있는걸 result에 추가 (g의 차수가 더 큰경우)
		{
			result.arr[i + j] = g.arr[j];
			result.count++;
			j++;
		}
		else //차수가 같아서 계수를 더하는 경우
		{
			mono temp = { f.arr[i].coef + g.arr[j].coef, f.arr[i].variable, f.arr[i].degree };
			result.arr[i + j] = temp;
			result.count++;
			i++; j++; 
		}
	}
	//남은 다항식 추가
	if (i < f.count)
	{
		for (int k = i; k < f.count; k++)
		{
			result.arr[k + j] = f.arr[k];
			result.count++;
		}
	}
	if (j < g.count)
	{
		for (int k = j; k < g.count; k++)
		{
			result.arr[k + (i - 1)] = g.arr[k];
			result.count++;
		}
	}

	//result 출력
	for (int p = 0; p < result.count; p++)
	{
		printf("%d%c^%d + ", result.arr[p].coef, result.arr[p].variable, result.arr[p].degree);
	}
	printf("\b\b\b   ");

	return 0;
}