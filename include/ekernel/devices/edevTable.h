//
// Created by Pavel Bibichenko on 06.07.2020.
//

#ifndef ESHELL_PIO_EDEVTABLE_H
#define ESHELL_PIO_EDEVTABLE_H

#include "edevice.h"

struct eDevTable {
    t_eDevice **devices;
    unsigned int count;

    void (* prepareAll)(struct eDevTable *self);
    void (* updateAll)(struct eDevTable *self);
    void (* emitAll)(struct eDevTable *self, const char *op, const char *cmd);
};
typedef struct eDevTable t_eDevTable;

void prepareAll(struct eDevTable *self);
void updateAll(struct eDevTable *self);
void emitAll(struct eDevTable *self, const char *op, const char *cmd);

t_eDevTable *eDevTable_instance();

#endif //ESHELL_PIO_EDEVTABLE_H
