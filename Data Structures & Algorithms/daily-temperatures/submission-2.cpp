class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        stack<pair<int, int>> s;

        for (size_t i = 0; i < temperatures.size(); ++i) {
            int temp = temperatures[i];
            while (!s.empty() && temp > s.top().first) {
                auto p = s.top();
                s.pop();
                res[p.second] = i - p.second;
            }
            s.push({temp, i});
        }

        return res;
    }
};
