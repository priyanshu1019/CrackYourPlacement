//without sorting using freq array
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> mp;
        for(auto &str:strs){
            vector<int> freq(26 , 0);
            for(char ch:str){
                freq[ch-'a']++;
            }
            string key = "";
            for(int i =0 ; i < 26 ; i++){
                if(freq[i] > 0){
                    char ch = 'a'+i;
                    for(int j =0 ;j < freq[i] ; j++){
                        key += ch;
                    }
                }
            }
            mp[key].push_back(str);
        }
        vector<vector<string>> result;
        for(auto &it:mp){
            result.push_back(it.second);
        }

        return result;
    }
};




//using sorting
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> mp;

        for(auto &str:strs){
            string temp = str;
            sort(temp.begin() , temp.end());
            
            mp[temp].push_back(str);
        }
        vector<vector<string>> result;
        for(auto &it:mp){
            result.push_back(it.second);
        }

        return result;
    }
};
