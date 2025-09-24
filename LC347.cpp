class Solution {
public:
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& l, const pair<int, int>& r) {
            return l.second > r.second;
        }
    };
    //小顶堆的比较器

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        //哈希表可以匹配键值和数据，unordered_map：底层是哈希表，利用哈希函数计算键的哈希值来确定元素存储位置
        //map底层是红黑树
        // 用map统计各个元素出现的频率

        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
        // 创建一个小顶堆
        // 分别是堆的元素类型，底层容器和比较器（最上面写的那个），只有小顶堆要写，大不用写
        //小顶堆内部自动根据map【i】即频率的值排序

        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            // 注意这里不能用map。size，要访问map。end，指向map最后一个元素的下一个位置
            pri_que.push(*it);
            // 把迭代器it看成是指针
            if (pri_que.size() > k) {
                pri_que.pop();
                // 堆从根节点开始向外弹出，小顶堆弹出是最小值
            }
        }

        vector<int> result(k);
        //注意这里有参数k
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
            //不要漏掉这句，记得弹出顶端的元素（最小值）
        }

        return result;
    }
};
// 需要具备哈希表，map，pair，堆，迭代器的知识