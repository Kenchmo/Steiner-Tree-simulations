//
//  intermediate_points.hpp
//  steiner tree simulation
//
//  Created by Enkhjargalyn Nyam-Ochir on 2/24/17.
//  Copyright © 2017 Lufan Zhou. All rights reserved.
//

#ifndef intermediate_points_hpp
#define intermediate_points_hpp

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class InterPoints{
    
    float x, y;
    string tag;
    vector<string> ptag; // points this intermediate point connects to
    InterPoints(){
        x = 0;
        y = 0;
    };
    InterPoints(float newx, float newy, string newtag){
        x = newx;
        y = newy;
        tag = newtag;
    };
    ~InterPoints(){};
    InterPoints & operator=(const InterPoints & other){
        if(this == &other) return *this;
        clear();
        copy(other);
        return *this;
    };
    
    void clear(){
    
    }
    
    void copy(const InterPoints & other){
        x = other.x;
        y = other.y;
        tag = other.tag;
    }


};
#endif /* intermediate_points_hpp */
