#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Shape.h"

using namespace ci;
using namespace ci::app;
using namespace ci::gl;
using namespace std;

class ShapeList {

//struct node_ {
  //  node_* next_;
   
//};
public:
    ShapeList();
	void setup();
	void update();
	void draw();
    void insert(Shape mShape);
    //void remove(node_* mLoc);
    //void at (node_* mLoc);
    
//private:
//    node_* sentinel_;
//    node_* next_;
//    Shape data_;
};