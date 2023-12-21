typedef struct{
    int size;
    char* arr;
    int top;
} stack;

void initstack(stack* s){
    s->size = (10*10*10*10)+10;
    s->arr = (char*) malloc(s->size * (sizeof(char)));
    s->top = -1;
}

void put(stack* s, char data){
    s->top += 1;
    s->arr[s->top] = data;
}

char get(stack* s){
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

char* removeDuplicateLetters(char* s) {
    int frequency[26];
    int visited[26];
    for (int i=0;i<26;i++){
        frequency[i] = 0;
    }

    for (int i=0;i<strlen(s);i++){
        int k = s[i] - 'a';
        frequency[k] += 1;
    }

    stack* st = (stack*) malloc(sizeof(stack));
    initstack(st);

    int index = 0;
    while (index<strlen(s)){
        char curr = s[index];
        index++;
        int pos = curr - 'a';
        if (visited[pos]==1){
            printf("%c ",curr);
            frequency[pos] -= 1;
            continue;
        }
        visited[pos] = 1;
        if (isempty(st)){
            put(st, curr);
            frequency[pos] -= 1;
        }
        else{
            int k = get(st) - 'a';
            while(!isempty(st) && get(st)>curr && frequency[k]!=0){
                visited[k] = 0;
                pop(st);
                if (!isempty(st)){
                    k = get(st) - 'a';
                }
            }
            put(st, curr);
            frequency[pos] -= 1;
        }
        printf("%c %d\n", get(st), st->top);
    }

    char* result = (char*)malloc((st->top + 2) * sizeof(char)); // +2 for null-terminator and one-based index
    int i = st->top;
    result[st->top+1] = '\0';
    while (i >= 0) {
        result[i] = get(st);
        pop(st);
        i--;
    }
    return result;


}
