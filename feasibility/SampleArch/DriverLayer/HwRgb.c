/*
 * HwRgb.c
 *
 *  Created on: Jul 12, 2024
 *      Author: John
 */

#include "msp.h"

#include <DriverLayer/HwRgb.h>

/*
 * TODO- init
 */
void HwRgb_init(void) {
    // Set as outputs.
    P2->DIR |= (BIT2 | BIT1 | BIT0);

    // Turn off.
    P2->OUT &= ~(BIT2 | BIT1 | BIT0);
}

/*
 * TODO- set the rgbs.
 */
void HwRgb_set(bool r, bool g, bool b) {
    // Get P2->OUT (w/ RGB LEDs off).
    uint8_t retOuts = P2->OUT & ~(BIT2 | BIT1 | BIT0);

    // Turn LEDs on as needed.
    retOuts = (r) ? (retOuts | BIT0) : retOuts;
    retOuts = (g) ? (retOuts | BIT1) : retOuts;
    retOuts = (b) ? (retOuts | BIT2) : retOuts;

    // Write P2->OUT (and LEDs with it).
    P2->OUT = retOuts;
}
