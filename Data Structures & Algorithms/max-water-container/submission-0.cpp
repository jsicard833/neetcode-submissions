class Solution {
public:
    int maxArea(vector<int>& heights) {
        auto left = heights.begin(), right = heights.end() - 1;
        int maxWater = 0;

        while (left < right) {
            int area = min(*left, *right) * (right - left);
            maxWater = max(area, maxWater);

            if (*left < *right) {
                ++left;
            } else {
                --right;
            }
        }

        return maxWater;
    }
};
