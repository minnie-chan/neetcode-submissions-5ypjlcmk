class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> vc(26, 0);

        for(char size : tasks){
            vc[size - 'A']++;
        }

        int maxfreq = 0;
        for(auto& sz: vc){
            maxfreq = max(maxfreq, sz);
        }

        int maxrp = 0;
        for(auto& zz : vc){
            if(maxfreq == zz){
                maxrp++;
            }
        }

        int math = (maxfreq - 1) * (n + 1) + maxrp;

        return max((int)tasks.size(), math);
    }
};
