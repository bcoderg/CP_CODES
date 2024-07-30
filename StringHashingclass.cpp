class StringHashing
{
public:
	string s;
	long long int p = 29;
	long long int m = (int)1e9 + 7;

	vector<long long int>prefixhash , ppower;

	StringHashing(string s , long p = 139 , long m = 1000000007)
	{
		this->s = s;
		this->p = p;
		this->m = m;

		int n = s.size();
		prefixhash.assign(n, 0);
		ppower.assign(n, 1);

		//calculating , storing ppowers
		for (int i = 1; i < n; i++) {
			ppower[i] = ( (ppower[i - 1] % m) * (p % m) ) % m;
		}

		//calculating prefix hashes
		long long int cur_hash = 0;
		for (int i = 0; i < n; i++)
		{
			cur_hash = ( (((cur_hash % m) * (p % m)) % m)  + (s[i] % m) ) % m;
			prefixhash[i] = cur_hash;
		}
	}

	long long int gethash(int l , int r)
	{
		if (l == 0)return prefixhash[r];
		long long int hash_value = ( (prefixhash[r] % m) - ( (( (prefixhash[l - 1] % m) * (ppower[r - l + 1] % m)) % m) % m) + m) % m;

		return hash_value;
	}
};
