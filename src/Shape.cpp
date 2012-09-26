//
//  Shape.cpp
//  HomeworkTwo
//

#include "Shape.h"

Shape::Shape(int x, int y, int radius){
	this->x_ = x;
	this->y_ = y;
    this->alpha_ = 0;
    
	this->child_ = NULL;
	this->anchor_x_ = x;
	this->anchor_y_ = y;
	this->bound_ = 0;
    
    
	//make sure the radius isn't too large
	if(radius > 100)
		this->radius_ = 100;
	else
		this->radius_ = radius;
    
	//make the shape a random color:
	Rand random;
	random.seed(x);
	this->color_ = Color8u(random.nextInt(0,256),
                           random.nextInt(0,256),random.nextInt(0,256));
    this->vis_color_ = color_;
}

void Shape::setChild(){
	this->child_ = new Shape(this->x_, this->y_, this->radius_ / 2);
	//bound should equal the radius of the outer shape minus the radius
	//of the inner shape.
	this->child_->bound_ = abs(this->radius_ - this->child_->radius_);
    this->updateTint(this->alpha_);
}

void Shape::removeChild(){
	delete this->child_;
}

void Shape::draw(){
    
	Vec2f* center = new Vec2f(this->x_, this->y_);
    
    color(this->vis_color_);
	drawSolidCircle(*center, radius_, 0);
	
	if(this->child_ != NULL)
		this->child_->draw();
	
}

void Shape::updateTint(float alpha) {
    this->alpha_ = alpha;
    
    this->vis_color_ = Color8u(this->color_.r * 1-alpha + 255 * alpha,
                            this->color_.g * 1-alpha + 255 * alpha,
                            this->color_.b * 1-alpha + 255 * alpha);
    
    if (this->child_ != NULL)
        this->child_->updateTint(alpha);
}

//This method checks whether or not a (x,y) point is within
//its bounds and returns a pointer to the shape. (if false return null)
Shape* Shape::findShapeWithPoint(int x, int y){
    
	int radius = this->radius_;
    
	//check that the x-coord of the point is within our shape's width,
	//then check if the y-coord is within the height.
	if((x >= x_ - radius) && (x <= x_ + radius)
       && (y >= y_ - radius) && (y <= y_ + radius)){
        
        //if shape has a child, recursively call to see if the point
        //is within the child's shape.
        if(this->child_ != NULL){
            Shape* active_child = this->child_->findShapeWithPoint(x,y);
            if(active_child != NULL)
                //you found that the point is contained in a child
                return active_child;
            else
                //no point was contained in a child
                return this;
        }
        else
            return this;
		
	}
	//otherwise return false
    return NULL;
    
}

//this function moves a shape's coordinates and all of its children.
void Shape::move(int x, int y){
    
	//if the shape is bounded, we must check that its center doesn't
	//go past the bound (outer shape radius) minus its own radius
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
		this->child_->bound_ = 0; //we have to take of the bounds while we're moving the whole stack
        
		this->child_->move(x + offset_x, y + offset_y);
		this->child_->bound_ = abs(this->radius_ - this->child_->radius_);
	}
}