class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> res(1, 1);
        vector<int> idx(primes.size(), 0);
        vector<int> tmp(primes.size(), 0);
        while (res.size() < n) {
            int tmin = INT_MAX, id = 0;
            for (int i = 0; i < idx.size(); i++) {
                tmp[i] = res[idx[i]] * primes[i];
                if (tmp[i] < tmin) {
                    tmin = tmp[i];
                    id = i;
                }
            }
            idx[id]++;
            if (tmin != res.back())
                res.push_back(tmin);
        }
        return res[n - 1];
    }
};
