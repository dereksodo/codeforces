#include <iostream>
using namespace std;
const int maxn = 2e5 + 5;
long long sum[maxn],a[maxn];
/*
3 6
10 15 12
1 9 12 23 26 37
*/
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n; ++i)
	{
		cin>>a[i];
		sum[i] = a[i] + sum[i - 1];
	}
	while(m--)
	{
		long long k;
		cin>>k;
		long long pos = lower_bound(sum + 1,sum + n + 1,k) - sum - 1;
		printf("%lld %lld\n",pos + 1,k - sum[pos]);
	}
	return 0;
}