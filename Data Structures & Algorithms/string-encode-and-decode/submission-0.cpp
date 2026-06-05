class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for (const auto& str : strs) {
            format_to(back_inserter(res), "{}#{}", str.length(), str);
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;

        size_t i = 0;
        while (i < s.length()) {
            size_t j = s.find('#', i);
            while (s[j] != '#') j++;

            size_t len = 0;
            from_chars(s.data() + i, s.data() + j, len);

            i = j + 1;

            res.emplace_back(s.substr(i, len));

            i += len;
        }

        return res;
    }
};
