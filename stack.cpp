#include <stdio.h>
#include <stdlib.h>

struct intNode {
    int data;
    struct intNode* next;
};

struct Stack {
    struct intNode* first;
};

void initStack(struct Stack* stack) {
    stack->first = NULL;
}

void pushStack(struct Stack* stack, int value) {
    struct intNode* newNode;
    newNode = (struct intNode*)malloc(sizeof(struct intNode));
    newNode->data = value;
    newNode->next = NULL;

    if (stack->first == NULL) { //If stack has no data
        stack->first = newNode;
    } else {
        newNode->next = stack->first;
        stack->first = newNode;
    }
}

int popStack(struct Stack* stack) {  
    int value;
    value = -1;
    if (stack->first == NULL) {
        printf("Stack is empty but tried to pop. \n");
    } else {
        value = stack->first->data;
        stack->first = stack->first->next;
    }
    return value;
}

int isEmptyStack(struct Stack* stack) {
    if (stack->first == NULL) { 
        return 1;
    } else {
        return 0;
    }
}

int main() {
    struct Stack s1;
    int cnt = 0;
    int num = 0;
    int tmp = 0;

    initStack(&s1);
    
    printf("How many integers do you want to input?\n> ");
    scanf("%d",&cnt);
    
    printf("Enter %d integers\n", cnt);
    for (int i = 0; i < cnt; i++) {
        printf("> ");
        scanf("%d", &num);
        pushStack(&s1, num);
    }
    
    while (isEmptyStack(&s1) == 0) {
        tmp = popStack(&s1);
        printf("Removed [%d]\n", tmp);
    }
    
    // struct Stack s1;
    // int a;
    // initStack(&s1);
    // pushStack(&s1, 10);
    // pushStack(&s1, 20);
    // pushStack(&s1, 30);

    // while (isEmptyStack(&s1) == 0) {
    //     a = popStack(&s1);
    //     printf("a = %d\n", a);
    // }
}
