
//regular BIT
class Fenwick_Tree
{
public:
	vi FT;
	Fenwick_Tree(int n)
	{
		FT.resize(n + 1, 0);//first index(0) not used 
	}
	int LSOne(int x)
	{
		return x&-x;
	}
	int RSQ(int b)//point sum if range update and [0-a] sum if point update
	{
		if (b <= 0)return 0;
		return FT[b] + RSQ(b - LSOne(b));
	}
	int RSQ(int a, int b)//range sum
	{
		return RSQ(b) - RSQ(a - 1);
	}
	void update(int i, int v)//used for update point and get point S only
	{
		if (i >= sz(FT))return;
		FT[i] += v; update(i + LSOne(i), v);
	}
	void update(int a,int b, int v)//used for update range and get point only
	{
		update(a, v);
		update(b + 1, -v);
	}
	int find_index_of_cumulative_frequency(int cumFre)//work of no neg. values
	{
		int idx = 0;
		int bitMask = 0;
		int v = sz(FT);
		while (v >>= 1) {
			bitMask++;
		}
		while ((bitMask != 0) && (idx < sz(FT)))
		{
			int tIdx = idx + bitMask;
			if (cumFre == FT[tIdx])
				return tIdx;
			else if (cumFre > FT[tIdx])
			{
				idx = tIdx;
				cumFre -= FT[tIdx];
			}
			bitMask >>= 1;
		}
		if (cumFre != 0) return -1;
		else return idx;
	}
};
//regular BIT with update range and query on range
class Fenwick_Tree
{
public:
	vi FT[2];
	Fenwick_Tree(int n)
	{
		FT[0].resize(n + 1, 0);
		FT[1].resize(n + 1, 0);
	}
	int LSOne(int x)
	{
		return x&-x;
	}
	void update(int f,int i, int v)
	{
		if (i >= sz(FT[f]))return;
		FT[f][i] += v; 
		update(f, i + LSOne(i), v);
	}
	void _update(int a,int b, int v)
	{
		update(0, a, v);
		update(0, b + 1, -v);
		update(1, a, v * (a - 1));
		update(1, b + 1, -v * b);
	}
	int RSQ(int f,int b)
	{
		if (b <= 0)return 0;
		return FT[f][b] + RSQ(f, b - LSOne(b));
	}
	int RSQ(int b)
	{
		return RSQ(0, b) * b - RSQ(1, b);
	}
	int _RSQ(int a, int b)
	{
		return RSQ(b) - RSQ(a - 1);
	}
};
//2D fenwick_tree
class fenwick_tree
{
	public:
	vvll FT;
	fenwick_tree_2D(int n)
	{
		FT.resize(n+1);
		lop(i,0,n+1)FT[i].resize(n+1,0);
	}
	int LSOne(int i)
	{
		return i&-i;
	}
	void update(int x,int y,int v)
	{
		for(int i=x;i<=N;i+=(i&-i))
		for(int j=y;j<=N;j+=(j&-j))
		FT[i][j]+=v;
	}
	int RSQ(int x,int y)
	{
		int ret=0;
		for(int i=x;i>0;i-=(i&-i))
		for(int j=y;j>0;j-=(j&-j))
		ret+=FT[i][j];
		return ret;
	}
};


