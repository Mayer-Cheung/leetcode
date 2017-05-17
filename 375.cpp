class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> res(n+1, vector<int>(n+1));
        for (int len = 2; len <= n; len++) {
          for (int start = 1; start + len - 1 <= n; start++) {
            int tmp = INT_MAX;
            for (int piv = start; piv < start + len - 1; piv++) {
              int r = piv + max(res[start][piv-1], res[piv+1][start+len-1]);
              tmp = min(r, tmp);
            }
            res[start][start+len-1] = tmp;
          }
        }
        return res[1][n];
    }
};
