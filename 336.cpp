class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> ht;
        set<int> mySet;
        vector<vector<int>> res;
        for (int i = 0; i < words.size(); i++) {
            ht[words[i]] = i;
            mySet.insert(words[i].size());
        }
        for (int i = 0; i < words.size(); i++) {
            string t = words[i];
            reverse(t.begin(), t.end());
            int len = t.size();
            if (ht.count(t) && ht[t] != i)
                res.push_back({i, ht[t]});
            auto pos = mySet.find(len);
            for (auto it = mySet.begin(); it != pos; it++) {
                int d = *it;
                if (isValid(t, 0, len - d - 1) && ht.count(t.substr(len - d)))
                    res.push_back({i, ht[t.substr(len - d)]});
                if (isValid(t, d, len - 1) && ht.count(t.substr(0, d)))
                    res.push_back({ht[t.substr(0, d)], i});
            }
        }
        return res;
    }
    bool isValid(string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }
};
