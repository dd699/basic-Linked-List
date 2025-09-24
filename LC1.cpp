class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            //下面是错误写法
            ///int complement=target-nums[i];
            ///auto itr=map.find(complement);
            auto itr = map.find(target - nums[i]);
            //find没有参数，

            //而使用 auto 后，编译器会自动推导出 iter 的类型就是 std::unordered_map<int, int>::iterator
            if (itr != map.end()) {
                return{ itr->second,i };
                //return {iter->second, i}; 是 C++11 及以上标准中支持的列表初始化返回方式，
                //用于直接返回一个包含两个元素的 vector<int> 对象。这种写法简洁高效，非常适合本题场景。

                //iter->second：哈希表中找到的互补元素的下标（之前遍历过的元素）first是键，second是值
                //i：当前遍历元素的下标
            }
            map.insert(pair<int, int>(nums[i], i));
            //哈希表的查找操作是通过键来实现的，必须将元素值作为键，才能通过 map.find(target - nums[i]) 快速判断互补元素是否存在
        }
        return {};

    }
};