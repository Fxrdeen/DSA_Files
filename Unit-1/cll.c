#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int val;
  struct Node *next;
}NODE;

NODE* createNode(int val){
  NODE* temp = (NODE*)malloc(sizeof(NODE));
  temp->val = val;
  temp->next = NULL;
  return temp;
}

NODE* insertFront(NODE* tail, int val){
  NODE* temp = createNode(val);
  if (tail == NULL){
    tail = temp;
    temp->next = temp;
    return tail;
  }
  temp->next = tail->next;
  tail->next = temp;
  return tail;
}

void displayList(NODE* tail){
  if (tail == NULL)
    printf("Tail is NULL\n");
  NODE* p = tail->next;
  while(p!=tail){
    printf("%d->",p->val);
    p = p->next;
  }
  printf("%d->",tail->val);
  printf("%d",tail->next->val);
  printf("\n");
}

void deleteVal(NODE* tail, int val){
  if (tail == NULL){
    printf("The list is empty\n");
    return;
  } 
  if (tail->next == tail){
    if (tail->val == val){
      NODE* p=tail;
      free(p);
      tail = NULL;
    } else{
      printf("The Key does not match any element\n");
    }
    return;
  }
  NODE* start = tail->next; NODE* prev=start;
  while(start->next != tail){
    if (start->val == val){

    }
    prev = start;
    start = start->next;
  }







}

int main(){
  NODE* head = NULL;
  NODE* tail = NULL;
  int choice;
  do {
    printf("1. Insert Front\n");
    printf("2. Display List\n");
    printf("3. Delete Key\n");
    printf("Enter your choice:"); scanf("%d",&choice);
    switch (choice) {
      case 1:
        printf("Enter the value to be inserted:");
        int val;
        scanf("%d",&val);
        tail = insertFront(tail, val);
        break;
      case 2:
        printf("The list is:\n");
        displayList(tail);
        break;
      case 3:
        printf("Enter the value to be deleted:"); scanf("%d",&val);
        deleteVal(tail, val);
        printf("The element has been deleted\n");
        break;
    }
  } while (choice<4);
}
