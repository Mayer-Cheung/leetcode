class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int cnt = 0;
        for (auto n : data) {
            if (cnt == 0) {
                if ((n >> 5) == 0b110)
                    cnt = 1;
                else if ((n >> 4) == 0b1110)
                    cnt = 2;
                else if ((n >> 3) == 0b11110)
                    cnt = 3;
                else if (n >> 7)
                    return false;
            } else {
                if ((n >> 6) != 0b10)
                    return false;
                cnt--;
            }
        }
        return cnt == 0;
    }
};
