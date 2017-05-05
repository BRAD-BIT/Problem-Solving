void Rabin_Karp(string T, string P)
{

	if (sz(T) < sz(P)) {
		printf("No Match found\n");
		return;
	}

	int BASE = 26;
	int HASHMOD = 1e9 + 7;

	int hp = 0;//pattern hash
	int ht = 0;//hash for first sz(P) char in T
	int B = 1;

	lop(i, 0, sz(P))
		hp = (hp + ((P[sz(P) - i - 1] - 'a')*B) % HASHMOD) % HASHMOD, B = (B* BASE) % HASHMOD;

	B = 1;
	lop(i, 0, sz(P))
		ht = (ht + ((T[sz(P) - i - 1] - 'a')*B) % HASHMOD) % HASHMOD, B = (i != sz(P) - 1) ? (B* BASE) % HASHMOD : B;

	if (ht == hp)
		printf("pattern found in pos %d\n", 0);

	lop(i, sz(P), sz(T))
	{
		ht = ((((ht - B*(T[i - sz(P)] - 'a') + HASHMOD) % HASHMOD)*BASE) % HASHMOD + (T[i] - 'a')) % HASHMOD;

		if (ht == hp)
			printf("pattern found in pos %d\n", i - sz(P) + 1);
	}
}