#include <stdio.h>
#include<stdlib.h>

typedef struct Queue{
  int size,front, rear, *arr;
}Q;

int isFull(Q* q){
  if ((q->rear+1)%(q->size) == q->front-1)
    return 1;
  return 0;
}

int isEmpty(Q* q){
  if (q->front == q->rear)
    return 1;
  return 0;
}

void enqueue(Q* q, int val){
  if (isFull(q)){
    printf("This is queue is full\n");
  } else{
    q->rear = (q->rear+1)%q->size;
    q->arr[q->rear] = val;
  }
}

int dequeue(Q* q){
  int a=-1;
  if (isEmpty(q)){
    printf("The queue is empty\n");
  } else{
    q->front = (q->front+1)%(q->size);
    a = q->arr[q->front];
  }
  return a;
}

void display(Q* q){
  int i;
  for( i=q->front+1; i!=q->rear; i=(i+1)%(q->size)){
    printf("%d ",q->arr[i]);
  }
  printf("%d ",q->arr[i]);
  printf("\n");
}

int main(){
  Q q;
  q.rear = q.front = -1;
  q.size = 3;
  q.arr = (int*)malloc(q.size * sizeof(int));
  enqueue(&q, 12);
  enqueue(&q, 15);
  enqueue(&q, 16);

  display(&q);
  dequeue(&q);
  display(&q);
  enqueue(&q, 11);
  display(&q);

}




