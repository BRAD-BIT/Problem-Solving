#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<sstream>
#include<stack>
#include<queue>
#include<bitset> 
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include <iterator>
#include<list>
#include<stdio.h>
#include<fstream>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long
struct conv{ string a, b; int t; };
int main()
{
	int n, d; cin >> n >> d; conv a[1001];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].a >> a[i].b >> a[i].t;
	}
	set<pair<string, string>> s;
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (a[i].a == a[j].b&&a[i].b == a[j].a)
			{
				if (a[j].t - a[i].t>0 && a[j].t - a[i].t <= d)
				{
					pair<string, string>x;
					if (a[i].a>a[i].b){ x.first = a[i].a; x.second = a[i].b; }else{ x.first = a[i].b; x.second = a[i].a; }
					s.insert(x);
				}
			}
		}
	}
	cout << s.size() << endl;
	for (set<pair<string, string>>::iterator it = s.begin(); it != s.end(); it++){ pair<string, string>x; x = *it; cout << x.first << " " << x.second << endl; }
}