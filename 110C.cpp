#include <iostream>
using namespace std;
void pr(int x,int y)
{
	while(x--)
	{
		printf("4");
	}
	while(y--)
	{
		printf("7");
	}
	printf("\n");
	exit(0);
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	//4x+7y=n
	for(int i = n / 7;i >= 0; --i)
	{
		if((n - 7 * i) % 4 == 0)
		{
			pr((n - 7 * i) / 4,i);
		}
	}
	printf("-1\n");
	return 0;
}