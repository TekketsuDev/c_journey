/*
┌───────────────┐
│     main      │  ← input + loop raylib
└───────┬───────┘
        │
┌───────▼────────┐
│ DataStructure  │  ← FACTORY (elige visualizador)
└───────┬────────┘
        │
┌───────▼────────┐
│ VisualAdapter  │  ← interfaz común (update/draw/requests)
└───────┬────────┘
        │
┌───────▼────────┐
│ VisualQueue    │  ← implementación concreta
│ VisualStack    │
│ VisualDeque    │
└────────────────┘
*/
#include "raylib.h"

#include "model/t_queue.h"
#include "model/t_stack.h"
#include "model/t_manager.h"

#include "view/visual_ds.h"
#include "view/visual_factory.h"

#include <stdlib.h>
#include <time.h>

static VisualDS *recreate_visual(VisualDS *old,
                                 const tDsItem *item)
{
    VisualDS *new_visual =
        visual_factory_create(item->type, item->instance);

    if (!new_visual) {
        TraceLog(LOG_WARNING,
                 "No visual for this structure, keeping previous");
        return old;
    }

    /* 👇 AQUÍ */
    new_visual->name = item->name;
    new_visual->type_name =
        (item->type == DS_QUEUE) ? "Queue" : "Stack";

    if (old && old->ops->destroy) {
        old->ops->destroy(old);
    }

    return new_visual;
}


int main(void)
{
    /* ===============================
     * Raylib init
     * =============================== */
    const int screenWidth  = 1000;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight,
               "Data Structure Visual Factory");
    SetTargetFPS(60);

    srand((unsigned int)time(NULL));

    /* ===============================
     * Models
     * =============================== */
    tQueue queue1;
    tStack stack1;
    tStack stack2;

    initQueue(&queue1);
    initStack(&stack1);
    initStack(&stack2);

    /* ===============================
     * Manager
     * =============================== */
    tManager manager;
    t_manager_init(&manager);

    t_manager_add(&manager, DS_QUEUE, &queue1, "Queue 1");
    t_manager_add(&manager, DS_STACK, &stack1, "Stack A");
    t_manager_add(&manager, DS_STACK, &stack2, "Stack B");

    const tDsItem *current = t_manager_current_const(&manager);
    if (!current) {
        CloseWindow();
        return 1;
    }

    /* ===============================
     * Visual init
     * =============================== */
    VisualDS *visual = visual_factory_create(
        current->type,
        current->instance
    );

  if (!visual) {
      TraceLog(LOG_ERROR, "Failed to create visual");
  }
  if (visual) {
    visual->name = current->name;
    visual->type_name = (current->type == DS_QUEUE) ? "Queue" : "Stack";
  }


    /* ===============================
     * Main loop
     * =============================== */
    while (!WindowShouldClose()) {
        float dt = GetFrameTime();

        /* ---------- Input ---------- */

        /* Push / Enqueue */
        if (IsKeyPressed(KEY_E)) {
            int value = rand() % 100;
            /* Opaque Handle ops and Virtual Table */
            visual->ops->request_push(visual, value);
        }

        /* Pop / Dequeue */
        if (IsKeyPressed(KEY_D)) {
            visual->ops->request_pop(visual);
        }

        /* Next structure */
        if (IsKeyPressed(KEY_TAB)) {
            t_manager_next(&manager);
            current = t_manager_current_const(&manager);
            visual = recreate_visual(visual, current);
        }

        /* Previous structure */
        if (IsKeyPressed(KEY_LEFT_SHIFT) &&
            IsKeyPressed(KEY_TAB)) {
            t_manager_prev(&manager);
            current = t_manager_current_const(&manager);
            visual = recreate_visual(visual, current);
        }

        /* ---------- Update ---------- */
        if (visual) {
            visual->ops->update(visual, dt);
        }
        /* ---------- Draw ---------- */
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("E = push / enqueue", 20, 20, 20, DARKGRAY);
        DrawText("D = pop / dequeue", 20, 50, 20, DARKGRAY);
        DrawText("TAB = next structure", 20, 80, 20, DARKGRAY);

        if (current && current->name) {
            DrawText(current->name, 20, 120, 24, BLACK);
        }

        if (visual) {
            visual->ops->draw(visual);
        } else {
            DrawText("No visual available for this structure", 200, 300, 20, RED);
        }
        EndDrawing();
    }

    /* ===============================
     * Cleanup
     * =============================== */
    if (visual && visual->ops->destroy) {
        visual->ops->destroy(visual);
    }

    CloseWindow();
    return 0;
}
