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
static const int maxn = 2005;
long long a[maxn];
//我们可以在ti和ci输入的时候就讲dp算好当前最少要付的钱。
//因为一秒钟可以偷一样物品，所以枚举j从n至0，把每一秒枚举出来
//dp[i]表示前i个最少付的钱
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	memset(a,0x3f3f3f3f,sizeof(a));
	a[0] = 0;//be careful
	for(int i = 0;i < n; ++i)
	{
		int t,c;
		cin>>t>>c;
		for(int j = n;j >= 0; --j)
		{
			int min_index = min(j + t + 1,n);
			a[min_index] = min(a[j] + c,a[min_index]);
		}
	}
	printf("%lld\n",a[n]);
	return 0;
}