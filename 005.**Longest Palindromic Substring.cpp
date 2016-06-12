class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() <= 1) return s;
		int start = 0, maxLen = 1;
		const int n = s.length();
		bool isPal[n][n] = { false };
		for (int i = n - 1; i >= 0; i--) 
		{
			for (int j = i; j < n; j++) 
			{
				if ((i + 1>j - 1 || isPal[i + 1][j - 1]) && s[i] == s[j]) 
				{
					isPal[i][j] = true;
					if (j - i + 1 > maxLen) 
					{
						maxLen = j - i + 1;
						start = i;
					}

				}
			}
		}
		return s.substr(start, maxLen);

	}
};
