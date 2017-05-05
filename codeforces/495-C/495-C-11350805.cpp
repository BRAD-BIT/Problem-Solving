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
int main()
{
    string s;int sum1=0,sum2=0,sum3=0,sum4=0,sum5=0,sum6=0;cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')sum1++;else if(s[i]==')')sum2++;else sum3++;
        if(sum2>sum1||sum3>(sum1-sum2)){cout<<-1<<endl;return 0;}
    }
    sum4=sum1-sum2;if(sum4<sum3){cout<<-1<<endl;return 0;}
    sum5=sum3;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='#'&&sum5>1){s[i]=')';sum5--;}if(s[i]=='#')sum6=i;
    }
    string temp1,temp2,temp3;temp2=s.substr(0,sum6);temp3=s.substr(sum6+1,s.length());
    for(int i=0;i<sum4-(sum3-1);i++)temp1+=")";s=temp2+temp1+temp3;
    sum1=0,sum2=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')sum1++;else if(s[i]==')')sum2++;
        if(sum2>sum1){cout<<-1<<endl;return 0;}
    }
    for(int i=0;i<sum3-1;i++)cout<<1<<endl;cout<<sum4-(sum3-1)<<endl;
}