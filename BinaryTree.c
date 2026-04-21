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
    *rootptr = createNewNode(data);
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
}

bool findNode(node *root, int data) {
  if (root == NULL) {
    return false;
  }

  if (root->data == data) {
    return true;
  }

  if (data < root->data) {
    return findNode(root->left, data);
  } else {
    return findNode(root->right, data);
  }
}

void printTree(node *root) {
  if (root == NULL) {
    return;
  }

  printf("Value = %d\n", root->data);

  printf("left\n");
  printTree(root->left);

  printf("right\n");
  printTree(root->right);

  printf("done\n");
}

node *getSuccessor(node *root) {
  node *curr = root->right;

  while (curr != NULL && curr->left != NULL) {
    curr = curr->left;
  }

  return curr;
}

node *deleteNode(node *root, int data) {
  if (root == NULL) {
    return NULL;
  }

  if (data < root->data) {
    root->left = deleteNode(root->left, data);
  } else if (data > root->data) {
    root->right = deleteNode(root->right, data);
  } else {
    // Node found

    // Case 1: one or no child
    if (root->left == NULL) {
      node *temp = root->right;
      free(root);
      return temp;
    }

    if (root->right == NULL) {
      node *temp = root->left;
      free(root);
      return temp;
    }

    // Case 2: two children
    node *succ = getSuccessor(root);
    root->data = succ->data;
    root->right = deleteNode(root->right, succ->data);
  }

  return root;
}

int main() {
  node *root = NULL;

  insertNode(&root, 10);
  insertNode(&root, 13);
  insertNode(&root, 14);
  insertNode(&root, 12);
  insertNode(&root, 11);

  printTree(root);

  printf("%d\n", findNode(root, 13));

  root = deleteNode(root, 13);

  printf("%d\n", findNode(root, 13));

  return 0;
}
