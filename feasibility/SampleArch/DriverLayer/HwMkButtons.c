/*
 * HwMkButtons.c
 *
 *  Created on: Jul 12, 2024
 *      Author: John
 */

#include "msp.h"

#include <DriverLayer/HwMkButtons.h>

//==============================================================================
//
void HwMkButtons_init(void) {
    // Set pin to S1 button as input.
    P5->DIR &= ~BIT1;

    // Set pin to S2 button as input.
    P3->DIR &= ~BIT5;

    // Both pins are already pull-ups //
}

//==============================================================================
//
LogicLevel_e HwMkButtons_readS1(void) {
    // Return based on read value.
    return ((P5->IN & BIT1) ? LOGIC_LOW : LOGIC_HIGH); // active low
}

//==============================================================================
//
LogicLevel_e HwMkButtons_readS2(void) {
    // Return based on read value.
    return ((P3->IN & BIT5) ? LOGIC_LOW : LOGIC_HIGH); // active low
}
