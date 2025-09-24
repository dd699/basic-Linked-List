//这里不用考虑两个字符串一模一样的情况
class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = { 0 };
        //注意一定要初始化为零
        for (int i = 0; i < s.size(); i++) {
            record[s[i] - 'a']++;
            //注意要加单引号
        }
        for (int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }
        //注意不能这么写，要一个一个遍历 if(record={0}){
             //return true;
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) {
                return false;
            }
        }
        return true;
    }
};