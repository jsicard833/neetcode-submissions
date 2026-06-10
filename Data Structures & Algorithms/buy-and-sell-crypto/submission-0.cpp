class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit{0}, minSeen{numeric_limits<int>::max()};
        for(const auto& price : prices) {
            minSeen = min(minSeen, price);
            maxProfit = max(maxProfit, price - minSeen);
        }

        return maxProfit;
    }
};
