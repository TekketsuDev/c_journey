#ifndef VISUAL_FACTORY_H
#define VISUAL_FACTORY_H

#include "model/t_manager.h"   // <-- OBLIGATORIO (define tDsType)
#include "view/visual_ds.h"

VisualDS *visual_factory_create(tDsType type, void *model);

#endif

