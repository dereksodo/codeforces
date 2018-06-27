#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 100005;
int a[maxn];
void ex(int a)
{
	printf("%d\n",a);
	exit(0);
}
bool check(int a)
{

}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int lastsum = 0;
	bool flag = 1;
	int difff = 0;
	int sum = 0;
	for(int i = 0;i < n; ++i)
	{
		cin>>a[i];
		if(i > 0)
		{
			int newsum = a[i] - a[i - 1];
			if(abs(newsum - lastsum) > 2)
			{
				flag = 0;
			}
			lastsum = newsum;
			difff += newsum;
		}
		sum += a[i];
	}
	if(!flag)
	{
		ex(-1);
	}
	int maxsum = sum + n - 1;
	int minsum = sum - n + 1;
	int maxx = difff + n - 1;
	int minn = difff - n + 1;
	while(minn + 1 < maxx)
	{
		int mid = (minn + maxx) / 2;
		if(check(mid))
		{
			ex(0);
		}
	}
	return 0;
}