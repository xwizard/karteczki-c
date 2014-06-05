#ifndef BOX_H
#define BOX_H

#include <glib.h>
#include "id.h"

#define POCKETS 5

typedef struct Box {
    char* id;
    GList* pockets[POCKETS];
} Box;

Box* box_new();

#endif // BOX_H

