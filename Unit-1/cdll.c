#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int val;
  struct Node *llink;
  struct Node *rlink;
} NODE;


NODE* createNode(int val){
  NODE* temp = (NODE*)malloc(sizeof(NODE));
  temp->val = val;
  temp->rlink = NULL;
  temp->llink = NULL;
  return temp;
}

void insertFront(NODE* head, NODE* tail, int val){
  NODE* temp = createNode(val);
  if (head==NULL){
    temp->rlink = temp;
    temp->llink = temp;
    head = temp;
    tail = temp;
    return;
  }
  temp->rlink = head;
  head = temp;
  temp->llink = tail;
  tail->rlink = head;
}

void display(NODE* head, NODE* tail){
  NODE* p = head;
while(p!=tail){
    printf("%d->",p->val);
    p=p->rlink;
  }
}

int main(){
  int choice;
  NODE* head = NULL; int val;
  NODE* tail = NULL;
  do {
    printf("1. InsertFront\n");
    printf("2. Display List\n");
    printf("Enter your choice:"); scanf("%d",&choice);
    switch (choice) {
      case 1:
        printf("Enter the value to be inserted:");
        scanf("%d",&val);
        insertFront(head,tail, val);
        break;
      case 2:
        printf("The list is:\n");
        display(head, tail);
        break;
    }
  } while(choice<3);
}

