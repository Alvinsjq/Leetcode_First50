#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode *p1 = l1, *p2 = l2;
        ListNode *q = new ListNode(0);
        ListNode *curr = q;
        int temp = 0;
        while(p1!=NULL || p2!=NULL){
            int x = (p1 != NULL) ? p1->val : 0;
            int y = (p2 != NULL) ? p2->val : 0; //������ĸ��Ѿ�Ϊ�յ�ʱ�򣬷���0����
            int t = temp+x+y;  //�����м�ֵt����ֵ�����������Ӧλ�����λ����֮��
            temp = t/10;       //tempΪ��λֵ
            curr -> next = new ListNode(t%10);//��ôʵ��ֵ��Ȼ���Ƕ��м�ֵ��ȡ��
            curr = curr -> next;
            if(p1!=NULL) p1 = p1->next;   //�����δ��ͷ�Ǿͼ���
            if(p2!=NULL) p2 = p2->next;
        }
        if( temp > 0){
            curr->next = new ListNode(temp); //�������λֵ������0���Ǿ�Ϊ������һ��
        }
        return q->next;

    }
};


int main(){

    ListNode *l1 = new ListNode(9);
    ListNode *l2 = new ListNode(1);

    ListNode *_l1 = l1;
    l1 -> next = new ListNode(9);
    l1 = l1 ->next;


    Solution s;

    ListNode *q = s.addTwoNumbers(_l1,l2);

    while(q!=NULL){
        cout<<q->val<<endl;
        q = q ->next;
    }



}
