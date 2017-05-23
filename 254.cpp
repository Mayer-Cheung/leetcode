class Solution {
public:

    void help(vector<vector<int>>& res, vector<int>& row, int n) {
        int i = row.empty() ? 2 : row.back();
        for (; i <= n / i; i++) {
            if (n % i == 0) {
                row.push_back(i);
                row.push_back(n / i);
                res.push_back(row);
                row.pop_back();
                help(res, row, n / i);
                row.pop_back();
            }
        }
    }

    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> row;
        help(res, row, n);
        return res;
    }
};
