class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        nums = candidates;
        ranges::sort(nums);
        vector<int> current;
        backtrack(0, 0, target, current);
        return res;
    }

private:
    void backtrack(int index, int total, int target, vector<int>& current) {
        if (total == target) {
            res.push_back(current);
            return;
        }

        if (index == nums.size()) return;

        for (int i = index; i < nums.size(); ++i) {
            if (i > index && nums[i] == nums[i - 1]) continue;

            if (total + nums[i] > target) break;

            current.push_back(nums[i]);
            backtrack(i + 1, total + nums[i], target, current);
            current.pop_back();
        }
    }

    vector<vector<int>> res;
    vector<int> nums;
};
