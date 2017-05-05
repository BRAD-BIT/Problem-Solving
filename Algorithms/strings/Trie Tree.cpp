class TrieTree
{
	TrieTree* child[26]; int isleaf;
public:
	TrieTree(){ memset(child, 0, sizeof child); isleaf = 0; }
	void insert(char *str)
	{
		if (*str == '\0'){ isleaf = 1; return; }
		int i = *str - 'a';
		if (child[i] == 0)child[i] = new TrieTree();
		child[i]->insert(str + 1);
	}
	bool wordExist(char *str)
	{
		if (*str == '\0')return isleaf;
		int i = *str - 'a';
		if (child[i] == 0)return 0;
		return child[i]->wordExist(str + 1);
	}
	bool prefixExist(char *str)
	{
		if (*str == '\0')return  1;
		int i = *str - 'a';
		if (child[i] == 0)return 0;
		return child[i]->prefixExist(str + 1);
	}
};