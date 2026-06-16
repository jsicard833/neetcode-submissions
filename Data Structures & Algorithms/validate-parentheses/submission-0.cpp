class Solution {
public:
    bool isValid(string s) {
        stack<char, std::vector<char>> expected_brackets;

        for (const char c : s) {
            if (c == '(') expected_brackets.push(')');
            else if (c == '{') expected_brackets.push('}');
            else if (c== '[') expected_brackets.push(']');
            else {
                if (expected_brackets.empty() || expected_brackets.top() != c) {
                    return false;
                }
                expected_brackets.pop();
            }
        }

        return expected_brackets.empty();
    }
};
