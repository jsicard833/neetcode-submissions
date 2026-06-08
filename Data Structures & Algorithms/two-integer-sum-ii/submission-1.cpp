class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0, high = numbers.size() - 1;

        while (low < high) {
            int num = numbers[low] + numbers[high];

            if (num == target) return {low + 1, high + 1};
            else if (num < target) ++low; 
            else --high;
        }

        return {};
    }
};
