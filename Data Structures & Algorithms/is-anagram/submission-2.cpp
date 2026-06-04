class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        const size_t N = s.length();

        int freq[26]{};

        for (size_t i = 0; i < N; ++i) {
            ++freq[s[i] - 'a'];
            --freq[t[i] - 'a'];
        }

        for (const auto& num : freq) {
            if (num != 0) return false;
        }

        return true;
    }
};
