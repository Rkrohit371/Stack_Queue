#include<bits/stdc++.h>
using namespace std;

void func(vector<int>&arr, int n){
    stack<int>st;
    st.push(arr[0]);
    int temp[n];
    temp[0] = -1;
    for(int i=1;i<n;i++){
        while(st.size() > 0 && arr[i] > st.top()){
            st.pop();
        } 
        if(st.size()==0){
            temp[i]=-1;
        } else {
            temp[i] = st.top();
        }
        st.push(arr[i]);
    }

    for(auto num : temp){
        cout<<num<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    func(arr, n);

    return 0;
}