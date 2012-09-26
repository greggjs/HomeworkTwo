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
	bool moving_;
	int index_; 
	int mouse_x_;
	int mouse_y_;
	int radius_;
	bool is_increasing_;
	Shape* my_shape;
    
};