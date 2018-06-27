#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string input;
	char a[n][n],temp[n][n];
	char ans[n][n];
	memset(ans,0x00,sizeof(ans));
	memset(a,0x00,sizeof(a));
	memset(temp,0x00,sizeof(temp));
	for(int i = 0;i < n; ++i)
	{
		for(int j = 0;j < n; ++j)
		{
			cin>>a[i][j];
		}
	}
	cin.ignore();
	cin>>input;
	int last_time = 4;
	int now_pos = 0;
	while(last_time--)
	{
		for(int i = 0;i < n; ++i)
		{
			for(int j = 0;j < n; ++j)
			{
				if(a[i][j] == '.')
				{
					if(ans[i][j] != 0)
					{
						printf("invalid grille\n");
						return 0;
					}
					ans[i][j] = input[now_pos++];
				}
			}
		}
		for(int i = 0;i < n; ++i)
		{
			for(int j = 0;j < n; ++j)
			{
				temp[i][j] = a[n - j - 1][i];
			}
		}
		memcpy(a,temp,sizeof(a));
	}
	for(int i = 0;i < n; ++i)
	{
		for(int j = 0;j < n; ++j)
		{
			if(ans[i][j] == 0)
			{
				printf("invalid grille\n");
				return 0;
			}
		}
	}
	for(int i = 0;i < n; ++i)
	{
		for(int j = 0;j < n; ++j)
		{
			printf("%c",ans[i][j]);
		}
	}
	printf("\n");
	return 0;
}