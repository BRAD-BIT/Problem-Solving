
vvi graph[NAX_NODE];
visited[MAX_NODE]

void DFS(int node)
{
	visited[node] = 1;
	for (int i = 0; i < graph[node].size(); i++)
	{
		int child = graph[node][i];
		if (!visited[child])DFS(child);
	}
}
int ConnectedComponenetsCnt(int visited[], vector<vector<int>>graph)
{
	int cnt = 0;
	for (int i = 0; i < graph.size(); i++)
	{
		if (!visited[i])
		{
			cnt++;
			DFS(visited, graph, i + 1);
		}
	}
	return cnt;
}