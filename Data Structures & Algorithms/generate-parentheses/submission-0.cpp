class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string current;
        backtrack(0, 0, n, current);
        return res;
    }

private:
    void backtrack(int open, int closed, int n, string& current) {
        if (open == closed && open == n) {
            res.push_back(current);
            return;
        }

        if (open < n) {
            current.push_back('(');
            backtrack(open + 1, closed, n, current);
            current.pop_back();
        }
        if (closed < open) {
            current.push_back(')');
            backtrack(open, closed + 1, n, current);
            current.pop_back();
        }
    }

    vector<string> res;
};
