//���ﲻ�ÿ��������ַ���һģһ�������
class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = { 0 };
        //ע��һ��Ҫ��ʼ��Ϊ��
        for (int i = 0; i < s.size(); i++) {
            record[s[i] - 'a']++;
            //ע��Ҫ�ӵ�����
        }
        for (int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }
        //ע�ⲻ����ôд��Ҫһ��һ������ if(record={0}){
             //return true;
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) {
                return false;
            }
        }
        return true;
    }
};