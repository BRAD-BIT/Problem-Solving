#include<iostream>
#include<string>
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
	int m, x, y, sum = 0; cin >> m; int *a = new int[m]; for (int i = 0; i < m; i++){ cin >> a[i]; sum += a[i]; }cin >> x >> y;
	for (int i = 0; i < m; i++)
	{
		int sum1 = 0, sum2 = 0;
		for (int d = 0; d < i; d++)sum1 += a[d]; for (int s = m - 1; s >= i; s--)sum2 += a[s];
		if ((sum1 >= x&&sum1 <= y) && (sum2 >= x&&sum2 <= y)){ cout << i + 1 << endl; return 0; }
	}
	cout << 0 << endl;
}