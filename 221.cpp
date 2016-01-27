class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty() or matrix[0].empty()) {
      return 0;
    }
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int res = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == 0 or j == 0) {
          dp[i][j] = matrix[i][j] - '0';
        }else if (matrix[i][j] == '0') {
          dp[i][j] = 0;
        }else {
          dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
        }
        res = max(res, dp[i][j]);
      }
    }
    return res * res;
  }
};
