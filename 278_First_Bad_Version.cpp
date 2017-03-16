/*
	normal binary search through some API. It's important to understand the problem
	at first.
*/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, h = n;
        while (l < h) {
            int mid = l + (h - l) / 2;
            if (isBadVersion(mid) == false)
                l = mid + 1;
            else
                h = mid;
        }
        return l;
    }
};