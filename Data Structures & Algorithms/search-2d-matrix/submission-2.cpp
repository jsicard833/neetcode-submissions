class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const size_t ROWS{ matrix.size() };
        const size_t COLS{ matrix[0].size() };

        size_t low{0}, high{ ROWS * COLS };

        while (low < high) {
            size_t mid = low + (high - low) / 2;

            int val = matrix[mid / COLS][mid % COLS];

            if (val == target) {
                return true;
            } else if (val > target) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return false;
    }
};
