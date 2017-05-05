#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
#include <bitset> 
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include <stdio.h>
#include<fstream>
using namespace std;
int main()
{
    long long n, k, sum = 1, m = 0; string s; cin >> n >> k >> s; vector<long long> a;
    sort(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != s[i + 1]){a.push_back(sum); sum = 1; }
        else sum++;
    }
    int x = a.size() - 1; sum = 0;
    sort(a.begin(), a.end());
    while (k != 0)
    {
        k -= a[x];
        sum += (a[x]*a[x]);
        x--;
        if (k < 0)
        {
            x++;
            k += a[x];
            sum -= (a[x]*a[x]);
            sum += (k*k);
            k = 0;
        }
    }
    cout << sum << endl;
}