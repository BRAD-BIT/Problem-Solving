int PF[MAX];
void computePF(string P)
{
	int i = 1, j = 0;
	PF[0] = 0;
	while (i < sz(P))
	{
		while (j > 0 && P[i] != P[j])j = PF[j - 1];
		j += (P[i] == P[j]); 
		PF[i] = j; i++;
	}
	
}

void KMP(string T, string P)
{
	computePF(P);
	int i = 0, j = 0;
	while (i < sz(T))
	{
		while (j > 0 && T[i] != P[j])j = PF[j - 1];
		j += (T[i] == P[j]); i++;
		if (j == sz(P))
		{
			cout << "Pattern found in pos " << i << endl;
			j = PF[j-1];
		}
	}
}

KMP("I DO NOT LIKE SEVENTY SEV BUT SEVENTY SEVENTY SEVEN", "SEVENTY SEVEN");
