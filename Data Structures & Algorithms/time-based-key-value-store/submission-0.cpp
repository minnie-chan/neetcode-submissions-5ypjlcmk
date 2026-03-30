class TimeMap {
public:

          unordered_map<string, vector<pair<int,string>>> mp; 
         
    TimeMap() = default;
    
    void set(string key, string value, int timestamp) {
         mp[key].push_back({timestamp, value}); 
    }
    
    string get(string key, int timestamp) {
        auto it = mp.find(key);
        if ( it  == mp.end()) {
            return "";
        }
        const auto& arr = it->second;

        auto ub = upper_bound(
    arr.begin(), arr.end(), timestamp,
    [](int T, const pair<int,string>& p){
         return T < p.first; }
    );

    if (ub == arr.begin()) return "";  
    --ub;                              
    return ub->second;    
    }
};
