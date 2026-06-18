class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        size_t low{0}, mid, high{matrix.size()};
        while (low < high) {
            mid = low + (high - low) / 2;
            if (matrix[mid][0] > target) {
                // search to left
                high = mid;
            } else if (matrix[mid][matrix[mid].size() - 1] < target) {
                // search to right
                low = mid + 1;
            } else {
                size_t i = mid;
                low = 0;
                high = matrix[mid].size();

                while (low < high) {
                    mid = low + (high - low) / 2;
                    if (matrix[i][mid] > target) {
                        // search to left
                        high = mid;
                    } else if (matrix[i][mid] < target) {
                        // search to right
                        low = mid + 1;
                    } else {
                        return true;
                    }
                }
                return false;
            }
        }

        return false;
    }
};
