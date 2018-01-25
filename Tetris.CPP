#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
int a[20][24];
class shape
{   public:
      void sq(int a,int b,int c=0)
	{    if(c==1)
	    setcolor(0);
	    else
	    setcolor(GREEN);
		rectangle(a-15,b-15,a-1,b-1);
		rectangle(a+1,b-15,a+15,b-1);
		rectangle(a-15,b+1,a-1,b+15);
		rectangle(a+1,b+1,a+15,b+15);
	}
	void l(int a,int b,int c=0,int d=0)
	{  if(d==1)
	    setcolor(0);
	    else
	    setcolor(MAGENTA);
	  if(c==0)
		rectangle(a-15,b+1,a-1,b+15);
	  else if(c==1)
		rectangle(a-15,b-31,a-1,b-17);
	  else if(c==2)
		rectangle(a+1,b-31,a+15,b-17);
	  else
		rectangle(a+1,b+1,a+15,b+15);
	    if(c==0||c==1)
	    {
		rectangle(a+1,b-31,a+15,b-17);
		rectangle(a+1,b-15,a+15,b-1);
		rectangle(a+1,b+1,a+15,b+15);
	    }
	    if(c==2||c==3)
	    {   rectangle(a-15,b-15,a-1,b-1);
		rectangle(a-15,b+1,a-1,b+15);
		rectangle(a-15,b-31,a-1,b-17);
	    }
	}
	void st(int a,int b,int c=0,int d=0)
	{
	  if(d==1)
	  setcolor(0);
	  else
	  setcolor(RED);
	  if(c==0)
	  {
		rectangle(a+1,b-31,a+15,b-17);
		rectangle(a+1,b-15,a+15,b-1);
		rectangle(a+1,b+1,a+15,b+15);
		rectangle(a+1,b+17,a+15,b+31);
	  }
	  else
	  {
		rectangle(a+1,b-15,a+15,b-1);
		rectangle(a+17,b-15,a+31,b-1);
		rectangle(a-15,b-15,a-1,b-1);
		rectangle(a-31,b-15,a-17,b-1);
	  }
	}
}s;
void assign(int x,int y,int n,int n1)
{
	int r,i,j;
	for(i=3;i<=16;i++)
	    if(x==(16*i)-1)
	       for(j=25;j>=2;j--)
		   if(y==(16*j)-1)
		    {
		       if(n==0)
		       {	a[i-2][j-2]=1;
				a[i-3][j-2]=1;
				a[i-2][j-3]=1;
				a[i-3][j-3]=1;
		       }
		      if(n==1)
		      {
				if(n1==0||n1==1)
				{
				  if(n1==0)
				    a[i-3][j-2]=1;
				  else
				    a[i-3][j-4]=1;
				  a[i-2][j-2]=1;
				  a[i-2][j-3]=1;
				  a[i-2][j-4]=1;
				 }
				 else
				 {
				   if(n1==2)
				     a[i-2][j-4]=1;
				    else
				      a[i-2][j-2]=1;
				    a[i-3][j-2]=1;
				    a[i-3][j-3]=1;
				    a[i-3][j-4]=1;
				   }
			 }
			 if(n==2)
			 {
				   if(n1==0)
				   { a[i-2][j-1]=1;
				     a[i-2][j-2]=1;
				     a[i-2][j-3]=1;
				     a[i-2][j-4]=1;
				   }
				   else
				   { a[i-2][j-3]=1;
				     a[i-1][j-3]=1;
				     a[i-3][j-3]=1;
				     a[i-4][j-3]=1;
				   }
			  }
		  }
}
void checkend()
{
  for(int i=0;i<20;i++)
   if(a[i][0]==1)
   { setcolor(RED);
     outtextxy(190,160," GAME OVER!!!");
     delay(2000);
     cleardevice();
     exit(0);
   }
}
void checkrow()
{
	int i,j,flag=0,k[4],k1=0,x;
	for(i=0;i<20;i++)
	{    flag=0;
	  for(j=0;j<24;j++)
	  {
	     if(a[i][j]==1)
	      flag++;
	  }
	  if(flag==24)
	   {   k[k1++]=j;
	    printf("%d",j);  }
	 }
       for(x=0;x<k1;x++)
	{
	 for(j=k[x]-1;j>=0;j--)
	 {
	   for(i=0;i<20;i++)
	   {
	     if(a[i][j]==1)
	     { a[i][j+1]=1;
	       a[i][j]=0;
	     }
	   }
	 }
	 for(j=k[x];j>=0;j--)
	 {
	   for(i=0;i<20;i++)
	   {
	    if(a[i][j]==1)
	      rectangle(16*i+32,16*j+32,16*i+46,16*j+46);
	   }
	 }
      }
}
int main(void)
{
	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, "");
	printf("press q to quit");
	rectangle(30,30,352,416);
	randomize();
	int n,n1,i,x,y,k=0,xx=0,yy=0,flag=0,ch=0;
	char c;
	while(k++<25)
	{       flag=0;
		x=191;
		n1=0;
		n=rand()%3;
		if(n==1)
		  n1=rand()%4;
		if(n==2)
		  n1=rand()%2;
		if((n1==1&&n==2)||(n==0))
		   y=47;
		else
		   y=63;
	    for(i=0;;i+=16)
	    {    fflush(stdin);
		if(kbhit())
		 { c=getch();
		   ch=1;
		   if(c==75||c==77)
		    if(i>0)
		    i-=16;
		 }

		else
		  c=80;
		xx=((x+1)/16)-2;
		yy=((y+i+1)/16)-2;
		switch(c)
		{
		      case 72:
			if(n==1)
			   n1=(++n1)%4;
			if(n==2)
			   n1=(++n1)%2;
			 break;
		      case 77:
			 if(n==2&&n1==1)
			 { if(((y+i)<415)&&(x+16<=319)&&a[xx+2][yy-1]==0)
				 x+=16;}
			 if(n==0)
			 {  if(((y+i)<399)&&(x+16<=335)&&a[xx+1][yy]==0&&a[xx+1][yy-1]==0)
				      x+=16; }
			 if(n==2&&n1==0)
			 {  if(((y+i)<383)&&(x+16<=335)&&a[xx+1][yy+1]==0&&a[xx+1][yy]==0&&a[xx+1][yy-1]==0&&a[xx+1][yy-2]==0)
				      x+=16; }
			if(n==1)
			{  if(n1==0||n1==1)
			     { if(((y+i)<399)&&(x+16<=335)&&a[xx+1][yy]==0&&a[xx+1][yy-1]==0&&a[xx+1][yy-2]==0)
				      x+=16; }
			   else if(n1==2)
			     { if(((y+i)<399)&&(x+16<=335)&&a[xx+1][yy]==0&&a[xx+1][yy-1]==0&&a[xx+2][yy-2]==0)
				      x+=16; }
			   else if(n1==3)
			     { if(((y+i)<399)&&(x+16<=335)&&a[xx+2][yy]==0&&a[xx+1][yy-1]==0&&a[xx+1][yy-2]==0)
				      x+=16; }
			 }
			break;
		     case 75:
			 if(n==2&&n1==1)
			   { if(((y+i)<415)&&(x-16>=63)&&a[xx-3][yy-1]==0)
				 x-=16;}
			 if(n==0)
			   {  if(((y+i)<399)&&(x-16>=47)&&a[xx-2][yy]==0&&a[xx-2][yy-1]==0)
				      x-=16; }
			 if(n==2&&n1==0)
			   {  if(((y+i)<383)&&(x-16>=31)&&a[xx-1][yy+1]==0&&a[xx-1][yy]==0&&a[xx-1][yy-1]==0&&a[xx-1][yy-2]==0)
				      x-=16; }
			 if(n==1)
			    {  if(n1==0)
				    { if(((y+i)<399)&&(x-16>=47)&&a[xx-2][yy]==0&&a[xx-1][yy-1]==0&&a[xx-1][yy-2]==0)
				      x-=16; }
			       else if(n1==1)
				    { if(((y+i)<399)&&(x-16>=47)&&a[xx-1][yy]==0&&a[xx-1][yy-1]==0&&a[xx-2][yy-2]==0)
				      x-=16; }
			       else if(n1==2||n1==3)
				    { if(((y+i)<399)&&(x-16>=47)&&a[xx-2][yy]==0&&a[xx-2][yy-1]==0&&a[xx-2][yy-2]==0)
				      x-=16; }
			     }
			     break;

			  case 'q':
			  case 'Q':cleardevice(); exit(0);
		  }

		  if(n==2&&n1==1)
		  { if(((y+i)<415)&&(a[xx+1][yy]==0)&&(a[xx][yy]==0)&&(a[xx-1][yy]==0)&&(a[xx-2][yy]==0))
		       {}
		      else
			{assign(x,y+i,n,n1); flag=1;}
		  }
		if(n==0||(n==1&&(n1==0||n1==3)))
		   {  if(((y+i)<399)&&(a[xx-1][yy+1]==0)&&(a[xx][yy+1]==0))
		      {}
		      else
		      {assign(x,y+i,n,n1); flag=1;}
		   }
		if(n==2&&n1==0)
		  {  if(((y+i)<383)&&(a[xx][yy+2]==0))
			{}
			else
			{assign(x,y+i,n,n1); flag=1; }
		  }
		if(n==1&&n1==1)
		   {  if(((y+i)<399)&&(a[xx][yy+1]==0)&&(a[xx-1][yy-1]==0))
			{}
			else
			{ assign(x,y+i,n,n1); flag=1;}
		      }
		  if(n==1&&n1==2)
		    {  if(((y+i)<399)&&(a[xx-1][yy+1]==0)&&(a[xx][yy-1]==0))
			{}
			else
			{assign(x,y+i,n,n1);flag=1; }
		   }
		   if(n==0)
			s.sq(x,y+i);
		      else if(n==1)
			s.l(x,y+i,n1);
		      else
			s.st(x,y+i,n1);

		   if(ch==0)
		     delay(300);
		   else
		    { delay(100); ch=0; }
		   checkend();
	       //  checkrow();
		  if(flag==0)
		   {
		     if(n==0)
			s.sq(x,y+i,1);
		      else if(n==1)
			s.l(x,y+i,n1,1);
		      else
			s.st(x,y+i,n1,1);
		    }
		  else
		   break;
	    }
	}
	getch();
	cleardevice();
	closegraph();
	return 0;
}
