#include<stdio.h>

//将两个升序链表合并为一个新的 升序 链表并返回。
//新链表是通过拼接给定的两个链表的所有节点组成的。 
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    // if(l1 == NULL ||l2 == NULL)
    // return l1 == NULL ? l2 : l1;
    // struct ListNode* cur1,*cur2,*newHead,*newTail; 
    // cur1 = l1;
    // cur2 = l2;
    // newHead = newTail = NULL;
    // //同时遍历
    // while(cur1 && cur2)
    // {
    //     if(cur1->val <= cur2->val)
    //     {
    //         if(newTail == NULL)
    //         {
    //         newHead =  newTail = cur1;
    //         }

    //     else
    //     {
    //         newTail->next = cur1;
    //         newTail = newTail->next;
    //     }
    //     cur1 = cur1->next;
    //     }
    //     else
    //     {
    //         if(newTail == NULL)
    //         newHead = newTail = cur2;
    //         else
    //         {
    //             newTail->next = cur2;
    //             newTail = newTail->next;
    //         }
    //         cur2 = cur2->next;
    //     }
    // }
    // if(cur1)
    // newTail->next = cur1;
    // if(cur2)
    // newTail->next = cur2;
    // return newHead;

    //2.0先给头结点
    //  if(l1 == NULL ||l2 == NULL)
    // return l1 == NULL ? l2 : l1;
    // struct ListNode* cur1,*cur2,*newHead,*newTail; 

    // if(l1->val <= l2->val)
    // {
    //     newHead = newTail = l1;
    //     l1 = l1->next;
    // }
    // else
    // {
    //     newHead = newTail = l2;
    //     l2 = l2->next;
    // }
    // cur1 = l1;
    // cur2 = l2; 

    // //同时遍历
    // while(cur1 && cur2)
    // {
    //     if(cur1->val <= cur2->val)
    //     {
    //     newTail->next = cur1;
    //     newTail = newTail->next;
    //     cur1 = cur1->next;
    //     }
    //     else
    //     {

    //         newTail->next = cur2;
    //         newTail = newTail->next;
    //         cur2 = cur2->next;
    //     }
    // }
    // if(cur1)
    // newTail->next = cur1;
    // if(cur2)
    // newTail->next = cur2;
    // return newHead;

//    if (l1 == NULL || l2 == NULL)
//        return l1 == NULL ? l2 : l1;
//    struct ListNode* cur1, * cur2, * newHead, * newTail;
//    newHead = newTail = (struct ListNode*)malloc(sizeof(struct ListNode));
//    cur1 = l1;
//    cur2 = l2;
//
//    //同时遍历
//    while (cur1 && cur2)
//    {
//        if (cur1->val <= cur2->val)
//        {
//            newTail->next = cur1;
//            newTail = newTail->next;
//            cur1 = cur1->next;
//        }
//        else
//        {
//
//            newTail->next = cur2;
//            newTail = newTail->next;
//            cur2 = cur2->next;
//        }
//    }
//    if (cur1)
//        newTail->next = cur1;
//    if (cur2)
//        newTail->next = cur2;
//    struct ListNode* head = newHead->next;
//    free(newHead);
//
//    return head;
//
//}



//现有一链表的头指针 ListNode* pHead，给一定值x，
//编写一段代码将所有小于x的结点排在其余结点之前，且不能改变原来的数据顺序，返回重新排列后的链表的头指针。
//
ListNode* partition(ListNode* pHead, int x) {
//    if (pHead == NULL)
//        return pHead;
//    struct  ListNode* lesshead, * greaterhead, * lesstail, * greatertail, * cur;
//    lesshead = greaterhead = lesstail = greatertail = NULL;
//    cur = pHead;
//    while (cur)
//    {
//        if (cur->val < x)
//        {
//            if (lesstail == NULL)
//            {
//                lesshead = lesstail = cur;
//            }
//            else
//            {
//                lesstail->next = cur;
//                lesstail = lesstail->next;
//            }
//
//            cur = cur->next;
//
//        }
//        else
//        {
//            if (greatertail == NULL)
//            {
//                greaterhead = greatertail = cur;
//            }
//            else
//            {
//                greatertail->next = cur;
//                greatertail = greatertail->next;
//            }
//            cur = cur->next;
//
//        }
//    }
//    if (greatertail)
//        greatertail->next = NULL;
//    if (lesshead == NULL)
//        return greaterhead;
//    if (greaterhead == NULL)
//    {
//        if (lesstail)
//            lesstail->next = NULL;
//        return lesshead;
//    }
//
//    //两个链表都不为空,拼接
//    lesstail->next = greaterhead;
//    return lesshead;

//
//
//if (pHead == NULL)
//        return pHead;
//    struct  ListNode* lesshead, * greaterhead, * lesstail, * greatertail, * cur;
//    lesshead = lesstail = (struct ListNode*)malloc(sizeof(struct ListNode));
//    greaterhead = greatertail = (struct ListNode*)malloc(sizeof(struct ListNode));
//    cur = pHead;
//    while (cur)
//    {
//        if (cur->val < x)
//        {
//            lesstail->next = cur;
//            lesstail = lesstail->next;
//            cur = cur->next;
//
//        }
//        else
//        {
//          
//                greatertail->next = cur;
//                greatertail = greatertail->next;
//            
//            cur = cur->next;
//
//        }
//    }
//    if (greatertail)
//        greatertail->next = NULL;
//    struct  ListNode* newhead = lesshead->next;
//    lesstail->next = greaterhead->next;
//    free(lesshead);
//    free(lesstail);
//    free(greaterhead);
//    free(greatertail);
//
//    return newhead;

//}


    bool chkPalindrome(ListNode * A) {
        if (A == NULL || A->next == NULL)
            return true;

        //中间节点
        struct ListNode* fast, * slow;
        fast = slow = A;
        while (fast == NULL && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        //头插进行逆转
        struct ListNode* newhead = NULL;
        struct ListNode* cur = slow;
        while (cur)
        {
            struct ListNode* next = cur->next;

            cur->next = newhead;
            newhead = cur;

            cur = next;
        }
        //同时遍历
        while (A && newhead)
        {
            if (A->val != newhead->val)
                return false;
            A = A->next;
            newhead = newhead->next;
        }
        return true;
    }