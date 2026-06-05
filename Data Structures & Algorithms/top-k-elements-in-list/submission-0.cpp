class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);

        for (const auto& num : nums) {
            ++count[num];
        }

        for (const auto& [num, amount] : count) {
            freq[amount].push_back(num);
        }

        vector<int> result;
        for (auto i = freq.size() - 1; i > 0; --i) {
            for (auto n : freq[i]) {
                result.push_back(n);
                if (result.size() == k) {
                    return result;
                }
            }
        }

        return result;
    }
};
