class Solution {
public:
    string longestPalindrome(string s) {
        int  n = s.size();
        if (n == 0) {
            return "";
        }
        int l = 0;
        int r = 0;
        int beststart = 0;
        int bestlen = 1;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                l = i;
                r = j;
                int len = j - i + 1;
            
            bool valid = true;

            while(l < r){
                if(s[l] != s[r]){
                    valid = false;
                    break;
                }
                l++;
                r--;
            }
            if(valid == true){
               if(len > bestlen){
                bestlen = len;
                beststart = i;
               }
            }
          }

        }
        return s.substr(beststart, bestlen);
    }

};
