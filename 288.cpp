class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> dictionary) {
        for (auto w : dictionary) {
            int n = w.size();
            string abr = w[0] + to_string(n - 2) + w[n - 1];
            ht[abr].insert(w);
        }
    }

    bool isUnique(string word) {
        int n = word.size();
        string abr = word[0] + to_string(n - 2) + word[n - 1];
        return ht[abr].count(word) == ht[abr].size();
    }
private:
    map<string, set<string>> ht;
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */
