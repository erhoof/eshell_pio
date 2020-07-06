//
// Created by Pavel Bibichenko on 06.07.2020.
//

#ifndef ESHELL_PIO_EKERNEL_H
#define ESHELL_PIO_EKERNEL_H

struct eKernel {
    void (*exec)(struct eKernel *self);
};
typedef struct eKernel t_eKernel;

t_eKernel *ekernel_instance();

#endif //ESHELL_PIO_EKERNEL_H
