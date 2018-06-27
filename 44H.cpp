#include <iostream>
#include <cstring>
#include <set>
using namespace std;
string input,now;
long long ans = 0;
void dfs(int v)
{
	if(v == input.size() - 1)
	{
		if(now != input)
		{
			ans++;
		}
		return;
	}
	int k = (now[v] - '0') + (input[v + 1] - '0');
	int t = k / 2;
	int ss = (k + 1) / 2;
	++v;
	long long ans = 0;
	if(t != ss)
	{
		now += (char)(t + '0');
		dfs(v);
		now = now.substr(0,now.size() - 1);
	}
	now += (char)(ss + '0');
	dfs(v);
	now = now.substr(0,now.size() - 1);
}
int main(int argc, char const *argv[])
{
	cin>>input;
	for(int i = 0;i <= 9; ++i)
	{
		now = (char)i + '0';
		dfs(0);
	}
	printf("%lld\n",ans);
	return 0;
}