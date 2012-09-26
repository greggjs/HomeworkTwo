//
//  HomeworkTwoApp.cpp
//  HomeworkTwo
//

#include "HomeworkTwoApp.h"

void HomeworkTwoApp::prepareSettings(Settings* settings){
	settings->setWindowSize(kAppWidth,kAppHeight);
	settings->setResizable(false);
}

void HomeworkTwoApp::setup()
{
	list_ = new ShapeList();
	
	moving_ = false;
	is_increasing_ = false;
	radius_ = 25;
	index_ = 1;
}

void HomeworkTwoApp::mouseMove(MouseEvent event){
    
	mouse_x_ = event.getX();
	mouse_y_ = event.getY();
    
}

//scrolling the mousewheel changes the radii of the
//circles drawn. if you scroll with the shift button down
//it decreases the radius.
void HomeworkTwoApp::mouseWheel(MouseEvent event){
	if(is_increasing_)
		radius_ += abs( event.getWheelIncrement());
	else
		radius_ -= abs( event.getWheelIncrement()) * 5;
    
	if(radius_ < 1)
		radius_ = 1;
}

void HomeworkTwoApp::mouseDrag(MouseEvent event){
    
	if(event.isLeftDown() && moving_ && my_shape != NULL){
		mouseMove(event);
		my_shape->move(mouse_x_, mouse_y_);
	}
    
}

void HomeworkTwoApp::mouseDown( MouseEvent event )
{
	if(moving_ && event.isLeft()){
		my_shape = list_->getShapeAt(event.getX(),event.getY());
	}
	else if(event.isLeft()){
		//create a new node at the end of the list.
        
		Node* new_node = new Node(index_);
		new_node->data_ = new Shape(event.getX(), event.getY(), radius_);
        
		list_->insertAfter(new_node, list_->sentinel_);
		index_++;
	}
	else if(event.isRight()) {
		list_->bringToFront(event.getX(),event.getY());
        list_->updateTint();
    }
}

void HomeworkTwoApp::keyDown( KeyEvent event )
{
	switch(event.getChar()){
        case 'm':
            moving_ = !moving_;
            break;
        case 'r':
            list_->reverseOrder();
            list_->updateTint();
            break;
        case 'a':
            if(my_shape != NULL)
                my_shape->setChild();
        case 'i':
            is_increasing_ = !is_increasing_;
        default:
            break;
            
	}
}

void HomeworkTwoApp::update()
{
    
}

void HomeworkTwoApp::mouseUp(MouseEvent event){
    
}

void HomeworkTwoApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    
	list_->draw();
    
}

CINDER_APP_BASIC( HomeworkTwoApp, RendererGl )
