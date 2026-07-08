class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        this->nums = nums;
        ranges::sort(this->nums);
        vector<int> current;
        backtrack(0, target, 0, current);
        return res;
    }
private:
    void backtrack(int total, int target, int index, vector<int>& current) {
        if (total == target) {
            res.push_back(current);
            return;
        }

        for (int j = index; j < nums.size(); ++j) {
            if (total + nums[j] > target) {
                return;
            }
            current.push_back(nums[j]);
            backtrack(total + nums[j], target, j, current);
            current.pop_back();
        }
    }

    vector<vector<int>> res;
    vector<int> nums;
};
