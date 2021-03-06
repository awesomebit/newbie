#include <stdio.h>

int T;
int N;
int sol = 0;

int a[] = { 0, 1, 2, 4, 8, 16, 32, 64};

void DFS(int n, int sum)
{
	if (sum > N) return;

	if (sum == N)
	{
		sol++;
		return;
	}

	for (; n <= 7; n++)
	{
		DFS(n, sum + a[n]);
	}
}

void main(void)
{
	scanf("%d", &T);
	int i, j, n;
	for (i = 0; i < T; i++)
	{
		scanf("%d", &N);

		sol = 0;
		DFS(1, 0);
		printf("%d\n", sol);
	}
}
