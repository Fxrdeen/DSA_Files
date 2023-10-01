#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  struct Node *next;
}NODE;

typedef struct linkedliststack{
  NODE* top;
  int count;
}LLS;

LLS* createLinkedListStack(){
  LLS *lls = (LLS*)malloc(sizeof(LLS));
  lls->count=0;
  lls->top=NULL;
  return lls;
}

NODE* createNode(int ele){
  NODE* temp = (NODE*)malloc(sizeof(NODE));
  temp->data = ele;
  temp->next=NULL;
  return temp;
}


void push(LLS *lls,int data){
  NODE* temp = createNode(data);
  if (lls->count == 0){
    lls->count++;
    lls->top = temp;
    return;
  }
  lls->top->next = temp;
  lls->top = temp;
  lls->count++; 
  
}

void pop(LLS* lls){

}

void display(LLS *lls){
  NODE *p = lls->top;
  while(p->next!=NULL){
    printf("%d ",p->data);
    p = p->next;
  }
}

int main(){
  LLS *lls;
  lls = createLinkedListStack();
  int choice;
  do {
    printf("1. Push Element to the stack\n");
    printf("2. Pop element from the stack\n");
    printf("3. Display the stack\n");
    printf("4. Peek the topmost element from the stack\n");
    printf("Enter the choice:"); scanf("%d",&choice);
    switch (choice) {
      case 1: 
        printf("Enter the Element to be added:"); int el;
        scanf("%d",&el);
        push(lls, el);
        break;
      case 3:
        display(lls); break;
    }
  }while (choice<4);
}
