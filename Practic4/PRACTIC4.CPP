#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <bios.h>


#define LEFT  15104   //code of f1
#define RIGHT 15872   //code of f4
#define UP    15360   //code of f2
#define DOWN  15616   //code of f3
#define ESC   283


void printWindow(int x1, int y1, int x2, int y2) {
    // Border window
    clrscr();
    window(x1 - 1, y1 - 1, x2 + 1, y2 + 2);
    textbackground(BLACK);
    textcolor(WHITE);

    // Upper horizontal line
    cprintf("=");
    for (int i = 0; i < x2 - x1 + 1; ++i)
	cprintf("=");
    cprintf("=");

    // Vertical lines
    for (i = 0; i < y2 - y1 + 1; ++i) {
        cprintf("|");
        for (int j = 0; j < x2 - x1 + 1; ++j)
            cprintf(" ");
	cprintf("|");
    }

    // Lower horizontal line
    cprintf("=");
    for (i = 0; i < x2 - x1 + 1; ++i)
        cprintf("=");
    cprintf("=");

    // Active window
    window(x1, y1, x2, y2);
}


int getMode() {
    int ch;
	ch = bioskey(0);
	if (ch == DOWN)   return 1;
	if (ch == UP)     return 2;
	if (ch == LEFT)   return 3;
	if (ch == RIGHT)  return 4;
	if (ch == ESC)    return -1;

    return 0;
}


int main() {
    int x1 = 15, y1 = 8, x2 = 65, y2 = 18;
    int x = (x2 - x1) / 2, y = (y2 - y1) / 2; //change the center of area

    printWindow(x1, y1, x2, y2);
    _setcursortype(_NOCURSOR);

    gotoxy(x, y);
    cprintf("*");

    while (1) {

	while (bioskey(1) == 0) {
	    int choice = getMode();
	    switch (choice) {
		case -1: // Escape
		    return 0;
		case 1: // Down(f3)
		    y++;
		    if (y == y2 - y1 + 2) y = 1;
		    clrscr();
		    gotoxy(x,y);
		    cprintf("*");
		    break;
		case 2: // Up(f2)
		    y--;
		    if (y == 0) y = y2 - y1 + 1;
		    clrscr();
		    gotoxy(x,y);
		    cprintf("*");
		    break;
		case 3: // Left(f1)
		    x--;
		    if (x == 0) x = x2 - x1 + 1;
		    clrscr();
		    gotoxy(x,y);
		    cprintf("*");
		    break;
		case 4: // Right(f4)
		    x++;
		    if (x == x2 - x1 + 2) x = 1;
		    clrscr();
		    gotoxy(x,y);
		    cprintf("*");
		    break;
		default: // Unknown command
		    continue;
	    }
	}
    }
}