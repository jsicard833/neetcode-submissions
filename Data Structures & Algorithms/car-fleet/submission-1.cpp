class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars(position.size());

        for (size_t i{0}; i < position.size(); ++i) {
            cars[i].first = position[i];
            cars[i].second = speed[i];
        }    

        ranges::sort(cars, ranges::greater{});

        stack<double> times;

        for (const auto& [position, speed] : cars) {
            double time = (double)(target - position) / speed;
            if (times.empty() || time > times.top()) {
                times.push(time);
            }
        }

        return times.size();
    }
};
