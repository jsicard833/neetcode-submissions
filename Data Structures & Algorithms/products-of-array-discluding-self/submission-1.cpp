class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const size_t N = nums.size();

        vector<int> res(N, 1);

        for (auto i{1uz}; i < N; ++i) {
            res[i] = nums[i - 1] * res[i - 1];
        }

        int suffix = 1;
        for (int i = static_cast<int>(N) - 1; i >= 0; --i) {
            res[i] *= suffix;
            suffix *= nums[i];
        }

        return res;
    }
};
