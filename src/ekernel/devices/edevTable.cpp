//
// Created by Pavel Bibichenko on 06.07.2020.
//

#include "../../../include/ekernel/devices/edevTable.h"

#include <stdlib.h>

void prepareAll(struct eDevTable *self) {
    for (unsigned int i = 0; i < self->count; i++)
        self->devices[i]->prepare(self->devices[i]);
}

void updateAll(struct eDevTable *self) {
    for (unsigned int i = 0; i < self->count; i++)
        self->devices[i]->update(self->devices[i]);
}

void emitAll(struct eDevTable *self, char *op, char *cmd) {
    for (unsigned int i = 0; i < self->count; i++)
        self->devices[i]->emit(self->devices[i], op, cmd);
}

t_eDevTable *eDevTable_instance() {
    static t_eDevTable newDevTable;

    newDevTable.prepareAll = prepareAll;
    newDevTable.updateAll = updateAll;
    newDevTable.emitAll = emitAll;

    return &newDevTable;
}