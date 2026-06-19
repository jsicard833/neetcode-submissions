class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int low{1}, high{ranges::max(piles)}, lowestRate{high};

        while (low <= high) {
            const int mid{ low + (high - low) / 2 };
            long long totalTime{0};
            for (const auto pile : piles) {
                totalTime += ceil(static_cast<double>(pile) / mid);
            }
            if (totalTime <= h) {
                high = mid - 1;
                lowestRate = mid;
            } else {
                low = mid + 1;
            }
        }

        return lowestRate;
    }
};
