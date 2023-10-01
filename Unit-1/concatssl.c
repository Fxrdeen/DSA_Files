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
NODE* insertFront(NODE* head, int el){
  NODE* temp = createNode(el);
  if (head==NULL)
    head = temp;
  else{
    temp->next = head;
    head = temp;
  }
  return head;
}

void displayList(NODE* head){
  NODE* p = head;
  while(p!=NULL){
    printf("%d->",p->val);
    p = p->next;
  }
  printf("NULL\n");
}

NODE* listConcat(NODE* head1, NODE* head2){
  NODE* p = head1;
  while(p->next!=NULL){
    p = p->next;
  }
  p->next = head2;
  return head1;
}

int main(){
  printf("Enter the number of elements in the first List:");
  int el1;
  scanf("%d",&el1);
  printf("Enter the number of elements in the second List:");
  int el2;
  scanf("%d",&el2);
  NODE* head1 = NULL;
  NODE* head2 = NULL;
  for(int i=0;i<el1;i++){
    printf("Enter the value of the node:");
    int val; scanf("%d",&val);
    head1 = insertFront(head1, val);
  }
  for(int i=0;i<el2;i++){
    printf("Enter the value of the node:");
    int val; scanf("%d",&val);
    head2 = insertFront(head2, val);
  }
  printf("\n");
  printf("The list-1 is:\n");
  displayList(head1);
  printf("\n");
  printf("The list-2 is:\n");
  displayList(head2);
  printf("\n");
  printf("The lists after concatenation is:\n");
  head1 = listConcat(head1, head2);
  displayList(head1);
}
