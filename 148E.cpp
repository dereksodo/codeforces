#include <iostream>
#include <cstring>
#include <cstdlib>
#include <set>
#include <vector>
#include <map>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
using namespace std;
static const int maxn1 = 100;
int sum[maxn1 + 5],sumDP[maxn1 + 5],dp[maxn1 * maxn1 + 5];
//在输入的时候，可以算出每一层的花瓶的前缀和，接着再用一个循环来枚举在这一层选的个数，中间
//再定义一个数组来保存当前架子上选1～n的最大和，最后用一个全局数组dp来保存从第一个架子
//到现在这一个架子选m个的最大价值
//dp[i]表示选n - i个时最大的值
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	for(int i = 0;i < n; ++i)
	{
		int t;
		cin>>t;
		for(int j = 1;j <= t; ++j)
		{
			int p;
			cin>>p;
			sum[j] = sum[j - 1] + p;//前缀和
		}
		for(int j = 1;j <= t; ++j)
		{
			sumDP[j] = 0;
			for(int k = 0;k <= j; ++k)
			{
				sumDP[j] = max(sum[k] + sum[t] - sum[t - j + k],sumDP[j]);
				//在这个架子上选j个的最大值
			}
		}
		for(int j = 1;j <= m; ++j)
		{
			for(int k = 1;k <= min(j,t); ++k)
			{
				dp[j - k] = max(dp[j - k],dp[j] + sumDP[k]);
				//在以前输入的所有价值选j-k个的最大值
			}
		}
	}
	printf("%d\n",dp[0]);
	return 0;
}