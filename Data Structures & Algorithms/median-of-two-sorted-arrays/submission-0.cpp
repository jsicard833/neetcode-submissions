class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto& a = nums1, b = nums2;
        size_t total = a.size() + b.size();
        size_t half = (total + 1) / 2;

        if (b.size() < a.size()) {
            swap(a, b);
        }

        int left = 0, right = a.size();
        while (left <= right) {
            int i = left + (right - left) / 2;
            int j = half - i;

            double aLeft = (i > 0) ? a[i - 1] : -numeric_limits<double>::infinity();
            double aRight = (i < a.size()) ? a[i] : numeric_limits<double>::infinity();
            double bLeft = (j > 0) ? b[j - 1] : -numeric_limits<double>::infinity();
            double bRight = (j < b.size()) ? b[j]: numeric_limits<double>::infinity();

            if (aLeft <= bRight && bLeft <= aRight) {
                if (total % 2) {
                    return max(aLeft, bLeft);
                }

                return (max(aLeft, bLeft) + min(aRight, bRight)) / 2;
            } else if (aLeft > bRight) {
                right = i - 1;
            } else {
                left = i + 1;
            }
        }

        return -1;
    }
};
