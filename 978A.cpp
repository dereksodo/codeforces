#include <iostream>
#include <vector>
using namespace std;
const int maxn = 55;
const int maxnn = 1005;
int vis[maxnn],a[maxn];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		cin>>a[i];
		vis[a[i]]++;
	}
	vector<int> v;
	for(int i = n;i >= 1; --i)
	{
		if(vis[a[i]] >= 1)
		{
			vis[a[i]] = 0;
			v.push_back(a[i]);
		}
	}
	cout<<v.size()<<endl;
	for(int i = v.size() - 1;i >= 0; --i)
	{
		printf("%d ",v[i]);
	}
	cout<<endl;
	return 0;
}