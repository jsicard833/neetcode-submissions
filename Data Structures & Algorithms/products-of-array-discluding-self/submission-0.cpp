class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const size_t N = nums.size();

        vector<int> prefix(N, 1);
        vector<int> suffix(N, 1);

        for (auto i{1uz}; i < N; ++i) {
            prefix[i] = nums[i - 1] * prefix[i - 1];
        }

        for (int i = N - 2; i >= 0; --i) {
            suffix[i] = nums[i + 1] * suffix[i + 1];
        }

        vector<int> res;
        res.reserve(N);

        for (auto i{0uz}; i < N; ++i) {
            res.push_back(prefix[i] * suffix[i]);
        }

        return res;
    }
};
