class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());

        for (size_t i = 0; i < temperatures.size(); ++i) {
            int temp = temperatures[i];
            for (size_t j = i + 1; j < temperatures.size(); ++j) {
                if (temperatures[j] > temp) {
                    res[i] = j - i;
                    break;
                }
            }
        }
        return res;
    }
};
