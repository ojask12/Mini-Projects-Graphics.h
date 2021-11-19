#include<iostream.h>
#include<graphics.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
#include<stdio.h>

int l1,l2,l3,w,e;
void input(int chk)
{
if(chk == 0 )
{
outtextxy(20,10,"FOR DEFAULT VALUES ENTER 0");
}
if(chk == 1)
{
outtextxy(20,10,"Invalid Input!FOR DEFAULT VALUES ENTER 0");
}
outtextxy(20,40,"Crank Length:");
scanf("%d",&l2);
outtextxy(20,80,"Coupller Length(more than crank length by 40 atleast):");
scanf("%d",&l3);
outtextxy(20,120,"Angular velocity of crank(0-180) (not to scale):");
scanf("%d",&w);
if((l3==0)||(l2==0))
{
l3=160;
l2=70;
w=150;
}
}

int main()
{
int gd = DETECT,gm;
int k = 100;                  // offset of crank centre from origin
l1=100,l2=70,l3=160,e=0;  //l1=>link1 length ....e=eccentricity
float x1=k+l2,y1=k+l2;
float wd=34,ht=24;            //widht & height of link 4 box
w=150;                        //angular velocity of crank only for demo
initgraph(&gd,&gm,"C:/TURBOC3/BGI");

float x=20.0,y,icr=1.0,chng;    //chng is a temp variable to store x value
int i=-1;

input(0);
while(!(l3>l2+40)&&(w<181))
{
cleardevice();
input(1);
}


for(int ctr = 0;ctr<4;ctr++)    //loop to cover all quadrants
{
x=0;
while(x <= l2)                  //loop to execute crank motion
{
chng=x;
if(x>=l2-8)                     //increment value changed to compensate
{                               //for very fast change in y as x >=63
icr=0.5;
}
if(ctr == 1)  			//continue circular motion in 2nd quad
{
i=1;
x = l2 - x;
}
if(ctr == 2)                    //continue circular motion in 3rd quad
{
i=1;
x=chng*(-1);
}
if(ctr == 3)                    //continue circular motion in 4th quad
{
i=-1;
x = (l2 - x)*(-1);
}
float x3 ,y3 = y1+e;
float x2 = x1+x,y2=y1+y;
y =  sqrt(l2*l2-x*x);
y = y*i;
x3 =  sqrt(l3*l3-pow((y3-y2),2)) + x2;
line(x1,y1,x2,y2);               //draw crank link
line(x2,y2,x3,y3);               //draw coupler link
circle(x2,y2,ht/5);                //circle to show binary linkage
rectangle(x3-wd/2,y3-ht/2,x3+wd/2,y3+ht/2); //link 4 box
rectangle(x3+wd/5,y3-ht/2,x3+wd/3,y3+ht/2); //link 4 piston type look
circle(x1,y1,l2);                //circle to trace crank motion
x=chng;
delay(200-w);
cleardevice();
x=x+icr;
}
}
getch();
closegraph();
/*getch();                              //loop to test circle values
y=0;
float icr=1.0;
float erg = 0;
while(erg <= l2)
{
if(erg>=l2-8)
{
icr = 0.1;
}
y = (int) sqrt(l2*l2-erg*erg);
cout<<"x:"<<erg<<"y:"<<y<<"r:"<<sqrt(erg*erg+y*y)<<"\n";
erg=erg+icr;
}
getch();*/
return 0;
}