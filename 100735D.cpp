#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
static const int maxn = 20;
bool vis[maxn];
int main()
{
	int n;
	cin>>n;
	vector<int> a;
	for(int i = 0;i < n; ++i)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	int ans = 0;
	for(int i = 0;i < n; ++i)
	{
		for(int j = i + 1;j < n; ++j)
		{
			for(int k = j + 1;k < n; ++k)
			{
				if(vis[i] || vis[j] || vis[k])
				{
					continue;
				}
				if(a[i] + a[j] > a[k])
				{
					ans++;
					vis[i] = 1;
					vis[j] = 1;
					vis[k] = 1;
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}