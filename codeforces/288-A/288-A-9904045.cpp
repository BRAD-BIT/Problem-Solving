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
    int n, k; cin >> n >> k;
    if (k > n || (n != 1&&k==1)){ cout << -1 << endl; return 0; }
    if (n == 1){ cout << 'a' << endl; return 0; }
    char sum = 97;
    for (int i = 0; i < n-(k-2); i++)
    {
        if (i % 2 == 0)cout << 'a';
        else cout << 'b';
    }
    sum = 99;
    for (int i = n - (k - 2); i < n; i++)
    {
        cout << sum; sum++;
    }
}