#include <iostream>
using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        //ע��1 ������Ϊ�� ���� ����0����ʱ��
        if(pListHead == nullptr || k==0)
            return nullptr;

        ListNode *flag = pListHead;
        ListNode *p = NULL;
        for(unsigned int i=1;i<k;i++)
            if(flag -> next != nullptr)
                flag = flag -> next;
            else
            ////��k-1����û����͵�ͷ�˶Ҳ��˵��������û��k��ô���Ļ�
                return nullptr;
        p = pListHead;
        while(flag ->next != nullptr){
            flag = flag -> next;
            p = p -> next;
        }
        return p;
    }
};

int main(){
    Solution s;
    ListNode *a = new ListNode(1);
    ListNode *head = a;
    a -> next = new ListNode(2);
    a = a-> next;
    a -> next = new ListNode(3);
    a = a-> next;
     a -> next = new ListNode(4);
    a = a-> next;
     a -> next = new ListNode(5);
    a = a-> next;
    a -> next = nullptr;

    ListNode *res = s.FindKthToTail(head,2);
    cout<<res -> val<<endl;
    return 0;

}
