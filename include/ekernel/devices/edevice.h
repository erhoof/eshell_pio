//
// Created by Pavel Bibichenko on 06.07.2020.
//

#ifndef ESHELL_PIO_EDEVICE_H
#define ESHELL_PIO_EDEVICE_H

#include "eport.h"

struct eDevice {
    char name[8];

    t_ePort *ports;
    unsigned int portCount;
    void *data;

    void (*prepare)(struct eDevice *self);
    void (*update)(struct eDevice *self);
    void (*emit)(struct eDevice *self, char *op, char *cmd);
    void (*del)(struct eDevice *self);
};
typedef struct eDevice t_eDevice;

#endif //ESHELL_PIO_EDEVICE_H
