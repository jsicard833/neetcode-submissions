class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> seen;

        for (const auto& num : nums) {
            ++seen[num];

            if (seen[num] > 1) return true;
        }

        return false;
    }
};