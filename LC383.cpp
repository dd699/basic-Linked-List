class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = { 0 };
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        //size() �� length() ����ȫ�ȼ۵ĳ�Ա���������ǵ����ö��Ƿ����ַ��������������ĳ��ȣ�Ԫ�ظ�������
        for (int i = 0; i < magazine.length(); i++) {
            record[magazine[i] - 'a']++;
        }
        //��26��Сд��ĸ��ţ�������string[i]-'a'��Ȼû���õ�map�����ǹ�ϣ���˼�룬�������¼Ƶ��
        //��242��Ч����ĸ��λ���ķ���һ��
        //��Ϊ�����ظ�����magazine�����ĸ������magazine��ǰ��
        for (int i = 0; i < ransomNote.length(); i++) {
            record[ransomNote[i] - 'a']--;
            if (record[ransomNote[i] - 'a'] < 0) {
                return false;
            }

        }
        return true;
        //returnҪд��bool��������������ڣ�������д�������ѭ����
    }
};