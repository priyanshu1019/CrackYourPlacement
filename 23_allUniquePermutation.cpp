class Solution {
  public:
    void helper(vector<int>& nums , set<vector<int>>&st, int idx){
        if( idx >= nums.size()){
            st.insert(nums);
            return;
        }
        
        for(int i = idx; i<nums.size() ; i++){
            swap(nums[i] , nums[idx]);
            helper(nums , st , idx+1);
            swap(nums[i] , nums[idx]);
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        sort(arr.begin() , arr.end());
        vector<vector<int>> ans;
        set<vector<int>>st;
        helper(arr , st , 0);
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};
