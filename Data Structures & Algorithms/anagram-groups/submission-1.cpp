class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;

        res.reserve(strs.size());

        for (const auto& str : strs) {
            array<uint8_t, 26> freq{};

            for (const auto c : str) {
                ++freq[c - 'a'];
            }

            string key = to_string(freq[0]);
            for (uint8_t i = 1; i < 26; ++i) {
                key += ',' + to_string(freq[i]);
            }

            res[key].push_back(str);
        }

        vector<vector<string>> result;
        result.reserve(res.size());

        for (const auto& [_, group] : res) {
            result.push_back(move(group));
        }

        return result;
    }
};
