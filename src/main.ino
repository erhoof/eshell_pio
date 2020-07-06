#include "../include/eboot/eboot.h"
#include "../include/ekernel/devices/display_1602_i2c/display_1602_i2c.h"

void setup() {}

void loop() {
    eboot_exec();

    delay(20000);
}