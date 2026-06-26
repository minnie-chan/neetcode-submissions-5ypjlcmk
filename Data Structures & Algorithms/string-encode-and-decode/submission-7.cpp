class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";

        for(auto& s : strs){
            ans += to_string(s.size()) + '#' + s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> ans;

        while(i < s.size()){
            string a = "";
            while(s[i] != '#'){
                a += s[i];
                i++;
            }
            i++;
            int b = stoi(a);
            string c = s.substr(i, b);
            i += b;
            ans.push_back(c);
        }
        return ans;
    }
};
