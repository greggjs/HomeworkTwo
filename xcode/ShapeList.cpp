#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "ShapeList.h"
#include "Shape.h"
#include "Node.h"
#include "cinder/Vector.h"


using namespace ci;
using namespace ci::app;
using namespace ci::gl;
using namespace std;

ShapeList::ShapeList() {
    sentinel_ = new Node(-1);
    sentinel_->next_ = sentinel_;
    sentinel_->prev_ = sentinel_;
    sentinel_->data_ = NULL;
}

void ShapeList::reverseOrder() {
    Node* cur = this->sentinel_;
    do {
        Node temp = *(cur);
        cur->next_ = temp.prev_;
        cur->prev_ = temp.next_;
        cur  = cur->prev_;
    } while(cur != this->sentinel_);
}

void ShapeList::bringToFront(int x, int y) {
    Node* cur = this->getNodeAt(x, y);
    
    if (cur != NULL) {
        this->removeNode(cur);
        this->insertAfter(cur, this->sentinel_);
    }
}

void ShapeList::insertAfter(Node* new_node, Node* target_node) {
    new_node->next_ = target_node->next_;
    new_node->prev_ = target_node;
    target_node->next_ = new_node;
    (new_node->next_)->prev_ = new_node;
}

void ShapeList::insertBefore(Node* new_node, Node* target_node) {
    new_node->next_ = target_node;
    new_node->prev_ = target_node->prev_;
    
    target_node->prev_ = new_node;
    (new_node->prev_)->next_ = new_node;
}

Node* ShapeList::removeNode(Node* target_node) {
    (target_node->next_)->prev_ = target_node->prev_;
    (target_node->prev_)->next_ = target_node->next_;
    
    target_node->prev_ = NULL;
    target_node->next_ = NULL;
    
    return target_node;
}

void ShapeList::draw() {
    Node* cur = this->sentinel_->prev_;
    
    while (cur != this->sentinel_) {
        (cur->data_)->draw();
        cur = cur->prev_;
    }
}

Shape* ShapeList::getShapeAt(int x, int y) {
    
    Node* cur = (this->sentinel_)->next_;
    
    while (cur != this->sentinel_) {
        Shape* active_shape = (cur->data_)->findShapeWithPoint(x, y);
        if (active_shape != NULL)
            return active_shape;
        cur = cur->next_;
    }
    
    return NULL;
    
}

Node* ShapeList::getNodeAt(int x, int y) {
    
    Node* cur = (this->sentinel_)->next_;
    
    while (cur != this->sentinel_) {
        Shape* active_shape = (cur->data_)->findShapeWithPoint(x, y);
        if (active_shape != NULL)
            return cur;
        cur = cur->next_;
    }
    return NULL;
    
}