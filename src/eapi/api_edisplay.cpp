//
// Created by Pavel Bibichenko on 07.07.2020.
//

#include "../../include/eapi/api_edisplay.h"

#include "../../include/ekernel/devices/edevTable.h"

void api_edisplay_print(const char* line) {
    t_eDevTable *devTable = eDevTable_instance();

    devTable->emitAll(devTable, "print", line);
}