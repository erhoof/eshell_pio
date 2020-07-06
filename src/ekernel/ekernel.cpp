//
// Created by Pavel Bibichenko on 07.07.2020.
//

#include <Arduino.h>
#include "../../include/ekernel/ekernel.h"
#include "../../include/ekernel/devices/edevTable.h"

#include "../../include/esh/esh.h"

void exec(struct eKernel *self) {
    t_eDevTable *devTable = eDevTable_instance();

    devTable->emitAll(devTable, "pl", "EAPC");
    devTable->emitAll(devTable, "pl", "KERN: ok");
    devTable->emitAll(devTable, "pl", "SERIAL: ok");
    devTable->emitAll(devTable, "pl", "USREXEC: ..");
    devTable->emitAll(devTable, "pl", "esh wait.");
    delay(2000);

    t_eSh *esh = esh_instance();
    esh->exec(esh);
}

t_eKernel *ekernel_instance() {
    static t_eKernel kernel;

    kernel.exec = exec;

    return &kernel;
}