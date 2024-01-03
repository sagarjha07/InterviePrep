// LEETCODE 648

class Disjoint {
private:
    vector<int> parent;
    vector<int> sz;

public:
    Disjoint(int n) {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int getParent(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = getParent(parent[x]);
    }

    void mergeEdge(int x, int y) {
        int a = getParent(x);
        int b = getParent(y);
        if (sz[a] <= sz[b]) {
            parent[a] = b;
            sz[b] += sz[a];
        } else {
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        int n = edges.size();
        Disjoint d(n);
        for (vector<int>& e : edges) {
            int a = d.getParent(e[0]);
            int b = d.getParent(e[1]);
            if (a == b)
                ans.push_back(e[0]), ans.push_back(e[1]);
            else
                d.mergeEdge(e[0], e[1]);
        }
        return ans;
    }
};