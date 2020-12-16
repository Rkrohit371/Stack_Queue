#include<bits/stdc++.h>
using namespace std;

bool func(string str, int n){
    stack<char>st;
    for(int i=0;i<n;i++){
        if(str[i]!=')'){
            st.push(str[i]);
        } else if(str[i]==')') {
            if(st.top()=='('){
                return 0;
            }
            while(!st.empty() && st.top()!='('){
                st.pop();
            }
            st.pop();
        }
    }
    return st.empty();
}

int main(){
    string str;
    cin>>str;

    if(func(str, str.length())){
        cout<<"False";
    } else {
        cout<<"True";
    }

    return 0;
}