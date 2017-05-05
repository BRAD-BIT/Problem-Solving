#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<sstream>
#include<stack>
#include<queue>
#include<bitset> 
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<stdio.h>
#include<fstream>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long
int main()
{
    int a, b, c, x, y, z; cin >> a >> b >> c;
    x=(a+b-c)/2,y=b-x,z=a-x;if(x<0||y<0||z<0||(a+b-c)%2!=0)cout<<"Impossible"<<endl;else cout<<x<<" "<<y<<" "<<z<<endl;
}