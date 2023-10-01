#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  struct Node *left;
  struct Node *right;
}NODE;

NODE* createNode(int data){
  NODE *p = (NODE*)malloc(sizeof(NODE));
  p->left = NULL;
  p->right = NULL;
  p->data = data;
  return p;
}

void preOrder(NODE* root){
  if (root!=NULL){
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
  }
}

void postOrder(NODE* root){
  if (root !=NULL){
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
  }
}

void inOrder(NODE* root){
  if (root != NULL){
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
  }
}


int main(){

  NODE* p = createNode(4);
  NODE* p1 = createNode(1);
  NODE* p2 = createNode(6);
  NODE* p3 = createNode(5);
  NODE* p4 = createNode(2);

  p->left = p1;
  p->right = p2;
  p1->left = p3;
  p1->right = p4;

  preOrder(p);
  printf("\n");
  postOrder(p);
  printf("\n");
  inOrder(p);
  printf("\n");
}
