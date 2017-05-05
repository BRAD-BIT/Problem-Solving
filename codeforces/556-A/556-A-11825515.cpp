#include<bits/stdc++.h>
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
#define PI         3.14159265358979323846
#define ll         long long
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define  oo  1e9
using namespace std;
int main()
{
    int n;cin>>n;string s;cin>>s;int sum1=0,sum2=0;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='0')sum1++;else sum2++;
    }
    cout<<abs(sum1-sum2)<<endl;
}