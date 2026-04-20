#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node;

node *createNewNode(int data) {
  node *newNode = malloc(sizeof(node));
  if (newNode != NULL) {
    newNode->data = data;
    newNode->left = newNode->right = NULL;
  }
  return newNode;
}

bool insertNode(node **rootptr, int data) {
  node *root = *rootptr;
  if (root == NULL) {
    (*rootptr) = createNewNode(data);
    return true;
  }
  if (data == root->data) {
    return false;
  }
  if (data < root->data) {
    return insertNode(&(root->left), data);
  } else {
    return insertNode(&(root->right), data);
  }
  return true;
}

bool findNode(node *root, int data){
    if(root == NULL){
        return false;
    }
    if(root->data == data){
        return true;
    } else if(data < root->data){
        return findNode(root->left, data);
    } else {
        return findNode(root->right, data);
    }
}

void printTree(node *root) {
  if (root == NULL) {
    printf("Tree is empty\n");
    return;
  }
  printf("Value = %d\n", root->data);
  printf("left\n"); printTree(root->left);
  printf("right\n");
  printTree(root->right);
  printf("done\n");
}

int main() {
    node *root = NULL;
    insertNode(&root, 10);
    insertNode(&root, 13);
    insertNode(&root, 14);
    insertNode(&root, 12);
    insertNode(&root, 11);
    printTree(root);

    printf("%b\n", findNode(root,13));
}
