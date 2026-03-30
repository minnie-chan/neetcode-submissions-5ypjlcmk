class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(int i = 0; i < stones.size(); i++){
            pq.push(stones[i]);
        }

        while(pq.size() > 1){
            int tmp = pq.top();
            pq.pop();
            int temp = pq.top();
            pq.pop();
            if(tmp != temp){
                pq.push(tmp - temp);
            } 
        }
        return pq.empty() ? 0 : pq.top();
    }
};
