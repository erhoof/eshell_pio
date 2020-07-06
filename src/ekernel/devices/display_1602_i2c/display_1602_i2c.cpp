//
// Created by Pavel Bibichenko on 06.07.2020.
//

#include "../../../../include/ekernel/devices/display_1602_i2c/display_1602_i2c.h"

#include <stdlib.h>
#include <string.h>

#include "../../../../lib/LiquidCrystal/LiquidCrystal_I2C.h"
#include "Arduino.h"

void display_1602_i2c_prepare(struct eDevice *self);
void display_1602_i2c_update(struct eDevice *self);
void *display_1602_i2c_emit(struct eDevice *self, const char *op, const char *cmd);
void display_1602_i2c_del(struct eDevice *self);

t_eDevice *display_1602_i2c_instance() {
    t_eDevice *device = (t_eDevice *)malloc(sizeof(t_eDevice));

    strncpy(device->name, "1602dis", 8);
    device->name[7] = '\0';

    device->prepare = display_1602_i2c_prepare;
    device->update = display_1602_i2c_update;
    device->emit = display_1602_i2c_emit;
    device->del = display_1602_i2c_del;

    return device;
}

void display_1602_i2c_prepare(struct eDevice *self) {
    self->data = new LiquidCrystal_I2C(0x3f, 16, 2);

    LiquidCrystal_I2C *lcdPtr = (LiquidCrystal_I2C *)self->data;
    lcdPtr->init();
    lcdPtr->setBacklight(1);
    lcdPtr->home();

    strcpy((char *)self->altData, "1602DISP init.");
    lcdPtr->print((char *)self->altData);
    delay(1000);
}

void display_1602_i2c_update(struct eDevice *self) {

}

void *display_1602_i2c_emit(struct eDevice *self, const char *op, const char *cmd) {
    if (!strcmp(op, "pl")) {
        ((LiquidCrystal_I2C*) (self->data))->clear();
        ((LiquidCrystal_I2C*) (self->data))->print((char *)self->altData);

        ((LiquidCrystal_I2C*) (self->data))->setCursor(0, 1);
        strcpy((char *)self->altData, cmd);
        ((LiquidCrystal_I2C*) (self->data))->print((char *)self->altData);
        delay(500);
    } else if (!strcmp(op, "p")) {
        strcat((char *)self->altData, cmd);
        ((LiquidCrystal_I2C*) (self->data))->print(cmd);
    }

    return nullptr;
}

void display_1602_i2c_del(t_eDevice *self) {
    free(self->ports);
    free(self->data);
    free(self->altData);
    free(self);
}