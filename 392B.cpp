#include <iostream>
using namespace std;
int t[4][4];
long long dp[47][4][4];
int main()
{
	for(int i = 1;i <= 3; ++i)
	{
		for(int j = 1;j <= 3; ++j)
		{
			cin>>t[i][j];
		}
	}
	int n;
	cin>>n;
	for(int k = 1;k <= n; ++k)
	{
		for(int i = 1;i <= 3; ++i)
		{
			for(int j = 1;j <= 3; ++j)
			{
				if(i != j)
				{
					long long a = dp[k - 1][i][6 - i - j] + dp[k - 1][6 - i - j][j] + t[i][j];
					long long b = dp[k - 1][i][j] + t[i][6 - i - j] + dp[k - 1][j][i] + t[6 - i - j][j] + dp[k - 1][i][j];
					dp[k][i][j] = min(a,b);
				}
			}
		}
	}
	printf("%lld\n",dp[n][1][3]);
	return 0;
}