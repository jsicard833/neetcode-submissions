class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;

        string current;
        backtrack(0, current, digits);
        return res;
    }

private:
    static constexpr array<string_view, 10> mapping = {
        "",     "",     "abc",  "def", 
        "ghi",  "jkl",  "mno", 
        "pqrs", "tuv",  "wxyz"
    };

    void backtrack(int index, string& current, string_view digits) {
        if (index == digits.length()) {
            res.push_back(current);
            return;
        }

        const string_view letters = mapping[digits[index] - '0'];

        for (const auto c : letters) {
            current.push_back(c);
            backtrack(index + 1, current, digits);
            current.pop_back();
        }
    }

    vector<string> res;
};
