class PrefixTree {
public:
    unordered_set<string> mp;
    PrefixTree() {
        
    }
    
    void insert(string word) {
        mp.insert(word);
    }
    
    bool search(string word) {
        if(mp.find(word) == mp.end()){
            return false;
        } else {
            return true;
        }
    }
    
    bool startsWith(string prefix) {
        
        for(auto key: mp){
            if(key.substr(0, prefix.size()) == prefix){
                return true;
            } 
        }
        return false;
    }
};
