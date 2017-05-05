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
#include<list>
#include <stdio.h>
#include<fstream>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long
struct ass{ int score; string name; };
bool comp(ass a, ass b)
{
    return a.score < b.score;
}
int main()
{
    int n; cin >> n; vector<ass> v; ass max; max.score = 0; ass *a = new ass[n]; for (int i = 0; i < n; i++){ cin >> a[i].name >> a[i].score; }
    for (int i = 0; i < n; i++)
    {
        int sum = 0; bool test = true;
        for (int j = 0; j < v.size(); j++)
        {
            if (v[j].name == a[i].name){ v[j].score += a[i].score; test = false; }
        }
        if (test){ ass d; d.name = a[i].name; d.score = a[i].score; v.push_back(d); }
    }
    for (int z = 0; z < v.size(); z++){ if (max.score < v[z].score)max.score = v[z].score; }
    vector<ass> v2;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (v[i].score == max.score){ v2.push_back(v[i]); }
    }
    vector<ass> v3;
    for (int i = 0; i < n; i++)
    {
        int sum = 0; bool test = true;
        for (int j = 0; j < v3.size(); j++)
        {
            if (v3[j].name == a[i].name){ v3[j].score += a[i].score; test = false; }
        }
        if (test){ ass d; d.name = a[i].name; d.score = a[i].score; v3.push_back(d); }
        sort(v3.begin(), v3.end(), comp);
        ass max2; max2.score = v3[v3.size() - 1].score; max2.name = v3[v3.size() - 1].name;
        if (max2.score >= max.score)
        {
            for (int c = 0; c < v2.size(); c++)
            {
                if (max2.name == v2[c].name){ cout << max2.name << endl; return 0; }
            }
        }
    }
}