#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace ci::gl;
using namespace std;

class Shape {
public:
    Shape();
	void setup();
	void update();
	void draw();
};