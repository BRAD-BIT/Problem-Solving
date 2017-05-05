class Sparse_Table
{
public:
vvi ST;
	Sparse_Table(int N,int MAX_log)
	{
		ST.resize(N);lop(i,0,N)ST[i].resize(MAX_log);//ST[i 0 - n-1][j 0-logN] is index of min element in range[i,i+2^j]
		lop(i, 0, N)ST[i][0] = i;

		for (int j = 1; (1 << j) <= N; ++j)
		{
			for (int i = 0; i + (1 << j) - 1 < N; ++i)
			{
				if (arr[ST[i][j - 1]] < arr[ST[i + (1 << (j - 1))][j - 1]])
					ST[i][j] = ST[i][j - 1];
				else 
					ST[i][j] = ST[i + (1 << (j - 1))][j - 1];
			}
		}
	}
	int RMQ(int l,int r)
	{
		int k = (int)floor(log((double)r-l+1) / log(2.0));
		if (arr[ST[l][k]] <= arr[ST[r-(1<<k)+1][k]])
			return arr[ST[l][k]];
		else
			return arr[ST[r-(1<<k)+1][k]];
	}
};