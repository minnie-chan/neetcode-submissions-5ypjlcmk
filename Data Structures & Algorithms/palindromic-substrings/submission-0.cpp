class Solution {
public:
    int countSubstrings(string s) {
        int track = 0;
        int n = s.size();
        int l = 0;
        int r = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                l = i;
                r = j;
                bool confirm = true;
                while(l < r){
                    
                    if(s[l] != s[r]){
                        confirm = false;
                        break;
                    }
                    l++;
                    r--;
                }
                if(confirm == true){
                    if(s[l] == s[r]){
                        track++;
                    }
                }
            }
        }
        return track;
    }
};
