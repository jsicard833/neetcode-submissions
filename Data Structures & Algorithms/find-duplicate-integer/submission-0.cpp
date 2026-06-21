class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> seen;

        for (const auto num : nums) {
            auto [iterator, inserted] = seen.insert(num);
            if (!inserted) return *iterator;
        }

        return -1;
    }
};
