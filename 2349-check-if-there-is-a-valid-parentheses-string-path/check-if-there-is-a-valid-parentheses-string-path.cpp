class Solution {
    bool solve(int i, int j, vector<vector<char>>& grid,
        vector<vector<vector<int>>>& dp, int balance){
        int n = grid.size();
        int m = grid[0].size();

        if (balance < 0) return false;
        if (i >= n || j >= m) return false;

        if (grid[i][j] == '(')
            balance++;
        else
            balance--;

        if (balance < 0) return false;

        if (i == n - 1 && j == m - 1)
            return balance == 0;

        if (dp[i][j][balance] != -1)
            return dp[i][j][balance];

        bool down = solve(i + 1, j, grid, dp, balance);
        bool right = solve(i, j + 1, grid, dp, balance);

        return dp[i][j][balance] = down || right;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(n + m + 1, -1))
        );

        return solve(0, 0, grid, dp, 0);
    }
};