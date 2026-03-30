class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;

       
        for (int num : nums) {
            freqMap[num]++;
        }

       
        vector<pair<int, int>> freqList(freqMap.begin(), freqMap.end());

       
        sort(freqList.begin(), freqList.end(), [](auto& a, auto& b) {
            return a.second > b.second;
        });

        
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(freqList[i].first);
        }

        
        return result;
    }
};
