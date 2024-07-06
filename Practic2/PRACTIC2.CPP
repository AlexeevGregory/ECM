#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<graphics.h>

void printText(int txtclr){
	textcolor(txtclr);
	textbackground(15-txtclr);
}

int main(){
clrscr();
	int colors[] = {BLACK, BLUE, GREEN, RED, CYAN, MAGENTA, BROWN, LIGHTGRAY, DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE};
	char* namecolor[] = {"BLACK", "BLUE", "GREEN", "RED", "CYAN", "MAGENTA", "BROWN", "LIGHTGRAY", "LIGHTBLUE", "LIGHTGREEN", "LIGHTCYAN", "LIGHTRED", "LIGHTMAGENTA","YELLOW", "WHITE"};
	window(15,8,65,18);
	textcolor(WHITE);
	textbackground(BLACK);
	int x = 1, y = 1;
	gotoxy(x,y);
	while(!kbhit()){
		for(int i = 0; i < 16; i++){
		printText(colors[i]);
		cprintf("background: %d color: %s", colors[i], namecolor[15-i]);
		delay(800);
		y-=1;
		if(y<1){
			y=1;
			insline();
			insline();
			insline();
		}
		gotoxy(x,y);
		}
	}
	return 0;
}