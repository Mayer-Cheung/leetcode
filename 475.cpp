class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        vector<int> res(houses.size(), INT_MAX);

        for (int hs = 0, ht = 0; hs < houses.size() && ht < heaters.size();) {
            if (houses[hs] <= heaters[ht]) {
                res[hs] = heaters[ht] - houses[hs];
                hs++;
            } else {
                ht++;
            }
        }

        for (int hs = houses.size() - 1, ht = heaters.size() - 1; hs >= 0 && ht >= 0;) {
            if (heaters[ht] <= houses[hs]) {
                res[hs] = min(res[hs], houses[hs] - heaters[ht]);
                hs--;
            } else {
                ht--;
            }
        }
        return *max_element(res.begin(), res.end());
    }
};
