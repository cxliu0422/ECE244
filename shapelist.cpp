#include "ShapeList.h"

ShapeList::ShapeList() { 
  head = nullptr;
}

ShapeList::~ShapeList() {
  ShapeNode *current;
  while (head != NULL) {
    current=head;
    head=current->getNext();
    // nextone = current->getNext();
    // nextone=NULL;
    delete current;
  }
}


ShapeNode *ShapeList::getHead() const {
  return head; 
}

void ShapeList::setHead(ShapeNode *ptr) {
  head = ptr;
  return;
}

ShapeNode *ShapeList::find(string name) const {
  ShapeNode *current = head;
  ShapeNode *nextone;
  if (current == NULL) {
    return NULL;
  }
  while (current != NULL) {
    if ((current->getShape()->getName() == name)) {
      return current;
    }
    nextone = current->getNext();
    current = nextone;
  }
  return nullptr;
}

void ShapeList::insert(ShapeNode *s) {
  ShapeNode *current = head;
  ShapeNode *tempnode = NULL;

  while(current!=NULL){
    tempnode=current;
    current=current->getNext();
  }
  if(tempnode == NULL) {
    head = s;
    s->setNext(NULL);
  }
  else{
    tempnode->setNext(s);
    s->setNext(NULL);
  }
}

ShapeNode *ShapeList::remove(string name) {
  ShapeNode *current = head;
  ShapeNode *tempnode = NULL;
  if (current == NULL) {
    return NULL;
  }

  while (current != NULL && ((current->getShape())->getName() != name)) {

    tempnode = current;
    current = current->getNext();
  }

  if (tempnode == NULL) {
    head = current->getNext();
    return current;
    
  } else {
    // head is not the one remove
    tempnode->setNext(current->getNext());
    return current;
  }
}

void ShapeList::print() const {
  ShapeNode *current = head;
  while (current != NULL) {
    current->print();
    current = current->getNext();
  }
}
