// #include <stdio.h>
// #include <conio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <graphics.h>

void start_loading(){
	int i;
	int a,b,c;
	for(i=0;i<10;i++)
	{
	    a=b=c=BLACK;
	    if(i%3==0)a=GREEN;
	    else if(i%3 == 1)b=GREEN;
	    else c=GREEN;
	    setfillstyle(SOLID_FILL,a);
	    circle(255,150,5);
	    floodfill(256,150,WHITE);
	    setfillstyle(SOLID_FILL,b);
	    circle(285,150,5);
	    floodfill(286,150,WHITE);
	    setfillstyle(SOLID_FILL,c);
	    circle(315,150,5);
	    floodfill(316,150,WHITE);
	    settextstyle(8,0,1);
	    outtextxy(255,180,"Loading...");

	    delay(500);
	}
}

void load_title(){
	int i,j;
	char title[100][100],each;

	strcpy(title[0],"C");
	strcpy(title[1],"a");
	strcpy(title[2],"r");
	strcpy(title[3],"e");
	
	settextstyle(3,0,5);
	outtextxy(250,150,"Care");

	for(i=0;i<=10;i++)
	{
		cleardevice();
		for(j=0;j<4;j++)
		{
			if(j==i%4)
				setcolor(GREEN);
			settextstyle(3,0,8);
			if(j==3)
			outtextxy(240+j*35,150,title[j]);
			else
			outtextxy(240+j*40,150,title[j]);
			setcolor(WHITE);
			//delay(100);
		}
		delay(200);
	}
}

// void main() {

// 	int gd=DETECT,gm;
// 	initgraph(&gd,&gm,"c:\\turboc3\\bgi");

// 	cleardevice();
// 	load_title();

// 	cleardevice();
// 	start_loading();

// 	cleardevice();
// 	home();

// 	closegraph();
// 	getch();
// }


