//
// Created by Pavel Bibichenko on 07.07.2020.
//

#ifndef ESHELL_PIO_ESH_H
#define ESHELL_PIO_ESH_H

struct eSh {
    char drive;
    bool isRunning;

    void (* exec)(struct eSh *self);
};
typedef struct eSh t_eSh;

t_eSh *esh_instance();

#endif //ESHELL_PIO_ESH_H
