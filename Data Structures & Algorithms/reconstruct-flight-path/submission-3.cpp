class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> mp;
        sort(tickets.begin(), tickets.end());

        for(auto& ticket: tickets){
            mp[ticket[0]].push_back(ticket[1]);
        }
        vector<string> ans = {"JFK"};
        dfs("JFK", mp, ans, tickets.size() + 1);
        return ans;
    }
    bool dfs(const string& word, unordered_map<string, vector<string>>& mp,vector<string>& ans,int targetLen){
        if(ans.size() == targetLen){
            return true;
        }
        if(mp.find(word) == mp.end()){
            return false;
        }

        vector<string> temp = mp[word];
        for(int i = 0; i < mp[word].size(); i++){
            string a = temp[i];

            mp[word].erase(mp[word].begin() + i);
            ans.push_back(a);
            if(dfs(a,mp,ans,targetLen)){
                return true;
            }
            mp[word].insert(mp[word].begin() + i,a);
            ans.pop_back();
        }
        return false;
    }
};
