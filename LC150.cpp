#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //vector<string> 支持通过索引（tokens[i]）快速访问第 i 个标记，遍历逻辑简单（如 for (int i = 0; i < tokens.size(); i++)）
        //若用单个 string，需要自己处理 “如何从字符串中分割出每个标记” 的逻辑（比如用 stringstream 分割、手动查找分隔符等），代码会更繁琐。
        stack<long long> st;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i]=="+" || tokens[i] == "-"||tokens[i] == "*" || tokens[i] == "/") {
                //注意是双引号，和
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if (tokens[i] == "+") st.push(b+a);
                if (tokens[i] == "-") st.push(b-a);
                if (tokens[i] == "*") st.push(b*a);
                if (tokens[i] == "/") st.push(b/a);
                //易错点：后出栈的作为表达式前面的数
            }
            else {
                st.push(stoll(tokens[i]));
            }
        }
        int result = st.top();
        return result;
    }
};