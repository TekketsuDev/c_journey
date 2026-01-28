#ifndef T_MANAGER_H
#define T_MANAGER_H

#include <stddef.h>   // size_t

typedef enum {
    DS_STACK = 0,
    DS_QUEUE,
    DS_DEQUE,
    DS_TREE,
    DS_UNKNOWN
} tDsType;

typedef struct {
    tDsType type;
    void   *instance;
    const char *name;
} tDsItem;

#ifndef T_MANAGER_MAX
#define T_MANAGER_MAX 32
#endif

typedef struct {
    tDsItem items[T_MANAGER_MAX];
    int     count;
    int     current;
} tManager;

/* API */
void     t_manager_init(tManager *m);

int      t_manager_add(tManager *m, tDsType type, void *instance, const char *name);

tDsItem *t_manager_current(tManager *m);
const tDsItem *t_manager_current_const(const tManager *m);

void     t_manager_next(tManager *m);
void     t_manager_prev(tManager *m);

int      t_manager_count(const tManager *m);
int      t_manager_index(const tManager *m);

int      t_manager_select(tManager *m, int index);

#endif /* T_MANAGER_H */

