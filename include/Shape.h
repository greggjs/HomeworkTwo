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
    Shape(Vec2f mLoc_, Vec2f mDir_, float mRad_);
	void update();
	void draw();
    
private:
    Vec2f loc_;
    Vec2f dir_;
    float rad_;
    Color color_;
    float rand_red_;
    float rand_green_;
    float rand_blue_;
};

#endif
