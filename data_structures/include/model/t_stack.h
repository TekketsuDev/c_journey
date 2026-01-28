/*
 * TSTACK (Typed Stack) — LIFO container
 *
 *        TOP (v[nelem-1])
 *              |
 *              v
 *         +-----------+
 *         | v[n-1]=vn |   <- último en entrar (sale primero)
 *         +-----------+
 *         | v[n-2]=v? |
 *         +-----------+
 *         |    ...    |
 *         +-----------+
 *         |  v[1]=v2  |
 *         +-----------+
 *         |  v[0]=v1  |   <- base
 *         +-----------+
 *
 *   void initStack(tStack *s);
 *   bool isFullStack(tStack s);
 *   void push(tStack *s, int e);
 *   void pop(tStack *s);
 *   bool top(tStack *s, int *e);
 *   int  heightStack(tStack s);
 */
#ifndef T_STACK_H
#define T_STACK_H

#include <stdbool.h>

#define TSTACK_MAX 30

typedef struct {
    int vector[TSTACK_MAX];
    int nelem;
} tStack;

/* API */
void initStack(tStack *s);
void push(tStack *s, int e);
void pop(tStack *s);

bool top(const tStack *s, int *e);

bool isEmptyStack(const tStack *s);
bool isFullStack(const tStack *s);
int  lengthStack(const tStack *s);

#endif /* T_STACK_H */


