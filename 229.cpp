class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int x = 0, y = 1, cx = 0, cy = 0;
        for (auto n : nums) {
            if (x == n)
                cx++;
            else if (y == n)
                cy++;
            else if (cx == 0)
                x = n, cx = 1;
            else if (cy == 0)
                y = n, cy = 1;
            else
                cx--, cy--;
        }
        cx = cy = 0;
        for (auto n : nums) {
            if (n == x)
                cx++;
            if (n == y)
                cy++;
        }
        vector<int> res;
        if (cy > nums.size() / 3)
            res.push_back(y);
        if (cx > nums.size() / 3)
            res.push_back(x);
        return res;
    }
};
