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
#include <iterator>
#include<list>
#include<stdio.h>
#include<fstream>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long
int main()
{
    ll a, b,sum=0; cin >> a >> b;
    while (a != b&&a!=0&&b!=0)
    {
        sum += a / b;
        a = a%b;
        if (a < b)swap(a, b);
    }
    cout << sum << endl;
}