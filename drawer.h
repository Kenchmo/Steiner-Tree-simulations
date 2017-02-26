//
//  drawer.h
//  steiner tree simulation
//
//  Created by Enkhjargalyn Nyam-Ochir on 2/24/17.
//  Copyright © 2017 Lufan Zhou. All rights reserved.
//

#ifndef drawer_h
#define drawer_h

#include "png.h"
#include "points.h"


void setdot(int x, int y, PNG & canvas);

void setline(int x1, int y1, int x2, int y2, PNG & canvas);

void setpixel(int x, int y, PNG & canvas, int r, int g, int b);

#endif /* drawer_h */
