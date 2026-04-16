#include <bits/stdc++.h>
using namespace std;

unordered_map<int, set<char>> row, col, cube;

bool check()
{
    for (auto it : row)
        if (it.second.size() != 9)
            return false;
    for (auto it : col)
        if (it.second.size() != 9)
            return false;
    for (auto it : cube)
        if (it.second.size() != 9)
            return false;
    return true;
}

bool solve(vector<vector<char>> &board, int r, int c)
{
    if (r == 9)
    {
        return check();
    }
    if (c == 9)
        return solve(board, r + 1, 0);
    if (board[r][c] != '.')
    {
        return solve(board, r, c + 1);
    }
    int temp = (r / 3) * 3 + (c / 3);
    for (int ch = '1'; ch <= '9'; ch++)
    {
        if (row[r].find(ch) == row[r].end() && col[c].find(ch) == col[c].end() && cube[temp].find(ch) == cube[temp].end())
        {
            board[r][c] = ch;
            row[r].insert(ch);
            col[c].insert(ch);
            cube[temp].insert(ch);
            if (solve(board, r, c + 1))
                return true;
            board[r][c] = '.';
            row[r].erase(ch);
            col[c].erase(ch);
            cube[temp].erase(ch);
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>> &board)
{
    int r = board.size();
    int c = board[0].size();

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (board[i][j] == '.')
                continue;
            row[i].insert(board[i][j]);
            col[j].insert(board[i][j]);
            cube[(i / 3) * 3 + (j / 3)].insert(board[i][j]);
        }
    }
    solve(board, 0, 0);
}

int main()
{
    vector<vector<char>> sudoku = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    vector<vector<char>> cpy = sudoku;
    solveSudoku(sudoku);
    if (cpy == sudoku)
    {
        cout << "Can't be solved" << endl;
        return 0;
    }
    for (const auto &row : sudoku)
    {
        for (char num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}