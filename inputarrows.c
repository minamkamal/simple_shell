#include "main.h"

/**
 * processInput - Process input characters
 *
 * This function processes input characters, detecting and handling
 */

void processInput(void)
{
	char c;
	char arrow;

	while ((c = getchar()) != EOF)
	{
		if (c == '\n')
		{
			continue;
		}
		else if (c == '\033')
		{
			arrow = getchar();
			if ((arrow == EOF))
			{
				break;
			}

			handleArrowKeyPress(arrow);
		}
		else
		{
			putchar(c);
		}
	}
}
