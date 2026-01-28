#include "raylib.h"

#include "view/visual_factory.h"
#include "view/visual_queue.h"
#include "model/t_queue.h"
#include <stddef.h>


VisualDS *visual_factory_create(tDsType type, void *model)
{
    VisualDS *ds = NULL;

    switch (type) {
        case DS_QUEUE:
            ds = visual_queue_create((tQueue *)model);
            if (ds) ds->type_name = "Queue";
            break;

        case DS_STACK:
            TraceLog(LOG_WARNING, "VisualStack not implemented yet");
            return NULL;

        default:
            return NULL;
    }

    return ds;
}

