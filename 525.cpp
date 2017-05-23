class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> ht;
        ht[0] = -1;
        int len = 0, cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            cnt += nums[i] == 1 ? 1 : -1;
            if (ht.count(cnt))
                len = max(len, i - ht[cnt]);
            else
                ht[cnt] = i;
        }
        return len;
    }
};
