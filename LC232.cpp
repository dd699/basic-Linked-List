#include<iostream>
using namespace std;
#include<stack>

class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;//����stlջ����������һ��int�͵����������ջ��������ջʵ��һ������

    MyQueue() {

    }

    void push(int x) {
        stIn.push(x);//���ﲻ���ж�ջ�� C++ STL �У�stack ����Ĭ���Ƕ�̬���ݵģ�
        //���ײ�ͨ�����ڶ�̬���飨�� deque �� vector��ʵ�֣�û�й̶�����������
    }

    int pop() {
        if (stOut.empty()) {
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int x = stOut.top();
        stOut.pop();
        return x;
    }

    int peek() {
        int x = this->pop();//ע��stack.pop()����ֵ��bool������pop��һ��
        stOut.push(x);//ע��stOut.push�ǷŽ����ջ�this->push�ǷŽ�����ջ��
        return x;

    }

    bool empty() {
        return stIn.empty() && stOut.empty();
        }//��Ҫдif��else�жϣ�������ࣻ
       
};