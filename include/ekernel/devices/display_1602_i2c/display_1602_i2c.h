//
// Created by Pavel Bibichenko on 06.07.2020.
//

#ifndef ESHELL_PIO_DISPLAY_1602_I2C_H
#define ESHELL_PIO_DISPLAY_1602_I2C_H

#include "../edevice.h"

t_eDevice *display_1602_i2c_instance();
void prepare(struct eDevice *self);
void update(struct eDevice *self);
void emit(struct eDevice *self, const char *op, const char *cmd);
void del(struct eDevice *self);

#endif //ESHELL_PIO_DISPLAY_1602_I2C_H
