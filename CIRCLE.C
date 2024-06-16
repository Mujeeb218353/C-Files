#include<stdio.h>
#include<graphics.h>
int main(){
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\turboc3\\bgi");
cleardevice();
circle(200,200,50);
getch();
closegraph();
return 0;
}