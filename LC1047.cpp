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
        //���Ըĳɡ�string result����string ���͵ı�����������г�ʼ�����ᱻĬ�ϳ�ʼ��Ϊ���ַ������� string result = ""; ��Ч����һ���ģ���
        for (char c : s) {
            if (st.empty() || st.top() != c) {
                st.push(c);
            }
            else {
               
                st.pop();
            }
        }//���������ȵó�ջ���ٽ�ջת��Ϊ�ַ���

        while (!st.empty()) { 
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        //reverse��ת�Ĳ�������ҿ�
        //result.end() ����ָ���ַ��� result ���һ���ַ���һ��λ�õĵ�����������ҿ������ ���ҿ��� �߽磩��

        return result;
    }
};