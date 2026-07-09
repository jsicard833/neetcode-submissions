class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ranges::sort(nums);
        vector<int> current;
        backtrack(0, current, nums);
        return res;
    }

private:
    void backtrack(int index, vector<int>& current, const vector<int>& nums) {
        if (index == nums.size()) {
            res.push_back(current);
            return;
        }

        current.push_back(nums[index]);
        backtrack(index + 1, current, nums);
        current.pop_back();

        while (index + 1 < nums.size() && nums[index] == nums[index + 1]) ++index;
        
        backtrack(index + 1, current, nums);
    }

    vector<vector<int>> res;
};
