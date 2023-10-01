#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int val;
  struct Node *rlink;
  struct Node *llink;
}NODE;

NODE* createNode(int val){
  NODE* temp = (NODE*)malloc(sizeof(NODE));
  temp->val = val;
  temp->rlink = NULL;
  temp->llink = NULL;
  return temp;
}

NODE* insertNode(NODE* head, int val){
  NODE* temp = createNode(val);
  if (head == NULL)
    head = temp;
  else{
    temp->rlink = head;
    head->llink = temp;
    head = temp;
  }
  return head;
}

NODE* insertEnd(NODE* head, int val){
  NODE* temp = createNode(val);
  if (head == NULL)
    head = temp;
  else{
    NODE* p = head;
    while(p->rlink!=NULL){
      p = p->rlink;
    }
    p->rlink = temp;
    temp->llink = p;
  }
  return head;
}

void reverseLinkedList(NODE* head){
  int count=0;
  NODE* p = head;
  while(p!=NULL){
    count++;
    p=p->rlink;
  }
  int arr[count];
  p = head; int i=0;
  while(p!=NULL){
    arr[i] = p->val; i++;
    p=p->rlink;
  }
  p = head; i--;
  while(p!=NULL){
    p->val = arr[i];i--; p=p->rlink;
  }
}




NODE* insertBetween(NODE* head, int val, int pos){
  int count=0;
  NODE* temp = createNode(val);
  if (head == NULL){
    head = temp;
    return head;
  }
  NODE * p = head;
  while(p!=NULL){
    count++;
    p = p->rlink;
  }
  if (pos<0 || pos>count+1)
  {
    printf("Invalid position\n");
    return head;
  }
  p = head;
  for(int i=0;i<pos-2;i++){
    p = p->rlink;
  }
  temp->rlink = p->rlink;
  p->rlink = temp;
  return head;
}

NODE* deletePos(NODE* head, int pos){
  int count=0;
  if (head == NULL)
    return NULL;
  NODE* p = head;
  while(p!=NULL){
    count++;
    p = p->rlink;
  }
  if (pos<0 || pos>count){
    printf("Invalid position\n");
    return head;
  }
  p = head;
  for(int i=0;i<pos-2;i++){
    p = p->rlink;
  }
  p->rlink = p->rlink->rlink;
  p->rlink->llink = p;
  free(p->rlink);
  return head;
}


NODE* deleteFront(NODE* head){
  if (head==NULL)
    return NULL;
  if (head->rlink == NULL){
    NODE* p = head;
    free(p);
    head = NULL;
    return head;
  }
  NODE* p = head;
  head = head->rlink;
  free(p);
  head->llink = NULL;
  return head;
}

NODE* deleteEnd(NODE* head){
  if (head == NULL)
    return NULL;
  if (head->rlink == NULL){
    NODE* p = head;
    free(p);
    head = NULL;
    return head;
  }
  NODE* p = head;
  while(p->rlink->rlink!=NULL){
    p = p->rlink;
  }
  free(p->rlink);
  p->rlink = NULL;
  return head;
}

void displayListRight(NODE* head){
  if (head == NULL)
  {
    printf("The list is empty\n");
    return;
  }
  NODE* p = head;
  while(p!=NULL){
    printf("%d->",p->val);
    p = p->rlink;
  }
  printf("NULL\n");
}
void displayListLeft(NODE* head){
  if (head == NULL)
  {
    printf("List is empty\n");
    return;
  }
  NODE* p = head;
  while(p->rlink!=NULL){
    p = p->rlink;
  }
  while(p!=NULL){
    printf("%d->",p->val);
    p = p->llink;
  }
  printf("NULL\n");
}


int main(){
  int choice; int val; int pos;
  NODE* head = NULL;
  do{
    printf("1. Element to be inserted (InsertFront)\n");
    printf("2. Element to be inserted (InsertEnd)\n");
    printf("3. Element to be inserted (INbetween)\n");
    printf("4. Display List using Right link\n");
    printf("5. Display List using Left Link\n");
    printf("6. Delete Front Element\n");
    printf("7. Delete End element\n");
    printf("8. Delete Element in between\n");
    printf("9. Reverse the linked list\n");
    printf("Enter your choice: "); scanf("%d",&choice);
    switch (choice) {
      case 1:
        printf("\nEnter the element to be inserted:"); scanf("%d",&val);
        head = insertNode(head, val); break;
      case 2:
        printf("\nEnter the element to be inserted:"); scanf("%d",&val);
        head = insertEnd(head, val);
        break;
      case 3:
        printf("\nEnter the element to be inserted:");
        scanf("%d",&val);
        printf("\nEnter the position to be inserted at:");
        scanf("%d",&pos);
        head = insertBetween(head, val, pos); break;
      case 4:
        printf("The linked list is:\n");
        displayListRight(head);
        break;
      case 5:
        printf("THe linked list is:\n");
        displayListLeft(head);
        break;
      case 6:
        head = deleteFront(head);
        printf("The element has been deleted\n");
        break;
      case 7:
        head = deleteEnd(head);
        printf("The end element has been deleted\n");
        break;
      case 8:
        printf("Enter the position to be deleted at:");
        scanf("%d",&pos);
        head = deletePos(head, pos);
        printf("The element has been deleted\n");
      case 9:
        reverseLinkedList(head);
        printf("Linked list has been reversed\n");
    }

  }while(choice<10);
}
