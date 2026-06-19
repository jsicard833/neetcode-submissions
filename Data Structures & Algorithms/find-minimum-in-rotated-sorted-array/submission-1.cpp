class Solution {
public:
    int findMin(vector<int> &nums) {
        size_t left{0}, right{nums.size() - 1};

        while (left < right) {
            size_t mid = left + (right - left) / 2;
            if (nums[mid] < nums[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return nums[left];
    }
};
