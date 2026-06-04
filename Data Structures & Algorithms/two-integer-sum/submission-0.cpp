class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToIndex;

        for (size_t i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];

            if (numToIndex.contains(complement)) {
                return {numToIndex[complement], static_cast<int>(i)};
            }

            numToIndex[nums[i]] = i;
        }

        return {};
    }
};
