#include "view/visual_queue.h"
#include "raylib.h"

#include <stdlib.h>
#include <string.h>

/* ===== Layout ===== */
#define NODE_W  80
#define NODE_H  50
#define GAP     12
#define BASE_X  100
#define BASE_Y  200

/* ===== Internal visual node ===== */
typedef struct {
    int value;
    float x, y;
} VisualNode;

/* ===== Concrete implementation ===== */
struct VisualQueue {
    tQueue *queue;
    VisualNode nodes[TQUEUE_MAX];
    int nodeCount;
};

/* ===== Forward declarations (ops) ===== */
static void vq_update(VisualDS *self, float dt);
static void vq_draw(const VisualDS *self);
static void vq_request_push(VisualDS *self, int value);
static void vq_request_pop(VisualDS *self);
static void vq_destroy(VisualDS *self);

/* ===== VTable ===== */
static const VisualDSOps queue_ops = {
    .update        = vq_update,
    .draw          = vq_draw,
    .request_push  = vq_request_push,
    .request_pop   = vq_request_pop,
    .destroy       = vq_destroy
};

/* ===== Factory function ===== */
VisualDS *visual_queue_create(tQueue *q) {
    if (!q) return NULL;

    VisualQueue *vq = malloc(sizeof(VisualQueue));
    if (!vq) return NULL;

    memset(vq, 0, sizeof(*vq));
    vq->queue = q;
    VisualDS *ds = malloc(sizeof(VisualDS));
    if (!ds) {
        free(vq);
        return NULL;
    }

    ds->ops  = &queue_ops;
    ds->impl = vq;
    return ds;
}

/* ===== Ops implementation ===== */

static void vq_request_push(VisualDS *self, int value) {
    VisualQueue *vq = self->impl;
    if (!isFullQueue(vq->queue)) {
        enqueue(vq->queue, value);
    }
}

static void vq_request_pop(VisualDS *self) {
    VisualQueue *vq = self->impl;
    if (!isEmptyQueue(vq->queue)) {
        dequeue(vq->queue);
    }
}

static void vq_update(VisualDS *self, float dt) {
    (void)dt;
    VisualQueue *vq = self->impl;

    /* Sync visual nodes with logical queue */
    vq->nodeCount = vq->queue->nelem;

    for (int i = 0; i < vq->nodeCount; i++) {
        vq->nodes[i].value = vq->queue->vector[i];
        vq->nodes[i].x = BASE_X + i * (NODE_W + GAP);
        vq->nodes[i].y = BASE_Y;
    }
}

static void vq_draw(const VisualDS *self) {
    const VisualQueue *vq = self->impl;

    /* Título */
    if (self->name && self->type_name) {
        DrawText(
            TextFormat("%s (%s)", self->name, self->type_name),
            BASE_X,
            BASE_Y - 60,
            22,
            BLACK
        );
    }

    for (int i = 0; i < vq->nodeCount; i++) {
        const VisualNode *n = &vq->nodes[i];

        Color box = (i == 0) ? GREEN : BLUE;

        DrawRectangle((int)n->x, (int)n->y, NODE_W, NODE_H, box);
        DrawRectangleLines((int)n->x, (int)n->y,
                           NODE_W, NODE_H, DARKBLUE);

        /* Valor */
        DrawText(
            TextFormat("%d", n->value),
            (int)n->x + 20,
            (int)n->y + 18,
            20,
            RAYWHITE
        );

        /* Posición lógica */
        DrawText(
            TextFormat("[%d]", i),
            (int)n->x + 4,
            (int)n->y - 16,
            14,
            DARKGRAY
        );
    }

    if (vq->nodeCount == 0) {
        DrawText("Queue empty",
                 BASE_X, BASE_Y - 30,
                 20, GRAY);
    }
}

static void vq_destroy(VisualDS *self) {
    if (!self) return;
    free(self->impl);
    free(self);
}
