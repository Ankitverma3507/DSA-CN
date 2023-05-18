#include <bits/stdc++.h>
#include<vector>

using namespace std;

// -------------------------codestudio----------------------------
bool isSafe(int newx, int newy, vector<vector<bool>> &vis,
            vector<vector<int>> &arr, int n)
{
    if ((newx >= 0) and (newx < n) and ((newy >= 0) and (newy < n)) and
        vis[newx][newy] != 1 and arr[newx][newy] == 1)
        return true;
    else
        return false;
}

void solve(int x, int y, vector<vector<int>> &arr, int n,
           vector<string> &ans, vector<vector<bool>> &vis, string path)
{
    // base case
    if (x == n - 1 and y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    // 4movements
    // down
    vis[x][y] = 1;
    if (isSafe(x + 1, y, vis, arr, n))
    {
        solve(x + 1, y, arr, n, ans, vis, path + 'D');
    }

    // left
    if (isSafe(x, y - 1, vis, arr, n))
    {
        solve(x, y - 1, arr, n, ans, vis, path + 'L');
    }

    // right
    if (isSafe(x, y + 1, vis, arr, n))
    {
        solve(x, y + 1, arr, n, ans, vis, path + 'R');
    }

    // up
    if (isSafe(x - 1, y, vis, arr, n))
    {
        solve(x - 1, y, arr, n, ans, vis, path + 'U');
    }

    vis[x][y] = 0;
}

vector<string> searchMaze(vector<vector<int>> &arr, int n)
{

    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    string path = "";
    if (arr[0][0] == 0)
    {
        return ans;
    }

    solve(0, 0, arr, n, ans, visited, path);
    return ans;
}