#include<iostream>
#include<string>

using namespace std;

// abcdcedva
class Solution {
public:
    int max_len = 0;
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        int max_len=0;
        int flag[256];
        init_array(flag,256);

        while(i<s.length()){
            if(flag[s[i]]==-1){
                if(i==s.length()-1){
                     max_len=max_len>(i+1-j)?max_len:(i+1-j);
                }
                //����ĸ�Ŀӻ�û�б�ռ������ռ����
                flag[s[i]]=i;
                i++;

            }else{
                //����ĸ�Ŀ�λ��������
                //�õ������������������ظ�����ĸ���
                max_len=max_len>(i-j)?max_len:(i-j);
                j=flag[s[i]]+1;
                i=j;
                init_array(flag,256);
            }
        }
        return max_len;
    }

    int res(string s,int flag[]){
        //�ݹ�ɹ�������ʱ��
        if(s.length()>0){
            int i=0,j=0;
            init_array(flag,256);
            while(i<s.length()){
                if(flag[s[i]]==-1){
                    flag[s[i]]=i;
                    i++;
                }else{
                    max_len=max_len>(i-j)?max_len:(i-j);
                    int start=flag[s[i]]+1;
                    int next_len=res(s.substr(start,s.length()-start),flag);
                    return max_len>next_len?max_len:next_len;
                }
            }
            return s.length();
        }else
            return max_len;
    }

    void init_array(int a[],int len){
        int i=0;
        for(i=0;i<len;i++)
            a[i]=-1;
    }
};


int main(){
    string s;
    while(cin>>s){
        Solution solution;
        cout<<solution.lengthOfLongestSubstring(s)<<endl;
    }
    return 0;
}
