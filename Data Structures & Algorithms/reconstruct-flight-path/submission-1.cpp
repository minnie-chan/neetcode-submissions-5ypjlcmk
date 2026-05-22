class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> mp;
        sort(tickets.begin(), tickets.end());

        for(auto& tick : tickets){
            mp[tick[0]].push_back(tick[1]);
        }
        vector<string> ans = {"JFK"};
        dfs("JFK",mp,ans,tickets.size() + 1);
        return ans;
    }
    bool dfs(const string& word,unordered_map<string, vector<string>>& mp, vector<string>& ans, int targetLen){
        if (ans.size() == targetLen) {
            return true;
        }

        if (mp.find(word) == mp.end()) {
             return false;
        }

        vector<string> temp = mp[word];
        
        for(int i = 0; i < temp.size(); i++){
            string t = temp[i];

            mp[word].erase(mp[word].begin() + i);
            ans.push_back(t);
            if(dfs(t,mp,ans,targetLen)){
                return true;
            }
            mp[word].insert(mp[word].begin() + i, t);

            ans.pop_back();
        }
        return false;
    }
};
