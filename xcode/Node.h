//
//  Node.h
//  HomeworkTwo
//
//  Created by Jake Gregg on 9/24/12.
//
//

#ifndef HomeworkTwo_Node_h
#define HomeworkTwo_Node_h

#import "cinder/app/AppBasic.h"
#import "cinder/gl/gl.h"
#import "Shape.h"

class Node{
public:
    Node* next_;
    Node* prev_;
    Shape* data_;
    int index_;
    
    Node(int index);
};

#endif
