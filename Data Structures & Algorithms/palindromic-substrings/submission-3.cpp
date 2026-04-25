class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += isPow(s,i,i);
            ans += isPow(s,i,i+1);

        }
        return ans;
    }
    int isPow(string& s, int l, int r){
        int track = 0;

        while(l >= 0  && r < s.size() && s[l] == s[r]){

            l--;
            r++;
            track++;
        }
        return track;
    }
};
