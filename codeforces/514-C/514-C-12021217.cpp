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
#include<string>
#include<cstdio>
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
#define PI         3.14159265358979323846
#define ll         long long
#define sz(v)      (ll)v.size()
#define ii         pair<ll,ll>
#define vii        vector<ii>
#define vi         vector<int>
#define vll        vector<ll>
#define vs         vector<string>
#define vvii       vector<vector<ii>>
#define vvi        vector<vector<int>>
#define vvll       vector<vector<ll>>
#define all(v)     v.begin(),v.end()
#define sc(n)      scanf("%d",&n)
#define pr2(n)     printf("%d " ,n)
#define pr1(n)     printf("%d\n",n)
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
using namespace std;
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
class TrieTree
{
    map<int, TrieTree*>child; int isleaf;
public:
    TrieTree(){ isleaf = 0; }
    void insert(char *str)
    {
        if (*str == '\0'){ isleaf = 1; return; }
        int i = *str - 'a';
        if (child[i] == 0)child[i] = new TrieTree();
        child[i]->insert(str + 1);
    }
    bool wordExist(char*str,int count)
    {
        if (*str == '\0')if (count<=0)return isleaf; else return false;
        int cur = *str - 'a';
        if (child[cur] == 0 && count<=0)return false;
        int ans = false;
        for (int i = 0; i < 3; i++)
        {
            if (child[i])
            {
                if (count - (cur != i) < 0)continue;
                ans |= child[i]->wordExist(str + 1, count-(cur!=i));
            }
        }
        return ans;
    }
};
char str[900010];
int main()
{
    TrieTree TT;
    int n, m; cin >> n >> m; 
    string s; getchar();
    for (int l = 0; l < n; l++)
    {
        gets(str);
        TT.insert(str);
    }
    for (int i = 0; i < m; i++)
    {
        gets(str);
        if (TT.wordExist(str,1))cout << "YES\n";
        else cout << "NO\n";
    }
}