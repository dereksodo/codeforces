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
int main(int argc, char const *argv[])
{
	int r1,r2,c1,c2,d1,d2;
	cin>>r1>>r2>>c1>>c2>>d1>>d2;
	for(int i = 1;i <= 9; ++i)
	{
		for(int j = 1;j <= 9; ++j)
		{
			for(int k = 1;k <= 9; ++k)
			{
				for(int m = 1;m <= 9; ++m)
				{
					if(i + j == r1 && i + k == c1 && j + m == c2 && k + m == r2
						&& j + k == d2 && i + m == d1
						&& i != j && i != k && i != m && j != k && j != m && k != m)
					{
						printf("%d %d\n%d %d\n",i,j,k,m);
						return 0;
					}
				}
			}
		}
	}
	printf("-1\n");
	return 0;
}