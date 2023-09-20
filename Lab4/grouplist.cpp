//
//  GroupList.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright ?2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student:
//  Write the implementation (and only the implementation) of the GroupList class below

#include <iostream>
#include "GroupList.h"

GroupList::GroupList(){
  head=nullptr;
}

GroupList::~GroupList(){
  GroupNode*current;
  while(head!=NULL){
    current=head;
    head=current->getNext();
    delete current;
  }
}

GroupNode*GroupList::getHead()const{
  return head;
}

void GroupList::setHead(GroupNode*ptr){
  head=ptr;
  return;
}

void GroupList::insert(GroupNode* s){
  GroupNode *current = head;
  GroupNode *tempnode = NULL;

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

GroupNode*GroupList::remove(string name){
  GroupNode *current = head;
  GroupNode *tempnode = NULL;
  if (current == NULL) {
    return nullptr;
  }

  while (current != NULL && ((current->getName())!= name)){

    tempnode = current;
    current = current->getNext();
  }

  if (tempnode == NULL) {
    head = current->getNext();
    delete current;
    return nullptr;
    
  } else {
    // head is not the one remove
    tempnode->setNext(current->getNext());
    delete current;
    return nullptr;
  }
}

void GroupList::print()const{
  GroupNode* current = head;
  while (current != NULL) {
    current->print();
    current = current->getNext();
  }
}



