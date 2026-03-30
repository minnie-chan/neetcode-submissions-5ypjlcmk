class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int arr[26];
        for(int i = 0; i < 26; i++){
            arr[order[i] - 'a'] = i;
        }
        for (size_t k = 1; k < words.size(); ++k) {
    const string& left  = words[k - 1];
    const string& right = words[k];

    size_t l = 0, r = 0;
    while (l < left.size() && r < right.size() && left[l] == right[r]) {
        ++l; ++r;
    }
    if (l == left.size() || r == right.size()) {
        if (left.size() > right.size()) return false;
        continue;
    }
    int lef = arr[left[l]  - 'a'];
    int rig = arr[right[r] - 'a'];
    if (lef > rig) return false;
        }
        return true;
        }
        
    };
