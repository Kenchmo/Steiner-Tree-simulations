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

#include <stdlib.h>   
#include <time.h> 

#include "drawer.h"
#include "points.h"
#include "png.h"

using namespace std;



int main() {
    
    size_t width = 5000;   
    size_t height = 5000;
    
    const int npoints = 5000;  // number of points
    vector<Point *> v;
    vector<pair<int, int>> vline;
    // default_random_engine generator;
    // uniform_real_distribution<double> distribution(0.0,1.0);
    srand (time(NULL));
    for (int i=0; i < npoints; ++i){
        
        double x = double(rand() % width) / width;
        double y = double(rand() % height) / height;
        Point * ptr = new Point(x, y, false, false);
        v.push_back(ptr);
    }

    construct_triangle(v, vline);


    PNG output(width, height);
    for (size_t i = 0; i < width; ++i){
        for (size_t j = 0; j < height; ++j){  
            output(i, j)->red = 0;
            output(i, j)->green = 11;
            output(i, j)->blue = 35;
            output(i, j)->alpha = 255;
        }
    }

    setline(v, vline, output);

    int px, py;
    for(int i = 0; i < npoints; ++i){
      px = int(v[i]->x*width);
      py = int(v[i]->y*height);
      setdot(px, py, output);
    }

   output.writeToFile("out.png");


    return 0;
}
