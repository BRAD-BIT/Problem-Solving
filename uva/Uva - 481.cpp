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
#include<locale>
#include<codecvt>
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
#define pr3(n)     cout<<fixed<<setprecision(9)<<n<<endl
#define endl       "\n"
#define PI         2*acos(0.0)
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
#define EPS 1e-9
int dr[] = { 1, 0, -1, 0, -1, -1, 1, 1 };
int dc[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
const int MAX = 5*1e7 + 7;
const int MOD = 1073741824;
int arr[MAX], n = 0;
int GetCeilIndex(int A[], int T[], int l, int r, int key) 
{
	int m;
	while (r - l > 1){
		m = l + (r - l) / 2;
		if (A[T[m]] >= key)r = m;else l = m;
	}
	return r;
}

void LongestIncreasingSubsequence(int A[], int size) {
	int *tailIndices = new int[size];
	int *prevIndices = new int[size];
	int len;

	memset(tailIndices, 0, sizeof(tailIndices[0])*size);
	memset(prevIndices, 0xFF, sizeof(prevIndices[0])*size);

	tailIndices[0] = 0;
	prevIndices[0] = -1;
	len = 1;
	for (int i = 1; i < size; i++) {
		if (A[i] < A[tailIndices[0]]) {
			tailIndices[0] = i;
		}
		else if (A[i] > A[tailIndices[len - 1]]) {
			prevIndices[i] = tailIndices[len - 1];
			tailIndices[len++] = i;
		}
		else {
			int pos = GetCeilIndex(A, tailIndices, -1, len - 1, A[i]);

			prevIndices[i] = tailIndices[pos - 1];
			tailIndices[pos] = i;
		}
	}
	cout << len << endl << "-\n";
	vector<int>v;
	for (int i = tailIndices[len - 1]; i >= 0; i = prevIndices[i])v.push_back(A[i]);
	loop(i, sz(v), 0)cout << v[i] << endl;
}
int main()
{
	//R_W;
	while (cin >> arr[n++]); n--;
	LongestIncreasingSubsequence(arr,n);

}