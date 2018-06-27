#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char s[100];
long long dp[55][10];
int main()
{
	cin>>s;
	int n = strlen(s);
	for(int i = 0;i <= 9; ++i)
	{
		dp[0][i] = 1;
	}
	for(int i = 1;s[i]; ++i)
	{
		int t = s[i] - '0';
		for(int j = 0;j < 10; ++j)
		{
			int l = (t + j) / 2,r = (t + j + 1) / 2;
			dp[i][l] += dp[i - 1][j];
			if(l != r)
			{
				dp[i][r] += dp[i - 1][j];
			}
		}
	}
	// for(int i = 1;s[i]; ++i)
	// {
	// 	for(int j = 0;j <= 9; ++j)
	// 	{
	// 		printf("%lld ",dp[i][j]);
	// 	}
	// 	cout<<endl;
	// }
	int flag = 0;
	for(int i = 1;s[i]; ++i)
	{
		int t = s[i] - '0';
		int j = s[i - 1] - '0';
		if(t != (j + t) / 2 && t != (j + t + 1) / 2)
		{
			flag = 1;
			break;
		}
	}
	long long ans = -1 + flag;
	for(int i = 0;i <= 9; ++i)
	{
		ans += dp[n - 1][i];
	}
	cout<<ans<<endl;
	return 0;
}