#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"


//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int delta;
  //if endpoint is greater than start point, swap point values
  if (x1<x0){
    int temp=x1;
    x1=x0;
    x0=temp;
    temp=y1;
    y1=y0;
    y0=temp;
  }
  int a=y1-y0;
  int b=-(x1-x0);
  double m;
  if (b==0)
    m=2;
  else
    m=(double)(a*1.0)/(double)(b*-1.0);
	//octant I (and octant V)
  if (m>=0 && m<=1){
    delta=(2*a)+b;
    while(x0<=x1){
      plot(s,c,x0,y0);
      if (delta>0){
	y0+=1;
	delta+=2*b;
      }
      x0+=1;
      delta+=2*a;
    }
  }
  //octant II (and octant VII)
  if (m>1){
    delta=a+(2*b);
    while(y0<=y1){
      plot(s,c,x0,y0);
      if (delta<0){
	x0+=1;
	delta+=2*a;
      }
      y0+=1;
      delta+=2*b;
    }
  }
   //octant VII (and octant III)
  if (m<-1){
    delta=a-(2*b);
    while(y0>=y1){
      plot(s,c,x0,y0);
      if (delta>0){
	x0+=1;
	delta+=2*a;
      }
      y0-=1;
      delta-=2*b;
    }
  }
  //octant VIII (and octant IV)
  if (m<0 && m>= -1){
    delta=2*a-b;
    while(x0<=x1){
      plot(s,c,x0,y0);
      if (delta<0){
	y0-=1;
	delta-=2*b;
      }
      x0+=1;
      delta+=2*a;
    }
  }
 
}

