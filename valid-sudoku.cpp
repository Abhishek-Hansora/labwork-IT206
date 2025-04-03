#include <iostream>
#include <vector>
#include <unordered_set>

bool isValidSudoku(std::vector<std::vector<char>>& board) {
    std::unordered_set<std::string> seen;
    
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] != '.') {
                std::string num = std::string(1, board[row][col]);
                std::string rowCheck = num + " in row " + std::to_string(row);
                std::string colCheck = num + " in col " + std::to_string(col);
                std::string gridCheck = num + " in grid " + std::to_string(row / 3) + "-" + std::to_string(col / 3);

                if (seen.count(rowCheck) || seen.count(colCheck) || seen.count(gridCheck)) {
                    return false;
                }

                seen.insert(rowCheck);
                seen.insert(colCheck);
                seen.insert(gridCheck);
            }
        }
    }
    return true;
}

int main() {
    std::vector<std::vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    std::cout << (isValidSudoku(board) ? "Valid Sudoku" : "Invalid Sudoku") << std::endl;
    return 0;
}
