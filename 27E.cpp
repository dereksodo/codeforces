#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1005;
int main()
{
	freopen("in.txt","w",stdout);
	bool vis[maxn];
	memset(vis,0x00,sizeof(vis));
	int ans_cnt = 0,cnt;
	vis[1] = 1;
	printf("long long a[] = {1");
	long long p = 2;
	for(long long i = 2;i <= 1e18; i += 2)
	{
		cnt = 0;
		for(long long j = 1;j <= i; ++j)
		{
			if(i % j == 0)
			{
				cnt++;
			}
		}
		if(!vis[cnt])
		{
			vis[cnt] = 1;
			printf(",%lld",i);
			ans_cnt++;
		}
		if(ans_cnt == 1000)
		{
			break;
		}
		fflush(stdout);
	}
	printf("};");
	return 0;
}