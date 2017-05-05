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
    int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11 }; int n, sum = 0,m=0; cin >> n;
    for (int i = 0; i < 11; i++){ if (a[i] + 10 == n){ if (a[i] == 10)sum += 15; else sum += 4; } }cout << sum << endl;
}