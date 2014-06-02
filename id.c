#include "id.h"

void new_id(id_t id) {
    for (int i = 0; i < IDLEN; i++) {
        id[i] = '0';
    }
}
