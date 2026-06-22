class Solution {
public:

    string encode(vector<string>& strs) {
        string a;
        for(auto& b : strs){
            a += to_string(b.size()) + "#" + b;
        }
        return a;
         
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> v;
        while (i < s.size()){
            string a = "";

            while(s[i] != '#'){
                a += s[i];
                i++;
            }
            i++;
            int c = stoi(a);
            string d = s.substr(i, c);
            v.push_back(d);
            i += c;
        }
        return v;
    }
};
