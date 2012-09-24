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

Shape::Shape(int x, int y, float radius) {
    this->x_ = x;
    this->y_ = y;
    this->child_ = NULL;
    this->anchor_x_ = x;
    this->anchor_y_ = y;
    this->bound_ = 0;
    
    if (radius_ > 100)
        this->radius_ = 100;
    else
        this->radius_ = radius;
    
    Rand random;
    random.seed(x);
    this->color_ = Color8u(random.nextInt(0, 256),
        random.nextInt(0, 256), random.nextInt(0, 256));
    
}

void Shape::setChild() {
    this->child_ = new Shape(this->x_, this->y_, (this-> radius_)/2);
    this->child_->bound_ = abs(this->radius_ - this->child_->radius_);
}

void Shape::removeChild() {
    delete this->child_;
}

Shape* Shape::findShapeWithPoint(int x, int y) {
    int radius = this->radius_;
    
    if ((x >= x_-radius) && (x <= x_ + radius) &&
        (y >= y - radius) && (y <= y_ + radius)) {
        if (this->child_ != NULL) {
            Shape* active = this->child_->findShapeWithPoint(x, y);
            if (active != NULL)
                return active;
            else
                return this;
            
        }
        else
            return this;
    }
    else
        return NULL;
}

void Shape::move(int x, int y) {
    if (this->bound_ != 0) {
        if(this->bound_ != 0){
            if((x < this->anchor_x_ + this->bound_ && x > this->anchor_x_ - this->bound_)
               && (y < this->anchor_y_ + this->bound_ && y > this->anchor_y_ - this->bound_)){
                this->x_ = x;
                this->y_ = y;
            }
        }
        else{
            this->x_ = x;
            this->y_ = y;
        }
        
        if(this->child_ != NULL){
            int offset_x = this->child_->x_ - this->child_->anchor_x_;
            int offset_y = this->child_->y_ - this->child_->anchor_y_;
            
            this->child_->anchor_x_ = x;
            this->child_->anchor_y_ = y;
            this->child_->bound_ = 0; 
            
            this->child_->move(x + offset_x, y + offset_y);
            this->child_->bound_ = abs(this->radius_ - this->child_->radius_);
        }
    }
}

void Shape::draw() {
    Vec2f* center = new Vec2f(this->x_, this->y_);
    color(this->color_);
    drawSolidCircle(*center, radius_, 0);
    
    if (this->child_ != NULL)
        this->child_->draw();

    
}