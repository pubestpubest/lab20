#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *r1,Rect *r2){
	bool xOverlap;
	bool yOverlap;
	double x=0,y=0;
	if((*r1).x<(*r2).x){
		xOverlap=((*r1).x+(*r1).w)>((*r2).x);
	}else{
		xOverlap=((*r2).x+(*r2).w)>((*r1).x);
	}
	if((*r1).y<(*r2).y){
		yOverlap=((*r1).y+(*r1).h)>((*r2).y);
	}else{
		yOverlap=((*r2).y+(*r2).h)>((*r1).y);
	}
	if(xOverlap&&yOverlap){
		x=abs(max((*r1).x,(*r2).x)-min((*r1).x+(*r1).w,(*r2).x+(*r2).w));
		y=abs(min((*r1).y,(*r2).y)-max((*r1).y-(*r1).h,(*r2).y-(*r2).h));
		return x*y;
	}else	return 0;
}