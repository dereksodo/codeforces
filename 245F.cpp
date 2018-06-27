#include <iostream>
#include <cstring>
using namespace std;
static const int maxn = 5e6 + 5;
long long a[maxn];
string p_out[maxn];
int month[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
void doit()
{
	for(int i = 1;i <= 12; ++i){
		month[i] += month[i - 1];
	}
}
#define zh(x,y) (month[x - 1] + y) * 1ll
int main(int argc, char const *argv[])
{
	doit();
	int n,m;
	cin>>n>>m;
	cin.ignore();
	int p1,p2,p3,p4,p5,p6;
	string s;
	int cnt = 0;
	while(getline(cin,s) && s.size()){
		p_out[++cnt] = s.substr(0,19);
		sscanf(s.c_str(),"%d-%d-%d %d:%d:%d",&p1,&p2,&p3,&p4,&p5,&p6);
		a[cnt] = zh(p2,p3) * 24 * 3600ll + p4 * 3600ll + p5 * 60ll + p6 * 1ll;
	}
	for(int i = 1;i < cnt; ++i){
		long long next_prev = a[i] + n - 1;
		int c = 1;
		for(int j = i + 1;j < cnt; ++j){
			if(next_prev >= a[j] && c < m){
				c++;
			}else{
				break;
			}
		}
		if(c >= m){
			printf("%s\n",p_out[i + c - 1].c_str());
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}