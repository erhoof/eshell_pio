//
// Created by Pavel Bibichenko on 06.07.2020.
//

#include "../../../../include/ekernel/devices/display_1602_i2c/display_1602_i2c.h"

#include <stdlib.h>
#include <string.h>

#include "../../../../lib/LiquidCrystal/LiquidCrystal_I2C.h"

t_eDevice *display_1602_i2c_instance() {
    t_eDevice *device = (t_eDevice *)malloc(sizeof(t_eDevice));

    strncpy(device->name, "1602disp", 8);
    device->name[7] = '\0';

    device->prepare = prepare;
    device->update = update;
    device->emit = emit;
    device->del = del;

    return device;
}

void prepare(struct eDevice *self) {
    self->data = new LiquidCrystal_I2C(0x3f, 16, 2);

    LiquidCrystal_I2C *lcdPtr = (LiquidCrystal_I2C *)self->data;
    lcdPtr->init();
    lcdPtr->backlight();
    lcdPtr->home();
    lcdPtr->print("init.");
}

void update(struct eDevice *self) {

}

void emit(struct eDevice *self, char *op, char *cmd) {

}

void del(t_eDevice *self) {
    free(self->ports);
    free(self);
}