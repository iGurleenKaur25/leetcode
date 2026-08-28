class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();
        int m = n / 2;

        // Count characters
        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Check whether palindrome is possible
        int odd = 0;
        char middle = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                middle = char('a' + i);
            }
        }

        if (odd > 1) {
            return "";
        }

        // Characters available in the left half
        vector<int> halfCnt(26);

        for (int i = 0; i < 26; i++) {
            halfCnt[i] = cnt[i] / 2;
        }

        // Build complete palindrome from left half
        auto build = [&](string left) {

            string right = left;
            reverse(right.begin(), right.end());

            if (n % 2 == 1) {
                return left + string(1, middle) + right;
            }

            return left + right;
        };

        // --------------------------------------------------
        // STEP 1:
        // Check whether target's LEFT HALF itself is possible.
        // --------------------------------------------------

        string targetLeft = target.substr(0, m);

        vector<int> used(26, 0);
        bool canUseTargetLeft = true;

        for (char c : targetLeft) {

            used[c - 'a']++;

            if (used[c - 'a'] > halfCnt[c - 'a']) {
                canUseTargetLeft = false;
                break;
            }
        }

        // If we can use exactly targetLeft,
        // construct its palindrome and check it.
        if (canUseTargetLeft) {

            string candidate = build(targetLeft);

            if (candidate > target) {
                return candidate;
            }
        }

        // --------------------------------------------------
        // STEP 2:
        // Find the smallest left half GREATER than targetLeft.
        // --------------------------------------------------

        for (int i = m - 1; i >= 0; i--) {

            // Prefix targetLeft[0 ... i-1]
            // must be usable.
            vector<int> prefixCnt(26, 0);

            bool possible = true;

            for (int j = 0; j < i; j++) {

                int c = targetLeft[j] - 'a';

                prefixCnt[c]++;

                if (prefixCnt[c] > halfCnt[c]) {
                    possible = false;
                    break;
                }
            }

            if (!possible) {
                continue;
            }

            // At position i, choose the smallest
            // character greater than targetLeft[i].
            int current = targetLeft[i] - 'a';

            for (int c = current + 1; c < 26; c++) {

                if (prefixCnt[c] >= halfCnt[c]) {
                    continue;
                }

                // Build prefix
                string left = targetLeft.substr(0, i);

                // Put a larger character here
                left += char('a' + c);

                // Remaining characters
                vector<int> remaining = halfCnt;

                for (char ch : left) {
                    remaining[ch - 'a']--;
                }

                // Fill remaining positions with
                // smallest possible characters.
                for (int x = 0; x < 26; x++) {

                    left += string(
                        remaining[x],
                        char('a' + x)
                    );
                }

                return build(left);
            }
        }

        return "";
    }
};