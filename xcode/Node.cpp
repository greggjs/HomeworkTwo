//
//  Node.cpp
//  HomeworkTwo
//
//  Created by Jake Gregg on 9/24/12.
//
//

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Node.h"

Node::Node (int index) {
    index_ = index;
    next_ = NULL;
    prev_ = NULL;
    data_ = NULL;
}