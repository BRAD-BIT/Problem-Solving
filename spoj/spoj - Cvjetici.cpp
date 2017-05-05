#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define lop(i,a,n) for(ll i=a;i<n;++i)
#define ll         long long
#define ld         long double
#define vi         vector<int>
#define sz(v)      (ll)v.size()
#define sc(n)      scanf("%d",&n)
#define pr1(n)     printf("%d\n",n)
const int MAX = 1e5 + 7;
class Fenwick_Tree
{
public:
	vi FT;
	Fenwick_Tree(int n)
	{
		FT.resize(n + 1, 0);
	}
	int LSOne(int x)
	{
		return x&-x;
	}
	int RSQ(int b)
	{
		if (b <= 0)return 0;
		return FT[b] + RSQ(b - LSOne(b));
	}
	int RSQ(int a, int b)
	{
		return RSQ(b) - RSQ(a - 1);
	}
	void update(int i, int v)//used for update point and get point range only
	{
		if (i >= sz(FT))return;
		FT[i] += v; 
		update(i + LSOne(i), v);
	}
	void update(int a, int b, int v)//used for update range and get point only
	{
		update(a, v);
		update(b + 1, -v);
	}
};
int main()
{
	Fenwick_Tree FT(MAX);
	map<int, int>mp;
	int N; cin >> N;
	lop(i, 0, N)
	{
		int L, R;
		sc(L), sc(R);
		int ansL = FT.RSQ(L) - mp[L];
		int ansR = FT.RSQ(R) - mp[R];
		mp[L] += ansL;
		mp[R] += ansR;
		pr1(ansL + ansR);
		if (R - L >= 2)
			FT.update(L + 1, R - 1, 1);
	}
}