typedef struct {
    int size;
    int* arr;
    int front;
    int top;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* mq = (MyCircularQueue*) malloc(sizeof(MyCircularQueue));
    mq->size = k;
    mq->arr = (int*) malloc(k*sizeof(int));
    mq->front = -1;
    mq->top = -1;
    return mq;
}

int myCircularQueueEnQueue(MyCircularQueue* mq, int value) {
    if (mq->top==-1){
        mq->front = 0;
        mq->top = 0;
        mq->arr[0] = value;
        return 1;
    }
    else{
        if (mq->top+1==mq->front){
            return 0;
        }
        else{
            if (mq->top==mq->size-1){
                if (mq->front>0){
                    mq->arr[0] = value;
                    mq->top = 0;
                    return 1;
                }
                else{
                    return 0;
                }
            }
            else{
                mq->top += 1;
                mq->arr[mq->top] = value;
                return 1;
            }
        }
    }
}

int myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->top==-1){
        return 0;
    }
    else{
        if (obj->front==obj->top){
            obj->front = obj->top = -1;
        }
        else if (obj->front==obj->size-1){
            obj->front = 0;
        }
        else{
            obj->front += 1;
        }
        return 1;
    }
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj->top==-1){
        return -1;
    }
    return obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj->top==-1){
        return -1;
    }
    return obj->arr[obj->top];
}

int myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if (obj->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int myCircularQueueIsFull(MyCircularQueue* obj) {
    if (obj->top==obj->size-1){
        if (obj->front==0){
            return 1;
        }
        return 0;
    }
    else{
        if (obj->top+1==obj->front){
            return 1;
        }
        else{
            return 0;
        }
    }
}


