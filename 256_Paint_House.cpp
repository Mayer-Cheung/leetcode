/*
	This question give a matrix representing the cost of painting each house in different color
	and ask the minimum costs under the condition that no two adjacent color are the same.

	The first solution I came up with is use the in-place addtion, and since there are only
	three colors, it is very easy to enumerate all possible conditions. We can use dp[i][j] to
	represent the costs of painting ith house with the color end in j. Then we can draw the
	transition function that dp[i][0] += min(dp[i-1][1], dp[i-1][2]), dp[i][1] += min(dp[i-1][0]
	, dp[i-1][2]) and dp[i][2] = min(dp[i-1][0], dp[i-1][1]).

	After solving the paint house II, I realize that the in-place addition, which modifies
	the original data, isn't good. Also, since this question is the special case of PHII,
	I just rewrite the code and it works.

	One thing to notice that the conditional operator(Cond? True: False) really has low 
	precedence, so make sure use the parenthesis to make sure the expression in right order.
*/

//  solution 1
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty())
            return 0;
        int n = costs.size();
        for (int i = 1; i < n; i++) {
            costs[i][0] += min(costs[i-1][1], costs[i-1][2]);
            costs[i][1] += min(costs[i-1][0], costs[i-1][2]);
            costs[i][2] += min(costs[i-1][0], costs[i-1][1]);
        }
        return min(costs[n-1][0], min(costs[n-1][1], costs[n-1][2]));
    }
};

//  solution 2
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty())
            return 0;
        int n = costs.size();
        int prevMin = 0, prevIdx = -1, prevSecMin = 0;
        for (int i = 0; i < n; i++) {
            int curMin = INT_MAX, curIdx = -1, curSecMin = INT_MAX;
            for (int j = 0; j < 3; j++) {
                int val = costs[i][j] + (j == prevIdx ? prevSecMin : prevMin);
                if (curIdx < 0) {
                    curIdx = j;
                    curMin = val;
                } else if (val < curMin) {
                    curSecMin = curMin;
                    curMin = val;
                    curIdx = j;
                } else if (val < curSecMin) {
                    curSecMin = val;
                }
            }
            prevMin = curMin;
            prevIdx = curIdx;
            prevSecMin = curSecMin;
        }
        return prevMin;
    }
};