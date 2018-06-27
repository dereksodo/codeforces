#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
static const int maxn = 105;
char s[maxn][maxn];
int output[maxn][maxn];
static const int dx[] = {-1,0,0,1};
static const int dy[] = {0,1,-1,0};
int n,m;
// #define DEBUG
void f()
{
	for(int i = 2;i < n + 2; ++i)
	{
		for(int j = 2;j < m + 2; ++j)
		{
			if(i == 2 || j == 2 || i == n + 1 || j == m + 1)
			{
				output[i][j] = 1;
				continue;
			}
			int minx = 10000000;
			bool flag = 0;
			for(int cnt = 0;cnt < 4; ++cnt)
			{
				int x = i + dx[cnt],y = j + dy[cnt];
				if(s[x][y] == '.')
				{
					output[i][j] = 1;
					flag = 1;
					break;
				}
				else
				{
					minx = min(minx,output[x][y]);
				}
			}
			if(!flag)
			{
				output[i][j] = minx + 1;
			}
		}
	}
}
int main()
{
	#ifdef DEBUG
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	cin>>n>>m;
	memset(s,0x01,sizeof(s));
	int maxnn = -1;
	for(int i = 2;i < n + 2; ++i)
	{
		for(int j = 2;j < m + 2; ++j)
		{
			cin>>s[i][j];
		}
	}
	memset(output,0x3f3f3f,sizeof(output));
	for(int i = 1;i < 101; ++i)
	{
		f();
	}
	for(int i = 2;i < n + 2; ++i)
	{
		for(int j = 2;j < m + 2; ++j)
		{
			maxnn = max(maxnn,output[i][j]);
		}
	}
	if(maxnn < 10)
	{
		for(int i = 2;i < n + 2; ++i)
		{
			for(int j = 2;j < m + 2; ++j)
			{
				if(s[i][j] == '.')
				{
					printf("..");
				}
				else if(output[i][j])
				{
					printf(".%d",output[i][j]);
				}
			}
			printf("\n");
		}
	}
	else
	{
		for(int i = 2;i < n + 2; ++i)
		{
			for(int j = 2;j < m + 2; ++j)
			{
				if(s[i][j] == '.')
				{
					printf("...");
				}
				else if(output[i][j])
				{
					if(output[i][j] < 10)
					{
						printf(".");
					}
					printf(".%d",output[i][j]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}