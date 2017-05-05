int L[2 * MAX];//which records the depth of each visited node
int E[2 * MAX];//which records the sequence of visited nodes
int H[MAX];//where H[i] records the index of the first occurrence of node i in E
int idx = 0;
vvi Graph;
class Sparse_Table
{
public:
	vvi ST;
	Sparse_Table(int N, int MAX_log)
	{
		ST.resize(N); lop(i, 0, N)ST[i].resize(MAX_log);//ST[i 0 - n-1][j 0-logN] is index of min element in range[i,i+2^j]
		lop(i, 0, N)ST[i][0] = i;

		for (int j = 1; (1 << j) <= N; ++j)
		{
			for (int i = 0; i + (1 << j) - 1 < N; ++i)
			{
				if (L[ST[i][j - 1]] <  L[ST[i + (1 << (j - 1))][j - 1]])
					ST[i][j] = ST[i][j - 1];
				else
					ST[i][j] = ST[i + (1 << (j - 1))][j - 1];
			}
		}
	}
	int RMQ_idx(int l, int r)
	{
		int k = (int)floor(log((double)r - l + 1) / log(2.0));
		if (L[ST[l][k]] <= L[ST[r - (1 << k) + 1][k]])
			return ST[l][k];
		else
			return ST[r - (1 << k) + 1][k];
	}
};
void dfs(int cur, int depth)
{
	H[cur] = idx;
	E[idx] = cur;
	L[idx++] = depth;
	for (int i = 0; i < Graph[cur].size(); i++) {
		dfs(Graph[cur][i], depth + 1);
		E[idx] = cur; // backtrack to current node
		L[idx++] = depth;
	}
}
Sparse_Table *ST;
void buildRMQ() 
{
	idx = 0;
	memset(H, -1, sizeof H);
	dfs(0, 0); // we assume that the root is at index 0
	ST = new Sparse_Table(MAX, log2(MAX) + 1);
}
int LCA(int u, int v)
{
	if (H[u] > H[v])swap(u, v);//finding the vertex with the smallest depth in E[RSQ_idx([u],H[v])]
	return E[ST->RMQ_idx(H[u], H[v])];
}