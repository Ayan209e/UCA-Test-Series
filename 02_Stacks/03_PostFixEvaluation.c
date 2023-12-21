#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


typedef struct{
    int size;
    int* arr;
    int top;
} stack;

void initstack(stack* s){
    s->size = (10*10*10)+10;
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

int postfix_eval(char arr[][10], int count){
    stack* st = (stack*) malloc(sizeof(stack));
    initstack(st);
    for (int i=0;i<count;i++){
        if (strcmp(arr[i],"+" )==0){
            int first = get(st);
            pop(st);
            int second = get(st);
            pop(st);
            put(st, first + second);
        }
        else if (strcmp(arr[i],"-" )==0){
            int first = get(st);
            pop(st);
            int second = get(st);
            pop(st);
            put(st, second - first);
        }
        else if (strcmp(arr[i],"*" )==0){
            int first = get(st);
            pop(st);
            int second = get(st);
            pop(st);
            put(st, first * second);
        }
        else if (strcmp(arr[i],"/" )==0){
            int first = get(st);
            pop(st);
            int second = get(st);
            pop(st);
            put(st, second/first);
        }
        else{
            int index = 0;
            int num = 0;
            while(index<strlen(arr[i])){
                int k = arr[i][index++] - '0';
                num = num*10 + k;
            }
            put(st, num);
        }
    }
    return get(st);
}

int main() {
    int n;
    scanf("%d",&n);
    while (n--){
        char arr[1000][10];
        int count = 0;
        
        while (1){
            scanf("%s",arr[count]);
            if (strcmp(arr[count], "?")==0){
                break;
            }
            count = count+1;
        }
        int ans = postfix_eval(arr, count);
        printf("%d\n", ans);
    }
       
    return 0;
}