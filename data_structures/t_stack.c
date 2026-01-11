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

#include <bits/types/sigevent_t.h>
#include <bits/types/stack_t.h>
#include <stdbool.h>
#include <stdio.h>
#define MAX 30

typedef struct {
  int vector[MAX];
  int currentStack;
} tStack;

void initStack(tStack *s) { s->currentStack = 0; }

void push(tStack *s, int elem) {
  if (s->currentStack == MAX) {
    printf("Stack Full %d \n", s->currentStack);
  } else {
    s->vector[s->currentStack] = elem;
    s->currentStack++;
  }
}
void pop(tStack *s) {
  if (s->currentStack == 0) {
    printf("Stack Empty\n");
  } else {
    s->currentStack--;
  }
}
bool top(const tStack *s, int *e) {
  if (s->currentStack == 0)
    return false;
  *e = s->vector[s->currentStack - 1];
  return true;
}

bool isEmptyStack(const tStack *s) { return s->currentStack == 0; }

bool isFullStack(const tStack *s) { return s->currentStack == MAX; }

int heightStack(const tStack *s) { return s->currentStack; }

int main(void) {
  tStack my_stack;
  int x;

  printf("== Init stack ==\n");
  initStack(&my_stack);

  printf("Empty? %s\n", isEmptyStack(&my_stack) ? "yes" : "no");
  printf("Height: %d\n\n", heightStack(&my_stack));

  printf("== Push elements ==\n");
  push(&my_stack, 10);
  push(&my_stack, 20);
  push(&my_stack, 30);

  printf("Empty? %s\n", isEmptyStack(&my_stack) ? "yes" : "no");
  printf("Full? %s\n", isFullStack(&my_stack) ? "yes" : "no");
  printf("Height: %d\n\n", heightStack(&my_stack));

  printf("== Top ==\n");
  if (top(&my_stack, &x))
    printf("Top element: %d\n\n", x);
  else
    printf("Stack empty\n\n");

  printf("== Pop ==\n");
  pop(&my_stack);
  if (top(&my_stack, &x))
    printf("Top element after pop: %d\n\n", x);

  printf("== Pop all ==\n");
  pop(&my_stack);
  pop(&my_stack);

  printf("Empty? %s\n", isEmptyStack(&my_stack) ? "yes" : "no");

  printf("== Pop empty stack ==\n");
  pop(&my_stack);

  printf("\n== Fill stack ==\n");
  for (int i = 0; i < MAX + 1; i++) {
    push(&my_stack, i);
  }

  printf("Full? %s\n", isFullStack(&my_stack) ? "yes" : "no");
  printf("Height: %d\n", heightStack(&my_stack));

  return 0;
}
