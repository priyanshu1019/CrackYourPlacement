class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        int ans = INT_MIN;
        //storing points[i][1] - points[i][0] , points[i][0]
        //we will have the max value of this diff , second is to check the cond of k 
        priority_queue<pair<int,int>> pq;
        
        for(int i = 0 ;i < n ; i++){
            // if a point doesnt satisfy condn for the current point then it will not do for next point also bcz sorted 
            while(!pq.empty() and (points[i][0] - pq.top().second )> k){
                pq.pop();
            }
            if(!pq.empty()){
                ans = max(ans , points[i][1]+points[i][0] + pq.top().first);
            }
            pq.push({points[i][1] - points[i][0] , points[i][0] });
        }

        return ans;
    }
};
