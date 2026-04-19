#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_LENGTH 5

int top = -1;

int size(int stack[]) {
  int size;
  return size;
}

bool push(int stack[], int data) {
  if (top >= STACK_LENGTH - 1) {
    return false;
  }

  top++;
  stack[top] = data;
  return true;
}

int pop(int stack[]) {
  if (top == -1) {
    return INT_MIN;
  }
  int result = stack[top];
  top--;
  return result;
}

int peek(int stack[]){
    return stack[top];
}

int main() {
  int myarray[STACK_LENGTH];
  push(myarray,34);
  push(myarray,80);
  push(myarray,243);

  printf("%d\n", pop(myarray));
  printf("%d\n", pop(myarray));
  printf("%d\n", pop(myarray));

  return 1;
}
