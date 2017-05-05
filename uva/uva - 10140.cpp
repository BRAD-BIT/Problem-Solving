//In the name of Allah
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
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
#include<locale>
#include<codecvt>
using namespace std;
#define lop(i,a,n) for(int i=a;i<n;++i)
#define loop(i,n,a)for(int i=n-1;i>=a;--i)
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
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
#define pr4(n)     printf("%lld\n",n)
#define pr3(n)     cout<<fixed<<setprecision(2)<<n<<endl
#define endl       "\n"
#define PI         2*acos(0.0)
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
#define EPS pow(10,-9)
int dr[] = { 1, 0, -1, 0, -1, -1, 1, 1 };
int dc[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
const int MAX = 1e3 + 7;
const int MOD = 1e9 + 7;
void prime_interval(ll a,ll b) 
{
	int sqrt = (int)std::sqrt((double)b);
	vi is_prime(sqrt + 1, 1);
	is_prime[0] = is_prime[1] = 0;
	for (ll i = 2; i*i <= sqrt; i++)
		if (is_prime[i])
			for (ll j = i * 2; j <= sqrt; j += i)
				is_prime[j] = 0;

	vll primes;
	for (ll i = 2; i*i <= b; i++)
		if (is_prime[i])
			primes.push_back(i);

	vi is_prime2(b - a + 1, 1);
	if (a == 1)is_prime2[0] = 0;
	if (a == 0)is_prime2[0] = 0, is_prime2[1] = 0;

	lop(i, 0, sz(primes))
	{
		ll low = (ceil((ld)a / primes[i])*primes[i]);
		ll j = max(primes[i] * primes[i], low);
		for (; j <= b; j += primes[i])
		{
			is_prime2[j-a] = 0;
		}
	}
	//lop(i, 0, b-a+1)if (is_prime2[i])cout << i+a << endl;
	vi ans;
	lop(i, 0, b - a + 1)if (is_prime2[i])ans.push_back(i + a);
	if(sz(ans)<2){
		printf("There are no adjacent primes.\n"); return;
	}
	ii m1, m2;
	int x = oo, y = 0;
	lop(i, 0, sz(ans) - 1)
	{
		if (ans[i + 1] - ans[i] > y) {
			y = ans[i + 1] - ans[i];
			m2 = ii(ans[i], ans[i + 1]);
		}
		if (ans[i + 1] - ans[i] < x) {
			x = ans[i + 1] - ans[i];
			m1 = ii(ans[i], ans[i + 1]);
		}
	}
	printf("%lld,%lld are closest, %lld,%lld are most distant.\n", m1.first, m1.second, m2.first, m2.second);
}
int main()
{
	int a, b;
	while (cin>>a>>b)
	{
		prime_interval(a, b);
	}
}