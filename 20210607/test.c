#include<stdio.h>
//
//给你一个链表的头节点 head 和一个整数 val ，
//请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
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
//            //释放
//            free(cur);
//            //重新连接
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
//给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
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

//给定一个头结点为 head 的非空单链表，返回链表的中间结点。

//如果有两个中间结点，则返回第二个中间结点。


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
