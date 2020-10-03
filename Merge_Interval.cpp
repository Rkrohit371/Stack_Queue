#include<bits/stdc++.h>
using namespace std;

void func(vector<pair<int,int>>intervals){
    stack<pair<int,int>>st;
    st.push(intervals[0]);
    int n=intervals.size();
    for(int i=1;i<n;i++){
        auto top=st.top();
        if(intervals[i].first > top.second){
            st.push(intervals[i]);
        } else if(intervals[i].second > top.second){
            top.second = intervals[i].second;
            st.pop();
            st.push(top);
        }
    }
    while(!st.empty()){
        cout<<st.top().first<<" "<<st.top().second<<endl;
        st.pop();
    }
}

int main(){
    vector<pair<int,int>>intervals={{1,3},{2,5},{4,7},{8,12}};
    func(intervals);
    return 0;
}