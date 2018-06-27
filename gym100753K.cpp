#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
bool check(string s)
{
	unsigned long long ret = 0;
	for(int i = 0;i < s.size(); ++i)
	{
		ret = ret * 10 + s[i] - '0';
	}
	if(ret < 2)
	{
		return 0;
	}
	if(ret == 2)
	{
		return 1;
	}
	for(int i = 2;i <= sqrt(ret); ++i)
	{
		if(ret % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	string s;
	cin>>s;
	string zh;
	for(int i = 0;i < s.size(); ++i)
	{
		if(s[i] == '9')
		{
			zh += '6';
			continue;
		}
		else if(s[i] == '6')
		{
			zh += '9';
			continue;
		}
		else if(s[i] == '3' || s[i] == '4' || s[i] == '7')
		{
			printf("no\n");
			return 0;
		}
		zh += s[i];
	}
	reverse(zh.begin(),zh.end());
	if(check(zh) && check(s))
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}
	return 0;
}