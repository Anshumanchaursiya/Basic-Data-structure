#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {

    string s =  " hello i am a boy";
    stringstream sso;
    sso<<s;
    string word;
    stack<string> st;
    while(sso >> word){
        st.push(word);
    }
    
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    


}
