#include <stdio.h>
#include <stdlib.h>

// Write a funciton to insert a node before/after a node with the given key value



int count=0;

typedef struct Node{
  int val;
  struct Node* next;
}NODE;

NODE* createNode(int el){
  NODE* temp = (NODE*)malloc(sizeof(NODE));
  temp->val = el;
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


NODE* deleteFront(NODE* head){
  if (head == NULL)
    return NULL;
  else{
    NODE *p = head;
    head = p->next;
    free(p);
    return head;
  }
}

NODE * deleteLast(NODE* head){
  if (head == NULL)
    return NULL;
  else if (head->next == NULL){
    NODE* p = head;
    free(p);
    head = NULL;
    return head;
  }
  else{
    NODE* p = head;
    NODE* q = head->next;
    while(q->next!=NULL){
      q = q->next;
      p = p->next;
    }
    free(p->next);
    p->next = NULL;
  }
  return head;
}

NODE* deleteBetween(NODE* head, int pos){
  if (head == NULL){
    return head;
  } else{
    int bruh = 1;
    NODE *p1 = head;
    while(p1->next!=NULL){
      bruh++;
      p1=p1->next;
    }
    if (pos>bruh || pos<1){
      printf("Invalid Position given");
      return head;
    }
    NODE* p = head;
    NODE* q = p->next;
    while(pos--){
      q = q->next;
      p = p->next;
    }
    p->next = q->next;
    free(q);
  }
  return head;
}

NODE* deleteKey(NODE* head, int key){
  if (head == NULL)
    return NULL;
  else if (head->next == NULL){
    if (head->val == key){
      NODE* p = head;
      free(p);
      head = NULL;
      return head;
    } else{
      printf("Key is invalid\n");
    }
  } else{
    NODE* p = head;
    NODE* q = head->next;
    while(q->val!=key && q!=NULL){
      q = q->next;
      p = p->next;
    }
    if (q==NULL)
      printf("Key is invalid\n");
    else{
      p->next = q->next;
      free(q);
    }
  }
  return head;
}


NODE* insertBetween(NODE* head, int el, int pos){
  if (count==0 || pos==1)
    insertFront(head, el);
  else if (pos<0)
      insertFront(head,el);
  else if(pos>0 && pos<count){
    NODE* p = head;
    int c = 1;
    while(c<pos-1){
      p = p->next; c++;
    }
    NODE* temp = createNode(el);
    temp->val = el;
    temp->next = p->next;
    p-> next = temp;
  }
  else if (pos == count){
    NODE* p = head;
    int c = 1;
    while(c<pos){
      p = p->next; c++;
    }
    NODE* temp = createNode(el);
    temp->val = el;
    p->next = temp;
    temp->next = NULL;
  }
  else{
    printf("\nInvalid Position\n");
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

int main(){
  NODE* head = NULL; int pos;
  int choice;
  do{
    printf("\nEnter your choice:\n\n1. Add element to the list\n2. Display list");
    printf("\n3. Insert in between");
    printf("\n4. Delete The front element");
    printf("\n5. Delete the End element");
    printf("\n6. Delete the element in between");
    printf("\n\nEnter your choice: ");
    scanf("%d",&choice);
    int ele; 
    switch (choice) {
      case 1:
        printf("\nEnter the element :"); scanf("%d",&ele);
        head = insertFront(head,ele);
        count++;
        break;
      case 2:
        printf("\nThe linked list is :\n\n");
        displayList(head);
        printf("\n");
        break;
      case 3:
        printf("\nEnter the element: ");scanf("%d",&ele);
        printf("\nEnter the position: ");scanf("%d",&pos);
        head = insertBetween(head, ele, pos); count++;
        break;
      case 4:
        head = deleteFront(head);
        printf("\nFront element has been deleted\n");
      case 5:
        head = deleteLast(head);
        printf("\nThe last element has been deleted\n");
      case 6:
        printf("\nEnter the position of the element to be deleted");
        int pos; 
        scanf("%d",&pos);
        head = deleteBetween(head, pos);
        printf("The element has been deleted");

      default:
        break;

    };
  } while(choice<7);
}
