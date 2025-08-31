#include<iostream>
using namespace std;
#include<stack>

class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;//引入stl栈容器，创建一个int型的输出和输入栈，用两个栈实现一个队列

    MyQueue() {

    }

    void push(int x) {
        stIn.push(x);//这里不用判断栈满 C++ STL 中，stack 容器默认是动态扩容的，
        //它底层通常基于动态数组（如 deque 或 vector）实现，没有固定的容量上限
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
        int x = this->pop();//注意stack.pop()返回值是bool，两个pop不一样
        stOut.push(x);//注意stOut.push是放进输出栈里，this->push是放进输入栈里
        return x;

    }

    bool empty() {
        return stIn.empty() && stOut.empty();
        }//不要写if和else判断，不够简洁；
       
};