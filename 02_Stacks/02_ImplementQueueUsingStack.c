typedef struct{
    int size;
    int* arr;
    int top;
} stack;

void initstack(stack* s){
    s->size = (10*10*10*10)+10;
    s->arr = (int*) malloc(s->size * (sizeof(int)));
    s->top = -1;
}

void put(stack* s, int data){
    s->top += 1;
    s->arr[s->top] = data;
}

int get(stack* s){
    return s->arr[s->top];
}

void pop(stack* s){
    s->top -= 1;
}

int isempty(stack* s){
    if (s->top==-1){
        return 1;
    }
    return 0;
}


typedef struct {
    stack* first;
    stack* second;
} MyQueue;

void initQueue(MyQueue* q, stack* s1, stack* s2){
    q->first = s1;
    q->second = s2;
}


MyQueue* myQueueCreate() {
    stack* st1 = (stack*) malloc(sizeof(stack));
    stack* st2 = (stack*) malloc(sizeof(stack));
    initstack(st1);
    initstack(st2);
    MyQueue* mq = (MyQueue*) malloc(sizeof(MyQueue));
    initQueue(mq, st1, st2);
    return mq;
}

void myQueuePush(MyQueue* obj, int x) {
    put(obj->first, x);
}

int myQueuePop(MyQueue* obj) {
    if (isempty(obj->first)){
        return -1;
    }
    while (!isempty(obj->first)){
        put(obj->second, get(obj->first));
        pop(obj->first);
    }
    int ans = get(obj->second);
    pop(obj->second);
    while(!isempty(obj->second)){
        put(obj->first, get(obj->second));
        pop(obj->second);
    }
    return ans;
}

int myQueuePeek(MyQueue* obj) {
    if (isempty(obj->first)){
        return -1;
    }
    while (!isempty(obj->first)){
        put(obj->second, get(obj->first));
        pop(obj->first);
    }
    int ans = get(obj->second);
    while(!isempty(obj->second)){
        put(obj->first, get(obj->second));
        pop(obj->second);
    }
    return ans;
}

int myQueueEmpty(MyQueue* obj) {
    return isempty(obj->first);
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}
