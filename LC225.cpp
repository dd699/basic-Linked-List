#include<iostream>
using namespace std;
#include<stack>
#include<queue>

class MyStack {
public:
    queue<int> que;
    MyStack() {

    }
    //前两个判断不需要其他算法
    void push(int x) {
        que.push(x);
    }
    bool empty() {
        return que.empty();
    }


    int pop() {
        int s = que.size();
        s--;
        while (s--) {
            que.push(que.front());
            que.pop();
        }
        int x = que.front();
        que.pop();
        return x;
    }

    int top() {
        int x=this->pop();
        que.push(x);
        return x;
    }


};