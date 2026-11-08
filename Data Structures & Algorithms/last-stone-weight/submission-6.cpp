class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(auto& s : stones){
            pq.push(s);
        }

        while(pq.size() > 1){
            int save = pq.top();
            pq.pop();

            if(save > pq.top() ){
                int a = pq.top();
                pq.pop();
                pq.push(save - a);
            } else if(save == pq.top()){
                pq.pop();
                pq.push(0);
            }
        }
        return pq.top();
    }
};
