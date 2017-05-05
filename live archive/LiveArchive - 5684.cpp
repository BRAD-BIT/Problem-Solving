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
#define R_W        R_("in.txt"),W_("out.txt")
#define ll         long long
#define ld         long double
#define ii         pair<ll,ll>
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
#define pr3(n)     cout<<fixed<<setprecision(5)<<n
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
int const MAX = 500 + 7;
int const MOD = 1e9 + 7;
int arr[100];
int main()
{
	int t;cin>>t;
	lop(T,0,t)
	{
		int n;cin>>n;
		string s;int p=0,h=0,a=0,r=0;cin.ignore();
		lop(i,0,n)
		{
			int y=0,N=0;
			getline(cin,s);
			string tmp;
			s+=' ';
			lop(j,0,s.length())
			{
				if(s[j]!=' ')tmp+=s[j];
				else
				{
					if(tmp=="n"||tmp=="no")N++;
					if(tmp=="y"||tmp=="yes")y++;
					tmp.clear();
				}
			}
			//cout<<y<<" "<<N<<endl;
			if(y&&!N)p++;
			if(N&&y)h++;
			if(N==5)r++;
			if(!N&&!y)a++;
		}
		
		cout<<"Roll-call: "<<T+1<<endl;
	    printf("Present: %d out of %d\n",p,n);
        printf("Needs to study at home: %d out of %d\n",h,n);
        printf("Needs remedial work after school: %d out of %d\n",r,n);
        printf("Absent: %d out of %d\n",a,n);
	}
}