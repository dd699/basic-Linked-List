class Solution {
public:
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& l, const pair<int, int>& r) {
            return l.second > r.second;
        }
    };
    //С���ѵıȽ���

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        //��ϣ�����ƥ���ֵ�����ݣ�unordered_map���ײ��ǹ�ϣ�����ù�ϣ����������Ĺ�ϣֵ��ȷ��Ԫ�ش洢λ��
        //map�ײ��Ǻ����
        // ��mapͳ�Ƹ���Ԫ�س��ֵ�Ƶ��

        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
        // ����һ��С����
        // �ֱ��Ƕѵ�Ԫ�����ͣ��ײ������ͱȽ�����������д���Ǹ�����ֻ��С����Ҫд������д
        //С�����ڲ��Զ�����map��i����Ƶ�ʵ�ֵ����

        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            // ע�����ﲻ����map��size��Ҫ����map��end��ָ��map���һ��Ԫ�ص���һ��λ��
            pri_que.push(*it);
            // �ѵ�����it������ָ��
            if (pri_que.size() > k) {
                pri_que.pop();
                // �ѴӸ��ڵ㿪ʼ���ⵯ����С���ѵ�������Сֵ
            }
        }

        vector<int> result(k);
        //ע�������в���k
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
            //��Ҫ©����䣬�ǵõ������˵�Ԫ�أ���Сֵ��
        }

        return result;
    }
};
// ��Ҫ�߱���ϣ��map��pair���ѣ���������֪ʶ