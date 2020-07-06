//
// Created by Pavel Bibichenko on 07.07.2020.
//

#include "../../../../include/ekernel/devices/serial_auno/serial_auno.h"

#include <stdlib.h>
#include <string.h>

#include <Arduino.h>

void serial_auno_prepare(struct eDevice *self);
void serial_auno_update(struct eDevice *self);
void *serial_auno_emit(struct eDevice *self, const char *op, const char *cmd);
void serial_auno_del(struct eDevice *self);

t_eDevice *serial_auno_instance() {
    t_eDevice *device = (t_eDevice *)malloc(sizeof(t_eDevice));

    strncpy(device->name, "serial", 8);
    device->name[7] = '\0';

    device->prepare = serial_auno_prepare;
    device->update = serial_auno_update;
    device->emit = serial_auno_emit;
    device->del = serial_auno_del;

    return device;
}

void serial_auno_prepare(struct eDevice *self) {
    Serial.begin(9600);
    Serial.println("SERIAL init.");

    delay(1000);
}

void serial_auno_update(struct eDevice *self) {

}

void *serial_auno_emit(struct eDevice *self, const char *op, const char *cmd) {
    if (!strcmp(op, "i")) {
        char *out = (char *)malloc(sizeof(char) * 2);
        //unsigned char curChar = 0;
        //out[0] = 'b';
        //out[1] = '\0';

        if (Serial.available()) {
            char byte = Serial.read();

            //Serial.println("line: ");

            out[0] = byte;
            out[1] = '\0';

            //Serial.print(*out);

            return out;
            /*out[curChar] = byte;
            curChar++;

            if (byte == '\n') {
                out[curChar] = '\0';
                break;
            } */
        }
    }

    return nullptr;
}

void serial_auno_del(t_eDevice *self) {
    free(self->ports);
    free(self->data);
    free(self->altData);
    free(self);
}