class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //加引号是为了防止传原参数被大量拷贝，如果加const还可以防止原参数被修改
        unordered_set<int> result;
        unordered_set<int> numcopy(nums1.begin(), nums1.end());
        //创建一个新set，存储数组nums1转换为set后的结果
        //转换的原因是set本身可以避免元素重复出现
        for (int num : nums2) {
            if (numcopy.find(num) != numcopy.end()) {
                //注意看直接用find查找，不要遍历所有元素；
                result.insert(num);
            }
        }
        return vector<int>(result.begin(), result.end());
        //把set转换为vector输出
    }
};