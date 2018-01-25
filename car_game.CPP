#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

void draw_car(int x, int y,int c=0);

int main(void)
{  randomize();
   int gdriver = DETECT, gmode, errorcode;
   void *car[2];
   int x[3], y[3],x1,y1,X,Y;
   unsigned int size;
   initgraph(&gdriver, &gmode, "");
   Y = 65;
   X = 52;
   y1=300;
   x1=52;
   for(int i=0;i<2;i++)
  {
   draw_car(X, Y,i);
   size = imagesize(X-5, Y+4, X+40, Y-63);
   car[i] = malloc(size);
   getimage(X-5, Y+4, X+40, Y-63, car[i]);
   }
   cleardevice();
   y[0]=0;y[1]=130;y[2]=260;
   x[0]=7;x[1]=97;x[2]=7;
   int n=0,flag=0,k=0;
   while(1)
   {    char ch;
     if(flag==1)
     { n=rand()%3;
      if(n==0)
       x[k]=7;
      else if(n==1)
      x[k]=52;
      else
      x[k]=97;}
      flag=0;
      rectangle(0,0,140,441);
      if (kbhit())
	{ ch=getch();
		switch(ch)
		 {
			case 77:
			      if(x1<100)  x1=x1+45; break;
			case 75:
				if(x1>45) x1-=45;  break;
			case 72:
			      if(y1>=70) y1-=30; break;
			case 80:
			      if(y1<=280) y1+=30; break;
			case 'q': exit(1);

		}

	}

	putimage(x1-5, y1, car[1], XOR_PUT);

	putimage(x[0]-5, y[0]+3, car[0], XOR_PUT);
	putimage(x[1]-5, y[1]+3, car[0], XOR_PUT);
	putimage(x[2]-5, y[2]+3, car[0], XOR_PUT);

       if((x1==x[0]&&(y1>=y[0]-67&&y1<=y[0]+67))||(x1==x[1]&&(y1>=y[1]-67&&y1<=y[1]+67))||(x1==x[1]&&(y1>=y[1]-67&&y1<=y[1]+67)))
	 { delay(1000);  exit(0);}
	  y[0] +=10;y[1]+=10;y[2]+=10;
	 for(i=0;i<3;i++)
	 if(y[i]>370)
	 {flag=1;y[i]=0;k=i;}
	 delay(100);
	 cleardevice();
   }
   /* clean up */
   free(car);
   cleardevice();
   closegraph();
   return 0;
}
void draw_car(int x, int y,int c)
{
   moveto(x,y);
   linerel(-2,-10);
   linerel(2,-20);
   linerel(-5,-2);
   linerel(0,-2);
   linerel(5,-5);
   linerel(0,-8);
   moveto(x+35,y);
   linerel(2,-10);
   linerel(-2,-20);
   linerel(5,-2);
   linerel(0,-2);
   linerel(-5,-5);
   linerel(0,-8);
   ellipse(x+18,y-45,0,180,18,15);
   ellipse(x+18,y-11,227,313,25,15);
   moveto(x+8,y-8);
   linerel(-1,-7);
   linerel(20,0);
   linerel(-1,7);
   ellipse(x+17,y-14,210,330,11,12);
    moveto(x+4,y-40);
    linerel(2,11);
    linerel(24,0);
    linerel(2,-11);
     ellipse(x+17,y-30,45,125,21,13);
     if(c==0)
   setfillstyle(SOLID_FILL,getmaxcolor()-11);
   else
    setfillstyle(SOLID_FILL,getmaxcolor()-8);
    floodfill(x+4,y-2,getmaxcolor());
}
