class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = { 0 };
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        //size() 和 length() 是完全等价的成员函数，它们的作用都是返回字符串（或容器）的长度（元素个数）。
        for (int i = 0; i < magazine.length(); i++) {
            record[magazine[i] - 'a']++;
        }
        //给26个小写字母编号，基操是string[i]-'a'虽然没有用到map但是是哈希表的思想，用数组记录频率
        //跟242有效的字母异位符的方法一样
        //因为不能重复出现magazine里的字母，所以magazine在前面
        for (int i = 0; i < ransomNote.length(); i++) {
            record[ransomNote[i] - 'a']--;
            if (record[ransomNote[i] - 'a'] < 0) {
                return false;
            }

        }
        return true;
        //return要写在bool函数的最后括号内，不可以写在里面的循环里
    }
};