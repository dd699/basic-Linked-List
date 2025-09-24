class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> map;
        for (int a : nums1) {
            for (int b : nums2) {
                map[a + b]++;
            }
        }
        //���÷��ε�˼�룬����ǰ�����ĺͣ����������
        //�󲹼���˼�룬����������Ч����ƥ�䣬����֮�͵���Ŀ֮��
        //�ù�ϣ������ΪҪ�洢�Ӻ�����ֵĴ���
        int count = 0;
        for (int c : nums3) {
            for (int d : nums4) {
                if (map.find(0 - (c + d)) != map.end()) {
                    count += map[0 - (c + d)];
                }
            }
        }
        return count;
    }
};