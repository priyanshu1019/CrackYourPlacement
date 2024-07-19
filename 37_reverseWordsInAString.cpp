class Solution {
public:
    string reverseWords(string s) {
        string token = "";
        stack<string> st;
        stringstream ss(s);

        while (ss >> token) {
            if( token != "")
                st.push(token);
        }
        string result = "";
        while(!st.empty()){
            result = result + st.top();
            if( st.size() != 1){
                result = result +" ";
            }
            st.pop();
        }
        return result;
    }
};
