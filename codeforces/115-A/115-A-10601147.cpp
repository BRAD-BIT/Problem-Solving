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
vector<int>Max;
vector<vector<int>>graph;
void FindMAXheight(int node,int height)
{
    for (int i = 0; i < graph[node].size(); i++)
    {
        int child = graph[node][i];
        FindMAXheight(child,height+1);
    }
    Max.push_back(height);
}
int main()
{
    int n; cin >> n;
    graph= vector<vector<int>>(n+1);
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if (x != -1)graph[x].push_back(i + 1); else graph[0].push_back(i + 1);
    }
    FindMAXheight(0,0);
    sort(Max.begin(), Max.end());
    cout << Max[Max.size() - 1]  << endl;
}