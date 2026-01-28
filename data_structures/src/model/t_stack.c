#include "model/t_stack.h"

void initStack(tStack *s) {
    s->nelem = 0;
}

void push(tStack *s, int e) {
    if (s->nelem == TSTACK_MAX) return;
    s->vector[s->nelem++] = e;
}

void pop(tStack *s) {
    if (s->nelem == 0) return;
    s->nelem--;
}

bool top(const tStack *s, int *e) {
    if (s->nelem == 0) return false;
    *e = s->vector[s->nelem - 1];
    return true;
}

bool isEmptyStack(const tStack *s) {
    return s->nelem == 0;
}

bool isFullStack(const tStack *s) {
    return s->nelem == TSTACK_MAX;
}

int lengthStack(const tStack *s) {
    return s->nelem;
}

