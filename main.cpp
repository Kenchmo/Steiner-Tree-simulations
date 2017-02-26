//
//  main.cpp
//  steiner tree simulation
//
//  Created by Lufan Zhou on 2/18/17.
//


#include <vector>
#include <iostream>

#include <string>
#include <random>

#include <sstream>
#include <fstream>

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "drawer.h"
#include "points.h"
#include "png.h"

using namespace std;



int main() {
    
    size_t width = 10000;   
    size_t height = 6000;
    
    const int npoints = 20000;  // number of points
    vector<Point *> v;
    // default_random_engine generator;
    // uniform_real_distribution<double> distribution(0.0,1.0);
    srand (time(NULL));
    for (int i=0; i < npoints; ++i){
        
        double x = double(rand() % width) / width;
        double y = double(rand() % height) / height;
        Point * ptr = new Point(x, y, false);
        v.push_back(ptr);
    }
    
    


   PNG output(width, height);
   
   
   for (size_t i = 0; i < width; ++i){
       for (size_t j = 0; j < height; ++j){  //flipping by 180 degrees require that both
           output(i, j)->red = 0;
           output(i, j)->green = 11;
           output(i, j)->blue = 35;
           output(i, j)->alpha = 255;
       }
   }
   int lpx, lpy;
   int px, py;
   for(int i = 0; i < npoints; ++i){
        if(i!=0){
          lpx = px;
          lpy = py;
        }

        px = int(v[i]->x*width);
        py = int(v[i]->y*height);


        setdot(px, py, output);
        //if(i!=0 && i < 7) setline(lpx,lpy,px,py,output);

   }

   output.writeToFile("out.png");


    return 0;
}
