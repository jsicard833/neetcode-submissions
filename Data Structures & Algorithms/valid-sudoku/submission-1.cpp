class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        array<array<bool, 10>, 9> rows;
        array<array<bool, 10>, 9> cols;
        array<array<array<bool, 10>, 3>, 3> subSquares;

        for (auto r{0uz}; r < 9; ++r) {
            for (auto c{0uz}; c < 9; ++c) {
                char num = board[r][c];
                if (num == '.') continue;

                int digit = num - '0';
                if (rows[r][digit] || cols[c][digit] || subSquares[r / 3][c / 3][digit]) return false;

                rows[r][digit] = true;
                cols[c][digit] = true;
                subSquares[r / 3][c / 3][digit] = true;
            }
        }

        return true;
    }
};
