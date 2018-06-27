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
static const int maxn = 2005;
bool input[maxn][maxn];
int sum[maxn];
int sum2[maxn];
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	cin.ignore();
	for(int i = 1;i <= n; ++i)
	{
		string s;
		getline(cin,s);
		for(int j = 1;j <= m; ++j)
		{
			input[i][j] = s[j - 1] - '0';
			sum[j] += input[i][j];
			sum2[j] = sum[j];
		}
	}
	for(int i = 1;i <= n; ++i)
	{
		memcpy(sum2,sum,sizeof(sum));
		bool flag = 1;
		for(int j = 1;j <= m; ++j)
		{
			sum2[j] -= input[i][j];
			if(!sum2[j])
			{
				flag = 0;
				break;
			}
		}
		if(flag)
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}