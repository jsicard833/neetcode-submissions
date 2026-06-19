class TimeMap {
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        data[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        const auto& values = data[key];
        int left = 0, right = values.size() - 1;
        string res = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;
            const auto& [time, value] = values[mid];
            
            if (time <= timestamp) {
                res = value;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return res;
    }

private:
    unordered_map<string, vector<pair<int, string>>> data;
};
