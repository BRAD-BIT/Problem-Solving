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
    ll n, s1 = 0, s2 = 0, s3 = 0, x; cin >> n;
    for (int i = 0; i < n; i++){ cin >> x; s1 += x; }
    for (int i = 0; i < n-1; i++){ cin >> x; s2 += x; }
    for (int i = 0; i < n-2; i++){ cin >> x; s3 += x; }
    cout << s1 - s2 << endl << s2 - s3 << endl;
}