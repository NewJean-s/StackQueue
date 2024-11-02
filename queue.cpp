#include <stdio.h>
#include <stdlib.h>

struct intNode {
    int data;
    struct intNode* next;
};

struct Queue {
    struct intNode* first;
};

void initQueue(struct Queue* queue) {
    (*queue).first = NULL;

}

void printQueue(struct Queue* queue) {
    struct intNode* temp;
    temp = queue->first;
    while (temp != NULL) {
        printf("[%d] -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertQueue(struct Queue* queue, int value) {
    struct intNode* newNode;
    struct intNode* last;
    newNode = (struct intNode*)malloc(sizeof(struct intNode));
    newNode->data = value;
    newNode->next = NULL;

    if (queue->first == NULL) { //If queue has no data
        queue->first = newNode;
    } else { //If queue has more than one data
        last = queue->first;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
    }
}

int removeQueue(struct Queue* queue) {
    int value;
    value = -1;
    if (queue->first == NULL) { //If queue has no data
        printf("Try to remove data for an empty queue.\n");
    } else {
        value = (queue->first)->data;
        queue->first = queue->first->next;
    }

    return value;
}

int isEmptyQueue(struct Queue queue) {
    if (queue.first == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int getSizeQueue(struct Queue queue) {
    int cnt = 0;
    struct intNode* tmp;
    tmp = queue.first;
    while (tmp != NULL) {
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}

int main() {
    struct Queue q1;
    int cnt = 0;
    int num = 0;
    int tmp = 0;

    initQueue(&q1);
    
    printf("How many integers do you want to input?\n> ");
    scanf("%d",&cnt);
    
    printf("Enter %d integers\n", cnt);
    for (int i = 0; i < cnt; i++) {
        printf("> ");
        scanf("%d", &num);
        insertQueue(&q1, num);
    }
    
    while (isEmptyQueue(q1) == 0) {
        tmp = removeQueue(&q1);
        printf("Removed [%d]\n", tmp);
    }
    

    // insertQueue(&q1, 10);
    // insertQueue(&q1, 20);
    // insertQueue(&q1, 30);
    // printQueue(&q1);

    // a = removeQueue(&q1);
    // printf("a = %d \n", a);
    // printQueue(&q1);

    // while (isEmptyQueue(q1) == 0) {
    //     a = removeQueue(&q1);
    //     printf("a = %d\n", a);
    // }
}
