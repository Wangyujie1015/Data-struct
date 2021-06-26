// 不允许遍历链表, 在 pos之前插入 
void LinkListInsertBefore(LinkNode** head, LinkNode* pos, LinkType value)
{
    if (head == NULL)
    {
        //非法输入
        return;
    }
    if (*head == NULL)
    {
        *head = CreateNode(value);
        return;
    }
    if (pos == NULL)
    {
        return;
    }
    if (pos == *head)
    {
        LinkListPushFront(head, value);
        return;
    }
    LinkNode* new_node = CreateNode(pos->data);
    LinkNode* next = pos->next;
    pos->next = new_node;
    new_node->next = next;
    pos->data = value;
    return;
}
