#include <iostream>
using namespace std;
long long n,m;
long long k,res;
#define left lllll
#define right rrrrr
long long lesss(long long x)
{
	long long ret = 0;
	for(int i = 1;i <= n; ++i)
	{
		ret += min((long long)(m),x / i);
	}
	return ret;
}
int main()
{
	cin>>n>>m>>k;
	long long left = 1,right = (long long)(n) * m;
	while(left <= right)
	{
		long long mid = (left + right) >> 1ll;
		// printf("left = %lld,right = %lld,mid = %lld\n",left,right,mid);
		if(lesss(mid) >= k)
		{
			res = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout<<res<<endl;
	return 0;
}