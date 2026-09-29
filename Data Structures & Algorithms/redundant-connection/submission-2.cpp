class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> p(edges.size() + 1,0);

        for(int i = 0; i < edges.size();i++){
            p[i] += i;
        }

        for(auto i : edges){
            int a = i[0];
            int b = i[1];

            int c = find(p,a);
            int d = find(p,b);

            if(c == d){
                return {a,b};
            }
            p[d] = c;
        }
        return {};
    }
    int find(vector<int>& p, int x){
        if(p[x] != x){
            p[x] = find(p,p[x]);
        }

        return p[x];
    }
};
