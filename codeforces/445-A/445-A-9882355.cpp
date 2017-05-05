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
#include<list>
#include <stdio.h>
#include<fstream>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long
int main()
{
	int n, m; cin >> n >> m; char x;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> x; 
			if (x == '-')cout << '-';
			else
			{
				if (i % 2 == 0){ if (j % 2 == 0)cout << 'B'; else cout << 'W'; }
				else { if (j % 2 == 0)cout << 'W'; else cout << 'B'; }
			}
		}
		cout << endl;
	}
}