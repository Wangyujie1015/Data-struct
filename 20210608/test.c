#include<stdio.h>

//��������������ϲ�Ϊһ���µ� ���� �������ء�
//��������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ� 
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    // if(l1 == NULL ||l2 == NULL)
    // return l1 == NULL ? l2 : l1;
    // struct ListNode* cur1,*cur2,*newHead,*newTail; 
    // cur1 = l1;
    // cur2 = l2;
    // newHead = newTail = NULL;
    // //ͬʱ����
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

    //2.0�ȸ�ͷ���
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

    // //ͬʱ����
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
//    //ͬʱ����
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



//����һ�����ͷָ�� ListNode* pHead����һ��ֵx��
//��дһ�δ��뽫����С��x�Ľ������������֮ǰ���Ҳ��ܸı�ԭ��������˳�򣬷����������к�������ͷָ�롣
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
//    //����������Ϊ��,ƴ��
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

        //�м�ڵ�
        struct ListNode* fast, * slow;
        fast = slow = A;
        while (fast == NULL && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        //ͷ�������ת
        struct ListNode* newhead = NULL;
        struct ListNode* cur = slow;
        while (cur)
        {
            struct ListNode* next = cur->next;

            cur->next = newhead;
            newhead = cur;

            cur = next;
        }
        //ͬʱ����
        while (A && newhead)
        {
            if (A->val != newhead->val)
                return false;
            A = A->next;
            newhead = newhead->next;
        }
        return true;
    }