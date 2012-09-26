//
//  ShapeList.h
//  HomeworkTwo
//

#include "cinder/app/AppBasic.h"
#include "cinder/Vector.h"
#include "cinder/gl/gl.h"
#include "Shape.h"
#include "Node.h"

using namespace ci;
using namespace ci::app;
using namespace ci::gl;
using namespace std;

class ShapeList {

public:
    ShapeList();
	void setup();
	void update();
	void draw();
    
    Node* sentinel_;
    
    void reverseOrder();
    void bringToFront(int x, int y);
    void insertAfter(Node* new_link, Node* target_link);
    void insertBefore(Node* new_link, Node* target_link);
    void updateTint();
    Node* removeNode(Node* target_node);
    Shape* getShapeAt(int x, int y);
    Node* getNodeAt(int x, int y);
};