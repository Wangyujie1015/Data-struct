#include<stdio.h>
//
//����һ�������ͷ�ڵ� head ��һ������ val ��
//����ɾ���������������� Node.val == val �Ľڵ㣬������ �µ�ͷ�ڵ� ��
//
// Definition for singly-linked list.
  struct ListNode {
      int val;
      struct ListNode *next;
 };
 
//
//
//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//    struct ListNode* cur, * prev;
//    cur = head;
//    prev = NULL;
//    while (cur)
//    {
//        if (cur->val == val)
//        {
//            struct ListNode* next = cur->next;
//            //�ͷ�
//            free(cur);
//            //��������
//            if (prev == NULL)
//                head = next;
//            else
//                prev->next = next;
//
//            cur = next;
//        }
//        else
//        {
//            prev = cur;
//            cur = cur->next;
//        }
//    }
//    return head;
//}

//
//���㵥�����ͷ�ڵ� head �����㷴ת���������ط�ת�������
//
struct ListNode* reverseList(struct ListNode* head) {
   if(head == NULL || head->next == NULL)
	  return head;
   /* struct ListNode* newHead, * cur, * next;
    newHead = NULL;
    cur = head;
    while (cur)
    {
        next = cur->next;

        cur->next = newHead;
        newHead = cur;

        cur = next;
    }
    return newHead;*/
   //struct ListNode* n1, * n2, * n3;
   //n1 = NULL;
   //n2 = head;
   //n3 = n2->next;
   //while (n2)
   //{
   //    n2->next = n1;
   //    n1 = n2;
   //    n2 = n3;
   //    if (n3)
   //        n3 = n3->next;
   //}
   //return n1;
}

//����һ��ͷ���Ϊ head �ķǿյ���������������м��㡣

//����������м��㣬�򷵻صڶ����м��㡣


struct ListNode* middleNode(struct ListNode* head)
{
    //int count = 0;
    //struct ListNode* cur = head;
    //while (cur)
    //{
    //    count++;
    //    cur = cur->next;
    //}
    //int i = 0;
    //cur = head;
    //for (i = 0; i < (count / 2); i++)
    //{
    //    cur = cur->next;
    //}
    //return cur;
    struct ListNode* fast, * slow;
    fast = head;
    slow = head;
    while (fast != NULL && fast->next != NULL)
    {

        fast = fast->next->next;
        slow = slow->next;


    }
    return slow;
}
