//
//  drawer.h
//  steiner tree simulation
//
//  Created by Enkhjargalyn Nyam-Ochir on 2/24/17.
//  Copyright © 2017 Lufan Zhou. All rights reserved.
//

#include "drawer.h"

void setdot(int x, int y, PNG & canvas){
    int width = canvas.width();
    int height = canvas.height();
    int left = x-2;
    int right = x+2;
    int up = y-2;
    int down = y+2;


    if(left < 0)left = 0;
    if(right >= width) right = width-1;
    if(up < 0) up = 0;
    if(down >= height) down = height-1;
    for(int i = left; i <= right; ++i){
        for(int j = up; j <= down; ++j){
            canvas(i,j)->red = 252;
            canvas(i,j)->green = 203;
            canvas(i,j)->blue = 27;
        }
    }

    setpixel(x,y, canvas, 225,225,225);
    if(x-3 >= 0) setpixel(x-3,y, canvas, 252,203,27);
    if(x+3 < width) setpixel(x+3,y, canvas, 252,203,27);
    if(y-3 >= 0) setpixel(x,y-3, canvas, 252,203,27);
    if(y+3 < height) setpixel(x,y+3, canvas, 252,203,27);

}



void setline(const vector<Point*> & v, const vector<pair<int, int>> & vline, PNG & canvas){
    int len = vline.size();
    int width = canvas.width();
    int height = canvas.height();
    for(int i = 0; i < len; i++){
        Point* origin = v[vline[i].first];
        Point* dest = v[vline[i].second];


        setline(int(origin->x * width), int(origin->y * height), int(dest->x * width), int(dest->y * height), canvas);
    }
}



void setline(int x1, int y1, int x2, int y2, PNG & canvas){

    if(x1 > x2){
        int temp = x1;
        x1 = x2;
        x2 = temp;

        temp = y1;
        y1 = y2;
        y2 = temp;
    }
    if(x1 != x2){
        float k = float(y2-y1)/(x2-x1);
        float c = y1 - x1 * k;


        for(int i = x1; i <= x2; ++i){
            int j = k * i + c;
            setpixel(i, j, canvas, 97, 130, 183);    
        }
    }


    if(y1 > y2){
        int temp = x1;
        x1 = x2;
        x2 = temp;

        temp = y1;
        y1 = y2;
        y2 = temp;
    }
    if(y1 != y2){
        float ky = float(x2-x1)/(y2-y1);
        float cy = x1 - y1*ky;
        for(int i = y1; i <= y2; ++i){
            int j = ky*i+ cy;
            setpixel(j, i, canvas, 97, 130, 183);
        }
    }
}


void setpixel(int x, int y, PNG & canvas, int r, int g, int b){

    canvas(x,y)->red = r;
    canvas(x,y)->green = g;
    canvas(x,y)->blue = b;

}
