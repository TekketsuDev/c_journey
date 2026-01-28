#include "model/t_queue.h"

void initQueue(tQueue *q) {
    q->nelem = 0;
}

void enqueue(tQueue *q, int e) {
    if (q->nelem == TQUEUE_MAX) return;
    q->vector[q->nelem++] = e;
}

void dequeue(tQueue *q) {
    if (q->nelem == 0) return;

    for (int i = 0; i < q->nelem - 1; ++i) {
        q->vector[i] = q->vector[i + 1];
    }
    q->nelem--;
}

bool head(const tQueue *q, int *e) {
    if (q->nelem == 0) return false;
    *e = q->vector[0];
    return true;
}

bool isEmptyQueue(const tQueue *q) {
    return q->nelem == 0;
}

bool isFullQueue(const tQueue *q) {
    return q->nelem == TQUEUE_MAX;
}

int lengthQueue(const tQueue *q) {
    return q->nelem;
}

