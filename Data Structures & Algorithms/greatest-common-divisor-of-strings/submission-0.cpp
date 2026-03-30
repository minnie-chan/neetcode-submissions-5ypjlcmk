class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string ans = "";
        if(str2 + str1 != str1 + str2){
            return ans;
        }
        int g = gcd((int)str1.size(),(int)str2.size());
        return str1.substr(0,g);
    }
};