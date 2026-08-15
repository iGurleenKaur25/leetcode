class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x = 0;

        // XOR of the whole array
        for (int num : nums) {
            x ^= num;
        }

        // Whole array has non-zero XOR
        if (x != 0) {
            return nums.size();
        }

        // If XOR is 0, remove one non-zero element
        for (int num : nums) {
            if (num != 0) {
                return nums.size() - 1;
            }
        }

        // All elements are 0
        return 0;
    }
};