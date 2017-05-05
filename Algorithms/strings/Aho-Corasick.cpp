struct TrieTree
{
	TrieTree *child[26];
	TrieTree *fail;
	vector<int>patIDs;
	TrieTree() { memset(child, NULL, sizeof child); }

	void insert(char *str, int indx)
	{
		if (*str == '\0') { this->patIDs.push_back(indx); return; }
		int i = *str - 'a';
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

	lop(i, 0, 26)
		if (root->child[i] != 0) {
			root->child[i]->fail = root;
			q.push(root->child[i]);
		}

	while (!q.empty())
	{
		TrieTree* cur = q.front(); q.pop();
		lop(i, 0, 26)
		{
			if (cur->child[i] == 0)continue;
			q.push(cur->child[i]);
			cur->child[i]->fail = getFail(cur->fail, i);
			cur->child[i]->patIDs.insert(cur->child[i]->patIDs.end(), all(cur->child[i]->fail->patIDs));
		}
	}
	return root;
}

void match(TrieTree* root, char* str)
{
	TrieTree* k = root;
	for (int i = 0; str[i]; i++)
	{
		k = getFail(k, str[i]-'a');

		lop(j, 0, sz(k->patIDs))
			cout << "pattern of indx " << k->patIDs[j] << " is matched at pos " << i << endl;
	}
}