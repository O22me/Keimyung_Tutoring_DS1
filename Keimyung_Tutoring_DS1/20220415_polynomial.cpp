#include <stdio.h>

typedef struct {
	int coef;		//���
	char variable;
	int degree;
}mono;	//���׿� ���� ����ü

typedef struct {
	int count; //���� ����
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
		if (f.arr[i].degree > g.arr[j].degree)		//�� ū ������ ������ �ִ°� result�� �߰� (f�� ������ �� ū���)
		{
			result.arr[i + j] = f.arr[i];
			result.count++;
			i++;
		}
		else if (g.arr[j].degree > f.arr[i].degree)	//�� ū ������ ������ �ִ°� result�� �߰� (g�� ������ �� ū���)
		{
			result.arr[i + j] = g.arr[j];
			result.count++;
			j++;
		}
		else //������ ���Ƽ� ����� ���ϴ� ���
		{
			mono temp = { f.arr[i].coef + g.arr[j].coef, f.arr[i].variable, f.arr[i].degree };
			result.arr[i + j] = temp;
			result.count++;
			i++; j++; 
		}
	}
	//���� ���׽� �߰�
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

	//result ���
	for (int p = 0; p < result.count; p++)
	{
		printf("%d%c^%d + ", result.arr[p].coef, result.arr[p].variable, result.arr[p].degree);
	}
	printf("\b\b\b   ");

	return 0;
}