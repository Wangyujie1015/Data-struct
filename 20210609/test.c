

//���������������ͷ�ڵ� headA �� headB �������ҳ������������������ཻ����ʼ�ڵ㡣
// �����������û�н��㣬���� null ��
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
//    //ͬʱ��
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
//����һ�������ж��������Ƿ��л���
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


//���ƴ����ָ�������
//
//struct Node* copyRandomList(struct Node* head) {
//    if (head == NULL)
//        return head;
//    struct Node* cur = head;
//    //��������
//    while (cur)
//    {
//        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//        newNode->val = cur->val;
//        newNode->next = cur->next;
//        cur->next = newNode;
//        cur = newNode->next;
//    }
//    //�������ָ��
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
//    //����
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