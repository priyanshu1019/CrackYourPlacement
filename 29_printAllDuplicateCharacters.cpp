// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
void findDuplicates(string &str){
    map<char,int> mp;
    
    for(char ch:str){
        mp[ch]++;
    }
    for(auto it:mp){
        if( it.second > 1)
            cout<<it.first<<", count "<<it.second<<endl;
    }
    
}
int main() {
    string str;
    cout<<"enter your string "<<endl;
    cin>>str;
    findDuplicates(str);
    return 0;
}
