class Solution {

public:
    int lastStoneWeight(vector<int>& stones) {
       priority_queue<int> pq;

       for(int s: stones){
        pq.push(s);
       }
       while (pq.size() > 1) {
            int y = pq.top(); pq.pop(); // heaviest
            int x = pq.top(); pq.pop(); // 2nd heaviest

            if (y != x)
                pq.push(y - x); // push the difference back
        }
        return pq.empty() ? 0 : pq.top();
    }
};
