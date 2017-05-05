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
	int n; cin >> n; int a[100]; for (int i = 0; i < n; i++)cin >> a[i]; sort(a, a + n); swap(a[0], a[n - 1]); for (int i = 0; i < n; i++)cout << a[i] << " ";
}