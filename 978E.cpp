#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 1005;
int a[maxn];
int main()
{
	int n,w;
	cin>>n>>w;
	for(int i = 0;i < n; ++i)
	{
		cin>>a[i];
	}
	int minn = 0;
	int maxx = w;
	int minn2 = minn - 1,maxx2 = maxx + 1;
	bool flag = 0;
	while(minn2 <= w)
	{
		flag = 0;
		minn2++;
		minn = minn2;
		for(int i = 0;i < n; ++i)
		{
			if(minn + a[i] < 0 || minn + a[i] > w)
			{
				flag = 1;
				break;
			}
			minn += a[i];
		}
		if(flag)
		{
			continue;
		}
		else
		{
			break;
		}
	}
	flag = 0;
	while(maxx2 >= 0)
	{
		flag = 0;
		maxx2--;
		maxx = maxx2;
		for(int i = 0;i < n; ++i)
		{
			if(maxx + a[i] > w || maxx + a[i] < 0)
			{
				flag = 1;
				break;
			}
			maxx += a[i];
		}
		if(flag)
		{
			continue;
		}
		else
		{
			break;
		}
	}
	printf("%d\n",max(0,maxx2 - minn2 + 1));
	return 0;
}