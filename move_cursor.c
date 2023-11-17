#include "main.h"

/**
 * moveCursorLeft - Move the cursor to the left
 *
 * This function moves the cursor to the left by outputting the backsppace
 */
void moveCursorLeft(void)
{
	printf("\b");
}

/**
 * moveCursorRight - Move the cursor to the right
 *
 * This function moves the cursor to the right by outputting the escape
 */

void moveCursorRight(void)
{
	printf("\033[C");
}

/**
 * handleArrowKeyPress - Handle arrow key press
 * @arrow: The arrow key identifier
 *
 * This function handles arrow key presses and performs cursor
 */
void handleArrowKeyPress(char arrow)
{
	if (arrow == 'D')
	{
		moveCursorLeft();
	}
	else if (arrow == 'C')
	{
		moveCursorRight();
	}
}
