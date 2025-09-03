#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
private:
    class MyQueue {
    public:
        deque<int> que;
        //双端队列，左边是头右边是尾
        void  pop(int value) {
            if (!que.empty() && que.front() == value) {
                que.pop_front();
                
            }
        }
        //注意pop用的是if,push用的是while,因为pop只需要判断队头，push要删除所有比value小的元素

        void push(int value) {
            while(!que.empty() && value > que.back()) {
                que.pop_back();
            }
            //作用：向队列中加入新元素，并维持队列的「单调递减」特性。
            //逻辑：（注意是先删除再入队）
            //新元素入队前，从队列尾部开始，删除所有「比新元素小」的元素（因为这些元素在新元素存在时，永远不可能成为窗口最大值）。
            que.push_back(value);
            //最后将新元素加入队列尾部。
        }

        int front() {
            return que.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> result;
        
        for (int i = 0; i < k; i++) {
            que.push(nums[i]);

        }
        //第一个循环单独处理
        //前 k 个元素是窗口的初始内容，需要全部加入队列并调整为单调递减结构。
        //只有完成初始窗口的构建，才能获取第一个最大值（result 的第一个元素）。
        result.push_back(que.front());
        //动态数组可以直接把元素放在末尾，不用考虑下标
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i-k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }
};