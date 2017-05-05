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
#define EPS pow(10,-9)
int dr[] = { 1, 0, -1, 0, -1, -1, 1, 1 };
int dc[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
const int MAX = 1e6 + 7;
const int MOD = 1e9;
typedef struct item * pitem;
struct item {
	int prior, value, cnt;
	bool rev;
	pitem l, r, parent;
};
class TREAP
{
public:
	pitem root;
	vector<pitem>TP;
	TREAP()
	{
		root = NULL;
	}
	int getcnt(pitem it)
	{
		return it ? it->cnt : 0;
	}

	void upd_cnt(pitem it)
	{
		if (it)
			it->cnt = getcnt(it->l) + getcnt(it->r) + 1;
	}
	//shift lazy to childs
	void push(pitem it)
	{
		if (it && it->rev) {
			it->rev = false;
			swap(it->l, it->r);
			if (it->l)  it->l->rev ^= true;
			if (it->r)  it->r->rev ^= true;
		}
	}
	//merge two trees and keep it max heap and binary search tree
	void merge(pitem & t, pitem l, pitem r)//all indx int r greater than all indx in l because [0-----n] for example l=[2...5] and r=[20.....99]
	{
		push(l);
		push(r);
		if (!l || !r)
			t = l ? l : r;
		else if (l->prior > r->prior)
			merge(l->r, l->r, r), t = l;
		else
			merge(r->l, l, r->l), t = r;
		upd_cnt(t);

		if (t&&t->l)t->l->parent = t;
		if (t&&t->r)t->r->parent = t;
	}
	//tree t into two trees 1.tree l(have all indx less than key) r(have the rest)
	//key is the order in the t not on the array
	void split(pitem t, pitem & l, pitem & r, int key, int add = 0) {
		if (!t)
			return void(l = r = 0);
		push(t);
		int cur_key = add + getcnt(t->l);
		if (key <= cur_key)
			split(t->l, l, t->l, key, add), r = t;
		else
			split(t->r, t->r, r, key, add + 1 + getcnt(t->l)), l = t;
		upd_cnt(t);

		if (l&&l->l)l->l->parent = l;
		if (l&&l->r)l->r->parent = l;
		if (r&&r->l)r->l->parent = r;
		if (r&&r->r)r->r->parent = r;
	}

	void _reverse(pitem t, int l, int r) {
		pitem t1, t2, t3;
		split(t, t1, t2, l);
		if (t1)t1->parent = NULL;
		if (t2)t2->parent = NULL;
		split(t2, t2, t3, r - l + 1);
		if (t2)t2->parent = NULL;
		if (t3)t3->parent = NULL;
		t2->rev ^= true;
		merge(t, t1, t2);
		merge(t, t, t3);
	}

	void output(pitem t) {
		if (!t)  return;
		push(t);
		output(t->l);
		printf("%d ", t->value);
		output(t->r);
	}
	void push_back(int value)
	{
		pitem it = new item();
		it->cnt = 1;
		it->value = value;
		it->prior = rand();
		it->rev = 0;
		it->l = it->r = it->parent = NULL;
		merge(root, root, it);
		TP.push_back(it);
	}
	int get_index_of_node(pitem node)
	{
		vi ret;
		way_to_root(node, ret);
		return way_to_node(root, sz(ret) - 1, ret, node);
	}
	void way_to_root(pitem node,vi &reverse_way)
	{
		if (root == node)return;
		if (node->parent->r == node)
			reverse_way.push_back(1);
		else reverse_way.push_back(0);
		way_to_root(node->parent, reverse_way);
	}
	int way_to_node(pitem cur,int i,vi &reverse_way,pitem target)
	{
		if (cur == target)return ((cur->rev == 0) ? (getcnt(cur->l) + 1) : (getcnt(cur->r) + 1));
		if (cur->rev)
		{
			if (cur->l)  cur->l->rev ^= true;
			if (cur->r)  cur->r->rev ^= true;
		}
		int ret;
		if (reverse_way[i] == 0)
		{
			int ext = ((cur->rev) ? (getcnt(cur->r) + 1) : 0);
			ret= way_to_node(cur->l, i - 1, reverse_way, target) + ext;
		}
		else
		{
			int ext = ((cur->rev == 0) ? (getcnt(cur->l) + 1) : 0);
			ret = way_to_node(cur->r, i - 1, reverse_way, target) + ext;
		}
		if (cur->rev)
		{
			cur->rev = false;
			swap(cur->l, cur->r);
		}
		return ret;
	}
};
ii arr[MAX];
int main()
{
	int n;
	while ((cin >> n)&&n)
	{
		TREAP T;
		lop(i, 0, n)
		{
			sc(arr[i].first); arr[i].second = i;

			T.push_back(arr[i].first);
		}
		sort(arr, arr + n);
		lop(i, 0, n)
		{
			int indx = T.get_index_of_node(T.TP[arr[i].second]);
			T._reverse(T.root, i, indx-1);
		//	T.output(T.root);
			printf("%d%c", indx, " \n"[i == n - 1]);
		}
	}
}