#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string result = "";
        //可以改成“string result”，string 类型的变量如果不进行初始化，会被默认初始化为空字符串（和 string result = ""; 的效果是一样的）。
        for (char c : s) {
            if (st.empty() || st.top() != c) {
                st.push(c);
            }
            else {
               
                st.pop();
            }
        }//分两步，先得出栈，再将栈转化为字符串

        while (!st.empty()) { 
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        //reverse反转的部分左闭右开
        //result.end() 返回指向字符串 result 最后一个字符下一个位置的迭代器（左闭右开区间的 “右开” 边界）。

        return result;
    }
};