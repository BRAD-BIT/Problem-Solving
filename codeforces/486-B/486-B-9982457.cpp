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
#include<list>
#include<stdio.h>
#include<fstream>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long
int m, n;  int a[100][100];
int or(int i, int j)
{
	for (int x = 0; x < n; x++)
	{
		if (a[i][x] == 1)return 1;
	}
	for (int x = 0; x < m; x++)
	{
		if (a[x][j] == 1)return 1;
	}
	return 0;
}
int main()
{
	cin >> m >> n; int b[100][100]; int c[100][100];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> c[i][j];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			a[i][j] = -1;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (c[i][j] == 0)
			{
				for (int x = 0; x < n; x++)
					a[i][x] = 0;
				for (int x = 0; x < m; x++)
					a[x][j] = 0;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] != 0)a[i][j] = 1;
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[i][j] = or(i, j);
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (b[i][j] != c[i][j]){ cout << "NO"; return 0; }
		}
	}
	cout << "YES" << endl;
	for (int i = 0; i < m; i++){ for (int j = 0; j < n; j++)cout << a[i][j] << " "; cout << endl; }
}