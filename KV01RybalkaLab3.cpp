#include "graphics.h" // включить описание графических функций С/С++ Borland'a
#include <math.h>
#include <iostream>
#include <stdio.h>
int WIDTH, HEIGHT;
void drawLine(int moveToX, int moveToY, int drawX, int drawY, int color, int textX, int textY, char *name)
{
    moveto(moveToX, moveToY);
    setcolor(color);
    lineto(drawX, drawY);
    outtextxy(textX, textY, name);
}
//using namespace std;

int main()
{
double x, y;
int N=1; //переменная для изменения разметки
printf("to change the interval of calculated values on the axes enter a variable\n");
for(;N>0;)
{
    int a;
    printf("scaling(enter 0 if you want to end the program): ");
    scanf("%d", &N);
    if(N<=0)
    {
        break;
    }
    printf("width: ");scanf("%4d", &WIDTH);
    printf("height: ");scanf("%4d", &HEIGHT);
    printf("a: "); scanf("%d", &a);
    initwindow(WIDTH, HEIGHT);
    char dop[10];
    char dop1[10];
    drawLine(WIDTH/2,0,WIDTH/2, HEIGHT, WHITE, WIDTH/2+10, 0, "   Y");
    drawLine(0,HEIGHT/2,WIDTH, HEIGHT/2, WHITE, WIDTH-20,HEIGHT/2+10, "\n\nX");

    for(int i=0, j=0, h=0;h<=2*a;i=i+2)
    {
        sprintf(dop, "%d", h);sprintf(dop1, "-%d", h);
        outtextxy(WIDTH/2+5, HEIGHT/2+5+j, dop);outtextxy(WIDTH/2+5, HEIGHT/2+5-j, dop1);
        outtextxy(WIDTH/2+5-j, HEIGHT/2+5, dop);outtextxy(WIDTH/2+5+j, HEIGHT/2+5, dop1);
        j=j-N*21.5;
        h=h+N;
    }
    outtextxy(WIDTH-WIDTH/2.4, HEIGHT-HEIGHT/4, "y=a*cosh(x/a) Created by Rybalka V. S.");
    moveto(WIDTH/2+20*(-2*a), HEIGHT/2-20*a*cosh(-2*a/a));
    setcolor(YELLOW);
    int i1;
    printf("\tx\ty\n");
    for(x=-2*a, i1=0;x<=2*a;x+=0.01, i1++)
    {
        y=a*cosh(x/a);
        lineto(WIDTH/2+20*x, HEIGHT/2-20*y); //рисует функцию по точкам
        if(i1==0 || i1%100==0)
        {
            printf("\t%3.2f\t%3.2f\n", x,y); //аналіз значень
        }
    }
    char dop2[40];
    sprintf(dop2, "x is in the range of[-%d, %d]", 2*a, 2*a);
    outtextxy(WIDTH-WIDTH/2.4, HEIGHT-HEIGHT/3, dop2);
    getch();
    closegraph();
}
return 0;
}
