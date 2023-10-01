#include <stdio.h>
#include<stdlib.h>

typedef struct {
    int priority;
    int data;
} Data;

typedef struct {
    int front;
    int rear;
    int capacity;
    Data *array;
} Queue;

int is_empty(Queue *ptrQ) {
    return ptrQ->front == -1;
}

int is_full(Queue *ptrQ) {
    return (ptrQ->rear + 1) % ptrQ->capacity == ptrQ->front;
}

int insert(Queue *ptrQ, Data ele) {
    if (is_full(ptrQ)) {
        printf("Queue is full. Cannot insert.\n");
        return 0; 
    }

    int i = ptrQ->rear;
    while (i >= ptrQ->front && ptrQ->array[i].priority > ele.priority) {
        ptrQ->array[(i + 1) % ptrQ->capacity] = ptrQ->array[i];
        i = (i - 1 + ptrQ->capacity) % ptrQ->capacity;
    }

    

    ptrQ->array[(i + 1) % ptrQ->capacity] = ele;
    ptrQ->rear = (ptrQ->rear + 1) % ptrQ->capacity;

    if (ptrQ->front == -1) {
        ptrQ->front = 0;
    }

    return 1;
}

int createNode(NODE* head, inte ele){
}
int deleteQ(QueueLL *ptr){

}





int main() {
    Queue Q;
    Q.front = -1; 
    Q.rear = 0;
    Q.capacity = 5; 
    Q.array = (Data *)malloc(Q.capacity * sizeof(Data)); 

    if (Q.array == NULL) {
        printf("Memory allocation failed.\n");
        return 1; 
    }
    Data ele1 = {2, 42};
    Data ele2 = {1, 17};
    Data ele3 = {3, 8};

    insert(&Q, ele1);
    insert(&Q, ele2);
    insert(&Q, ele3);

    printf("Queue elements:\n");
    int i = Q.front;
    while (i != Q.rear) {
        printf("Priority: %d, Data: %d\n", Q.array[i].priority, Q.array[i].data);
        i = (i + 1) % Q.capacity;
    }

    free(Q.array);

    return 0;
}
