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
vector<int>v1;
vector<int>v2;
vector<int>v3;
int a[507][507];
int main()
{
    int n,m,q;cin>>n>>m>>q;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j];int max_row[507]={0};
     int sum;
        for(int i=0;i<n;i++)
        {
            sum=0;
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==0){if(sum>max_row[i])max_row[i]=sum;sum=0;}else sum++;
            }
            if(sum>max_row[i]){max_row[i]=sum;}
        }
    for(int i=0;i<q;i++)
    {
       int x,y;cin>>x>>y;a[x-1][y-1]=!a[x-1][y-1];
       sum=0;int score=0;
       for(int j=0;j<m;j++)
       {
           if(a[x-1][j]==0){if(sum>score)score=sum;sum=0;}else sum++;
       }
       if(sum>score)score=sum;
       max_row[x-1]=score;
        
      int max=0;
      for(int k=0;k<n;k++)if(max_row[k]>max)max=max_row[k];
        v1.push_back(max);
    }
    for(int i=0;i<v1.size();i++)cout<<v1[i]<<endl;
}