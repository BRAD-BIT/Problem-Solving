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
struct interval{ int a, b; };
int visited[307] = { 0 };
bool test = false;
int counter = 1;
void Connected(int from, int to)
{
    if (from == to){ test = true; return; }
    visited[from] = counter;
    for (int i = 0; i < graph[from].size(); i++)
    {
        int child = graph[from][i];
        if (visited[child] != counter)Connected(child, to);
    }
}
int main()
{
    vector<interval>VI;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int c; interval d; cin >> c;
        if (c == 1)
        {
            cin >> d.a >> d.b;
            vector<int>temp;
            for (int j = 0; j < VI.size(); j++)
            {
                if ((VI[j].a>d.a&&VI[j].a<d.b) || (VI[j].b>d.a&&VI[j].b < d.b))graph[j].push_back(graph.size());
                if ((d.a>VI[j].a&&d.a<VI[j].b) || (d.b>VI[j].a&&d.b < VI[j].b))temp.push_back(j);
            }
            VI.push_back(d);
            graph.push_back(temp);
        }
        else
        {
            cin >> d.a >> d.b;
            test = false;
            counter++;
            Connected(d.a - 1, d.b - 1);
            if (test)cout << "YES" << endl; else cout << "NO" << endl;
        }
    }
}