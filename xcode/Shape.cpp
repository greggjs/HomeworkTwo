#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Vector.h"
#include "cinder/Rand.h"
#include "Shape.h"

using namespace ci;
using namespace ci::app;
using namespace ci::gl;
using namespace std;

Shape::Shape() {
    
}

Shape::Shape(Vec2f mLoc_, Vec2f mDir_, float mRad_) {
    loc_ = mLoc_;
    dir_ = mDir_;
    rad_ = mRad_;
    color_ = Color(1.0f, 1.0f, 1.0f);
}

void Shape::update() {
    rand_red_ = randFloat(0.0f, 1.0f);
    rand_green_ = randFloat(0.0f, 1.0f);
    rand_blue_ = randFloat(0.0f, 1.0f);
}

void Shape::draw() {
    color(color_);
    Rectf rect_(loc_.x, loc_.y, loc_.x+rad_, loc_.y+rad_);
    drawSolidRect(rect_);
}