class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> map;
        for (int a : nums1) {
            for (int b : nums2) {
                map[a + b]++;
            }
        }
        //采用分治的思想，先算前两个的和，再算后两个
        //求补集的思想，还运用在有效括号匹配，两数之和的题目之中
        //用哈希表是因为要存储加和与出现的次数
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