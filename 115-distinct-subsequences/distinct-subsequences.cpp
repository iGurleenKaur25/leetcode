class Solution {
public:
    int numDistinct(string s, string t) {

        int m = s.size();
        int n = t.size();

        vector<unsigned long long> dp(n + 1, 0);

        // Empty t can always be formed in 1 way
        dp[0] = 1;

        for (int i = 1; i <= m; i++) {

            // RIGHT TO LEFT
            for (int j = n; j >= 1; j--) {

                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[n];
    }
};