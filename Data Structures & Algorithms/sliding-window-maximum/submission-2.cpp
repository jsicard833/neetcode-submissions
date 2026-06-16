class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        const size_t N = nums.size();
        vector<int> res(N - k + 1);
        deque<int> q;

        size_t left{0}, right{0};

        while (right < N) {
            while (!q.empty() && nums[q.back()] < nums[right]) {
                q.pop_back();
            }
            q.push_back(right);

            if (left > q.front()) {
                q.pop_front();
            }

            if ((right + 1) >= k) {
                res[left] = nums[q.front()];
                ++left;
            }
            ++right;
        }
        
        return res;
    }
};
