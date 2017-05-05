#include<algorithm>
#include<stdlib.h>
#include<iterator>
#include<iostream>
#include<numeric>
#include<sstream>
#include<cstring>
#include<ctype.h>
#include<iomanip>
#include<stdio.h>
#include<fstream>
#include<vector>
#include<bitset>
#include<string>
#include<math.h>
#include<queue>
#include<stack>
#include<cmath>
#include<set>
#include<map>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long
int main()
{
	int n, x = 0, y; cin >> n; string a[] = { "Sheldon", "Leonard", "Penny", "Rajesh", "Howard" };
	while (5 * (pow(2.000, x) - 1) < n){ x++; }
	n = n - 5 * (pow(2.000, x - 1) - 1); y = pow(2.000, x - 1); x = 0;
	while (n>0){ n -= y; x++; }
	cout << a[x-1] << endl;
}