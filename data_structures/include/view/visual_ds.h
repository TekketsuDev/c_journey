#ifndef VISUAL_DS_H
#define VISUAL_DS_H

#include <stdbool.h>

/* ===============================
 * Visual Data Structure Interface
 * =============================== */

/* Forward declaration */
typedef struct VisualDS VisualDS;

/* Operations (polymorphism in C) */
typedef struct {
    /* Frame lifecycle */
    void (*update)(VisualDS *self, float dt);
    void (*draw)(const VisualDS *self);

    /* Requests from input */
    void (*request_push)(VisualDS *self, int value);
    void (*request_pop)(VisualDS *self);

    /* Cleanup */
    void (*destroy)(VisualDS *self);
} VisualDSOps;

/* Generic visual data structure */
struct VisualDS {
    const VisualDSOps *ops; /* virtual table */
    void *impl;            /* concrete implementation */
    const char *name;      // "Queue 1"
    const char *type_name;
};

#endif /* VISUAL_DS_H */

