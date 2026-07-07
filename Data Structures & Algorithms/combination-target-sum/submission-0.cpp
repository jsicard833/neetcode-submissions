class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        this->nums = nums;
        vector<int> current;
        backtrack(target, 0, current);
        return res;
    }
private:
    void backtrack(int remaining_target, int index, vector<int>& current) {
        if (remaining_target == 0) {
            res.push_back(current);
            return;
        }

        if (index >= nums.size() || remaining_target < 0) {
            return;
        }

        current.push_back(nums[index]);
        backtrack(remaining_target - nums[index], index, current);
        current.pop_back();

        backtrack(remaining_target, index + 1, current);
    }

    vector<vector<int>> res;
    vector<int> nums;
};
