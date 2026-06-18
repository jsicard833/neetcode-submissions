class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea{0};

        for (int i{0}; i < heights.size(); ++i) {
            int right{i}, left{i};
            while (right < heights.size() - 1 && heights[right + 1] >= heights[i]) {
                ++right;
            }
            while (left > 0 && heights[left - 1] >= heights[i]) {
                --left;
            }
            maxArea = max(maxArea, heights[i] * (right - left + 1));
        }

        return maxArea;
    }
};
