class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxR(height.size());
        vector<int> maxL(height.size());

        for(auto l{1uz}; l < height.size(); ++l) {
            auto r = height.size() - l - 1;

            maxL[l] = max(maxL[l - 1], height[l - 1]);
            maxR[r] = max(maxR[r + 1], height[r + 1]);
        }

        int area = 0;
        for(auto i{0uz}; i < height.size(); ++i) {
            area += max(min(maxL[i], maxR[i]) - height[i], 0);
        }

        return area;
    }
};
