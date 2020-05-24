#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>
#include <ctype.h>
#include <alloc.h>
#include "load.h"
//#include "states.h"
#include "mainpage.h"



void main() {

	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");

	//Preprocessing....
	read_updates();

	cleardevice();
	load_title();

	cleardevice();
	start_loading();

	cleardevice();
	home();

	// cleardevice();
	// states_main();

	// cleardevice();
	// survey_main();

	getch();
	closegraph();
}