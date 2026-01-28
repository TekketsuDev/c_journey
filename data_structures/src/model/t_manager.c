#include "model/t_manager.h"

void t_manager_init(tManager *m) {
    if (!m) return;
    m->count = 0;
    m->current = 0;
}

int t_manager_add(tManager *m, tDsType type, void *instance, const char *name) {
    if (!m) return -1;
    if (m->count >= T_MANAGER_MAX) return -1;

    m->items[m->count].type = type;
    m->items[m->count].instance = instance;
    m->items[m->count].name = name;

    // si es el primer item, selecciónalo
    if (m->count == 0) m->current = 0;

    m->count++;
    return m->count - 1;
}

tDsItem *t_manager_current(tManager *m) {
    if (!m) return NULL;
    if (m->count == 0 || m->current < 0 || m->current >= m->count) return NULL;
    return &m->items[m->current];
}

const tDsItem *t_manager_current_const(const tManager *m) {
    if (!m) return NULL;
    if (m->count == 0 || m->current < 0 || m->current >= m->count) return NULL;
    return &m->items[m->current];
}

void t_manager_next(tManager *m) {
    if (!m) return;
    if (m->count == 0) return;
    m->current = (m->current + 1) % m->count;
}

void t_manager_prev(tManager *m) {
    if (!m) return;
    if (m->count == 0) return;
    m->current = (m->current - 1 + m->count) % m->count;
}

int t_manager_count(const tManager *m) {
    return m ? m->count : 0;
}

int t_manager_index(const tManager *m) {
    return m ? m->current : -1;
}

int t_manager_select(tManager *m, int index) {
    if (!m) return 0;
    if (index < 0 || index >= m->count) return 0;
    m->current = index;
    return 1;
}

