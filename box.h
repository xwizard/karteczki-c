#ifndef BOX_H
#define BOX_H

#include <glib.h>
#include "id.h"

typedef struct Box {
    id_t id;
    GList* pockets[5];
} Box;

#endif // BOX_H

