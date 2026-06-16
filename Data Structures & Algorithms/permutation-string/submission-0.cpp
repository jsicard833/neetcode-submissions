class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length()) return false;

        int freq1[26]{};
        int freq2[26]{};
        for (size_t i = 0; i < s1.length(); ++i) {
            ++freq1[s1[i] - 'a'];
            ++freq2[s2[i] - 'a'];
        }

        int matches = 0;
        for (size_t i = 0; i < 26 ; ++i) {
            if (freq1[i] == freq2[i]) ++matches;
        }

        size_t l = 0;
        for(size_t r = s1.size(); r < s2.size(); ++r) {
            if (matches == 26) return true;

            int i = s2[r] - 'a';
            ++freq2[i];
            if (freq2[i] == freq1[i]) ++matches;
            else if (freq2[i] - 1 == freq1[i]) --matches;

            i = s2[l] - 'a';
            --freq2[i];
            if (freq2[i] == freq1[i]) ++matches;
            else if(freq2[i] + 1 == freq1[i]) --matches;

            l++;
        }

        return (matches == 26);
    }
};
