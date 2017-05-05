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
struct node{string s[8];};bool reached=0;
int check(node &temp,int x,int cur_r,int cur_c)
{
    if((x==1&&cur_r==0&&cur_c==6)||(x==4&&cur_r==1&&cur_c==7)||(x==5&&cur_r==1&&cur_c==6))return 1;
    if((x==1&&cur_c+1>=8)||(x==2&&cur_r+1>=8)||(x==3&&cur_c-1<0)||(x==4&&cur_r-1<0)||(x==5&&(cur_r-1<0||cur_c+1>=8))||(x==6&&(cur_r+1>7||cur_c+1>7))||(x==7&&(cur_r+1>7||cur_c-1<0))||(x==8&&(cur_r-1<0||cur_c-1<0)))return -1;
    if((x==1&&temp.s[cur_r][cur_c+1]=='S')||(x==2&&temp.s[cur_r+1][cur_c]=='S')||(x==3&&temp.s[cur_r][cur_c-1]=='S')||(x==4&&temp.s[cur_r-1][cur_c]=='S')||(x==5&&temp.s[cur_r-1][cur_c+1]=='S')||(x==6&&temp.s[cur_r+1][cur_c+1]=='S')||(x==7&&temp.s[cur_r+1][cur_c-1]=='S')||(x==8&&temp.s[cur_r-1][cur_c-1]=='S'))return -1;
    temp.s[cur_r][cur_c]='.';
    if(x==1){cur_r=cur_r;cur_c=cur_c+1;}if(x==2){cur_r=cur_r+1;cur_c=cur_c;}if(x==3){cur_r=cur_r;cur_c=cur_c-1;}
    if(x==4){cur_r=cur_r-1;cur_c=cur_c;}if(x==5){cur_r=cur_r-1;cur_c=cur_c+1;}if(x==6){cur_r=cur_r+1;cur_c=cur_c+1;}
    if(x==7){cur_r=cur_r+1;cur_c=cur_c-1;}if(x==8){cur_r=cur_r-1;cur_c=cur_c-1;}
    
    if(cur_r!=0)if(temp.s[cur_r-1][cur_c]=='S')return -1;

    temp.s[cur_r][cur_c]='.';temp.s[0][7]='.';
    for(int i=7;i>0;i--)temp.s[i]=temp.s[i-1];
    temp.s[cur_r][cur_c]='M';temp.s[0][7]='A';
    return 2;
}
void solve(node temp,int cur_r,int cur_c,int sum)
{
    if(sum>=8||reached){reached=1;return;}

    int ans1,ans2,ans3,ans4,ans5,ans6,ans7,ans8,ans9;
    node temp1=temp,temp2=temp,temp3=temp,temp4=temp,temp5=temp,temp6=temp,temp7=temp,temp8=temp,temp9=temp;

    ans1=check(temp1,1,cur_r,cur_c);ans2=check(temp2,2,cur_r,cur_c);
    ans3=check(temp3,3,cur_r,cur_c);ans4=check(temp4,4,cur_r,cur_c);
    ans5=check(temp5,5,cur_r,cur_c);ans6=check(temp6,6,cur_r,cur_c);
    ans7=check(temp7,7,cur_r,cur_c);ans8=check(temp8,8,cur_r,cur_c);
    ans9=check(temp9,0,cur_r,cur_c);
    if(ans1==2){solve(temp1,cur_r,cur_c+1,sum+1);}
    if(ans2==2){solve(temp2,cur_r+1,cur_c,sum+1);}
    if(ans3==2){solve(temp3,cur_r,cur_c-1,sum+1);}
    if(ans4==2){solve(temp4,cur_r-1,cur_c,sum+1);}
    if(ans5==2){solve(temp5,cur_r-1,cur_c+1,sum+1);}
    if(ans6==2){solve(temp6,cur_r+1,cur_c+1,sum+1);}
    if(ans7==2){solve(temp7,cur_r+1,cur_c-1,sum+1);}
    if(ans8==2){solve(temp8,cur_r-1,cur_c-1,sum+1);}
    if(ans9==2){solve(temp9,cur_r,cur_c,sum+1);}
    return;
}
int main()
{
    node temp;
    cin>>temp.s[0]>>temp.s[1]>>temp.s[2]>>temp.s[3]>>temp.s[4]>>temp.s[5]>>temp.s[6]>>temp.s[7];
    solve(temp,7,0,0);
    if(reached)cout<<"WIN\n";else cout<<"LOSE\n";
}