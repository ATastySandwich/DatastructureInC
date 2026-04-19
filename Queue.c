#include <stdbool.h>
#include <stdio.h>

#define QUEUE_LENGTH 10

int queue[QUEUE_LENGTH];
int first = 0, last = 0;

void enqueue(int queue[], int data) {
  if (last == QUEUE_LENGTH) {
    return;
  }
  queue[last] = data;
  last++;
}

int peek(int queue[]) { return queue[first]; }

int dequeue(int queue[]) {
    if(last == 0) return false;
  int result = queue[first];
  for (int i = 0; i < last -1; i++) {
    queue[i] = queue[i + 1];
  }
  last--;
  return result;
}

int main() {

  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  enqueue(queue, 4);

  for (int i = 0; i < 4; i++) {
    printf("%d ", dequeue(queue));
  }
  peek(queue);
}
