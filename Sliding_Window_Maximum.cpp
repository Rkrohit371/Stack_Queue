#include<bits/stdc++.h>
using namespace std;

void func(vector<int>&arr, int n, int window){
    stack<int>st;
    int nge[n];
    nge[n-1] = n;
    st.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(st.size() > 0 && arr[i] >= arr[st.top()]){
            st.pop();
        } 
        if(st.size()==0){
            nge[i] = n;
        } else {
            nge[i] = st.top();
        }
        st.push(i);
    }

    int j=0;
    for(int i=0;i<=n-window;i++){
        if(j < i){
            j = i;
        }
        while(nge[j] < i+window){
            j = nge[j];
        }
        cout<<arr[j]<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int window;
    cin>>window;
    func(arr, n, window);

    return 0;
}