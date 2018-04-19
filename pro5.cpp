#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        //����p[i,j]�����Ƿ�Ϊ�����ִ�
        //��ôP[i,j] <- P[i+1,j-1] ���� si=sj
        //��P[i,i]ʱ Ϊ true
        //��P[i,i+1] <- si=si + 1
        //������ôһ����̬�滮˼·��ؼ����������λ
        int len = s.length();
        bool p[len][len];
        int i,j,max_=0;
        string res = "";
        for(i=len-1;i>=0;i--)
            for(j=i;j<len;j++)
                if(i == j)
                    p[i][j] = true;
                else if(i+1 == j)
                    p[i][j] =  (s[i]==s[i+1]);
                else
                    p[i][j] = (p[i+1][j-1] && s[i]==s[j]);

        for(i=len-1;i>=0;i--)
            for(j=i;j<len;j++){
                if(p[i][j])
                    if(max_<j-i){
                        res = s.substr(i,(j-i+1));
                        max_ = j-i;
                    }
            }
        if(res==""&&len>=1)
            res = s[0];

        return res;
    }
};


int main(){
    string s;
    Solution sol;
    while(cin>>s)
        cout<<sol.longestPalindrome(s)<<endl;
    return 0;
}
