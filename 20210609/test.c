

//给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。
// 如果两个链表没有交点，返回 null 。
//
//
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//    struct ListNode* cura, * curb;
//    cura = headA;
//    curb = headB;
//    int lena = 0;
//    int lenb = 0;
//    while (cura)
//
//    {
//        lena++;
//        cura = cura->next;
//    }
//    while (curb)
//    {
//        lenb++;
//        curb = curb->next;
//    }
//    int gat = abs(lena - lenb);
//    cura = headA;
//    curb = headB;
//    if (lena > lenb)
//    {
//        while (gat--)
//        {
//            cura = cura->next;
//        }
//    }
//    else
//    {
//        while (gat--)
//        {
//            curb = curb->next;
//        }
//    }
//
//    //同时走
//    while (cura && curb)
//    {
//        if (cura == curb)
//            return cura;
//        cura = cura->next;
//        curb = curb->next;
//    }
//
//    return NULL;
//}
//
//给定一个链表，判断链表中是否有环。
//
//bool hasCycle(struct ListNode* head) {
//    if (head == NULL)
//        return false;
//    struct ListNode* fast, * slow;
//    fast = slow = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//        if (fast == slow)
//            return true;
//
//    }
//    return false;
//}


//复制带随机指针的链表
//
//struct Node* copyRandomList(struct Node* head) {
//    if (head == NULL)
//        return head;
//    struct Node* cur = head;
//    //拷贝数据
//    while (cur)
//    {
//        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//        newNode->val = cur->val;
//        newNode->next = cur->next;
//        cur->next = newNode;
//        cur = newNode->next;
//    }
//    //拷贝随机指针
//    cur = head;
//    while (cur)
//    {
//        struct Node* copy = cur->next;
//        if (cur->random)
//            copy->random = cur->random->next;
//        else
//            copy->random = NULL;
//
//        cur = copy->next;
//    }
//    //拆链
//    struct Node* newHead = NULL;
//    cur = head;
//    while (cur)
//    {
//        struct Node* copy = cur->next;
//        struct Node* next = copy->next;
//
//        cur->next = next;
//        if (newHead == NULL)
//            newHead = copy;
//        if (next)
//            copy->next = next->next;
//
//        cur = next;
//    }
//    return newHead;
//}