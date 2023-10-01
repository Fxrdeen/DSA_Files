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


void inOrder(NODE* root){
  if (root != NULL){
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
  }
}

int isBST(NODE* root){
  static NODE* prev = NULL;
  if (root!=NULL){
    if (!isBST(root->left)){
      return 0;
    }
    if (prev!=NULL && root->data <= prev->data){
      return 0;
    }
    prev = root;
    return isBST(root->right);
  } else{
    return 1;
  }
}

NODE* search(NODE* root, int key){
  if (root == NULL) return NULL;
  if (root->data == key) return root;
  if (root->data < key) return search(root->right, key);
  else return search(root->left, key);
}

NODE* searchIter(NODE* root, int key){
  while(root!=NULL){
    if (root->data == key) return root;
    else if (key < root->data) root = root->left;
    else root = root->right;
  }
  return NULL;
}

void insertNode(NODE* root, int key){
  NODE* prev = NULL;
  while(root!=NULL){
    prev = root;
    if (key == root->data) return;
    else if (key < root->data) root = root->left;
    else root = root->right;

  }
  NODE* new = createNode(key);
  if (key < prev->data) prev->left = new;
  else prev->right = new;


}

NODE* inOrderPre(NODE* root){
  root = root->left;
  while(root->right!=NULL){
    root = root->right;
  }
  return root;
}

NODE* delete(NODE* root, int val){
  if (root == NULL) return NULL;
  if (root->left == NULL && root->right == NULL){
    free(root); return NULL;
  }
  if (val < root->data){
    root->left = delete(root->left, val);
  } else if (val > root->data){
    root->right = delete(root->right, val);
  }
  else {
    NODE* iPre = inOrderPre(root);
    root->data = iPre->data;
    root->left = delete(root->left, iPre->data);
  }
  return root;
}

int main(){

  NODE* p = createNode(5);
  NODE* p1 = createNode(3);
  NODE* p2 = createNode(6);
  NODE* p3 = createNode(1);
  NODE* p4 = createNode(4);

  p->left = p1;
  p->right = p2;
  p1->left = p3;
  p1->right = p4;

  /*inOrder(p);
  printf("\n");
  printf("%d",isBST(p));
  NODE* res = search(p, 8);
  printf("\n");
  if (res == NULL) printf("Element not found");
  else printf("%d ",res->data);

  NODE* res1 = searchIter(p, 11);
  printf("\n");
  if (res1 == NULL) printf("Element not found");
  else printf("%d ",res1->data);*/

  insertNode(p, 2);
  inOrder(p);
  delete(p, 5);
printf("\n");

  inOrder(p);
}
