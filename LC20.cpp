#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) {
            return false;
        }
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(')');
            else if (s[i] == '[') st.push(']');
            else if (s[i] == '{') st.push('}');
            //选elseif不选if的好处在于判断完一个条件就不用判断下一个，不用全部条件都判断一遍，增加时间复度；
            else if (st.empty()||st.top() != s[i] ) return false;
            //易错点，这两个的调用不能调换，对 stack 调用 top() 前，必须确保栈不为空
            // 第二种情况：遍历字符串匹配的过程中，发现栈里没有我们要匹配的字符。所以return false
            // 第三种情况：遍历字符串匹配的过程中，栈已经为空了，没有匹配的字符了，说明右括号没有找到对应的左括号 return false
            else st.pop();
        }
        return st.empty();
        // 第一种情况：此时我们已经遍历完了字符串，但是栈不为空，说明有相应的左括号没有右括号来匹配，所以return false，否则就return true
    }
};//1 在匹配左括号的时候，右括号先入栈，就只需要比较当前元素和栈顶相不相等就可以了，比左括号先入栈代码实现要简单的多了！
//2 括号匹配不能跨越最近的括号，只能匹配最近的和下一个，匹配不上就是错的
//3 两次st.empty()的作用刚好是相反的，第一次是当字符串没空时栈空返回错误，第二次是当栈没空时字符串是空时返回错误