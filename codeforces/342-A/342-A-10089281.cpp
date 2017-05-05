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
    int n, x; cin >> n; int a[8] = { 0 };
    for (int i = 0; i < n; i++){ cin >> x; a[x]++;}
    if (a[1]!=n/3||a[5]!=0||a[7]!=0||(a[2]!=a[4]+a[6]-a[3])||(a[3]>a[6])){ cout << -1 << endl; return 0; }
    while (a[3] != 0){ cout << "1 3 6" << endl; a[3]--; a[6]--; }
    while (a[4] != 0){ cout << "1 2 4" << endl; a[4]--; }
    while (a[6] != 0){ cout << "1 2 6" << endl; a[6]--; }
}