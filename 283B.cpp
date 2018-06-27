#include <iostream>
#include <cstring>
#include <cstdlib>
#include <set>
#include <vector>
#include <map>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
using namespace std;
static const int maxn = 2e5 + 5;
int a[maxn];
int n;
map<long long,bool> mp;
long long x,y;
#pragma GCC optimize(2)
#define DEBUG
long long dp()
{
	long long ret = 0;
	while(1)
	{
		if(x <= 0 || x > n){
			ret = y;
			break;
		}
		if(mp[x]){
			ret = -1;
			break;
		}
		mp[x] = 1;
		y += a[x],x += a[x];
		if(x <= 0 || x > n){
			ret = y;
			break;
		}
		if(x < a[x]){
			ret = y + a[x];
			break;
		}
		y += a[x],x -= a[x];
	}
	return ret;
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	#ifdef DEBUG
		freopen("in.txt","r",stdin);
		// freopen("out.txt","w",stdout);
	#endif
	clock_t time1 = clock();
	scanf("%d",&n);
	for(int i = 2;i <= n; ++i)
	{
		scanf("%d",a + i);
	}
	for(int i = 1;i <= n - 1; ++i)
	{
		mp.clear();
		a[1] = i;
		x = 1,y = 0;
		// cout<<dp()<<endl;
		dp();
	}
	clock_t time2 = clock();
	printf("%f seconds",(double)(time2 - time1) / CLOCKS_PER_SEC);
	return 0;
}