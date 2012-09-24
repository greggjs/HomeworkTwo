/**
 * Filename: HomeworkTwoApp.cpp
 * Author: Jake Gregg
 *
 */

#include "Shape.h"
#include "ShapeList.h"
#include "cinder/Rand.h"
#include "cinder/Color.h"
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace ci::gl;
using namespace std;

class HomeworkTwoApp : public AppBasic {
public:
	void setup();
	void mouseDown( MouseEvent event );
	void keyDown(KeyEvent event);
	void mouseDrag(MouseEvent event);
	void mouseMove(MouseEvent event);
	void mouseUp(MouseEvent event);
	void mouseWheel(MouseEvent event);
	void update();
	void draw();
	void prepareSettings(Settings* settings);
    
private:
	ShapeList* list_;

	static const int kAppWidth=800;
	static const int kAppHeight=600;
	bool is_moving_circles_;
	int index_; 
	int mouse_x_;
	int mouse_y_;
	int radius_;
	bool radius_is_increasing_;
	Shape* mobile_circle;
    
};

void HomeworkTwoApp::prepareSettings(Settings* settings){
	settings->setWindowSize(kAppWidth,kAppHeight);
	settings->setResizable(false);
}

void HomeworkTwoApp::setup()
{
	list_ = new ShapeList();
	
	is_moving_circles_ = false;
	radius_is_increasing_ = false;
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
	if(radius_is_increasing_)
		radius_ += abs( event.getWheelIncrement());
	else
		radius_ -= abs( event.getWheelIncrement()) * 5;
    
	if(radius_ < 1)
		radius_ = 1;
}

void HomeworkTwoApp::mouseDrag(MouseEvent event){
    
	if(event.isLeftDown() && is_moving_circles_ && mobile_circle != NULL){
		mouseMove(event);
		mobile_circle->move(mouse_x_, mouse_y_);
	}
    
}

void HomeworkTwoApp::mouseDown( MouseEvent event )
{
	if(is_moving_circles_){
		mobile_circle = list_->getShapeAt(event.getX(),event.getY());
	}
	else if(event.isLeft()){
		//create a new node at the end of the list.
        
		Node* new_node = new Node(index_);
		new_node->data_ = new Shape(event.getX(), event.getY(), radius_);
        
		list_->insertAfter(new_node, list_->sentinel_);
		index_++;
	}
	else if(event.isRight())
		list_->bringToFront(event.getX(),event.getY());
	
}

void HomeworkTwoApp::keyDown( KeyEvent event )
{
	switch(event.getChar()){
        case 'm':
            is_moving_circles_ = !is_moving_circles_;
            break;
        case 'r':
            list_->reverseOrder();
            break;
        case 'a':
            if(mobile_circle != NULL)
                mobile_circle->setChild();
        case 'i':
            radius_is_increasing_ = !radius_is_increasing_;
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
