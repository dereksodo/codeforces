#include <iostream>
using namespace std;
static const int maxn = 20;
bool vis[maxn];
int a[maxn];
int ret = 0;
int n;
bool is_ok(int a,int b,int c)
{
	return (a + b) > c && (a + c) > b && (b + c) > a;
}
void dfs(int tri)
{
	ret = max(ret,tri);
	if(n - tri < 3)
	{
		return;
	}
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
				if(is_ok(a[i],a[j],a[k]))
				{
					vis[i] = vis[j] = vis[k] = 1;
					dfs(tri + 1);
					vis[i] = vis[j] = vis[k] = 0;
				}
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	cin>>n;
	for(int i = 0;i < n; ++i)
	{
		cin>>a[i];
	}
	dfs(0);
	printf("%d\n",ret);
	return 0;
}