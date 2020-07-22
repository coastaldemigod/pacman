#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include <stdlib.h>
#include <stdio.h>
#include<dos.h>
#include<string.h>
#include<fstream.h>

 struct saver
       {
	 char name[20];
	 unsigned int score;
	 };
class pacman
{
public:
char ch;
char name[20];
int life;
unsigned int score;
int level;

int mover;
int a[70][40];

int gmover[4];
int timerx[4];
int timery[4];
int countertimer[4];
int ghostrev[4];
int rdom[4];
int x,y;
int x1[4],y1[4];

void pacanimation();

void moveup();
void moveleft();
void moveright();
void movedown();
void checkd();
void cmove();

void up();
void left();
void right();
void down();
int checkup(int h,int k);
int checkdown(int h,int k);
int checkright(int h,int k);
int checkleft(int h,int k);

void newgame();
void initialize();
void displayf();
void displayg();
void change();
void change1(int gn);
void ghostmove(int gn);
void reverseghost(int gn);

void pacloc();
int checkpacloc(int h, int k);

void save();
saver highscore();
void leaderboard();
void homepage1();
void start(char c);
void homepage();
void gameover();

};


inline int pacman ::  checkup(int h,int k)
{
if(k==20)return 1;
else if(k==140 && ( (h>100 && h<320) || (h>320 && h<540)) )return 1;
else if(k==200 &&( (h>20 && h<100)||(h>540 && h<620) ))return 1;
else if(k==270 && ( (h>100 && h<220) || (h>220 && h<420) || ( h>420 && h<540)) )return 1;
else if(k==390 && ( (h>100 && h<320) || (h>320 && h<540) || (h>20 && h<100) || ( h>540 && h<620)) )return 1;
else return 0;
}
inline int pacman :: checkdown(int h,int k)
{
if(k==390)return 1;
else if(k==270 && ( (h>100 && h<320) || (h>320 && h<540)) )return 1;
else if(k==200 &&( (h>20 && h<100)||(h>540 && h<620) ))return 1;
else if(k==140 && ( (h>100 && h<220) || (h>220 && h<420) || ( h>420 && h<540)) )return 1;
else if(k==20 && ( (h>100 && h<320) || (h>320 && h<540) || (h>20 && h<100) || ( h>540 && h<620) ) )return 1;
else return 0;
}
inline int pacman ::checkright(int h,int k)
{
if(h==20 && ( (k>20 && k<200) || (k>200 && k<390) ) )return 1;
else if(h==100 && ( (k>20 && k<140) || (k>140 && k<270) || ( k>270 && k<390) ) )return 1;
else if(h==220 && ( (k>140 && k<270) ) )return 1;
else if(h==320 && ( (k>20 && k<140) || (k>270 && k<390) ) )return 1;
else if(h==420 && ( (k>140 && k<270) ) )return 1;
else if(h==540 && ( (k>20 && k<200) || (k>200 && k<390) ) )return 1;
else if(h==620)return 1;
else return 0;
}
inline int pacman :: checkleft(int h,int k)
{
if(h==620 && ( (k>20 && k<200) || (k>200 && k<390) ) )return 1;
else if(h==540 && ( (k>20 && k<140) || (k>140 && k<270) || ( k>270 && k<390) ) )return 1;
else if(h==420 && ( (k>140 && k<270) ) )return 1;
else if(h==320 && ( (k>20 && k<140) || (k>270 && k<390) ) )return 1;
else if(h==220 && ( (k>140 && k<270) ) )return 1;
else if(h==100 && ( (k>20 && k<200) || (k>200 && k<390) ) )return 1;
else if(h==20)return 1;
else return 0;
}
void pacman :: displayg()
{
int l=level;
if(l>15)
l=random(15);
setcolor(l);
setlinestyle(0,0,3);
rectangle(5,5,635,405);
rectangle(35,35,85,185);
rectangle(35,215,85,375);
rectangle(115,35,305,125);
rectangle(115,155,200,255);
rectangle(115,285,305,375);
rectangle(235,155,405,255);
rectangle(335,35,525,125);
rectangle(335,285,525,375);
rectangle(435,155,525,255);
rectangle(555,35,605,185);
rectangle(555,215,605,375);
setlinestyle(0,0,1);
setcolor(14);
}

void pacman :: displayf()
{
int i;
   setfillstyle(SOLID_FILL,14);
i=20;
while(i<400 )
{
    fillellipse(20,i,2,2);
    fillellipse(100,i,2,2);
  fillellipse(540,i,2,2);
  fillellipse(620,i,2,2);

   i=i+10;
  }

  i=150;
while(i<260 )
{
  fillellipse(220,i,2,2);
  fillellipse(420,i,2,2);

    i=i+10;
}
i=30;
while(i<130 )
{
  fillellipse(320,i,2,2);

     i=i+10;
      }

      i=280;
  while(i<380 )
{
  fillellipse(320,i,2,2);

  i=i+10;
}


i=20;
while(i<630 )
{
  fillellipse(i,20,2,2);
  fillellipse(i,390,2,2);

     i=i+10;
}

i=100;
while(i<540 )
{

  fillellipse(i,140,2,2);
  fillellipse(i,270,2,2);

 i=i+10;
}

i=20;
while(i<100)
{
fillellipse(i,200,2,2);

i=i+10;
}
i=540;
while(i<620)
{
fillellipse(i,200,2,2);

i=i+10;
}
}

inline void pacman :: change()
{
setfillstyle(SOLID_FILL,0);
floodfill(x,y,0);
}


inline void pacman :: pacanimation()
{

  setcolor(14);
setfillstyle(SOLID_FILL,14);
fillellipse(x,y,8,8);

setfillstyle(SOLID_FILL,4);
fillellipse(x+4,y-4,2,3);

setfillstyle(SOLID_FILL,9);
fillellipse(x1[1],y1[1],6,6);

setfillstyle(SOLID_FILL,10);
fillellipse(x1[2],y1[2],6,6);

setfillstyle(SOLID_FILL,11);
fillellipse(x1[3],y1[3],6,6);

setfillstyle(SOLID_FILL,12);
fillellipse(x1[0],y1[0],6,6);
int u=5-level;
if(u<0)
u=0;
delay(u);

ghostmove( 0);
ghostmove( 1);
ghostmove( 2);
ghostmove( 3);


if(x%10==0 && y%10==0)
pacloc();

gotoxy(35,13);
cout<<"score: "<<score*10;


if(score==412*level )
gameover();
}
inline void pacman :: up()
{
	if(checkup(x,y))
	y++;

change( );
	change1(1);
	change1(2);
change1(3);
change1(0);
      //	y--;
	pacanimation( );
}
inline void pacman :: left()
{
 if(checkleft( x,y))
	x++;
	change( );
	change1(1);
	change1(2);
change1(3);
change1(0);
       //	x--;
	pacanimation( );
}
inline void pacman :: down()
{
 if(checkdown(x,y ))
	y--;

	change( );
	change1(1);
	change1(2);
change1(3);
change1(0);
      //	y++;
	pacanimation( );
}
inline void pacman :: right()
{
 if(checkright(x,y ))
	x--;

	  change( );
	change1(1);
	change1(2);
change1(3);
change1(0);
      //	x++;
	pacanimation( );
	  }

void pacman :: cmove()
{
 switch(mover)
  {
  case 77:right();
	  break;
  case 72:up();
	  break;
  case 75:left();
	  break;
  case 80:down();
	  break;
  }
}



void pacman :: checkd()
{

	switch(ch)
	{
		case 77:if(checkright(x,y))
		  {
	       while(1)
		  {
		 cmove( );

	     if(y==20 || (y==140 && (x!=540 && x!=20 && x!=620)) || (y==200 && (x==20 || x==540)) || (y==270 && (x!=540 && x!=20 && x!=620)) || y==390 )
	      moveright( );
		 else if(kbhit())
		{
		ch=getch();
		checkd( );
		}
       }
}
else
moveright( );
break;

		case 72:if(checkup(x,y))
{
	while(1)
	{
	cmove( );

	 if( (x==20 && y!=20) || (x==100 && y!=20)  || ( x==220 && (y!=390 && y!=140 && y!=20) )  || (x==320 && y!=270) || (x==420 && (y!=390 && y!=140 && y!=20) ) || (x==540 && y!=20) || (x==620 && y!=20))
	 moveup( );
	 else if(kbhit())
	 {
	   ch=getch();
	   checkd( );
	  }
       }
}
else
moveup( );
break;

		case 75:if(checkleft(x,y))
{
       while(1)
	{
	 cmove( );

	 if(y==20 || (y==270 && (x!=100 && x!=20 && x!=620)) || (y==200 && (x==100 || x==620)) || (y==140 && (x!=100 && x!=20 && x!=620)) || y==20)
	  moveleft( );
	 else if(kbhit())
	 {
	   ch=getch();
	   checkd( );
	  }
       }
}
else
moveleft( );
break;
		case 80:  if(checkdown(x,y))
{
	while(1)
	{
	cmove( );

	if( (x==20 && y!=390) || (x==100 && y!=390 )  || ( x==220 && (y!=390 && y!=270 && y!=20) )  || (x==320 && y!=140) || (x==420 && (y!=390 && y!=270 && y!=20) ) || (x==540 && y!=390) || (x==620 && y!=390))
		 movedown( );
	 else if(kbhit())
	 {
	   ch=getch();
	   checkd( );
	  }
	}
}
else
movedown( );
break;
      case 97:
      while(!kbhit())
      { }
      ch=mover;
      checkd();

      break;
   /*   case 108:
	 life++;
	 if(life>9)
	 life=9;

	 gotoxy(35,14);
cout<<"lives: ";
int u=42;
for(int t=0;t<life;t++)
{ gotoxy(u,14);
 cout<<(char)(3);
 u++;
 }
		break;

     */
	}
}

void pacman :: moveup()
{
while(1)
{
while(!kbhit())
{  mover=72;
up( );}

ch=getch();
checkd( );
	if(ch==27)
	exit(0);
}
}

void pacman :: moveleft()
{

while(1)
{
while(!kbhit())
{ mover=75;
left( );}

	ch=getch();
checkd( );
	if(ch==27)
		exit(0);
	}
}

void pacman :: movedown()
{
while(1)
{
  while(!kbhit())
{   mover=80;
down( );}

		ch=getch();
checkd( );
	if(ch==27)
		exit(0);
	 }
}


void pacman :: moveright()
{

while(1){
while(!kbhit())
{  mover=77;
right( ); }

	ch=getch();
checkd( );
	if(ch==27)
		exit(0);
		}
}

inline void pacman :: pacloc()
{
	if(a[x/10][y/10]!=1)
{
	a[x/10][y/10]=1;
score++;
}
}
inline int pacman :: checkpacloc(int h, int k)
{
 if(a[h/10][k/10]==1)
 return 1;
 else
 return 0;
}

void pacman :: change1(int gn)
{

setfillstyle(SOLID_FILL,0);
setcolor(0);
fillellipse(x1[gn],y1[gn],7,7);


	setfillstyle(SOLID_FILL,14);
	setcolor(14);
	switch(gmover[gn])
		{
		case 77:  if(checkpacloc(x1[gn]-10,y1[gn])==0)
			     if((x1[gn]-10)%10==0)
			fillellipse(x1[gn]-10,y1[gn],2,2);
	  break;
  case 72:if(checkpacloc(x1[gn],y1[gn]+10)==0)
	  if((y1[gn]+10)%10==0)
				fillellipse(x1[gn],y1[gn]+10,2,2);
	  break;
  case 75:if(checkpacloc(x1[gn]+10,y1[gn])==0)
	if((x1[gn]+10)%10==0)
				fillellipse(x1[gn]+10,y1[gn],2,2);
	  break;
  case 80: if(checkpacloc(x1[gn],y1[gn]-10)==0)
	    if((y1[gn]-10)%10==0)
				fillellipse(x1[gn],y1[gn]-10,2,2);
	  break;
	}
	setcolor(0);
}
void pacman :: reverseghost(int gn)
{
ghostrev[gn]=1;

	if(x1[gn]>x && !checkright(x1[gn],y1[gn]))
	{
	x1[gn]++;
	gmover[gn]=77;
	}
	else if(x1[gn]<x && !checkleft(x1[gn],y1[gn]))
	{x1[gn]--;
	gmover[gn]=75;
	}
	else if(y1[gn]>y && !checkdown(x1[gn],y1[gn]))
	{y1[gn]++;
	gmover[gn]=80;
	}
	else if(y1[gn]<y && !checkup(x1[gn],y1[gn]))
	{y1[gn]--;
	gmover[gn]=72;
       }

    countertimer[gn]++;
if(countertimer[gn]>=400)
{
	timerx[gn]=0;
	timery[gn]=0;
	ghostrev[gn]=0;
}
}


void pacman :: ghostmove( int gn)
{
	if(ghostrev[gn]!=1)
{	countertimer[gn]=0;
	rdom[gn]=random(2);

if(abs(y1[gn]-y)>=abs(x-x1[gn]))
{
if(y1[gn]<y && !checkdown(x1[gn],y1[gn]))
	{y1[gn]++;
	gmover[gn]=80;
	}
	else if(y1[gn]>y && !checkup(x1[gn],y1[gn]))
	{y1[gn]--;
	gmover[gn]=72;
	}
	else if(x1[gn]<x && !checkright(x1[gn],y1[gn]))
	{
	x1[gn]++;
	gmover[gn]=77;
	}
	else if(x1[gn]>x && !checkleft(x1[gn],y1[gn]))
	{x1[gn]--;
	gmover[gn]=75;
	}
 }

else
{
	if(x1[gn]<x && !checkright(x1[gn],y1[gn]))
	{
	x1[gn]++;
	gmover[gn]=77;
	}
	else if(x1[gn]>x && !checkleft(x1[gn],y1[gn]))
	{x1[gn]--;
	gmover[gn]=75;
	}
	else if(y1[gn]<y && !checkdown(x1[gn],y1[gn]))
	{y1[gn]++;
	gmover[gn]=80;
	}
	else if(y1[gn]>y && !checkup(x1[gn],y1[gn]))
	{y1[gn]--;
	gmover[gn]=72;
	}
}
    }
   if(x==x1[gn])
	timerx[gn]++;

   if(y==y1[gn])
	timery[gn]++;

	if( ( timerx[gn] + timery[gn] ) >=250)
	{
	if(rdom[gn])
	reverseghost( gn );
	else
	{
	timerx[gn]=0;
	timery[gn]=0;
	}
	}

	if((x==x1[gn] && y==y1[gn]) || (x-12==x1[gn] && y==y1[gn]) || (x+12==x1[gn] && y==y1[gn]) || (x==x1[gn] && y-12==y1[gn]) || (x==x1[gn] && y+12==y1[gn]) )
	 gameover();

}
void pacman :: newgame()
{
for(int i=0;i<40;i++)
for(int j=0;j<70;j++)
a[j][i]=0;

life=4;
score=0;
level=1;
}
void pacman :: initialize()
{
x=20,y=20;
	x1[0]=220,x1[1]=520,x1[2]=420,x1[3]=320;
	y1[0]=390,y1[1]=390,y1[2]=390,y1[3]=390;

	ch=77;
	for(int r=0;r<4;r++)
	{
		gmover[r]=0;

timerx[r]=0;
timery[r]=0;
countertimer[r]=0;
ghostrev[r]=0;
rdom[r]=0;
	}
mover=0;
}
void pacman :: start(char c)
{
clrscr();
		randomize();
		int gd = DETECT,gm;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

 initialize();
	   if(c=='n')
	      homepage();
	 else
       {  life--;
	  if(life==0)
	  start('n');
	 }

	 displayg();
	 displayf();

	 gotoxy(35,14);
cout<<"lives: ";
int u=42;
for(int t=0;t<life;t++)
{ gotoxy(u,14);
 cout<<(char)(3);
 u++;
 }


for(int i=0;i<40;i++)
for(int j=0;j<70;j++)
{
if(a[j][i]==1)
{
 setcolor(0);
setfillstyle(SOLID_FILL,0);
fillellipse(j*10,i*10,4,4);
setcolor(14);

}
}



	   settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
      outtextxy(140,60,name);
      outtextxy(140,70,"playing pacman");
      char h[2];
      itoa(level,h,10);
      setcolor(level);
      settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
      outtextxy(150,310,"LEVEL");
      outtextxy(230,310,h);
      setcolor(14);

 saver k;
 k=highscore();
     gotoxy(47,20);
     cout<<"HIGHSCORE";
     gotoxy(47,22);
     cout<<k.name<<" - "<<k.score*10;
	if(score>k.score)
	{
	gotoxy(47,22);
     cout<<name<<" - "<<score*10;
	}
	while(1){
	moveright();
	}
	}

void pacman :: gameover()
{
int fl=0;
if(score==412*level)
{
//save();
fl=1;
 settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
      setcolor(2);
      outtextxy(380,60,"YOU WIN");

      for(int o=0;o<4;o++)
      {   delay(100);
      int r=6;
while(r!=0)
{
 setfillstyle(SOLID_FILL,14);
 setcolor(14);
  fillellipse(x1[o],y1[o],r,r);
  delay(60);
  setfillstyle(SOLID_FILL,0);
  floodfill(x1[o],y1[o],0);

 r--;
 }
 }
 int st =score;
 int lv=level;
 int lf=life;
 newgame();
 score=st;
 level=lv;
 level++;
 life=lf;
 life+=2;
 if(life>9)
 life=9;
}

else
{
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
      setcolor(4);
	    outtextxy(380,60,"YOU LOSE ");
 delay(100);

 int k=8;
while(k!=0)
{
 setfillstyle(SOLID_FILL,14);
 setcolor(14);
  fillellipse(x,y,k,k);
  delay(20);
  setfillstyle(SOLID_FILL,0);
  floodfill(x,y,0);

 k--;
 }

}

delay(2000);
gotoxy(30,15);
textcolor(2);
puts(" press n for new game");
char d;
d=getch();
if(fl==0 && (life==1 ||d=='n'))
{
//save();
gotoxy(30,19);
cout<<"saved";
delay(2000);
}
closegraph();
if(d==27)
exit(0);
else
start(d);
}
void pacman :: homepage()
 {
		int gd1 = DETECT,gm1;
	initgraph(&gd1, &gm1,"C:\\TURBOC3\\BGI");

	 settextstyle(DEFAULT_FONT, HORIZ_DIR, 10);
      outtextxy(60,90,"PA MAN");
	       setcolor(14);
	       setfillstyle(SOLID_FILL,14);
      pieslice(255,127,45,315,38);


	      settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	 outtextxy(240,200,"Loading ");
	 int g=360;
	 for(int p=0;p<2;p++)
	{
	 fillellipse(g,210,3,3);
	 delay(700);
	 g=g+8;
	 }



closegraph();
homepage1();


}

void pacman :: homepage1()
{ int i;
 _setcursortype(_NOCURSOR);
	 textcolor(15);
	 textbackground(1);
	 gotoxy(30,15);
	 cprintf("enter game");
	 i=1;
	textbackground(0);
	 gotoxy(30,16);
	 cprintf("leaderboard");
	 textbackground(0);
	 gotoxy(30,17);
	 cprintf("exit");

		   char ch;
	while(1)
	 {
	ch=getch();
	   switch(ch)
	  {
		  case 72:  if(i==2)
		  { clrscr();
		   textbackground(1);
	 gotoxy(30,15);
	 cprintf("enter game");
	 i=1;
	 textbackground(0);
	 gotoxy(30,16);
	 cprintf("leaderboard");
	 textbackground(0);
	 gotoxy(30,17);
	 cprintf("exit");
			  }
	 else if(i==3)
	 {
	 clrscr();
		   textbackground(0);
	 gotoxy(30,15);
	 cprintf("enter game");
	 textbackground(1);
	 gotoxy(30,16);
	 cprintf("leaderboard");
	 i=2;
	 textbackground(0);
	 gotoxy(30,17);
	 cprintf("exit");
	  }
	 break;
	  case 80: if(i==1)
	 {clrscr();
	  textbackground(0);
	 gotoxy(30,15);
	 cprintf("enter game");
	 textbackground(1);
	 gotoxy(30,16);
	 cprintf("leaderboard");
	      i=2;
     textbackground(0);
	 gotoxy(30,17);
	 cprintf("exit");

     }
     else if(i==2)
	 {clrscr();
	  textbackground(0);
	 gotoxy(30,15);
	 cprintf("enter game");
	 textbackground(0);
	 gotoxy(30,16);
	 cprintf("leaderboard");
	 textbackground(1);
	 gotoxy(30,17);
	 cprintf("exit");
	 i=3;
	 textbackground(0);
	      }
	 break;
	 case 13:
	 if(i==1)
	 {
		 clrscr();
		 gotoxy(30,15);
		 cout<<"enter name";
		 gotoxy(30,17);
		 gets(name);
		  if(strlen(name)>19)
	   { gotoxy(22,18);
	    cout<<"enter name not more than 20 characters";
	    delay(2000);
	    homepage1();

		  }
		  newgame();
	      start('y');

	 }
    else if(i==2)
	{ textbackground(0);
	leaderboard();
	homepage1();
	}
	else if(i==3)
	{
	exit(0);
break;
	 }
	  }
	     }

}

void pacman :: save()
{
       saver s;
	 strcpy(s.name,name);
	 s.score=score;
	  ofstream fout("a.dat",ios::binary|ios::app);
	  fout.write((char *)&s,(sizeof(name)+sizeof(score)) ) ;
	 fout.close();


}
saver pacman :: highscore()
{
saver s,h1,h;
 ifstream fin("a.dat",ios::binary);
			    int k=0;
  while(!fin.eof())
 {
 fin.read((char *)&s,(sizeof(name)+sizeof(score)));
	       h1=s;

	       if(k==0)
	      { h=h1;
	      k=1;
	      }
	      if(k==1)
	      {
	       if(h1.score>h.score)
	       h=h1;
	      }

 }

 fin.close();
   return h;
}

void pacman :: leaderboard()
{                
	 _setcursortype(_NOCURSOR);
saver a[20];
 clrscr();
 gotoxy(30,1);
 cout<<"LEADERBOARD";
ifstream fin;
  for(int i=0;i<20;i++)
  {
  fin.open("a.dat",ios::binary);
	  saver h,h1,s;
	  h.score=0;
	  h.name[0]='a';
  while(!fin.eof())
 {
 fin.read((char *)&s,(sizeof(name)+sizeof(score)));
	       h1=s;

	      int u=0;
      for(int j=0 ;j<i ;j++)
     {
	       if(h1.score==a[j].score || strcmp(h1.name,a[j].name)==0)
	     {  u=1;
	     break;
	     }
      }
      if(u==0)
     { if(h1.score>=h.score)
      h=h1;
      }
 }
gotoxy(25,i+3);
if( i!=0 && a[i-1].score==h.score && strcmp(a[i-1].name,h.name)==0  || h.name[0]=='a');
else
cout<<i+1<<". "<<h.name<<" - "<<h.score*10;
a[i]=h;
 fin.close();
   }
getch();
clrscr();
}
void main()
    {
    pacman obj;
    obj.homepage();
}