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
bool test(string s, int k)
{
    for (int i = 0; i <= k; i++)
    {
        bool test = true;
        for (int j = 0; j < s.length(); j++)
        {
            int x = s[j] - 48;
            if (x == i){ test = false; }
        }
        if (test)return false;
    }
    return true;
}
int main()
{
    int n, k, sum = 0; cin >> n >> k; string x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (test(x, k))sum++;
    }
    cout << sum << endl;
}