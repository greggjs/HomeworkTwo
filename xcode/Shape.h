//
//  Shape.h
//  HomeworkTwo
//
//  Created by Jake Gregg on 9/18/12.
//
//

#ifndef HomeworkTwo_Shape_h
#define HomeworkTwo_Shape_h

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Vector.h"
#include "cinder/Color.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace ci::gl;
using namespace std;

class Shape {
public:
    Shape();
    Shape(int x, int y, int radius);
	void draw();
    
    int x_;
    int y_;
    int radius_;
    Color8u color_;
    
    int anchor_x_;
    int anchor_y_;
    int bound_;
    Rand random;
    
    Shape* child_;
    
    Shape* findShapeWithPoint(int x, int y);
    void setChild();
    void removeChild();
    void move(int x, int y);
};

#endif
