//
// Created by Pavel Bibichenko on 07.07.2020.
//

#include <ekernel/devices/edevTable.h>
#include "../../include/esh/esh.h"

#include <string.h>
#include <stdlib.h>
#include <HardwareSerial.h>
#include <Arduino.h>

void esh_exec(struct eSh *);
void esh_loop(struct eSh *);

t_eSh *esh_instance() {
    static t_eSh esh;

    esh.exec = esh_exec;
    esh.drive = 'A';
    esh.isRunning = true;

    return &esh;
}

void esh_exec(struct eSh *self) {
    esh_loop(self);
}

void esh_loop(struct eSh *self) {
    t_eDevTable *devTable = eDevTable_instance();
    char enter[4] = {self->drive, '>', ' ', '\0'};
    bool lineInput;
    char *line;

    while (self->isRunning) {
        enter[0] = self->drive;

        devTable->emitAll(devTable, "pl", enter);

        lineInput = true;
        while (lineInput) {
            delay(100);
            line = (char *)devTable->emitAll(devTable, "i", nullptr);
            if (!line)
                continue;

            //Serial.print("here.");
            //Serial.print((int) *line);

            if (line && line[0] == 13) {
                lineInput = false;
                devTable->emitAll(devTable, "pl", "unk cmd.");
            }
            else if (line)
                devTable->emitAll(devTable, "p", line);

            //free(line);
        }
    }
}