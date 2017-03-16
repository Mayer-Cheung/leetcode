/*
	find out the first integer n that 1 + 2 + ... + n < target but 
	1 + 2 + ... + n + (n + 1) > target

	first solution
	try binary search here
*/

//  solution 1
//  binary search
class Solution {
public:
    int arrangeCoins(int n) {
        if (n == 1)
            return 1;
        
        long l = 1, h = n;
        while (l < h) {
            long mid = l + (h - l) / 2;
            if (mid * (mid + 1) / 2 <= n)
                l = mid + 1;
            else
                h = mid;
        }
        return l - 1;
    }
};