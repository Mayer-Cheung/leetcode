class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        for (int i = 0; i < max(v1.size(), v2.size()); i++) {
            if (i < v1.size()) {
                vec.push_back(v1[i]);
            }
            if (i < v2.size()) {
                vec.push_back(v2[i]);
            }
        }
        cnt = vec.size();
        cur = 0;
    }

    int next() {
        return vec[cur++];
    }

    bool hasNext() {
        return cur < cnt;
    }
private:
    vector<int> vec;
    int cnt;
    int cur;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
