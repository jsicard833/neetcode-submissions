class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) return "";

        size_t tfreq[128]{};
        size_t sfreq[128]{};

        size_t tKeys{0};
        for (char c : t) {
            if (tfreq[c] == 0) ++tKeys;
            ++tfreq[c];
        }

        size_t matches{0};
        size_t minLen{numeric_limits<size_t>::max()};
        size_t minStart{0};

        size_t left{0};
        for (size_t right = 0; right < s.length(); ++right) {
            char rChar = s[right];
            ++sfreq[rChar];

            if (tfreq[rChar] > 0 && sfreq[rChar] == tfreq[rChar])
                ++matches;

            while (matches == tKeys) {
                size_t currentLen = right - left + 1;
                if (currentLen < minLen) {
                    minLen = currentLen;
                    minStart = left;
                }

                char lChar = s[left];
                if (tfreq[lChar] > 0 && sfreq[lChar] == tfreq[lChar])
                    --matches;

                --sfreq[lChar];
                ++left;
            }
        }

        return (minLen == numeric_limits<size_t>::max())
            ? ""
            : s.substr(minStart, minLen);
    }
};
