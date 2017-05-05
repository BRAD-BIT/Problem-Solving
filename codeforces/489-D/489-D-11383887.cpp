#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<iterator>
#include<cmath>
#include<string>
#include<sstream>
#include<cstring>
#include<ctype.h>
#include<iomanip>
#include<functional>
#include<bitset>
#include<stdio.h>
#include<fstream>
#include<regex>
#include<stdlib.h>
#include<math.h>
#include<ctime>
#include<array>
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
#define PI         3.14159265358979323846
#define ll         long long
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
using namespace std;
vector<vector<int>>graph; int a[3007][3007];
int main()
{
	int n, m; cin >> n >> m;memset(a, 0, sizeof a);
	graph.resize(n); ll sum = 0, ans = 0;
	for (int i = 0; i < m; i++){ int from, to; cin >> from >> to; graph[from - 1].push_back(to - 1); a[from - 1][to - 1] = 1; }
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)if (i != j){
			sum = 0;
			for (int k = 0; k < graph[i].size(); k++)if (a[graph[i][k]][j])sum++;
			ans+= sum * (sum - 1) / 2;
		}
	}
	cout << ans << endl;
}