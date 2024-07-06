#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <math.h>

int main(){

    const double pi = 3.14159265358979323846;
    const double x_approach = 35/pi; // approximation coefficient
    const double y_approach = 17.5; // approximation coefficient
    const int ten_num = 10;
    const float start_out = 1.5; // start pi coefficient
    const int end_out = 16; // end pi coefficient
    const int hatch_out = 35;
    const int number_out = 10;
    const int lines_out = 22;
    double y_result; // y coordinate
    double x_result; // x coordinate
    double y_out; // y coordinate for output
    double x_out; // x coordinate for output
    double max_result = -100; // function maximum

    int i;

    int gd, gm;

    int max_x; // maximal x coodrinate in window
    int max_y; // maximal y coodrinate in window

    char symbols_out[4]; 
    char maximum_out[50]; 

    clrscr();
	gd = DETECT;
	detectgraph(&gd, &gm);
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	
    // GETTING MAXIMAL NUMBER OF X AND Y COORINATES IN VIDEOMODE
    max_x = getmaxx();
	max_y = getmaxy();
	setviewport(0, 0, max_x, max_y, 0);
	setlinestyle(0, 0, 3); 
	line(lines_out, max_y, lines_out, 0); 
	line(lines_out, max_y/2, max_x, max_y/2); 


    for(i = start_out; i < end_out + 1; i++){
		sprintf(symbols_out, "%dPI", i); 
        outtextxy(ten_num + hatch_out*i, max_y/2 - lines_out, symbols_out); 
        line(lines_out + hatch_out*i, max_y/2 + ten_num/2, lines_out + hatch_out*i, max_y/2 - ten_num/2); 
    }
    for(i = -number_out + 1; i < number_out; i++){
		sprintf(symbols_out, "%d", i); 
		outtextxy(0, max_y/2 - hatch_out*i/2 - ten_num/2, symbols_out); 
		line(lines_out + ten_num/2, max_y/2 - hatch_out*i/2, lines_out - ten_num/2, max_y/2 - hatch_out*i/2); 
    }
	
    //the start assymptote
    setlinestyle(3, 0, 3);
    line(lines_out + hatch_out*start_out, max_y, lines_out + hatch_out*start_out, 0); 
    setlinestyle(0, 0, 3); 
    setviewport(0, 0, max_x, max_y, 0);
	
    // the graph of function
    for(x_result = start_out*pi; x_result <= end_out*pi; x_result = x_result + 0.001){
	y_result = pow(cos(x_result/4), 2) + sqrt(x_result);
        x_out = x_result*x_approach; 
        y_out = y_result*y_approach; 
        if(y_result > max_result){ 
		    max_result = y_result;
        }
        putpixel(lines_out + x_out, max_y/2 - y_out, 4);
    }
	
	// the end assymptote
    setlinestyle(3, 0, 3); 
    line(lines_out + hatch_out*end_out, max_y, lines_out + hatch_out*end_out, 0); 

    // output the max of function
    sprintf(maximum_out, "The max of function =  %f", max_result);
	outtextxy(max_x/3, max_y - lines_out, maximum_out);
	getch();
	closegraph();
	return 0;
}