////////////////////////////////////////////////
//문제 번호 : [TST]보물섬
////////////////////////////////////////////////
#if 01
#include <stdio.h>

typedef struct st
{
	int i, j, d;
}Q_t;

Q_t q[50*50 + 10];

int N, M;
char a[50 + 10][50 + 10];
int map[50 + 10][50 + 10];
int chk[50 + 10][50 + 10];
int sol = 0;
int wp, rp;

void print(void)
{
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			printf("%d", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void reset(void)
{
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			chk[i][j] = 0;
		}
	}

	for (i = 1; q[i].i != 0; i++)
	{
		q[i].i = 0;
		q[i].j = 0;
		q[i].d = 0;
	}
	wp = 0;
	rp = 0;
}

int BFS(int i, int j)
{
	int di[] = { -1, 1, 0, 0 };
	int dj[] = { 0, 0, -1, 1 };
	int ni, nj, nd;
	int ti, tj, td;

	q[wp].i = i;
	q[wp].j = j;
	q[wp++].d = 0;
	chk[i][j] = 1;

	while (wp > rp)
	{
		ti = q[rp].i;
		tj = q[rp].j;
		td = q[rp++].d;

		int k;
		for (k = 0; k < 4; k++)
		{
			ni = ti + di[k];
			nj = tj + dj[k];
			nd = td + 1;

			if (ni < 1 || ni > N || nj < 1 || nj > M) continue;
			if (chk[ni][nj] == 1 || map[ni][nj] == 0) continue;

			q[wp].i = ni;
			q[wp].j = nj;
			q[wp++].d = nd;
			chk[ni][nj] = 1;
		}
	}
	return td;
}


void main(void)
{
	scanf("%d %d", &N, &M);
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			scanf(" %c", &a[i][j]);
			if (a[i][j] == 'W')
			{
				map[i][j] = 0;
			}
			else if (a[i][j] == 'L')
			{
				map[i][j] = 1;
			}
		}
	}

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			if (map[i][j] == 1)
			{
				int temp;
				temp = BFS(i, j);
				if (sol < temp)
				{
					sol = temp;
				}
				//print();
				reset();
			}
		}
	}
	printf("%d", sol);
}

#endif