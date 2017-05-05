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
int len[1000007];int r,c;char a[1007][1007];
int pos(int R,int C)
{
    return R*c+C+1;
}
void rev_pos(int value,int &R,int &C)
{
    R=value/c;
    C=value - value/c*c-1;
    if(value%c==0){C+=c;R--;}
}
int check(int ps,int value)
{
    int x,y;rev_pos(ps,x,y);
    if(value==1)if(y+1<c)if(a[x][y+1]!='T')return pos(x,y+1);
    if(value==-1)if(y-1>=0)if(a[x][y-1]!='T')return pos(x,y-1);
    if(value==-c)if(x-1>=0)if(a[x-1][y]!='T')return pos(x-1,y);
    if(value==+c)if(x+1<r)if(a[x+1][y]!='T')return pos(x+1,y);
    return -1;

}
void shortest_path(int exit_r,int exit_c)
{
    queue<int>q;q.push(pos(exit_r,exit_c));len[pos(exit_r,exit_c)]=0;
    int cur,dep;
    while(!q.empty())
    {
        cur=q.front();q.pop();dep=len[cur];
        if(check(cur,-1)!=-1&&len[check(cur,-1)]==-1){len[check(cur,-1)]=dep+1;q.push(check(cur,-1));}
        if(check(cur,+1)!=-1&&len[check(cur,+1)]==-1){len[check(cur,+1)]=dep+1;q.push(check(cur,+1));}
        if(check(cur,-c)!=-1&&len[check(cur,-c)]==-1){len[check(cur,-c)]=dep+1;q.push(check(cur,-c));}
        if(check(cur,+c)!=-1&&len[check(cur,+c)]==-1){len[check(cur,+c)]=dep+1;q.push(check(cur,+c));}
    }
}
int main()
{
    cin>>r>>c;
    pair<int,int>exit;pair<int,int>start;
    for(int i=0;i<r;i++)for(int j=0;j<c;j++)
    {cin>>a[i][j];
    if(a[i][j]=='E'){exit.first=i;exit.second=j;}
    if(a[i][j]=='S'){start.first=i;start.second=j;}}
    memset(len,-1,sizeof len);
    shortest_path(exit.first,exit.second);
    int sum=0;
    int x=1;
    for(int i=0;i<r;i++)
    {
        int n,m;
        for(int j=0;j<c;j++)
        {
            if(len[x]<=len[pos(start.first,start.second)]&&x!=pos(start.first,start.second)&&len[x]!=-1&&x!=pos(exit.first,exit.second))
            {rev_pos(x,n,m);sum+=(int(a[n][m])-48);}x++;
        }
    }
    cout<<sum<<endl;
}