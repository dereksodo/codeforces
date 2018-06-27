#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int cnt = 0;
	int ans = 0;
	for(int i = 0;i < s.size(); ++i)
	{
		if(cnt == 3)
		{
			ans++;
			cnt--;
		}
		if(s[i] == 'x')
		{
			cnt++;
		}
		else
		{
			cnt = 0;
		}
	}
	if(cnt == 3)
	{
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}