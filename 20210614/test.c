
//循环队列
typedef struct {
    //队头元素位置
    int _front;
    //队尾元素的下一个位置
    int _rear;
    //队列容量
    int _k;
    //  存放元素空间首地址
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
    //队列已满,不能入队
    if (myCircularQueueIsFull(obj))
        return false;
    //队尾入队
    obj->_data[obj->_rear++] = value;

    //判断队尾是否越界
    if (obj->_rear > obj->_k)
    {
        obj->_rear = 0;
    }
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
    //队列为空,出队失败
    if (myCircularQueueIsEmpty(obj))
        return false;
    //队头出队
    obj->_front++;

    //判断队头是否越界
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



 //2..0 加入_size元素,记录多少有效数据
typedef struct {
    //队头元素位置
    int _front;
    //队尾元素的下一个位置
    int _rear;
    //队列容量
    int _k;
    //队列实际元素
    int _size;
    //  存放元素空间首地址
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
    //队列已满,不能入队
    if(myCircularQueueIsFull(obj))
    return false;
    //队尾入队
    obj->_data[obj->_rear++] = value;

    //判断队尾是否越界
    if(obj->_rear >= obj->_k)
    {
        obj->_rear = 0;
    }
    obj->_size++;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj)
 {
    //队列为空,出队失败
    if(myCircularQueueIsEmpty(obj))
    return false;
    //队头出队
    obj->_front++;

    //判断队头是否越界
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
