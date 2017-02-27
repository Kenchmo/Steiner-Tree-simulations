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

	triangle_helper(v,vline,prev1,prev2);
	triangle_helper(v,vline,prev1,prev3);
	triangle_helper(v,vline,prev2,prev3);

	return;
}


void triangle_helper(const vector<Point*> & v, vector<pair<int, int>> & vline, int prev1, int prev2){
	int cur = find_nearest(v, prev1, prev2);
	if(cur == -1) return;
	// //avoiding overlap triangles
	// double testdist1 = dist(v,cur,prev1) + dist(v,cur,back);
	// double testdist2 = dist(v,cur,prev2) + dist(v,cur,back);
	// double thisdist = dist(v,cur,prev1) + dist(v,cur,prev2);
	// if(thisdist > testdist1 || thisdist > testdist2) return;

	//avoid overlap lines
	int len = vline.size();
	for(int i = 0; i < len; ++i){
		if(check_overlap(v, vline[i].first, vline[i].second, cur, prev1) ||
			check_overlap(v, vline[i].first, vline[i].second, cur, prev2)){

			//cout<<"overlap\n";
			return;
		}

	}
	vline.push_back({cur, prev1});
	vline.push_back({cur, prev2});
	v[cur]->connect();
	triangle_helper(v, vline, cur, prev1);
	triangle_helper(v, vline, cur, prev2);
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
		//radius = dist(v, i , first) + dist(v, i, second);
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





//reference: http://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/

//check if q is on segment pr
bool on_segment(const vector<Point*> & v, int p, int q, int r){
	double px = v[p]->x, py = v[p]->y;
	double qx = v[q]->x, qy = v[q]->y;
	double rx = v[r]->x, ry = v[r]->y;
    if (qx <= max(px, rx) && qx >= min(px, rx) &&
        qy <= max(py, ry) && qy >= min(py, ry))
       return true;
 
    return false;
}
 
// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(const vector<Point*> & v, int p, int q, int r){
	double px = v[p]->x, py = v[p]->y;
	double qx = v[q]->x, qy = v[q]->y;
	double rx = v[r]->x, ry = v[r]->y;

    double val = (qy - py) * (rx - qx) -
              (qx - px) * (ry - qy);
    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

 
//The main function that returns true if line segment 'p1q1'
//and 'p2q2' intersect.
bool check_overlap(const vector<Point*> & v, int p1, int q1, int p2, int q2){

	if(p1 == p2 || p1 == q2 || q1 == p2 || q1 == q2) return false;



    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(v, p1, q1, p2);
    int o2 = orientation(v, p1, q1, q2);
    int o3 = orientation(v, p2, q2, p1);
    int o4 = orientation(v, p2, q2, q1);
    // General case
    if (o1 != o2 && o3 != o4)
        return true;
    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && on_segment(v, p1, p2, q1)) return true;
    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && on_segment(v, p1, q2, q1)) return true;
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && on_segment(v, p2, p1, q2)) return true;
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && on_segment(v, p2, q1, q2)) return true;
    return false; // Doesn't fall in any of the above cases
}