//
// Created by Pavel Bibichenko on 06.07.2020.
//

#include "../../../include/ekernel/devices/edevTable.h"

#include <stdlib.h>
#include <HardwareSerial.h>

void prepareAll(struct eDevTable *self);
void updateAll(struct eDevTable *self);
void *emitAll(struct eDevTable *self, const char *op, const char *cmd);

void prepareAll(struct eDevTable *self) {
    for (unsigned int i = 0; i < self->count; i++)
        self->devices[i]->prepare(self->devices[i]);
}

void updateAll(struct eDevTable *self) {
    for (unsigned int i = 0; i < self->count; i++)
        self->devices[i]->update(self->devices[i]);
}

void *emitAll(struct eDevTable *self, const char *op, const char *cmd) {
    void *data;

    for (unsigned int i = 0; i < self->count; i++) {
        data = self->devices[i]->emit(self->devices[i], op, cmd);

        //Serial.print("emitAll");
        //Serial.print((char*)(data));

        if (data)
            return data;
    }

    return nullptr;
}

t_eDevTable *eDevTable_instance() {
    static t_eDevTable newDevTable;

    newDevTable.prepareAll = prepareAll;
    newDevTable.updateAll = updateAll;
    newDevTable.emitAll = emitAll;

    return &newDevTable;
}