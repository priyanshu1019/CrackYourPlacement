class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin() , nums.end());

        for(int i =0 ; i < n ; i++){
            if( i > 0 and nums[i] == nums[i-1]) continue;
            for(int j =i+1 ; j < n ; j++){
                if( j > i + 1 and nums[j] == nums[j-1])continue;

                int low = j+1;
                int high= n-1;
                long long tar = (long long )target - (long long )nums[i] - (long long)nums[j];
                while( low < high){
                    long long sum = nums[low]+nums[high];
                    if( sum > tar){
                        high--;
                    }else if( sum < tar){
                        low++;
                    }else{
                        while( low+1 < n and nums[low] == nums[low+1])low++;
                        while( high-1 >= 0 and nums[high] == nums[high-1]) high--;

                        ans.push_back({nums[i] , nums[j] , nums[low] , nums[high]});
                        low++;
                        high--;
                    }
                }
            }

        }

        return ans;
    }
};
