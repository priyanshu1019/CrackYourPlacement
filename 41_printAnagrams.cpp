class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string>> ans;
        
        map<string,vector<string>> mp;
        
        for(auto str:string_list){
            int freq[26] = {0};
            for (char c : str) {
                freq[c - 'a']++;
            }
            string key = "";
            for (int i = 0; i < 26; i++) {
                key += string(freq[i], 'a' + i);
            }
            mp[key].push_back(str);
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
