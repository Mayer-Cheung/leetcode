class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        if (n > 0) {
            grayCodeHelper(n, result);
        } else {
            result.push_back(0);
        }
        return result;
    }

    void grayCodeHelper(int n, vector<int>& res) {
        if (n == 1) {
            res.push_back(0);
            res.push_back(1);
            return;
        }

        grayCodeHelper(n-1, res);
        int size = res.size()-1;
        // n elements in res are already a part of
        // current gray code as they start with 0 as the MSB
        // we need to traverse the res in reverse order, or it
        // with 1 to get the next numbers.
        // If dont understand, then try making gray code seq
        // with 1 and then see how to get graycode(2) from 1.

        for (int i = size; i >= 0; --i) {
            int num = res[i] | (1<<(n-1));
            res.push_back(num);
        }
    }
};
