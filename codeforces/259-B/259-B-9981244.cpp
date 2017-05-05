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
int main()
{
	int a[3][3];
	for (int i = 0; i < 3; i++)for (int j = 0; j < 3; j++)cin >> a[i][j];
	int X = a[0][1] + a[0][2], Y = a[1][0] + a[1][2], Z = a[2][0] + a[2][1];
	a[0][0] = (Y + Z - X) / 2;
	a[1][1] = Z - a[0][0];
	a[2][2] = Y - a[0][0];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}