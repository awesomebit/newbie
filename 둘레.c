#include <stdio.h>

typedef struct st
{
	int i, j;
}SET;
SET q[10000+10];
map[110][110];
chk[110][110];
int N;
int sol;

void function(void)
{
	int di[] = {-1,1,0,0};
	int dj[] = {0,0,-1,1};
	int ni, nj;
	int ti, tj;
	int k,l;
	for (l = 0; l<N; l++)
	{
		ti = q[l].i;
		tj = q[l].j;
		
		for (k=0;k<4;k++)
		{
			ni = ti + di[k];
			nj = tj + dj[k];
			
			if(ni<1||ni>N||nj<1||nj>N) continue;
			if (chk[ni][nj] == 1) continue;
					
			map[ni][nj]++;
		}
	}

	int x,y;
	for(y=1;y<=N;y++)
	{
		for(x=1;x<=N;x++)
		{
			sol += map[y][x];
		}
	}
}

void main(void)
{
	scanf("%d", &N);
	int i;
	for (i = 0; i<N; i++)
	{
		scanf("%d %d", &q[i].j, &q[i].i);
		chk[q[i].i][q[i].j] = 1;
	}

	function();
	printf("%d",sol);
}
