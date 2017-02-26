//
//  points.cpp
//  steiner tree simulation
//
//

#include "points.h"
#include <math.h>


void construct_polygon(const vector<Point*> & v, vector<pair<int, int>> & vline){
	int len  = v.size();
	int visited = 0;
	while(visited != len){
		for(int i = 0 ; i < len; i++)
		vector<Point*> polygon;


	}
}


void construct_triangle(const vector<Point*> & v, vector<pair<int, int>> & vline){
	int len = v.size();
	int prev = 0;
	int cur = find_nearest(v, 0);
	int next;
	vline.push_back({prev, cur});
	v[prev]->connect();
	v[cur]->connect();
	
	int connected = 2;
	while(connected != len){
		next = find_nearest(v, prev, cur);
		vline.push_back({cur, next});
		vline.push_back({prev, next});
		prev = cur;
		cur = next;
		connected++;
	}

	return;
}

// find nearest point for one point
int find_nearest(const vector<Point*> & pts, int origin){
	int len = pts.size();
	double min = 2;
	int index = 0;
	double distance;
	for(int i = 0; i < len; i++){
		distance = dist(pts, origin, i);
		if(distance < min && i != origin && !pts[i]->connected){
			index = i;
			min = distance;
		}
	}
	pts[index]->connect();
	return index;
}



//find nearest point for two points
int find_nearest(const vector<Point*> pts, int first, int second){
	int len = pts.size();
	double min = 2;
	int index = 0;
	double distance;
	for(int i = 0; i < len; i++){
		distance = dist(pts, first, i)+dist(pts, second, i);
		if(distance < min && i != first && i != second && !pts[i]->connected){
			index = i;
			min = distance;
		}
	}
	pts[index]->connect();
	return index;
}

double dist(const vector<Point*> & pts, int first, int second){
	return sqrt(pow(pts[first]->x - pts[second]->x,2) + pow(pts[first]->y - pts[second]->y,2));
}