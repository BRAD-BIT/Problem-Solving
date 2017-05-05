#include<iostream>
#include<string>
#include<cmath>
#include<cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <sstream>
#include<stdio.h>
using namespace std;

int n,a,b,c;
int arr[4050][4050];
int ans(int s, int num)
{
    if(arr[num][s]!=-1)
        return arr[num][s];
    if(s == n)
        return num;
    else if(s>n)
        return 0;

    return arr[num][s]= max(max(ans(s+a,num+1),ans(s+b,num+1)),ans(s+c,num+1));
}
int main()
{memset(arr,-1,sizeof arr);
    scanf("%d",&n);
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);


cout<<ans(0,0)<<endl;   
    

return 0;
}