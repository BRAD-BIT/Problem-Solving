#include<algorithm>
#include<stdlib.h>
#include<iterator>
#include<iostream>
#include<numeric>
#include<sstream>
#include<cstring>
#include<ctype.h>
#include<iomanip>
#include<stdio.h>
#include<fstream>
#include<vector>
#include<bitset>
#include<string>
#include<math.h>
#include<queue>
#include<stack>
#include<cmath>
#include<set>
#include<map>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long
vector<vector<int>>graph;
vector<int>now;
vector<int>wanted;
vector<int>picked;
void Flips(int node, int oper1, int oper2, int level)
{
    if (level % 2 == 0)
    {
        if (oper1 == 1)
        {
            if (now[node] != wanted[node])now[node] == wanted[node];
            else{ oper1 = 0; picked.push_back(node + 1); }
        }
        else
        {
            if (now[node] != wanted[node]){ now[node] == wanted[node]; oper1 = 1; picked.push_back(node + 1); }
        }
    }
    else
    {
        if (oper2 == 1)
        {
            if (now[node] != wanted[node])now[node] == wanted[node];
            else{ oper2 = 0; picked.push_back(node + 1); }
        }
        else
        {
            if (now[node] != wanted[node]){ now[node] == wanted[node]; oper2 = 1; picked.push_back(node + 1); }
        }
    }
    for (int i = 0; i < graph[node].size(); i++)
    {
        int child = graph[node][i];
        Flips(child, oper1, oper2, level + 1);
    }
}
int main()
{
    int n; cin >> n;
    graph = vector<vector<int>>(n);
    vector<pair<int, int>>VP;
    set<int>ss;
    for (int i = 0; i < n - 1; i++)
    {
        pair<int, int>d; cin >> d.first >> d.second; ss.insert(d.first); VP.push_back(d);
    }
    for (int i = 0; i < n - 1; i++)
    {
        int to, from;
        if (ss.size() == n - 1){ from = VP[i].second; to = VP[i].first; }else{ from = VP[i].first; to = VP[i].second; }
        graph[from - 1].push_back(to - 1);
    }
    for (int i = 0; i < n; i++){ int a; cin >> a; now.push_back(a); }
    for (int i = 0; i < n; i++){ int a; cin >> a; wanted.push_back(a); }
    Flips(0, 0, 0, 0);
    cout << picked.size() << endl;
    for (int i = 0; i < picked.size(); i++)cout << picked[i] << endl;
}