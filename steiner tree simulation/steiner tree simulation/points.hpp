//
//  points.hpp
//  steiner tree simulation
//
//  Created by Lufan Zhou on 2/20/17.
//

#ifndef points_hpp
#define points_hpp

#include <stdio.h>
#include <string>

using namespace std;


class Point{
public:
    
    float x, y;
    string tag;
    Point(){
        x = 0;
        y = 0;
    };
    Point(float newx, float newy, string newtag){
        x = newx;
        y = newy;
        tag = newtag;
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
        tag = other.tag;
    }


};

#endif /* points_hpp */
