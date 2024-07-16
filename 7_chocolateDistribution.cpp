long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        sort(a.begin() , a.end());
        int i = 0 ;
        long long ans = LONG_MAX;
        if( n== 0 || m ==0 )return 0;
        if( m > n)return -1;
        while(i+m-1 < n){
            long long diff = a[i+m-1]-a[i];
            ans = min(ans , diff);
            i++;
        }
        
        return ans;
} 
