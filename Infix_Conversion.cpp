#include<bits/stdc++.h>
using namespace std;

int precedent(char op) {
    if(op == '-' || op == '+'){
        return 1;
    } else if(op == '*' || op == '/'){
        return 2;
    } else {
        return 0;
    }
}

void func(string str, int n){
    stack<string>pre,post;
    stack<char>ops;
    for(int i=0;i<n;i++){
        char ch = str[i];
        if(ch=='('){
            ops.push(ch);
        } else if((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || 
        (ch >= 'A' || ch <= 'Z')){
            post.push(ch + "");
            pre.push(ch + "");
        } else if(ch == ')'){
            while(ops.top() != '('){
                char op = ops.top();
                ops.pop();
                string postv2 = post.top();
                post.pop();
                string postv1 = post.top();
                post.pop();
                string prev2 = pre.top();
                pre.pop();
                string prev1 = pre.top();
                pre.pop();
                post.push(postv1+" "+postv2+" "+op);
                pre.push(prev1+" "+prev2+" "+op);
            }
            
        } else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            while(ops.size() > 0 && ops.top() != '(' && (precedent(ch) <= precedent(ops.top()))){
                char op = ops.top();
                ops.pop();
                string postv2 = post.top();
                post.pop();
                string postv1 = post.top();
                post.pop();
                string prev2 = pre.top();
                pre.pop();
                string prev1 = pre.top();
                pre.pop();
                post.push(postv1+postv2+to_string(op));
                pre.push(to_string(op)+prev1+prev2);
            }
            ops.push(ch);
        }
    }
    while(ops.size() > 0){
        char op = ops.top()
        ops.pop();
        string postv2 = post.top();
        post.pop();
        string postv1 = post.top();
        post.pop();
        string prev2 = pre.top();
        pre.pop();
        string prev1 = pre.top();
        pre.pop();
        post.push(postv1+postv2+to_string(op));
        pre.push(to_string(op)+prev1+prev2);
    }
    cout<<"Postfix "<<post.top()<<endl;
    cout<<"Prefix "<<pre.top();

}

int main(){
    string str;
    cin>>str;
    func(str, str.length());

    return 0;
}