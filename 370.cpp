class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length);
        for (auto u : updates) {
            res[u[0]] += u[2];
            if (u[1] < res.size() - 1)
                res[u[1] + 1] -= u[2];
        }
        for (int i = 1; i < res.size(); i++)
            res[i] += res[i - 1];
        return res;
    }
};
