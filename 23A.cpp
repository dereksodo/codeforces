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
using namespace std;
string s;
int main(int argc, char const *argv[])
{
	getline(cin,s);
	int ans = 0;
	for(int len = 1;len < s.size(); ++len)
	{
		for(int i = 0;i < s.size() - len + 1; ++i)
		{
			int cnt = 1;
			for(int j = i + 1;j < s.size() - len + 1; ++j)
			{
				if(s.substr(j,len) == s.substr(i,len))
				{
					++cnt;
				}
			}
			if(cnt >= 2)
			{
				ans = max(ans,len);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}