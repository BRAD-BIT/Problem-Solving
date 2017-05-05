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
#define lop(i,a,n) for(ll i=a;i<n;++i)
#define loop(i,n,a)for(ll i=n-1;i>=a;--i)
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
#define EPS 1e-9
int dr[] = { 1, 0, -1, 0, -1, -1, 1, 1 };
int dc[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
const int MAX = 1e3 + 7;
const int MOD = 1e9;
const int MAXC = 52;
struct TrieTree
{
	TrieTree *child[MAXC];
	TrieTree *fail;
	vector<int>patIDs;
	TrieTree() { memset(child, NULL, sizeof child); }

	void insert(char *str, int indx)
	{
		if (*str == '\0') { this->patIDs.push_back(indx); return; }
		int i = *str - 'a';

		if (islower(*str))i = *str - 'a';
		else i = (*str - 'A') + 26;
		if (child[i] == NULL)child[i] = new TrieTree();
		child[i]->insert(str + 1, indx);
	}
};

TrieTree* getFail(TrieTree* k, int c)
{
	while (k->child[c] == NULL) {
		if (k == k->fail)return k;
		k = k->fail;
	}
	return k->child[c];
}

TrieTree * buildAhoTree(char pat[][MAX], int len)
{
	TrieTree *root = new TrieTree();
	root->fail = root;
	lop(i, 0, len)
		root->insert(pat[i], i);

	queue<TrieTree*>q;

	lop(i, 0, MAXC)
		if (root->child[i] != 0) {
			root->child[i]->fail = root;
			q.push(root->child[i]);
		}

	while (!q.empty())
	{
		TrieTree* cur = q.front(); q.pop();
		lop(i, 0, MAXC)
		{
			if (cur->child[i] == 0)continue;
			q.push(cur->child[i]);
			cur->child[i]->fail = getFail(cur->fail, i);
			cur->child[i]->patIDs.insert(cur->child[i]->patIDs.end(), all(cur->child[i]->fail->patIDs));
		}
	}
	return root;
}
bool ans[MAX];
void match(TrieTree* root, char* str)
{
	TrieTree* k = root;
	for (int i = 0; str[i]; i++)
	{
		int u;
		if (islower(str[i]))u = str[i] - 'a';
		else u = (str[i] - 'A') + 26;
		k = getFail(k, u);

		lop(j, 0, sz(k->patIDs))
			ans[k->patIDs[j]] = 1;
	}
}
char p[MAX][MAX];
char s[MAX*MAX];
int main()
{
	int T; sc(T);
	lop(t, 0, T) 
	{
		memset(ans, 0, sizeof ans);
		scanf("%s", s);
		int n; sc(n);
		lop(i, 0, n)scanf("%s", p[i]);
		TrieTree * root = buildAhoTree(p, n);
		match(root, s);
		lop(i, 0, n)(ans[i])? printf("y\n") : printf("n\n");
	}
}