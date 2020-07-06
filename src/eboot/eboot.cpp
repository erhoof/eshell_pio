//
// Created by Pavel Bibichenko on 06.07.2020.
//

#include "../../include/eboot/eboot.h"

#include <stdlib.h>

#include "../../include/ekernel/devices/edevTable.h"
#include "../../include/ekernel/devices/display_1602_i2c/display_1602_i2c.h"

void eboot_exec() {
    t_eDevTable *devTable = eDevTable_instance();

    devTable->count = 1;
    devTable->devices = (t_eDevice **)malloc(sizeof(t_eDevice *) * devTable->count);

    devTable->devices[0] = display_1602_i2c_instance();

    devTable->prepareAll(devTable);
}