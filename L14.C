#include<stdio.h>
#include<graphics.h>
#include<math.h>
void main()
{   long d1,d2;
    int i,gd=DETECT,gm,x,y,x0,y0;
    long rx,ry,rxsq,rysq,tworxsq,tworysq,dx,dy;
    clrscr();
    
    printf("Enter rx and ry:");
    scanf("%ld%ld",&rx,&ry);
    printf("\nEnter the xc and yc:\n");
    scanf("%d%d",&x0,&y0);
    
    initgraph(&gd,&gm,"c:\\TC\\BGI");

    rxsq=rx*rx;
    rysq=ry*ry;
    tworxsq=2*rxsq;
    tworysq=2*rysq;

    x=0; y=ry;
    d1=rysq-rxsq*ry+(0.25*rxsq);
    dx=tworysq*x;
    dy=tworxsq*y;
    
    do{
        putpixel(x0+x,y0+y,15);
        putpixel(x0-x,y0-y,15);
        putpixel(x0+x,y0-y,15);
        putpixel(x0-x,y0+y,15);
        
        if(d1<0)
        {   x=x+1; y=y;
            dx=dx+tworysq;
            d1=d1+dx+rysq;
        }
        else
        {   x=x+1; y=y-1;
            dx=dx+tworysq;
            dy=dy-tworxsq;
            d1=d1+dx-dy+rysq;
        }
    }while(dx<dy);
    d2=rysq*(x+0.5)*(x+0.5)+rxsq*(y-1)*(y-1)-(rxsq*rysq);
    do{
        putpixel(x0+x,y0+y,15);
        putpixel(x0-x,y0-y,15);
        putpixel(x0+x,y0-y,15); 
        putpixel(x0-x,y0+y,15);
        
        if(d2>0)
        {   x=x; y=y-1;
            dy=dy-tworxsq;
            d2=d2-dy+rxsq;
        }
        else
        {   x=x+1;y=y-1;
            dx=dx+tworysq;
            dy=dy-tworxsq;
            d2=d2+dx-dy+rxsq;
        }
    }while(y>0);
    getch();
    closegraph();
}