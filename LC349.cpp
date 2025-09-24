class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //��������Ϊ�˷�ֹ��ԭ���������������������const�����Է�ֹԭ�������޸�
        unordered_set<int> result;
        unordered_set<int> numcopy(nums1.begin(), nums1.end());
        //����һ����set���洢����nums1ת��Ϊset��Ľ��
        //ת����ԭ����set������Ա���Ԫ���ظ�����
        for (int num : nums2) {
            if (numcopy.find(num) != numcopy.end()) {
                //ע�⿴ֱ����find���ң���Ҫ��������Ԫ�أ�
                result.insert(num);
            }
        }
        return vector<int>(result.begin(), result.end());
        //��setת��Ϊvector���
    }
};