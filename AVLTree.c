#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
  int height;
} node;

node *newNode(int data) {
  node *newNode = malloc(sizeof(node));
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  newNode->height = 1;
  return newNode;
};

// Function : Get height of the tree

int height(node *node) {
  if (node == NULL) {
    return 0;
  }
  return node->height;
}

// Function : gets maximum of 2 integers
int max(int a, int b) { return (a > b) ? a : b; }

node *rightRotate(node *y) {

  node *x = y->left;
  node *temp = x->right;

  x->right = y;
  y->left = temp;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}
/*
 * How this works
 *
 *  we have tree 1 -> 2 -> 3
 *  we pass 1 = a
 *
 *  we creat var to store a->right
 *  b = a->righ
 *  we create var to store b left which is bigger than a
 *  t = b->left
 *
 *  no we have a is a         1
 *  b = a-right               b = 2
 *  t = b->left               null for this
 *
 *  b->l = a
 *  a->r = t
 *
 */
node *leftRotate(node *x) {
  // Storing and prepping for swap
  node *y = x->right;
  node *temp = y->left; // Actually storing the value of x left

  // Swapping
  y->left = x;
  x->right = temp;

  // update height

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

int getBalance(node *n) {
  if (n == NULL) {
    return 0;
  }
  return height(n->left) - height(n->right);
}

node *insertNode(node *root, int data) {
  if (root == NULL) {
    return newNode(data);
  }

  if (data < root->data) {
    root->left = insertNode(root->left, data);
  } else if (data > root->data) {
    root->right = insertNode(root->right, data);
  } else {
    // This is the case if the data is equal(no duplicates allowed)
    return root;
  }

  root->height = 1 + max(height(root->left), height(root->right));

  int balance = getBalance(root);
  // Balancing will be here

  // If this node becomes unbalanced, then
  // there are 4 cases

  // Left Left Case
  if (balance > 1 && data < root->left->data)
    return rightRotate(root);

  // Right Right Case
  if (balance < -1 && data > root->right->data)
    return leftRotate(root);

  // Left Right Case
  if (balance > 1 && data > root->left->data) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  // Right Left Case
  if (balance < -1 && data < root->right->data) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

node *minValueNode(node *n) {
  node *current = n;
  while (current->left != NULL)
    current = current->left;
  return current;
}

node *deleteNode(node *root, int key) {

  // 1. NORMAL BST DELETE
  if (root == NULL)
    return root;

  if (key < root->data) {
    root->left = deleteNode(root->left, key);
  } else if (key > root->data) {
    root->right = deleteNode(root->right, key);
  } else {
    // FOUND NODE

    // Case 1: no child
    // Case 2: one child
    if ((root->left == NULL) || (root->right == NULL)) {

      node *temp = root->left ? root->left : root->right;

      // No child
      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else {
        // One child → copy contents
        *root = *temp;
      }

      free(temp);
    } else {
      // Case 3: two children
      node *temp = minValueNode(root->right);

      root->data = temp->data;

      root->right = deleteNode(root->right, temp->data);
    }
  }

  // If tree had only one node
  if (root == NULL)
    return root;

  // 2. UPDATE HEIGHT
  root->height = 1 + max(height(root->left), height(root->right));

  // 3. GET BALANCE
  int balance = getBalance(root);

  // 4. REBALANCE (same 4 cases)

  // Left Left
  if (balance > 1 && getBalance(root->left) >= 0)
    return rightRotate(root);

  // Left Right
  if (balance > 1 && getBalance(root->left) < 0) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  // Right Right
  if (balance < -1 && getBalance(root->right) <= 0)
    return leftRotate(root);

  // Right Left
  if (balance < -1 && getBalance(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}
void preOrder(node *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
  }
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

int main() {
  node *root = NULL;
  for (int i = 0; i < 1000; i++) {
    root = insertNode(root, i);
  }

  preOrder(root);
}
