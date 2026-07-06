class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        this->nums = nums;
        vector<int> current;
        backtrack(0, current);
        return res;
    }

private:
    void backtrack(int index, vector<int>& current) {
        if (index == nums.size()) {
            res.push_back(current);
            return;
        }

        current.push_back(nums[index]);
        backtrack(index + 1, current);
        current.pop_back();
        backtrack(index + 1, current);
    }

    vector<vector<int>> res;
    vector<int> nums;
};
