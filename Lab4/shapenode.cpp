#include "ShapeNode.h"

ShapeNode::ShapeNode(){
  myShape= nullptr;
  next= nullptr;
}

ShapeNode::~ShapeNode(){
  delete myShape;
}

Shape*ShapeNode::getShape()const{
  return myShape;
}

void ShapeNode::setShape(Shape*ptr){
  myShape=ptr;
  return;
}

ShapeNode* ShapeNode::getNext() const{
  return next;
}

void ShapeNode::setNext(ShapeNode*ptr){
  next=ptr;
  return;
}

void ShapeNode::print()const{
  (*myShape).draw();
  return;
}
