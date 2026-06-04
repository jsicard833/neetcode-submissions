class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        const size_t N = s.length();

        unordered_map<char, size_t> freq;

        for (size_t i = 0; i < N; ++i) {
            ++freq[s[i]];
            --freq[t[i]];
        }

        for (const auto& [_, num] : freq) {
            if (num != 0) return false;
        }

        return true;
    }
};
