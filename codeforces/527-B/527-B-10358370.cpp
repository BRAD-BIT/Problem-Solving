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
int a[26][200001];
int main()
{
    int n, sum = 0; string s, t; cin >> n >> s >> t; vector<int>v;
    for (int j = 0; j < n; j++)if (s[j] != t[j]){ sum++; v.push_back(j); }
    if (sum == 0||s==t){ cout << sum << endl << -1 << " " << -1 << endl; return 0; }
    int aa[26] = { 0 };
    for (int i = 0; i < n; i++)
    {
        if (t[i]!=s[i])
        {
            a[s[i] - 'a'][aa[s[i] - 'a']] = i;
            aa[s[i] - 'a']++;
        }
    }
    if (sum != 200000&&sum!=100000)
    {
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < aa[t[v[i]] - 'a']; j++)
            {
                if (t[a[t[v[i]] - 'a'][j]] == s[v[i]] && s[a[t[v[i]] - 'a'][j]] != t[a[t[v[i]] - 'a'][j]])
                {
                    cout << sum - 2 << endl << v[i] + 1 << " " << a[t[v[i]] - 'a'][j] + 1 << endl; return 0;
                }
            }
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < aa[t[v[i]] - 'a']; j++)
        {
            if (s[a[t[v[i]] - 'a'][j]] != t[a[t[v[i]] - 'a'][j]])
            {
                cout << sum - 1 << endl << v[i] + 1 << " " << a[t[v[i]] - 'a'][j] + 1 << endl;
                return 0;
            }
        }
    }
    cout << sum << endl << -1 << " " << -1 << endl;
}