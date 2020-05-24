// #include <stdio.h>
// #include <conio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <math.h>
// #include <graphics.h>
//#include "load.h"
//#include "states.h"
#include "imggraph.h"
#define MAX_STR 100

void home();



//-------------------------------------------------------------INFO & SURVEY PAGE ---------------------------------------


int pos;
char s[100];
void aware()
{
	FILE *fp;
	char c[1000];
	clrscr();
	fp=fopen("aware.txt","r");
	fscanf(fp,"%[^*]",c);
	printf("%s",c);
	fclose(fp);
	return;
}
void support()
{
int i,j,k,l,m,c=0,n,p,q;
char ch,chh,dummy;
clrscr();
printf("# Your health matters to us #\n\nHave a quick self assessment of your health through our app\npress enter to start\n");
fflush(stdin);
scanf("%c",&ch);
printf("How old are you\n");
scanf("%d",&i);
printf("please select your gender\n\n1:MALE\t2:FEMALE\t3:OTHERS\n");
scanf("%d",&j);
clrscr();
printf("please let us know your body temperature\n\n1:NORMAL(96'f-98.6'f)\t2:FEVER(98.6'f-102'f)\t3:HIGH FEVER(102'f)\n");
scanf("%d",&k);
printf("Are you experiencing any of the symptoms below\n\n1:DRY COUGH\t2:LOSS or DIMINISHED SENSE OF SMELL\n\n3:SORE THROAT\t4:WEAKNESS\n\n5:CHANGE IN APETITE\t6:NONRE OF THSESE\n");
scanf("%d",&l);
if(l!=6)
c++;
clrscr();
printf("Additionally,please verify if you are experiencing any of those symptoms below\n\n1:MODERATE TO SEVERE COUGH\t2:FEELING BREATHLESS\n\n3:DROWSINESS\t4:PRESSURE IN CHEST\n\n5:SEVERE WEAKNESS\t6:NONE OF THESE\n");
scanf("%d",&m);
if(m!=6)
c++;
clrscr();
printf("We would like to know about your smoking history\n\n1:CURRENT SMOKER\t2:PREVIOUS SMIOKER\t3:NEVER SMOKE\n");
scanf("%d",&n);
if(n!=3)
c++;
clrscr();
printf("Please select your travel and exposure details\n\n1:NO TRAVEL HISTORY\t2:NO CONTACT WITH ANYONE WITH SYMPTOMS\n\n3:HISTORY OF TRAVEL OR MEETING IN AFFECTED AREA IN LAST 14 DAYS\n\n4:CLOSE CONTACT WITH A PERSON WITH FEVER AND COUGH IN LAST 14 DAYS\n");
scanf("%d",&p);
if(p==3||p==4)
c++;
clrscr();
printf("Do you have a history of any of these conditions\n\n1:DIABETES\n\n2:HIGH BLOOD PRESSURE\n\n3:HEART DISESASE\n\n4:KIDNEY DISEASE\n\n5:LUNG DISEASES\n\n6:STROKE\n\n7:NONE OF THESE\n");
scanf("%d",&q);
if(q!=7)
c++;
clrscr();
printf("Your information is being processed: PRESS ENTER\n");
fflush(stdin);
scanf("%c",&dummy);
if(c==0)
{
printf("YOUR TEST RESULT:\ncovid-19 RISK LEVEL---LOW\n\n");
printf("STAY HOME STAY SAFE\n\nfollow below guidelines");
}
else if(c<3)
{
printf("YOUR TEST RESULT:\ncovid-19 RISK LEVEL---MEDIUM\n\n");
printf("CONSULT NEARBY DOCTOR\n\nfollow below guidelines");
}
else
{
printf("YOUR TEST RESULT:\ncovid-19 RISK LEVEL---HIGH\n\n");
printf("HAVE A PHYSICAL TEST IN NEARBY HOSPITAL\n\nfollow below guidelines");
}
return;
}

void survey_main(){
	int choice;
	int gd=DETECT,gm;
	closegraph();
	do
	{
		clrscr();
		printf("\n1:support\n2:aware\n3:Go Back\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:support();break;
		case 2:aware();break;
		}
	}while(choice<3);
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	home();
	getch();
}



//---------------------------------------------------COMPLAINT BOX PAGE ------------------------------------------

void complaint_main(){
	FILE* fp;
	int gd=DETECT,gm;
	char num[MAX_STR], temp[MAX_STR],c[2],txt[10],ch[MAX_STR],bit,data[1000],some[MAX_STR],op=' ';
	int n,i,j=1,k=1,z=1;

	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	cleardevice();

	fp = fopen("manage.txt","r");
	fscanf(fp,"%s",num);
	n = atoi(num);
	fclose(fp);

	settextstyle(3,0,1);

	do{
		k++;
		cleardevice();
		settextstyle(3,0,1);
		outtextxy(250,0,"Complaint Box");
		settextstyle(3,0,1);
		outtextxy(150,50,"Choose one option:");
		j=0;
		if(j==k%(n+2))setcolor(GREEN);
		outtextxy(200,100,"Enter your own complaint");
		setcolor(WHITE);
		z=1;
		for(i=n,j=1;i>=1;i--){
			strcpy(c,"c");
		    strcpy(txt,".txt");
			sprintf(temp, "%d", i);
			fp = fopen(strcat(strcat(c, temp), txt), "r");
			fscanf(fp, "%[^\n]", temp);
			sprintf(some,"%d. %s ...ReadMore",z,temp);
			if(j==k%(n+2))setcolor(GREEN);
			outtextxy(200,100+(j+1)*25,some);
			setcolor(WHITE);
			fclose(fp);
			j++;
			z++;
		}
		if(j==k%(n+2))setcolor(GREEN);
		outtextxy(200,100 + (j+1)*30,"Return to HomePage");
		setcolor(WHITE);
	}while((op=getch())!='\r');

	sprintf(ch,"%d",k%(n+2));

	if(k%(n+2)==n+1)home();

	cleardevice();

	closegraph();


       if(!strcmp("0",ch)){
      // u r an idiot if you don't find thid


		fp = fopen("manage.txt","r");
		fscanf(fp,"%s",num);
		fclose(fp);
		n = atoi(num);
		n += 1;
		fp = fopen("manage.txt","w");
		sprintf(temp,"%d",n);
		fprintf(fp,"%s",temp);
		fclose(fp);
		strcpy(c,"c");
	    strcpy(txt,".txt");
		sprintf(temp, "%d", n);
		fp = fopen(strcat(strcat(c, temp), txt), "w");
		printf("Enter your data. Enter $ to stop.\n");
		scanf("%[^$]s",data);
		// for(i=1;data[i]!='\0';i++)
		// 	data[i-1]=data[i];
		// data[i-1]='\0';
		fprintf(fp,"%s",data);
		fclose(fp);
		printf("Thank you....We will look into it...:)");
		printf("\n\nPress any key to go back");
	    getch();
	    complaint_main();
	}
	else
	{
		strcpy(c,"c");
	    strcpy(txt,".txt");
	    sprintf(temp, "%d", n - atoi(ch) +1);
		fp = fopen(strcat(strcat(c, temp), txt), "r");
		while ((bit =getc(fp)) != EOF)
		 printf ("%c", bit);
	    fclose(fp);
	    printf("\n\nPress any key to go back");
	    getch();
	    complaint_main();
	}	
}


//-------------------------------------------------------STATES PAGE---------------------------------------------------



#define SIZE 50
#define MAX_STR 100

struct DataItem {
   char name[MAX_STR], confirmed[MAX_STR], recovered[MAX_STR];
   char deaths[MAX_STR], permillion[MAX_STR];
};

struct DataItem* hashArray[SIZE];
struct DataItem* item;


int is_greater(struct DataItem* a, struct DataItem* b){
	char n1 [MAX_STR], n2[MAX_STR];
	strcpy(n1, a->confirmed);
	strcpy(n2, b->confirmed);
	if(strlen(n1)!=strlen(n2))
		return strlen(n1) > strlen(n2);
	return strcmp(n1, n2)>=0;
}

void heapify(struct DataItem* arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    struct DataItem* temp;

    if (l < n && is_greater(arr[l], arr[largest]))
	largest = l;

    if (r < n && is_greater(arr[r], arr[largest]))
	largest = r;

    if (largest != i)
    {
	temp = arr[i];
	arr[i] = arr[largest];
	arr[largest] = temp;
	heapify(arr, n, largest);
    }
}

void heapSort(struct DataItem* arr[], int n)
{
	struct DataItem* temp;
	int i;
    for (i = n / 2 - 1; i >= 0; i--)
	heapify(arr, n, i);

    for (i=n-1; i>0; i--)
    {
	temp = arr[i];
	arr[i] = arr[0];
	arr[0] = temp;
	heapify(arr, i, 0);
    }
}


int hashCode(int key) {
   return key % SIZE;
}

struct DataItem* search(char s[]){
   int hashIndex = hashCode(s[0]);
   while(hashArray[hashIndex] != NULL) {
      if(strcmp(hashArray[hashIndex]->name,s) == 0)
	 return hashArray[hashIndex];
      ++hashIndex;
      hashIndex %= SIZE;
   }
   return NULL;
}

void insert_to_dict(char s[], char a[], char b[], char c[], char d[]) {
   int hashIndex;
   struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
   strcpy(item->name, s);
   strcpy(item->confirmed, a);
   strcpy(item->permillion, b);
   strcpy(item->recovered, c);
   strcpy(item->deaths, d);
   hashIndex = hashCode(s[0]);
   while(hashArray[hashIndex] != NULL) {
      ++hashIndex;
      hashIndex %= SIZE;
   }
   hashArray[hashIndex] = item;
}
char* lower(char []);
void read_updates(){
    char a[MAX_STR],b[MAX_STR],c[MAX_STR],s[MAX_STR],d[MAX_STR];
    int i;
    FILE* fp = fopen("data.txt","r");
    for(i=0;i<35;i++){
		fscanf(fp,"%s%s%s%s%s",&s,&a,&b,&c,&d);
		insert_to_dict(lower(s), a, c, b, d);
    }
    fclose(fp);
}

void display10(){
	int i,j=0;
	struct DataItem* arr[SIZE];
	for(i = 0;i < SIZE;i++){
		if(hashArray[i]!=NULL)
			arr[j++]=hashArray[i];
	}
	heapSort(arr, j);
	printf("%-20s %8s %8s %8s\n","STATE NAME", "CONFIRMED", "RECOVERED", "DEATHS");
	for(i=j-1;i>=j-11;i--){
		printf("%-20s %8s %8s %8s\n",arr[i]->name, arr[i]->confirmed, \
			arr[i]->recovered, arr[i]->deaths);
	}
	printf("\nPress Enter to continue\n");
	getch();
}

void display1(struct DataItem* item){
	char temp[MAX_STR];
	printf("%s\n",item->name);
	printf("Confirmed Cases : %-50s\n",item->confirmed);
	printf("recovered Cases : %-50s\n",item->recovered );
	printf("deaths : %-50s\n",item->deaths);
	sprintf(temp,"%s.bmp",item->name);
	//printf("%s",temp);
	ShowBMP(360,150,temp);
	printf("\nPress Enter to continue");
	getch();
}

void displayerr(){
	printf("Umm.. Thats not a state in India. Try Again\n");
	printf("Press Enter to continue");
	getch();
}

char* lower(char s[])
{
	char a[MAX_STR];
	int i;
	for(i=0;s[i]!='\0';i++)
		a[i]=tolower(s[i]);
	a[i]='\0';
	return a;
}

void states_main();

int states_display(){
	char ch[MAX_STR];
	cleardevice();

	settextstyle(8,0,1);
	outtextxy(0,0,"Enter -1 to go back");
	outtextxy(50,100,"Enter the name of state or enter \"ALL\"");
	outtextxy(50,120,"to see 10 most infected states");
	rectangle(100,180,350,150);
	gotoxy(16,11);
	scanf("%s",ch);
	printf("\n");
	gotoxy(0,0);

	if(strcmp(ch, "-1")==0){
		return -1;
	}

	if(strcmp(lower(ch),"all")==0)
		display10();
	else
	{
		item = search(lower(ch));
		if(item==NULL)
			displayerr();
		else
			display1(item);
	}
	return 0;
}

void states_main(){

	while(1){
		if(states_display()==-1)
		{
			fflush(stdin);settextstyle(3,0,1);home();
		}	
	}
}













//------------------------------------------------------MAIN PAGE----------------------------


void background(){
	int x,y;
	int i = 0;
	setcolor(WHITE);
	settextstyle(4,0,5);
	outtextxy(250,50,"Care");
	settextstyle(8,0,1);
	outtextxy(300,100,"We are with you.");
	while(i<30){
		x = rand()%(100);
		y = rand()%(600);
		circle(x,y,5);
		x = 500 + rand()%(600 -500);
		y = rand()%(600);
		circle(x,y,5);
		i++;
	}
}

int display_option(){
	int i=0,j,colour[7],x,y;
	int op = 7;
    settextstyle(3,0,3);
    fflush(stdin);
    do{
		x=200;
        y=180;
	    cleardevice();

	    background();

		for(j=0;j<op;j++)colour[j]=WHITE;
	    colour[i%op]=GREEN;

		settextstyle(3,0,1);

	    setcolor(colour[0]);
	     outtextxy(x,y,"Statistics in India");
	     y+=20;
	     setcolor(colour[1]);
	     outtextxy(x,y,"Complaint Box");
	     y+=20;
	     setcolor(colour[2]);
	     outtextxy(x,y,"Survey & Precautions");
	     y+=20;
	     setcolor(colour[3]);
	     outtextxy(x,y,"Donations");
	     y+=20;
	     setcolor(colour[4]);
	     outtextxy(x,y,"Hospital Appointment");
	     y+=20;
	     setcolor(colour[5]);
	     outtextxy(x,y,"Local Info");
	     y+=20;
	     setcolor(colour[6]);
	     outtextxy(x,y,"Exit");
	     y+=20;
	     i++;
    }while(getch()!='\r');
    setcolor(WHITE);
    if(i%op==0)
    	exit(0);
    return i%op;
}

void home(){
	int k = display_option();
	switch(k){
		case 1:states_main();
				break;
		case 2:complaint_main();
				break;
		case 3:survey_main();
				break;
		case 4:
		break;
		case 5:
		break;
		case 6:
		break;
	}
	exit(0);
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

// 	cleardevice();
// 	states_main();

// 	getch();
// 	closegraph();
// }


