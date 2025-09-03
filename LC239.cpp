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
        //˫�˶��У������ͷ�ұ���β
        void  pop(int value) {
            if (!que.empty() && que.front() == value) {
                que.pop_front();
                
            }
        }
        //ע��pop�õ���if,push�õ���while,��Ϊpopֻ��Ҫ�ж϶�ͷ��pushҪɾ�����б�valueС��Ԫ��

        void push(int value) {
            while(!que.empty() && value > que.back()) {
                que.pop_back();
            }
            //���ã�������м�����Ԫ�أ���ά�ֶ��еġ������ݼ������ԡ�
            //�߼�����ע������ɾ������ӣ�
            //��Ԫ�����ǰ���Ӷ���β����ʼ��ɾ�����С�����Ԫ��С����Ԫ�أ���Ϊ��ЩԪ������Ԫ�ش���ʱ����Զ�����ܳ�Ϊ�������ֵ����
            que.push_back(value);
            //�����Ԫ�ؼ������β����
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
        //��һ��ѭ����������
        //ǰ k ��Ԫ���Ǵ��ڵĳ�ʼ���ݣ���Ҫȫ��������в�����Ϊ�����ݼ��ṹ��
        //ֻ����ɳ�ʼ���ڵĹ��������ܻ�ȡ��һ�����ֵ��result �ĵ�һ��Ԫ�أ���
        result.push_back(que.front());
        //��̬�������ֱ�Ӱ�Ԫ�ط���ĩβ�����ÿ����±�
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i-k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }
};