#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
  int top;
  int capacity;
  int *array;
}STACK;

void createStack(STACK *st){
  printf("Enter the capacity of the stack\n");
  scanf("%d",&st->capacity);
  st->array = malloc(st->capacity*sizeof(int));
  st->top = 0;
}

int isfull(STACK *st){
  if (st->top == st->capacity)
    return 1;
  return 0;
}

void push(STACK* st, int ele){
  if (isfull(st)){
    printf("Stack is Full\n"); return;
  }
  st->array[st->top] = ele;
  st->top++;
}

int isEmpty(STACK *st){
  if (st->top==0)
    return 1;
  return 0;
}

void pop(STACK *st){
  if (isEmpty(st)){
    printf("Stack is empty\n");return;
  }
  st->array[st->top] = 0;
  st->top--;
}

void display(STACK *st){
  int count=0; printf("The stack is:\n");
  while(count<st->top){
    printf("%d ",st->array[count]);
    count++;
  }
  printf("\n");
}

int main(){
  STACK st;
  createStack(&st);
  pop(&st);
  push(&st, 1);
  push(&st, 2);
  push(&st, 3);
  printf("\nThe top element is: %d\n",st.top);
  display(&st);
  push(&st, 4);
  push(&st, 5);
  push(&st, 6);
  printf("\nThe top element is: %d\n",st.top);
  display(&st);
  pop(&st);
  pop(&st);
  display(&st);
  

}
