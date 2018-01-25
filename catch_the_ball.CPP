#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
void f(int ,int,int);
class b
{    public:
	basket(int x,int n,int k=0,int m=0)
	{     int y;
	   if(k==0)
	   {
	      if(n==1) y=270;
	      if(n==2) y=165;
	      if(n==3) y=60;
	   }
	   else y=n;
	   if(m==1) setcolor(0);
		 moveto(x,y);
		 linerel(0,30);
		 linerel(30,0);
		 linerel(0,-30);
		 setcolor(WHITE);
	}
	void cir(int x,int y,int d)
	{  if(d==0)
	     setcolor(BLACK);
	   else
	     setcolor(RED);
	   circle(x,y,9);
	   setcolor(WHITE);
	}
};
void main()
{
	clrscr();
	randomize();
	int gdriver = DETECT, gmode;
	int flag=0,flag1=0,flag2=0,j,x,n=0,t,t1;
	initgraph(&gdriver, &gmode, "");
	b b;
	t=(rand()%298)+30;
	t1=(rand()%298)+30;
       for(x=35;n<3;)
	{
		if(flag2==1)
		{
		   t1=(rand()%298)+30;
		   flag2=0;
		}
		 setcolor(WHITE);
		 rectangle(30,30,360,360);
		 b.basket(t1,3);
		 b.basket(t,2);
		 b.basket(x,1);
		 b.cir(x+15,289,1);
		 if(kbhit())
		 {  int kk=0;
		    char aa=getch();
		    outtextxy(getmaxx()/2,getmaxy()/2," ");
		    for(j=289;j<290;)
		    {
			b.cir(x+15,j,1);
			b.basket(t,2);
			delay(10);
			if(((x+15)<(t+30)&&(x+15)>t)&&j==184)
			{
			  if(kk++==1)
			  {
			   delay(1000);
			   n++;
			   flag2=1;
			   f(x,t,t1);
			   x=t;
			   t=t1;
			   break;
			   }
			 }
			b.cir(x+15,j,0);
			if(j==150)
			 flag1=1;
			flag1==0?j--:j++;
		    }
		    flag1=0;
		 }
		 if(x==330)
		  flag=1;
		 if(x==30)
		  flag=0;
		  delay(9);
		  b.basket(x,1,0,1);
		  b.cir(x+15,289,0);
		 flag==0?x++:x--;
	}
	getch();
	cleardevice();
	closegraph();
}
void f(int x,int t,int t1)
{       int i;
	b b;
	for(i=0;i<105;i++)
	{        rectangle(30,30,360,360);
		 if((270+i)<330)
		 {   b.basket(x,270+i,1); }
		  b.basket(t1,60+i,1);
		  b.basket(t,165+i,1);
		  b.cir(t+15,184+i,1);
		  delay(20);
		 cleardevice();
	    }
}