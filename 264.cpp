class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(1, 1);
        int p2 = 0, p3 = 0, p5 = 0;
        while (res.size() < n) {
            int t2 = res[p2] * 2, t3 = res[p3] * 3, t5 = res[p5] * 5;
            int t = min(t2, min(t3, t5));
            if (t == t2)
                p2++;
            if (t == t3)
                p3++;
            if (t == t5)
                p5++;
            res.push_back(t);
        }
        return res[n - 1];
    }
};
