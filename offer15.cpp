#include <iostream>

using namespace std;

class Solution {
public:
     // ʹ�����ƣ���n��1�������㣬�����Ϊ1ʱ������������1
     int  NumberOf1(int n) {
        int c = 0;
        unsigned int flag = 1;
        while(flag){
            if(n&flag)
                c++;
            flag = flag << 1;
        }
        return c;
     }

     //ʹ�ü�1
     int NumberOf1_minus(int n){
        int c = 0;
        while(n){
            c++;
            n = n & (n-1);
        }
        return c;
     }
};


int main(){
    Solution s;
    cout<<"hello"<<endl;
    cout<<s.NumberOf1(9)<<endl;
    cout<<s.NumberOf1_minus(9)<<endl;
    return 0;
}
