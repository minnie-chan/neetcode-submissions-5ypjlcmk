class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(auto& s : strs){
            res += to_string(s.size()) + '#' + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> ans;
        while(i != s.size()){
            
            string z = "";
            while( s[i] != '#'){
                z += s[i];
                i++;
            }
            i++;
             int c = stoi(z);
            z = s.substr(i, c);
            i += c;
            ans.push_back(z);
        }
        return ans;
    }
};
