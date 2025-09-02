#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //vector<string> ֧��ͨ��������tokens[i]�����ٷ��ʵ� i ����ǣ������߼��򵥣��� for (int i = 0; i < tokens.size(); i++)��
        //���õ��� string����Ҫ�Լ����� ����δ��ַ����зָ��ÿ����ǡ� ���߼��������� stringstream �ָ�ֶ����ҷָ����ȣ���������������
        stack<long long> st;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i]=="+" || tokens[i] == "-"||tokens[i] == "*" || tokens[i] == "/") {
                //ע����˫���ţ���
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if (tokens[i] == "+") st.push(b+a);
                if (tokens[i] == "-") st.push(b-a);
                if (tokens[i] == "*") st.push(b*a);
                if (tokens[i] == "/") st.push(b/a);
                //�״�㣺���ջ����Ϊ���ʽǰ�����
            }
            else {
                st.push(stoll(tokens[i]));
            }
        }
        int result = st.top();
        return result;
    }
};