class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> numChars;
        int maxFreq = 0;
        int l = 0, r = 0;
        int res = 0;

        while(r < s.size()) {
            ++numChars[s[r]];
            maxFreq = max(maxFreq, numChars[s[r]]);
            if ((r - l + 1) - maxFreq > k) {
                --numChars[s[l]];
                ++l;
            }
            res = max(res, (r - l + 1));
            ++r;
        }

        return res;
    }
};
