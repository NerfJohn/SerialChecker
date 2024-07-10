#include "msp.h"
#include "lcd.h"

// Definition for "unit" size (in pixels) of printout on LCD.
#define UNIT_SIZE  (17)
#define HALF_UNIT  (UNIT_SIZE / 2)

/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	// Initialize LCD.
	Crystalfontz128x128_Init();

	// Draw sized cubes to show how they fit on screen.
	uint16_t i, j;
	for (i = HALF_UNIT; i < LCD_VERTICAL_MAX; i += UNIT_SIZE) {
	    for (j = HALF_UNIT; j < LCD_HORIZONTAL_MAX; j += UNIT_SIZE) {
	        // Vary color to see units better.
	        uint16_t color = ((i ^ j) & 0x1) ? LCD_COLOR_ORANGE : LCD_COLOR_BLUE;

	        // Draw the unit.
	        lcd_draw_rectangle(i, j, UNIT_SIZE, UNIT_SIZE, color);
	    }
	}

	// Quick draw a unit to show where (0,0) roughly is.
	lcd_draw_rectangle(HALF_UNIT, HALF_UNIT, HALF_UNIT, HALF_UNIT, LCD_COLOR_RED);

	// Spin for user viewing.
	while (1) {}
}
