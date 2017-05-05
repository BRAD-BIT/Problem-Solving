import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
public class Code {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		int m = input.nextInt();
		Node nodes[] = new Node[n];
		for (int i = 0; i < n; i++)
			nodes[i] = new Node(i, input.nextInt());
		for (int i = 0; i < n - 1; i++) {
			int u = input.nextInt() - 1;
			int v = input.nextInt() - 1;
			nodes[u].adj.add(new Edge(v));
			nodes[v].adj.add(new Edge(u));
		}
		System.out.println(dfs(0, 0, 0, m, nodes));
	}
	public static int dfs(int p, int v, int cur, int m, Node[] nodes) {
		int newCur = cur;
		if (nodes[v].hasCat == 1)
			newCur++;
		else
			newCur = 0;
		if (newCur == m + 1)
			return 0;
		if (v != 0 && nodes[v].adj.size() == 1)
			return 1;
		int ans = 0;
		for (Edge i : nodes[v].adj)
			if (i.to != p)
				ans += dfs(v, i.to, newCur, m, nodes);
		return ans;
	}
	public static class Edge {
		int to;
		public Edge(int to) {
			this.to = to;
		}
	}
	public static class Node {
		List<Edge> adj = new ArrayList<>(1);
		int index, hasCat;
		public Node(int index, int hasCat) {
			this.index = index;
			this.hasCat = hasCat;
		}
	}
}