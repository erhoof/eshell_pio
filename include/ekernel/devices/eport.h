//
// Created by Pavel Bibichenko on 06.07.2020.
//

#ifndef ESHELL_PIO_EPORT_H
#define ESHELL_PIO_EPORT_H

enum ePortType {
    I2C,
    SPI,
    DIGITAL,
    DIGITAL_PWM,
    TX,
    RX,
    ANALOG
};
typedef enum ePortType t_ePortType;

struct ePort {
    t_ePortType type;
    unsigned char number;
};
typedef struct ePort t_ePort;

#endif //ESHELL_PIO_EPORT_H
