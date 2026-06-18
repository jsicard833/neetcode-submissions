class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const size_t N{heights.size()};
        int maxArea{0};
        stack<int> s;

        for (int i{0}; i <= N; ++i) {
            while (!s.empty() && (i == N || heights[s.top()] >= heights[i])) {
                int height = heights[s.top()];
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            s.push(i);
        }

        return maxArea;
    }
};
