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
    void keyDown ( KeyEvent event );
    void mouseDrag( MouseEvent event );
    void mouseMove( MouseEvent event );
    void mouseWheel(MouseEvent event);
	void update();
	void draw();
private:
    ShapeList* list_;
    ShapeList* groups_;
    bool moving_;
    int index_;
    int mouse_x_;
    int mouse_y_;
    int radius_;
    bool is_increasing_;
    Shape* my_shape;
    int random;
};

void HomeworkTwoApp::setup()
{
    list_ = new ShapeList();
    groups_ = new ShapeList();
    moving_ = false;
    is_increasing_ = false;
    random = Rand::randInt(0, 100);
    radius_ = random;
    index_ = 1;
}

void HomeworkTwoApp::mouseMove(MouseEvent event) {
    mouse_x_ = event.getX();
    mouse_y_ = event.getY();
}

void HomeworkTwoApp::mouseWheel(MouseEvent event ) {
    if (is_increasing_)
        radius_ += abs(event.getWheelIncrement());
    else
        radius_ -= abs(event.getWheelIncrement()) * 5;
    
    if (radius_ < 1)
        radius_ = 1;
}

void HomeworkTwoApp::mouseDrag(MouseEvent event) {
    if (event.isLeftDown() && moving_ && my_shape != NULL) {
        mouseMove(event);
        my_shape->move(mouse_x_, mouse_y_);
    }
        
}

void HomeworkTwoApp::mouseDown(MouseEvent event) {
    if (moving_)
        my_shape = list_->getShapeAt(event.getX(), event.getY());
    else if (event.isLeft()) {
        Node* new_node = new Node(index_);
        new_node->data_ = new Shape(event.getX(), event.getY(), radius_);
        
        list_->insertAfter(new_node, list_->sentinel_);
        index_++;
    }
    else if (event.isRight())
        list_->bringToFront(event.getX(), event.getY());
}

void HomeworkTwoApp::keyDown(KeyEvent event) {
    /*
    switch(event.getChar()) {
        case 'm':
            moving_ = !moving_;
            break;
        case 'r':
            list_->reverseOrder();
            break;
        case 's':
            if (my_shape != NULL)
                my_shape->setChild();
        case 'g':
            is_increasing_ = !is_increasing_;
        default:
            break;
    }
     */
    if (event.getChar() == 'm')
        moving_ = !moving_;
    else if (event.getChar() == 'r')
        list_->reverseOrder();
    else if (event.getChar() == 's')
        if (my_shape != NULL)
            my_shape->setChild();
    else if (event.getChar() == 'g')
        is_increasing_ = !is_increasing_;
}

void HomeworkTwoApp::update()
{
    
}

void HomeworkTwoApp::draw()
{
    clear(Color(0,0,0));
    list_->draw();
    
}

CINDER_APP_BASIC( HomeworkTwoApp, RendererGl )
