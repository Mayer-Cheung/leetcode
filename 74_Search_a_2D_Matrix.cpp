/*
	give a sorted matrix, check the target integer is in the matrix or not.

	this matrix is actually just a vector, and can use normal binary search to deal with it.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = m == 0 ? 0 : matrix[0].size();
        if (m == 0 || n == 0)
            return false;
        int l = 0, h = n * m - 1;
        while (l < h) {
            int mid = l + (h - l) / 2;
            int tmp = matrix[mid / n][mid % n];
            if (tmp < target)
                l = mid + 1;
            else
                h = mid;
        }
        return matrix[l / n][l % n] == target;
    }
};