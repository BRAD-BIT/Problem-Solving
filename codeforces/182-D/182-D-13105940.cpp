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
using namespace std;
#define lop(i,a,n) for(int i=a;i<n;++i)
#define loop(i,n,a)for(int i=n-1;i>=a;--i)
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
#define ll         long long
#define ld         long double
#define ii         pair<ld,ld>
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
#define pr3(n)     cout<<fixed<<setprecision(3)<<n<<endl
#define endl       "\n"
#define PI         2*acos(0.0)
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
#define EPS 1e-9
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
int const MAX = 1e6 + 7;
int const MOD = 1e9 + 7;
map<string, int>mp; int ans = 0;
void Z_Algrothim(string str,int two) {
    int n=str.length();
    vector<int>Z(n,0),freq(n+1,0);
    Z[0]=n;freq[n]=1;
    for(int i=1,L=0,R=0;i<n;i++)
    {
        if(i<=R)Z[i]=min(Z[i-L],R-i+1);
        while(i+Z[i]<n&&str[i+Z[i]]==str[Z[i]])Z[i]++;
        if(i+Z[i]-1>R)L=i,R=i+Z[i]-1;
        freq[Z[i]]++;
    }
    int x=n;
    for(int i=n-1;i>0;i--)freq[i]+=freq[i+1];
    for(int i=1;i<=n;i++)if(freq[i])if(n%freq[i]==0&&freq[i]*i==n){x=i;break;}
    string ss = str.substr(0, x);
    string m = ss;
    while (m.length() <= n)
    {
        if (n%m.length() == 0)
            if (two&&mp[m]){ ans++; }
            else { mp[m]++; }
        m += ss;
    }
}
int main() 
{
    string s1, s2; cin >> s1 >> s2;
    Z_Algrothim(s1, 0);
    Z_Algrothim(s2, 1);
    cout << ans << endl;
}