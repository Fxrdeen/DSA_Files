#include <stdio.h>
#include <stdlib.h>

int count=0;
unsigned long n=1;


int* push_back(int* list){
  if (count<n){
    int val; printf("Enter the value to be inserted:");
    scanf("%d",&val);
    list[count] = val;
    count++;
  } else{
    n=n*2;
    list = realloc(list, n*sizeof(int));
    int val; printf("Enter the value to be inserted:");
    scanf("%d",&val);
    list[count] = val;
    count++;
  }
  return list;
}

int* DeleteLast(int* list){
  if (count==0)
    printf("List is empty\n");
  else{
    list[count] = 0;
    count--;
  }
  return list;
}

int* insertFront(int* list){
  if (count+1<n){
    int val; printf("Enter the value to be inserted:");
    scanf("%d",&val);
    int arr[count];
    for(int i=0;i<count;i++)
      arr[i] = list[i];
    for(int i=1;i<=count;i++)
      list[i] = arr[i-1];
    list[0] = val;
  } else{
    n=n*2;
    list = realloc(list, n*sizeof(int));
    int val; printf("Enter the value to be inserted:");
    scanf("%d",&val);
    int arr[count];
    for(int i=0;i<count;i++)
      arr[i] = list[i];
    for(int i=1;i<=count;i++)
      list[i] = arr[i-1];
    list[0] = val;
  }
  count++;
  return list;
}

int* deleteFront(int* list){

}


void display(int* list){
  for(int i=0;i<count;i++){
    printf("%d-> ",list[i]);
  }
  printf("NULL");
  printf("\n");
}


int main(){
  int* list = (int*)malloc(n*sizeof(int));
  int choice;
  do {
    printf("1. PushBack\n");
    printf("2. Popback\n");
    printf("3. Display\n");
    printf("4. Push in Front\n");
    printf("Enter your choice:"); scanf("%d",&choice);
    switch (choice) {
      case 1:
        list = push_back(list);
        break;
      case 2:
        list = DeleteLast(list);
        break;
      case 3:
        display(list); break;
      case 4:
        list = insertFront(list); break;
    }
  }while (choice<5);
}
