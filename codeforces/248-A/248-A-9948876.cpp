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
	int n, r, l, sumL0 = 0, sumL1=0, sumR0 = 0, sumR1 = 0; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> r >> l;
		if (r == 1)sumR1++; else sumR0++;
		if (l == 1)sumL1++; else sumL0++;
	}
	cout << min(sumL1, sumL0) + min(sumR1, sumR0) << endl;
}