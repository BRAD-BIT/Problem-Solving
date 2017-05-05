//In the name of Allah
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
#include<stdlib.h>
#include<math.h>
#include<ctime>
#include<string>
#include<cstdio>
#include<locale>
#include<codecvt>
using namespace std;
#define lop(i,a,n) for(int i=a;i<n;++i)
#define loop(i,n,a)for(int i=n-1;i>=a;--i)
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("in.txt"),W_("out.txt")
#define ll         long long
#define ld         long double
#define ii         pair<ll,ll>
#define vii        vector<ii>
#define vi         vector<int>
#define vll        vector<ll>
#define vs         vector<string>
#define vvii       vector<vector<ii>>
#define vvi        vector<vector<int>>
#define vvll       vector<vector<ll>>
#define sz(v)      (ll)v.size()
#define all(v)     v.begin(),v.end()
#define sc(n)      scanf("%d",&n)
#define scl(n)     scanf("%lld",&n)
#define pr1(n)     printf("%d\n",n)
#define pr2(n)     printf("%d " ,n)
#define pr3(n)     cout<<fixed<<setprecision(9)<<n<<endl
#define endl       "\n"
#define PI         2*acos(0.0)
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
#define EPS 1e-9
int dr[] = { 1, 0, -1, 0, -1, -1, 1, 1 };
int dc[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
const int MAX = 1e2 + 7;
const int MOD = 1e9 + 7;
string s1, s2, virus;
int mem[MAX][MAX][MAX];
vi Z;
int Z_table[26][MAX];
void Z_Algrothim()
{
    for (int len = 0; len <virus.length(); ++len)
    {
        for (int k = 0; k < 26; ++k) 
        {
            string temp = virus + '@' + virus.substr(0, len) + char('A' + k);
            int n = temp.length();
            Z.resize(n); Z.assign(n, 0); Z[0] = n;
            for (int i = 1, L = 0, R = 0; i < n; i++)
            {
                if (i <= R)Z[i] = min(Z[i - L], R - i + 1);
                while (i + Z[i]<n&&temp[Z[i]] == temp[i + Z[i]])Z[i]++;
                if (i + Z[i] - 1>R)L = i, R = i + Z[i] - 1;
            }
            lop(i, virus.length() + 1, temp.length())
            {
                if (Z[i] == temp.length() - i)
                {
                    Z_table[k][len] =max(Z[i], Z_table[k][len]); break;
                }
            }
        }
    }
}
int LCS(int i, int j, int k)
{
    if (i == s1.length() || j == s2.length())return  mem[i][j][k] = 0;
    if (mem[i][j][k] != -1)return mem[i][j][k];
    mem[i][j][k] = 0;
    if (s1[i] == s2[j])
    {
        if (virus[k] == s1[i]){
            if (k + 1 == virus.length());
            else mem[i][j][k] = max(LCS(i + 1, j + 1, k + 1) + 1, mem[i][j][k]);
        }
        else {
            mem[i][j][k] = max(LCS(i + 1, j + 1, Z_table[s1[i] - 'A'][k]) + 1, mem[i][j][k]);
        }
        return mem[i][j][k] = max(LCS(i + 1, j + 1, k), mem[i][j][k]);
    }
    return  mem[i][j][k]=max(LCS(i + 1, j, k), LCS(i, j + 1, k));
}
string print_LCS()
{
    memset(mem, -1, sizeof mem);
    cin >> s1 >> s2 >> virus;
    Z_Algrothim();
    LCS(0, 0, 0);
    int i = 0, j = 0, k = 0;
    string ans;
    while (i < s1.length() && j < s2.length())
    {
        if (s1[i] == s2[j])
        {
            if (!(mem[i + 1][j + 1][k]>mem[i + 1][j + 1][k+1]&&mem[i + 1][j + 1][k]>mem[i + 1][j + 1][Z_table[s1[i]-'A'][k]]))
            {
                if (virus[k] == s1[i])
                {
                    if (k + 1 != virus.length()) { ans += s1[i]; i++, j++, k++; } else break;
                }
                else { ans += s1[i]; i++, j++; k = Z_table[s1[i - 1] - 'A'][k]; }
            }
            else i++, j++;
        }
        else
        if (mem[i + 1][j][k] > mem[i][j + 1][k])i++;
        else j++;
    }
    if (ans.length() != 0)return ans;
    return "0";
}
int main()
{
    cout << print_LCS() << endl;
}