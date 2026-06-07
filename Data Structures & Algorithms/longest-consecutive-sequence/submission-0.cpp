class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> numSet(nums.begin(), nums.end());

        auto longest{1uz};
        for (const auto num : numSet) {
            if(!numSet.contains(num - 1)) {
                auto currentNum{num};
                auto currentStreak{1uz};

                while(numSet.contains(currentNum  + 1)) {
                    ++currentNum;
                    ++currentStreak;
                }

                longest = max(longest, currentStreak);
            }
        }

        return longest;
    }
};
