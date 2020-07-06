//
// Created by Pavel Bibichenko on 07.07.2020.
//

#include "../../include/ekernel/ekernel.h"
#include "../../include/ekernel/devices/edevTable.h"

void exec(struct eKernel *self) {
    t_eDevTable *devTable = eDevTable_instance();

    devTable->emitAll(devTable, "print", "EAPC");
    devTable->emitAll(devTable, "print", "KERN: ok");
    devTable->emitAll(devTable, "print", "esh wait.");
}

t_eKernel *ekernel_instance() {
    static t_eKernel kernel;

    kernel.exec = exec;

    return &kernel;
}