class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<tuple<int, int, int>> max_heap;

        for (const auto& point : points) {
            int x = point[0];
            int y = point[1];
            int dist = (x * x) + (y * y);

            max_heap.emplace(dist, x, y);

            if (max_heap.size() > k) max_heap.pop();
        }

        vector<vector<int>> res;
        while (!max_heap.empty()) {
            auto [dist, x, y] = max_heap.top();
            max_heap.pop();
            res.push_back({x, y});
        }
        return res;
    }
};
