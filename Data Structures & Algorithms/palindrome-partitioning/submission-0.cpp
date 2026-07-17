class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> part;
        backtrack(0, s, part, res);
        return res;
    }

private:
    void backtrack(int i, string_view s, vector<string>& part, vector<vector<string>>& res) {
        if (i >= s.length()) {
            res.push_back(part);
            return;
        }
        for (int j = i; j < s.length(); j++) {
            if (isPalindrome(s, i, j)) {
                part.push_back(string(s.substr(i, j - i + 1)));
                backtrack(j + 1, s, part, res);
                part.pop_back();
            }
        }
    }

    bool isPalindrome(string_view s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            ++l; --r;
        }
        return true;
    }
};
