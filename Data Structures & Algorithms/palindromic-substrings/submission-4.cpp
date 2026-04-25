class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0; i < s.size();i++){
            
            count += p(s,i,i);
            count += p(s,i,i+1);
        }
        return count;
    }
    int p(string& s, int l, int r){
        int count = 0;

        while(l >= 0 && r < s.size() && s[l] == s[r]){
            l--;
            r++;
            count ++;
        }
        return count;

    }
};
