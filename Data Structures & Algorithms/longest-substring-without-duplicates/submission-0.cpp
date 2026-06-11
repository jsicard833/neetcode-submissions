#include <ranges>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen;

        int left{0}, maxSubstring{0};

        for(auto [right, c] : s | views::enumerate) {
            if (seen.contains(c)) left = max(seen[c] + 1, left);

            seen[c] = right;
            maxSubstring = max(maxSubstring, static_cast<int>(right - left + 1));
        }

        return maxSubstring;
    }
};
