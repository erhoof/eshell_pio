//
// Created by Pavel Bibichenko on 06.07.2020.
//

#include "../../include/eboot/eboot.h"

#include <stdlib.h>

#include "../../include/ekernel/devices/edevTable.h"
#include "../../include/ekernel/devices/display_1602_i2c/display_1602_i2c.h"
#include "../../include/ekernel/devices/serial_auno/serial_auno.h"

#include "../../include/ekernel/ekernel.h"

void eboot_exec() {
    t_eDevTable *devTable = eDevTable_instance();

    devTable->count = 2;
    devTable->devices = (t_eDevice **)malloc(sizeof(t_eDevice *) * devTable->count);

    devTable->devices[0] = display_1602_i2c_instance();
    devTable->devices[1] = serial_auno_instance();

    devTable->prepareAll(devTable);

    t_eKernel *kernel = ekernel_instance();
    ekernel_instance()->exec(kernel);
}