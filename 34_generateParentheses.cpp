void solve(string &str , vector<string>&result , int n ){
        if( str.size() == 2*n) {
            if( isValid(str) == true) result.push_back(str);

            return;
        }

        //open bracket 
        str.push_back('(');
        solve(str , result , n);
        //backtrack
        str.pop_back();
        //close bracket
        str.push_back(')');
        solve(str , result , n);
        str.pop_back();
    }
