class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";

        while(columnNumber > 0){
            columnNumber--;
            int n = columnNumber % 26;

            res += char('A' + n );
            columnNumber /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};