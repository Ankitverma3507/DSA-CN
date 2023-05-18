#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>

using namespace std;
void addsolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
    return;
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n, unordered_map<int, bool> &mpprow, unordered_map<int, bool> &mpplowerdiag, unordered_map<int, bool> &mppupperdiag)
{
    int x = row;
    int y = col;

    // checking for row
    if (mpprow[x] == 1)
    {
        return false;
    }

    // checking for diagonal

    x = row;
    y = col;
    // above diagonal
    if (mppupperdiag[(n - 1) + (y - x)] == 1)
    {
        return false;
    }

    x = row;
    y = col;
    // lower diagonal
    if (mpplowerdiag[(x + y)] == 1)
    {
        return false;
    }

    return true;
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n, unordered_map<int, bool> &mpprow, unordered_map<int, bool> &mpplowerdiag, unordered_map<int, bool> &mppupperdiag)
{

    if (col == n)
    {
        addsolution(board, ans, n);
        return;
    }

    // solve one case and rest will handle by recursion
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n, mpprow, mpplowerdiag, mppupperdiag))
        {
            // if it is safe
            board[row][col] = 1;
            mpprow[row] = 1;
            mpplowerdiag[(row + col)] = 1;
            mppupperdiag[((n - 1) + (col - row))] = 1;
            solve(col + 1, ans, board, n, mpprow, mpplowerdiag, mppupperdiag);
            // backtracking
            board[row][col] = 0;
            mpprow[row] = 0;
            mpplowerdiag[(row + col)] = 0;
            mppupperdiag[((n - 1) + (col - row))] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    // Write your code here
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    unordered_map<int, bool> mpprow;
    unordered_map<int, bool> mpplowerdiag;
    unordered_map<int, bool> mppupperdiag;

    solve(0, ans, board, n, mpprow, mpplowerdiag, mppupperdiag);
    return ans;
}