#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *createNodeEnd(struct Node *node, int data) {

  // If the tree/linked list has not been created it will return
  if (node == NULL) {
    printf("The tree has not been initiated\n");
    return NULL;
  }

  // Creating the new node to insert into the list
  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  // Creating a node to track where we are in the list
  // We are going straight to the end so in the while loop we wait till
  // next == NULL
  struct Node *current = node;

  // While loop will continue until current->next == NULL as this will be the
  // last node in the list
  while (current->next != NULL) {
    // Move on one node then repeat until the end
    current = current->next;
  }
  // Assigning the last node, to the second last node in the list
  current->next = newNode;
  printf("New node created at end with data: %d\n", data);
  return node;
}


struct Node *deleteNode(struct Node *node, int data) {
  if (node == NULL) {
    printf("The tree has not been initiated\n");
    return NULL;
  }

  struct Node *current = node;
  if (current->data == data) {
    node = node->next;
    free(current);
    printf("Node deleted with data %d\n", data);
    return node;
  }
  while (current->next != NULL) {
    if (current->next->data == data) {
      free(current->next);
      current->next = NULL;
      printf("Node deleted with data %d\n", data);
      break;
    }
    current = current->next;
  }
  printf("The node with data %d could not be found.\n", data);
  return node;
}

void printList(struct Node *node) {
  struct Node *curr = malloc(sizeof(struct Node));
  curr = node;
  while (curr->next != NULL) {
    printf("Current node %d\n", curr->data);
    curr = curr->next;
  }
  printf("Current node %d\n", curr->data);
}

struct Node *createNodeBeginning(struct Node *node, int data) {
  if (node == NULL) {
    printf("The tree has not been initiated\n");
    return NULL;
  }

  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = node;
  printf("New node created at beginning  with data: %d\n", data);
  return newNode;
}

int main() {
  printf("Program has started\n");
  struct Node *head;
  head = malloc(sizeof(struct Node));
  head->data = 0;
  head->next = NULL;

  createNodeEnd(head, 3);
  head = createNodeBeginning(head, 1);
  printList(head);
  head = deleteNode(head, 3);
  printList(head);
  head = deleteNode(head, 1);
  printList(head);
}
