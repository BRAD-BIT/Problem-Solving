#include <bits/stdc++.h>
#include <ext/numeric>
#include <vector>
using namespace std;
using namespace __gnu_cxx;
vector<vector<int> >G;
map<string,int>mp;
int vis[220];int ans=0;
void DFS(int node,int dep)
{
    vis[node]=1;ans=max(ans,dep);
    for(int i=0;i<(int)G[node].size();i++)if(!vis[G[node][i]])DFS(G[node][i],dep+1);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
//freopen("ot.txt", "wt", stdout);
#endif
    int n,x=0,y=0;cin>>n;G.resize(2*n);
    for(int i=0;i<n;i++)
    {
        string s1,s,s2;
        cin>>s1>>s>>s2;
        for(int j=0;j<(int)s1.length();++j)s1[j]=tolower(s1[j]);
        for(int j=0;j<(int)s2.length();++j)s2[j]=tolower(s2[j]);
        int a,b;
        if(mp.count(s1))a=mp[s1];else mp[s1]=x++,a=mp[s1];
        if(mp.count(s2))b=mp[s2];else mp[s2]=x++,b=mp[s2];
        G[b].push_back(a);
        if(s1=="polycarp")y=a;
        if(s2=="polycarp")y=b;
    }
    DFS(y,0);
    cout<<ans+1<<endl;
}