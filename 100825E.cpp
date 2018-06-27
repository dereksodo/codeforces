#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
static const int maxn=105;
vector<int> G[maxn];
long long vis[maxn];
long long vis2[maxn];
int n,m,s,t;
long long doit()
{
	memset(vis2,0x00,sizeof(vis2));
	long long ret = 0;
	for(int i = 0;i < n; ++i)
	{
		if(vis[i])
		{
			for(int j = 0;j < G[i].size(); ++j)
			{
				vis2[G[i][j]] += vis[i];
				ret += vis[i];
			}
		}
	}
	memcpy(vis,vis2,sizeof(vis));
	return ret;
}
int main()
{	
	cin>>n>>m>>s>>t;
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	if(!t)
	{
		printf("0\n");
		return 0;
	}
	vis[s] = 1;
	long long sum = 0;
	t--;
	while(t--)
	{
		doit();
	}
	printf("%lld\n",doit());
	return 0;
}