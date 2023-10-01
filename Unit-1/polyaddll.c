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


NODE* insertEnd(NODE* head, int val){
  NODE* temp = createNode(val);
  if (head==NULL){
    head = temp;
  } else{
    NODE* p = head;
    while(p->next!=NULL){
      p = p->next;
    }
    p->next = temp;
  }
  return head;
}

void displayList(NODE* head, int pow){
  NODE* p = head;
  while(p!=NULL){
    printf("%dx^%d+ ",p->val,pow);
    pow--;
    p = p->next;
  }
}



int main(){
  NODE* head1 = NULL;
  NODE* head2 = NULL;
  printf("We are adding 2 polynomials\n");
  printf("Enter the highest power of the polynomial: ");
  int p; scanf("%d",&p); int a = p+1;
  while(a){
    printf("Enter the coefficient of x^%d of polynomial 1: ",a-1);
    int el; scanf("%d",&el);
    head1 = insertEnd(head1, el); a--;
  }
  printf("\n");
  a = p+1;
  while(a){
     printf("Enter the coefficient of x^%d of polynomial 2: ",a-1);
    int el; scanf("%d",&el);
    head2 = insertEnd(head2, el);
    a--;
  }
  NODE* head3 = NULL;
  printf("\nThe first polynomial is: \n\n");
  displayList(head1, p);
  printf("\n\nThe Second polynomail is :\n");
  displayList(head2, p);
  printf("\nThe addition of both the polynomials is:\n");
  for(int i=p+1;i>0;i--){
    head3 = insertEnd(head3, head1->val+head2->val);
    head1 = head1->next;
    head2 = head2->next;
  }
  displayList(head3,p);
  


}
