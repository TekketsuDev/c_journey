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
 *     index:   -1    1    2    3    4
 *     v:      [a]  [b]  [c]  [ ]  [ ]
 *              ^             ^
 *            front          rear
 *
 *     size / nelem = 2
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

#ifndef T_QUEUE_H
#define T_QUEUE_H

#include <stdbool.h>

#define TQUEUE_MAX 50

typedef struct {
    int vector[TQUEUE_MAX];
    int nelem;
} tQueue;

/* API */
void initQueue(tQueue *q);
void enqueue(tQueue *q, int e);
void dequeue(tQueue *q);

bool head(const tQueue *q, int *e);

bool isEmptyQueue(const tQueue *q);
bool isFullQueue(const tQueue *q);
int  lengthQueue(const tQueue *q);

#endif /* T_QUEUE_H */

