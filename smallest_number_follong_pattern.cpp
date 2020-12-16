#include<bits/stdc++.h>
using namespace std;

void func(string str,int n){
    stack<int>st;
    int num=1;
    for(int i=0;i<n;i++){
        if(str[i]=='i'){
            st.push(num);
            num++;
            while(!st.empty()){
                cout<<st.top()<<" ";
                st.pop();
            }
        } else {
            st.push(num);
            num++;
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main(){
    string str;
    cin>>str;   

    func(str, str.length());

    return 0;
}