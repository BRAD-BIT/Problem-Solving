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
    string s;int k;cin>>s>>k;int x;if(s.length()%k!=0){cout<<"NO";return 0;}else x=s.length()/k;
    for(int i=0;i<s.length();i++)
    {
        string s2=s.substr(i,x),s3=s2;
        reverse(s2.begin(),s2.end());
        if(s2!=s3){cout<<"NO";return 0;}
        i+=(x-1);
    }
    cout<<"YES"<<endl;
}