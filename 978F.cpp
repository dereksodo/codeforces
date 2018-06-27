#include <iostream>
#include <vector>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
int sum[maxn];
int s[maxn];
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n; ++i)
	{
		cin>>a[i];
	}
	for(int i = 1;i <= n; ++i)
	{
		for(int j = i + 1;j <= n; ++j)
		{
			if(a[i] > a[j])
			{
				s[i]++;
			}
			else if(a[i] < a[j])
			{
				s[j]++;
			}
		}
	}
	for(int i = 0;i < m; ++i)
	{
		int x,y;
		cin>>x>>y;
		if(s[x] > s[y])
		{
			s[x]--;
		}
		else if(s[x] < s[y])
		{
			s[y]--;
		}
	}
	for(int i = 1;i <= n; ++i)
	{
		printf("%d ",s[i]);
	}
	cout<<endl;
	return 0;
}