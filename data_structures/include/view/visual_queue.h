#ifndef VISUAL_QUEUE_H
#define VISUAL_QUEUE_H

#include "view/visual_ds.h"
#include "model/t_queue.h"

typedef struct VisualQueue VisualQueue;

VisualDS *visual_queue_create(tQueue *queue);

#endif

