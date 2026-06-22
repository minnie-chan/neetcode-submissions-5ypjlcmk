class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for(auto& s : strs){
            encoded += to_string(s.size()) + "#" + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> vec;
        
        while (i < s.size()) {
            string lenStr = "";
            while (s[i] != '#') {
                lenStr += s[i];
                i++;
            }
            i++;

            int len = stoi(lenStr);
            string word = s.substr(i, len);
            vec.push_back(word);
            i += len;
        }
        return vec;
    }
};
