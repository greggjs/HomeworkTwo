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
using namespace std;

class HomeworkTwoApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void HomeworkTwoApp::setup()
{
}

void HomeworkTwoApp::mouseDown( MouseEvent event )
{
}

void HomeworkTwoApp::update()
{
}

void HomeworkTwoApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_BASIC( HomeworkTwoApp, RendererGl )
