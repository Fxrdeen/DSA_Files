#include <stdio.h>
#include <stdlib.h>

int count=0;

typedef struct queue{
  int data;
  struct queue *next;
}Q;

Q* createNode(int data){
  Q* temp = (Q*)malloc(sizeof(Q));
  temp->data = data;
  temp->next = NULL;
  return temp;
}

Q* Enqueue(Q* head,int data, int capacity){
  Q* temp = createNode(data);
  if (head==NULL) head=temp;
  else{
    if (count>=capacity){
      printf("Capacity is full\n");return head;;
    }
    temp->next = head;
    head = temp;
  }
  count++;
  return head;
}

void Dequeue(Q* head){
  Q* p = head;
  if (head==NULL){
    printf("The queue is empty\n");
    return;
  } if (head->next == NULL){
    free(head); head = NULL; count--; return;
  }
  p = head;
  while(p->next->next!=NULL){
    p = p->next; 
  }
  free(p->next); p->next = NULL; count--;
  return;
}

void Display(Q* head){
  Q* p = head;
  while(p!=NULL){
    printf("%d ",p->data); p = p->next;
  }
  printf("\n");
}

int main(){
  Q* head = NULL;
  printf("Enter the Capacity of the queue:");
  int capacity;
  scanf("%d",&capacity);
  head = Enqueue(head,1,capacity);
  head = Enqueue(head,2,capacity);
  head = Enqueue(head,3,capacity);
  head = Enqueue(head,4,capacity);
  head = Enqueue(head,5,capacity);
  Display(head);
  Dequeue(head);
  head = Enqueue(head, 6,capacity); 
  Display(head);
  Dequeue(head);
  head = Enqueue(head, 7,capacity); 
  Display(head);
  Display(head);
  head = Enqueue(head, 8,capacity); 
  Display(head);
  Dequeue(head);
  Dequeue(head);
  Display(head);
}

