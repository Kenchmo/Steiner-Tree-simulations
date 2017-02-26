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
#include <iostream>


using namespace std;


class Point{
public:

    Point(){
        x = 0;
        y = 0;
        intermediate = false;
        connected = false;
    };
    Point(float newx, float newy, bool interm, bool conn){
        x = newx;
        y = newy;
        intermediate = interm;
        connected = conn;
    };
    ~Point(){};
    Point & operator=(const Point & other){
        if(this == &other) return *this;
        clear();
        copy(other);
        return *this;
    };
    void connect(){
        connected = true;
    };
    void clear(){
    
    };

    void copy(const Point & other){
        x = other.x;
        y = other.y;
        
    }
    
    float x, y;
    bool intermediate;
    bool connected;
    vector<Point*> neighbors;
    

};

void construct_polygon(const vector<Point*> & v, vector<pair<int, int>> & vline);
void construct_triangle(const vector<Point*> & v, vector<pair<int, int>> & vline);
// find nearest point for one point
int find_nearest(const vector<Point*> & pts, int origin);
//find nearest point for two points
int find_nearest(const vector<Point*> pts, int first, int second);

double dist(const vector<Point*> & pts, int first, int second);

#endif /* points_h */
