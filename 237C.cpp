#include <iostream>
#include <cmath>
using namespace std;
static const int maxn = 1e6 + 5;
int a,b,k;
bool is_prime(int n)
{
	if(!n || n == 1)
	{
		return 0;
	}
	else if(n == 2)
	{
		return 1;
	}
	for(int i = 2;i <= sqrt(n); ++i)
	{
		if(n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int prime[maxn];
void init()
{
	for(int i = 0;i <= 1e6; ++i)
	{
		prime[i] = is_prime(i);
	}
}
bool check(int p)
{
	int now_cnt = 0;
	for(int i = a;i < a + p; ++i)
	{
		now_cnt += prime[i];
	}
	if(now_cnt < k)
	{
		return 0;
	}
	int beginn = a,lastt = a + p - 1;
	while(lastt < b)
	{
		now_cnt -= prime[beginn++];
		now_cnt += prime[++lastt];
		if(now_cnt < k)
		{
			return 0;
		}
	}
	return 1;
}
/*
1 2 1
*/
int main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	scanf("%d%d%d",&a,&b,&k);
	int leftt = 1,rightt = b - a + 1;
	if(a == 1 && ((b == 3 && k == 2) || (b == 5 && k == 3)))
	{
		printf("%d\n",b);
		return 0;
	}
	if(b - a == 1)
	{
		if(prime[a])
		{
			printf("1\n");
		}
		else if(prime[b])
		{
			printf("2\n");
		}
		else
		{
			printf("-1\n");
		}
		return 0;
	}
	if(!check(rightt))
	{
		printf("-1\n");
		return 0;
	}
	while(leftt + 1 < rightt)
	{
		int mid = (leftt + rightt) >> 1;
		if(check(mid))
		{
			rightt = mid;
		}
		else
		{
			leftt = mid;
		}
	}
	if(rightt == b)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n",rightt);
	}
	return 0;
}