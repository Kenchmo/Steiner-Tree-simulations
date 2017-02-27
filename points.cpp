//
//  points.cpp
//  steiner tree simulation
//
//

#include "points.h"
#include <math.h>


// void construct_polygon(const vector<Point*> & v, vector<pair<int, int>> & vline){
// 	int len  = v.size();
// 	int visited = 0;
// 	while(visited != len){
// 		for(int i = 0 ; i < len; i++)
// 		vector<Point*> polygon;
		

// 	}
// }



void construct_triangle(const vector<Point*> & v, vector<pair<int, int>> & vline){

	int prev1 = 0;
	int prev2 = find_nearest(v, prev1);
	int prev3 = find_nearest(v, prev2, prev1);
	vline.push_back({prev1, prev2});
	vline.push_back({prev2, prev3});
	vline.push_back({prev1, prev3});
	v[prev1]->connect();
	v[prev2]->connect();
	v[prev3]->connect();

	triangle_helper(v,vline,prev1,prev2, prev3);
	triangle_helper(v,vline,prev1,prev3, prev2);
	triangle_helper(v,vline,prev2,prev3, prev1);

	return;
}


void triangle_helper(const vector<Point*> & v, vector<pair<int, int>> & vline, int prev1, int prev2, int back){
	int cur = find_nearest(v, prev1, prev2);
	if(cur == -1) return;
	double testdist1 = dist(v,cur,prev1) + dist(v,cur,back);
	double testdist2 = dist(v,cur,prev2) + dist(v,cur,back);
	double thisdist = dist(v,cur,prev1) + dist(v,cur,prev2);
	if(thisdist > testdist1 || thisdist > testdist2) return;

	vline.push_back({cur, prev1});
	vline.push_back({cur, prev2});
	v[cur]->connect();
	triangle_helper(v, vline, cur, prev1, prev2);
	triangle_helper(v, vline, cur, prev2, prev1);
	return;
}

// find nearest point for one point
int find_nearest(const vector<Point*> & v, int origin){
	int len = v.size();
	double min = 2;
	int index = 0;
	double radius;
	for(int i = 0; i < len; i++){
		radius = dist(v, origin, i);
		if(radius < min && i != origin && !v[i]->connected){
			index = i;
			min = radius;
		}
	}
	v[index]->connect();
	return index;
}



//find nearest point for two points
int find_nearest(const vector<Point*> v, int first, int second){

	int len = v.size();
	double min = 2;
	int index = -1;
	double radius;
	for(int i = 0; i < len; i++){
		radius = rad(v, i, first, second);
		if(radius < min && i != first && i != second && !v[i]->connected){
			index = i;
			min = radius;
		}
	}
	if(index != -1) v[index]->connect();
	return index;
}

//the square of radius of the circle formed by the three points
double rad(const vector<Point*> & v, int i, int j, int k){
	double x1 = v[i]->x, y1 = v[i]->y;
	double x2 = v[j]->x, y2 = v[j]->y;
	double x3 = v[k]->x, y3 = v[k]->y;

    double mr = (double)((y2 - y1) / (x2 - x1));
    double mt = (double)((y3 - y2) / (x3 - x2));

    double xc = (double)((mr * mt * (y3 - y1) + mr * (x2 + x3) - mt * (x1 + x2)) / (2 * (mr - mt)));

    double yc = (double)((-1 / mr) * (xc - (x1 + x2) / 2) + (y1 + y2) / 2);
    double d = (xc - x1) * (xc - x1) + (yc - y1) * (yc - y1);

    return d;

}

double dist(const vector<Point*> & v, int first, int second){
	return sqrt(pow(v[first]->x - v[second]->x,2) + pow(v[first]->y - v[second]->y,2));
}