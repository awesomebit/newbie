////////////////////////////////////////////////
//���� ��ȣ : [TST] ���� Ż��
////////////////////////////////////////////////
#if 01
#include <stdio.h>

int N;
int arr[20 + 10][9 + 10];
int sum[9 + 10];
int sol = 0;

int input(int i, int j, int n)
{
	int num = n;
	while (n > 0)
	{
		arr[i][j] = num % 10;
		num /= 10;
		input(i, j + 1, num);
		return;
	}
}

int Check(int k)
{
	int i;
	for (i = 1; i < 10; i++)
	{
		if ((arr[k][i] + sum[i]) >= 10) return 1;
	}
	return 0;
}

void DFS(int n, int cnt)
{
	if (n > N)
	{
		if (sol < cnt)
		{
			sol = cnt;
		}
		return;
	}

	int i;

	if (Check(n) == 0)
	{
		for (i = 1; i <= 10; i++)
		{
			sum[i] += arr[n][i];
		}

		DFS(n + 1, cnt + 1);

		for (i = 1; i <= 10; i++)
		{
			sum[i] -= arr[n][i];
		}
	}

	DFS(n + 1, cnt);

}

void main(void)
{
	scanf("%d", &N);
	int i, j, n;
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &n);
		input(i, 1, n);
	}

	DFS(1, 0);

	printf("%d", sol);
}
#endif