//
//  points.hpp
//  steiner tree simulation
//
//  Created by Lufan Zhou on 2/20/17.
//

#ifndef points_h
#define points_h

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;


class Point{
public:

    Point(){
        x = 0;
        y = 0;
    };
    Point(float newx, float newy, bool interm){
        x = newx;
        y = newy;
        intermediate = interm;
    };
    ~Point(){};
    Point & operator=(const Point & other){
        if(this == &other) return *this;
        clear();
        copy(other);
        return *this;
    };
    
    void clear(){
    
    };

    void copy(const Point & other){
        x = other.x;
        y = other.y;
        
    }
    
    
    
    float x, y;
    bool intermediate;
    vector<Point*> neighbors;
    

};

#endif /* points_h */
