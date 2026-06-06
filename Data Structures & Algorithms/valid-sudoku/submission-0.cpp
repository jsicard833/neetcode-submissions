class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        array<unordered_set<char>, 9> rows;
        array<unordered_set<char>, 9> cols;
        array<array<unordered_set<char>, 3>, 3> subSquares;

        for (auto r{0uz}; r < 9; ++r) {
            for (auto c{0uz}; c < 9; ++c) {
                char num = board[r][c];
                if (num == '.') continue;

                auto rowResult = rows[r].insert(num);
                auto colResult = cols[c].insert(num);
                auto subResult = subSquares[r / 3][c / 3].insert(num);
                if (!rowResult.second || !colResult.second || !subResult.second) return false;
            }
        }

        return true;
    }
};
