#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
string s;
int main()
{
	cin>>s;
	vector<int> u[26];
	for(int i = 0;i < s.size(); ++i)
	{
		u[s[i] - 'a'].push_back(i);
	}
	int lastt = -1,ans = 1;
	cin>>s;
	for(int i = 0;i < s.size(); ++i)
	{
		int t = s[i] - 'a';
		if(u[t].empty())
		{
			printf("-1\n");
			return 0;
		}
		vector<int>::iterator iter = lower_bound(u[t].begin(),u[t].end(),lastt + 1);
		if(iter == u[t].end())
		{
			ans++;
			lastt = u[t].front();
		}
		else
		{
			lastt = *iter;
		}
	}
	printf("%d\n",ans);
	return 0;
}