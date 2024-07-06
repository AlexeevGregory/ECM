#include <dos.h>
#include <stdio.h>
#include <conio.h>

char text[100];
int index = 0;

int textlength(char* str) {
int l = 0;
while (str[l] != '\0') l++;
return l;
}

void interrupt (*prevInt09h) (...);

void interrupt Int09h (...) {
	unsigned char keyState = inp(0x60);

	if ((keyState & 128) == 0) {
		putch(text[index]);
		index = (index + 1) % textlength(text);
	}
	(*prevInt09h)();
}

int main() {
	clrscr();

	printf("Enter a text: ");
	gets(text);
	if (textlength(text) == 0) return -1;


	prevInt09h = _dos_getvect(0x09);
	_dos_setvect(0x09, Int09h);


	printf("Press <ESC> to exit programm\n\n\n\n\n[text]->");
	while (1) {
	    if (kbhit() && getch() == 27) {

	    _dos_setvect(0x09, Int09h);
            return 0;
	    }
	}
}