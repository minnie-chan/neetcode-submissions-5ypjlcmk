// What should my map's key represent?  string 
// What should my map's value represent? int 
// Which string should I put into the map? magaizne 
// As I process the other string, what should happen to the map?   hmm well i was thinking as the time were goign through randsom we coudl do somthign liek ifthe letters match we can liek decremt our maps valueand if the value ever reaches below 0 then we retun false  or if they dont match 
// What tells me it's impossible?  idk whta ou eman here but antoher thign is aa and the maps aa well we knwo that a = 0 and ocne we reach b we ntouce that magizne has a extra letter so its valid o anther thng is thy cant match in size 
class Solution {
public:
    bool canConstruct(string ransomNote, string ma) {
        unordered_map<char,int> mp;
        if(ransomNote.size() > ma.size()){
            return false;
        }

        for(auto& m: ma){
            mp[m]++;
        }

        for(int i = 0; i < ransomNote.size(); i++){
            
            char a = ransomNote[i];

            mp[a]--;

            if(mp[a] < 0){
                return false;
            }
        }
        return true;
    }
};