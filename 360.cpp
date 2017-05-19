class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> res(nums.size());
        if (res.empty())
            return res;
        int idx, i = 0, j = res.size() - 1;
        if (a > 0) {
            idx = res.size() - 1;
            while (i <= j) {
                if (cal(nums[i], a, b, c) > cal(nums[j], a, b, c)) {
                    res[idx--] = cal(nums[i++], a, b, c);
                } else {
                    res[idx--] = cal(nums[j--], a, b, c);
                }
            }
        } else {
            idx = 0;
            while (i <= j) {
                if (cal(nums[i], a, b, c) < cal(nums[j], a, b, c)) {
                    res[idx++] = cal(nums[i++], a, b, c);
                } else {
                    res[idx++] = cal(nums[j--], a, b, c);
                }
            }
        }
        return res;
    }
    int cal(int n, int a, int b, int c) {
        return n * n * a + n * b + c;
    }
};
