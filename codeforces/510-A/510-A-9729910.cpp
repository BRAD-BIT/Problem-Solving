#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
#include <bitset> 
#include<iomanip>
#include<vector>
#include<map>
#include<set>
using namespace std;
int main()
{
	int n, m, v = 0, c = 0;
	cin >> n >> m;
	while (n != 0)
	{
		if (v % 2 == 0)
		{
			for (int i = 0; i < m; i++)
			{
				cout << "#";
			}
			cout << endl;
		}
		else
		{
			if (c == 0)
			{
				for (int i = 0; i < m-1; i++)
				{
					cout << ".";
				}
				cout << "#" << endl;
				c = 1;
			}
			else
			if (c == 1)
			{
				cout << "#";
				for (int i = 0; i < m-1; i++)
				{
					cout << ".";
				}
				cout << endl;
				c = 0;
			}
		}
		n--;
		v++;
	}
}