
//classical segment tree :may used for RSQ and RMQ elct.
class SegmentTree
{
public:
	vector<int> ST; int n; int from, to;
	vector<int>ismixed;
	SegmentTree(int num)
	{
		ismixed.resize(4 * num, 0);
		ST.resize(4 * num, 0);
	}
	int bulid(int p, int start, int end)//nlogn
	{
		if (start == end)return ST[p] = 1;
		return ST[p] = bulid(2 * p, start, (start + end) / 2) + bulid(2 * p + 1, ((start + end) / 2) + 1, end);
	}
	int insert(int p, int start, int end, int num)//log(n)
	{
		ST[p]++;
		if (start == end)return ST[p];
		if (num <= (start + end) / 2)return insert(2 * p, start, (start + end) / 2, num);
		else return insert(2 * p + 1, (start + end) / 2 + 1, end, num) + ST[2 * p];
	}
	int remove(int p, int start, int end, int num)//log(n)
	{
		ST[p]--;
		if (start == end)return ST[p];
		if (num < (start + end) / 2)return remove(2 * p, start, (start + end) / 2, num);
		else return remove(2 * p + 1, (start + end) / 2 + 1, end, num) + ST[2 * p];
	}
	int del_kTH(int p, int start, int end, int kth)//log(n)
	{
		ST[p]--;
		if (start == end)return start;
		if (kth <= ST[2 * p])return del_kTH(2 * p, start, (start + end) / 2, kth);
		else return del_kTH(2 * p + 1, (start + end) / 2 + 1, end, kth - ST[2 * p]);
	}
	int get_kTH(int p, int start, int end, int kth)//log(n)
	{
		if (start == end)return start;
		if (kth <= ST[2 * p])return get_kTH(2 * p, start, (start + end) / 2, kth);
		else return get_kTH(2 * p + 1, (start + end) / 2 + 1, end, kth - ST[2 * p]);
	}
	int RMQ(int p, int start, int end, int from, int to)//but we will save min in St insted of num of elem.
	{
		if (start >= from&&to >= end)return ST[p];
		int mid = (start + end) / 2;
		if (to <= mid)return RMQ(2 * p, start, mid, from, to);
		if (from > mid)return RMQ(2 * p + 1, mid + 1, end, from, to);
		int a = RMQ(2 * p, start, mid, from, to);
		int b = RMQ(2 * p + 1, mid + 1, end, from, to);
		return a > b ? a : b;
	}
	void lazyupdate(int p, int start, int end)
	{
		if (from > end || to < start)return;

		if (from <= start&&to >= end&&!ismixed[p])
		{
			ST[p]++; return;
		}

		if (!ismixed[p])
		{
			ST[2 * p] = ST[2 * p + 1] = ST[p];
		}

		int mid = (start + end) / 2;
		lazyupdate(2 * p, start, mid);
		lazyupdate(2 * p + 1, mid + 1, end);

		ismixed[p] = ismixed[2 * p] || ismixed[2 * p + 1] || ST[2 * p] != ST[2 * p + 1];
		ST[p] = max(ST[2 * p], ST[2 * p + 1]);

	}
};


//SegmentTree with vectors
class segment_tree
{
public:
	vvi ST; int from; int to; int k;
	segment_tree(int n)
	{
		ST.resize(4 * n);
	}
	void build(int p, int start, int end)
	{
		if (start == end)
		{
			ST[p].push_back(arr[start]);
			return;
		}
		int mid = (start + end) / 2;
		build(2 * p, start, mid);
		build(2 * p + 1, mid + 1, end);
		merge(ST[2 * p].begin(), ST[2 * p].end(), ST[2 * p + 1].begin(), ST[2 * p + 1].end(), back_inserter(ST[p]));
	}
	int query(int p, int start, int end)//get number of numbers in [from,to] that are greater than k
	{
		if (from > end || to < start)return 0;
		if (from <= start &&end <= to)
		{
			return ST[p].size() - (upper_bound(ST[p].begin(), ST[p].end(), k) - ST[p].begin());
		}
		int mid = (start + end) / 2;
		return query(2 * p, start, mid) + query(2 * p + 1, mid + 1, end);
	}
};

//segmenttree with sets,maps
class segment_tree
{
public:
	vector<multiset<int>> ST; int from; int to; int k;
	segment_tree(int n)
	{
		ST.resize(4 * n);
	}
	void add(int p, int k, int id , int start, int end) {//	add num k in vector Ap of (a0,a1....an)vectors
		ST[id].insert(k);
		if (start == end)	return;
		int mid = (start + end) / 2;
		if (p < mid)
			add(p, k, id * 2, start, mid);
		else
			add(p, k, id * 2 + 1, mid + 1, end);
	}
	int ask(int x, int y, int k, int id, int start, int end)//return number of occr. of k in [x,y] intervar 
	{
		if (x > end || start > y)return 0;
		if (x <= start && end <= y)
			return ST[id].count(k);
		int mid = (start + end) / 2;
		return ask(x, y, k, 2 * id, start, mid) +
			ask(x, y, k, 2 * id + 1, mid, end);
	}
};
//Segment tree on a rooted tree
class segment_tree
{
public:
	vector<node> ST; vll height, s, f;
	ll v, x, k; 
	segment_tree(int n, int root)
	{
		ST.resize(4 * n), height.resize(4 * n), s.resize(n), f.resize(n);
		DFS(root, 0);
	}
	void DFS(int node,int h)
	{
		s[node] = tim++; height[node] = h;
		lop(i, 0, sz(Graph[node]))
		{
			int child = Graph[node][i];
			DFS(child, h + 1);
		}
		f[node] = tim;
	}

	void update(int p, int start, int end)
	{
		if (s[v] >= end || f[v] <= start)return;
		if (s[v]<= start&&f[v] >= end)
		{
			ST[p].k = (ST[p].k + 1LL*MOD - k) % MOD;
			ST[p].x = (ST[p].x + x) % MOD;
			ST[p].hk = (ST[p].hk*1LL + k*height[v]*1LL) % MOD;
			return;
		}
		int mid = (start + end) / 2;
		update(2 * p, start, mid);
		update(2 * p + 1, mid, end);
	}
	ll query(int p, int start, int end)
	{
		ll ans = 0LL;
		ans = (ans + ST[p].x) % MOD;
		ans = (ans + ST[p].hk) % MOD;
		ans = (ans + ST[p].k*height[v])%MOD;
		if (end - start < 2)return ans;
		int mid = (start + end) / 2;
		if (s[v] < mid)
		return (ans + query(2 * p, start, mid)) % MOD;
		return (ans+query(2 * p + 1, mid, end)) % MOD;
	}
}; 


:::::Notes
//best interval sum node(best left-best right-total sum,best sum)
//smallest number biger than given value(put all the seq ) - co-ordiate comparassion
//trick we can increase all elements in {l,r} by arr[l]++,arr[r+1]--;int v=0;lop(i,n)v+=arr[i];ocr[i]=v;