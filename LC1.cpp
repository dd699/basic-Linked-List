class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            //�����Ǵ���д��
            ///int complement=target-nums[i];
            ///auto itr=map.find(complement);
            auto itr = map.find(target - nums[i]);
            //findû�в�����

            //��ʹ�� auto �󣬱��������Զ��Ƶ��� iter �����;��� std::unordered_map<int, int>::iterator
            if (itr != map.end()) {
                return{ itr->second,i };
                //return {iter->second, i}; �� C++11 �����ϱ�׼��֧�ֵ��б��ʼ�����ط�ʽ��
                //����ֱ�ӷ���һ����������Ԫ�ص� vector<int> ��������д������Ч���ǳ��ʺϱ��ⳡ����

                //iter->second����ϣ�����ҵ��Ļ���Ԫ�ص��±֮꣨ǰ��������Ԫ�أ�first�Ǽ���second��ֵ
                //i����ǰ����Ԫ�ص��±�
            }
            map.insert(pair<int, int>(nums[i], i));
            //��ϣ��Ĳ��Ҳ�����ͨ������ʵ�ֵģ����뽫Ԫ��ֵ��Ϊ��������ͨ�� map.find(target - nums[i]) �����жϻ���Ԫ���Ƿ����
        }
        return {};

    }
};