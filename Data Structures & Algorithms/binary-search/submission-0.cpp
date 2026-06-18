class Solution {
public:
    int search(vector<int>& nums, int target) {
        size_t low{0}, high{nums.size()}, mid;

        while (low < high) {
            mid = low + (high - low) / 2;
            if (nums[mid] > target) {
                high = mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                return mid;
            }
        }

        return -1;
    }
};
