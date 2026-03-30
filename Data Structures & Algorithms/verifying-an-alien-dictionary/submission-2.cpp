class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int boy[26];
        
        for(int i = 0; i < 26; i++){
            boy[order[i] - 'a'] = i;
            }

        for(int i = 1; i < words.size(); i++){
            string L = words[i - 1];
            string R = words[i];

            size_t left = 0;
            size_t right = 0;
            
            while(left < L.size() && right < R.size() && L[left] == R[right] ){ 
                left ++;
                right ++;
            }
            if(left == L.size() || right == R.size()){
                if(L.size() > R.size()){
                    return false;
                }
                continue;
            } 
            int lefts = boy[L[left] - 'a'];
            int rights = boy[R[right] - 'a'];
            if(lefts > rights){
                return false;
            }
        }
        return true;
    }
};