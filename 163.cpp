class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int next = lower;
        vector<string> res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < next)
                continue;
            if (nums[i] == next) {
                next++;
                continue;
            }
            res.push_back(range(next, nums[i] - 1));
            next = nums[i] + 1;
        }
        if (next <= upper)
            res.push_back(range(next, upper));
        return res;
    }

    string range(int a, int b) {
        if (a == b)
            return to_string(a);
        return to_string(a) + "->" + to_string(b);
    }
};
