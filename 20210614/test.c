
//ѭ������
typedef struct {
    //��ͷԪ��λ��
    int _front;
    //��βԪ�ص���һ��λ��
    int _rear;
    //��������
    int _k;
    //  ���Ԫ�ؿռ��׵�ַ
    int* _data;
} MyCircularQueue;


bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->_front == obj->_rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->_rear + 1) % (obj->_k + 1) == obj->_front;
}


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    cq->_data = (int*)malloc(sizeof(int) * (k + 1));
    cq->_k = k;
    cq->_front = cq->_rear = 0;
    return cq;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    //��������,�������
    if (myCircularQueueIsFull(obj))
        return false;
    //��β���
    obj->_data[obj->_rear++] = value;

    //�ж϶�β�Ƿ�Խ��
    if (obj->_rear > obj->_k)
    {
        obj->_rear = 0;
    }
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
    //����Ϊ��,����ʧ��
    if (myCircularQueueIsEmpty(obj))
        return false;
    //��ͷ����
    obj->_front++;

    //�ж϶�ͷ�Ƿ�Խ��
    if (obj->_front > obj->_k)
        obj->_front = 0;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    return obj->_data[obj->_front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    if (obj->_rear != 0)
        return obj->_data[obj->_rear - 1];
    else
        return obj->_data[obj->_k];

}


void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->_data);
    free(obj);
}



 //2..0 ����_sizeԪ��,��¼������Ч����
typedef struct {
    //��ͷԪ��λ��
    int _front;
    //��βԪ�ص���һ��λ��
    int _rear;
    //��������
    int _k;
    //����ʵ��Ԫ��
    int _size;
    //  ���Ԫ�ؿռ��׵�ַ
    int* _data;
} MyCircularQueue;


bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
   return obj->_size == 0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
   return obj->_size == obj->_k;
}


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* cq = (MyCircularQueue*) malloc(sizeof(MyCircularQueue));
    cq->_data = (int*)malloc(sizeof(int)* k);
    cq->_k = k;
    cq->_front = cq->_rear = 0;
    cq->_size = 0;
    return cq;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    //��������,�������
    if(myCircularQueueIsFull(obj))
    return false;
    //��β���
    obj->_data[obj->_rear++] = value;

    //�ж϶�β�Ƿ�Խ��
    if(obj->_rear >= obj->_k)
    {
        obj->_rear = 0;
    }
    obj->_size++;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj)
 {
    //����Ϊ��,����ʧ��
    if(myCircularQueueIsEmpty(obj))
    return false;
    //��ͷ����
    obj->_front++;

    //�ж϶�ͷ�Ƿ�Խ��
    if(obj->_front >= obj->_k)
    obj->_front = 0;  
    
    obj->_size--;
    return true;

}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
    return -1;
    return obj->_data[obj->_front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
    return -1;
    if(obj->_rear != 0)
      return obj->_data[obj->_rear -1];
    else
    return obj->_data[obj->_k - 1]; 
    
}


void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->_data);
    free(obj);
}
