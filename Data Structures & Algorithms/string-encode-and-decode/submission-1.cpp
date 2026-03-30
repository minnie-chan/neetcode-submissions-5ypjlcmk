class Solution {
public:

    string encode(vector<string>& strs) {
        
        string input;
        for(auto& ss : strs){
           int lengt = ss.size();
            string bruce = to_string(lengt);
            input += bruce + "#" + ss;
        }
        return input;
    }

    vector<string> decode(string s) {
        vector<string> aa;
        int i = 0;

        while(i < s.size()){
           int  j = i;

            while (s[j] != '#'){
                j++;
            }
           string minnie =  s.substr(i, j - i);
          int pekky = stoi(minnie);

          int word_s = j+1;

          string word = s.substr(word_s, pekky );
                 i = word_s + pekky;  
           aa.push_back(word);
           

        }
        return aa;
    }
};
