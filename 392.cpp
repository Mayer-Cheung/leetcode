class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i, j;
        for (i = 0, j = 0; i < s.size() && j < t.size(); j++) {
            if (s[i] == t[j])
                i++;
        }
        if (i == s.size())
            return true;
        return false;
    }
};
