/*
 * TQUEUE (Typed Queue) — FIFO container
 *
 *        front (sale primero)            rear (entra último)
 *              |                               |
 *              v                               v
 *         +-----------+   +-----------+   +-----------+
 *         | v[front]  |   | v[?]      |   | v[rear]   |
 *         +-----------+   +-----------+   +-----------+
 *         |    ...    |   |    ...    |   |    ...    |
 *         +-----------+   +-----------+   +-----------+
 *
 *   Orden lógico (FIFO):
 *     enqueue(a) -> enqueue(b) -> enqueue(c)
 *     dequeue()  -> a  (sale el primero)
 *
 *   Representación típica (array circular):
 *
 *     index:   0    1    2    3    4
 *     v:      [a]  [b]  [c]  [ ]  [ ]
 *              ^             ^
 *            front          rear
 *
 *     size / nelem = 3
 *
 * Operaciones:
 *   void initQueue(tQueue *q);
 *   void enqueue(tQueue *q, int e);
 *   void dequeue(tQueue *q);
 *   bool isEmptyQueue(tQueue q);
 *   bool isFullQueue(tQueue q);
 *   bool head(tQueue *q, int *e);
 *   int  lengthQueue(tQueue q);
 */

#include <stdio.h>
#define MAX 50
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
  float vector[MAX];
  int nelem;
} tQueue;

void initQueue(tQueue *q) { q->nelem = 0; }

void enqueue(tQueue *q, int e) {
  if (q->nelem == MAX) {
    printf("Full Queue \n");
  } else {
    q->vector[q->nelem - 1] = e;
  }
}

void dequeue(tQueue *q, int e) {}

bool isEmptyQueue(tQueue q) { return q.nelem == 0; }

bool isFullFQueue(tQueue q) { return q.nelem == MAX; }

int main(int argc, char *argv[]) { return EXIT_SUCCESS; }
