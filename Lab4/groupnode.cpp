#include <iostream>
#include "GroupNode.h"
using namespace std;

GroupNode::GroupNode(string n){
  name=n;
  myShapeList= new ShapeList();
  next=nullptr;
}

GroupNode::~GroupNode(){
  delete myShapeList;
}

string GroupNode::getName()const{
  return name;
}

ShapeList*GroupNode::getShapeList()const{
  return myShapeList;
}

void GroupNode::setShapeList(ShapeList*ptr){
  myShapeList=ptr;
  return;
}

GroupNode*GroupNode::getNext()const{
  return next;
}

void GroupNode::setNext(GroupNode* ptr){
  next=ptr;
  return;
}

void GroupNode::print()const{
  cout<<name<<": "<<endl;
  myShapeList->print();
}
