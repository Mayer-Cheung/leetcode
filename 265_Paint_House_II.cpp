/*
	This problem serves as a generalize version of lc256, which give the costs of painting n
	house in different k colors, and asks for the minimum cost to paint all house that no
	two adjacent houses have same color.

	The first solution is insired by the lc256. Since here we have k colors instead of 3, we
	can still use the brute-force search from 256. Then the transition equation becomes:
	dp[i][j] += dp[i-1][k] s.t. k != j. The time complexity is O(n * k * k)

	The second solution answers the follow up to solve the problem in O(nk) time. Notice that
	we don't need to search every time for the least cost. Instead, we can note down the two
	smallest costs with last iteration and the index of the minimum. If the current condition
	has the same index, which means the same color, go to second minimum then. This also get
	rid of the in-place addition, which will modify the original input.

	One thing to take care of is the precedence of conditional operator, make sure to use
	parenthesis. It's strange that actually O(nk^2) and O(nk) solutions have the same running
	time.
*/

//  solution 1
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), k = n == 0? 0 : costs[0].size();
        if (n == 0 || k == 0)
            return 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < k; j++) {
                int tmp = INT_MAX;
                for (int a = 0; a < k; a++) {
                    if (a != j)
                        tmp = min(tmp, costs[i-1][a]);
                }
                costs[i][j] += tmp;
            }
        }
        int tmp = INT_MAX;
        for (int i = 0; i < k; i++)
            tmp = min(tmp, costs[n - 1][i]);
        return tmp;
    }
};

//  solution 2
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), k = (n == 0) ? 0 : costs[0].size();
        if (n == 0 || k == 0)
            return 0;
        int prevMin = 0, prevMinIdx = -1, prevSecMin = 0;
        for (int i = 0; i < n; ++i) {
            int tMin = INT_MAX, minIdx = -1, secMin = INT_MAX;
            for (int j = 0; j < k; ++j) {
                int val = costs[i][j] + (j == prevMinIdx ? prevSecMin : prevMin);
                if (minIdx < 0) {
                    tMin = val;
                    minIdx = j;
                } else if (val < tMin) {
                    secMin = tMin;
                    tMin = val;
                    minIdx = j;
                } else if (val < secMin) {
                    secMin = val;
                }
            }
            prevMin = tMin;
            prevMinIdx = minIdx;
            prevSecMin = secMin;
        }
        return prevMin;
    }
};