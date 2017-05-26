/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> ht;
        for (auto n : intervals) {
            ht[n.start]++;
            ht[n.end]--;
        }
        int res = 0, tmp = 0;
        for (auto i : ht) {
            res = max(res, tmp += i.second);
        }
        return res;
    }
};
