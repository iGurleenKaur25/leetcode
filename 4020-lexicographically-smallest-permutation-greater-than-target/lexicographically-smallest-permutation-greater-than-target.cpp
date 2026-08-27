class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        int cnt[26] = {};

        // Count characters of s
        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Remove characters needed by target
        for (char c : target) {
            cnt[c - 'a']--;
        }

        // Start from the right
        for (int i = target.size() - 1; i >= 0; i--) {

            // Put target[i] back
            // because we are now considering changing this position
            cnt[target[i] - 'a']++;

            // Check whether target[0 ... i-1]
            // can be formed
            bool possible = true;

            for (int j = 0; j < 26; j++) {
                if (cnt[j] < 0) {
                    possible = false;
                    break;
                }
            }

            if (!possible) {
                continue;
            }

            // Find the smallest character
            // greater than target[i]
            for (int c = target[i] - 'a' + 1; c < 26; c++) {

                if (cnt[c] > 0) {

                    // Keep target's prefix
                    string ans = target.substr(0, i);

                    // Make this position slightly bigger
                    ans += char('a' + c);

                    // Use this character
                    cnt[c]--;

                    // Put remaining characters
                    // in sorted order
                    for (int k = 0; k < 26; k++) {
                        while (cnt[k] > 0) {
                            ans += char('a' + k);
                            cnt[k]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};