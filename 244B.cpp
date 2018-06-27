#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int ans = 0;
	if(n > 99)
	{
		ans = 99;
		int bit__s[10] = {0};
		for(int i = 100;i <= n; ++i)
		{
			int p = i;
			memset(bit__s,0x00,sizeof(bit__s));
			while(p)
			{
				bit__s[p % 10] = 1;
				p /= 10;
			}
			int cnt = 0;
			for(int i = 0;i < 10; ++i)
			{
				cnt += bit__s[i];
			}
			if(cnt <= 2)
			{
				ans++;
			}
		}
	}
	else
	{
		ans = n;
	}
	printf("%d\n",ans);
	return 0;
}