#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node;

node *newNode(int data) {
  node *newNode = malloc(sizeof(node));
  newNode->data = data;
  return newNode;
};

node *insertNode(node *root, int data) {
  if (root == NULL) {
    return newNode(data);
  }

  if (data < root->data) {
    root->left = insertNode(root->left, data);
  }

  if (data > root->data) {
    root->right = insertNode(root->right, data);
  }
  return root;
}

node *findNode(node *root, int target) {
  if (root == NULL) {
    return NULL;
  }
  if (root->data == target) {
    return root;
  }

  if (target < root->data) {
    return findNode(root->left, target);
  } else {
    return findNode(root->right, target);
  }
}

struct node *getSuccessor( node *curr)
{
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
        curr = curr->left;
    return curr;
}

bool deleteNode(node *root, int target) {
  if (root == NULL) {
    return false;
  }

  if (target < root->data) {
    deleteNode(root->left, target);
  } else if (target > root->data) {
    deleteNode(root->right, target);
  } else {

    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    }
    if (root->right == NULL) {
      node *temp = root->left;
      free(root);
      return temp;
    }
    node *succ = getSuccessor(root);
    root->data = succ->data;
  }

  return false;
}

int main() {}
