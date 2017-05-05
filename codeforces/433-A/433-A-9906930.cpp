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
    int n, x, sum1 = 0, sum2 = 0; cin >> n;
    for (int i = 0; i < n; i++){ cin >> x; if (x == 100)sum1++; else sum2++; }
    if (sum1 == 0){ if (sum2 % 2 == 0)cout << "YES" << endl; else cout << "NO" << endl; }
    else
    if (sum2 == 0){ if (sum1 % 2 == 0)cout << "YES" << endl; else cout << "NO" << endl; }
    else
    if (((sum1*100 + sum2*200) / 100) % 2 == 0)cout << "YES" << endl;
    else cout << "NO" << endl;
}