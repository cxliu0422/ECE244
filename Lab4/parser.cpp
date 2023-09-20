
//
//  parser.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright ?2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "GroupList.h"
#include "GroupNode.h"
#include "Shape.h"
#include "ShapeList.h"
#include "ShapeNode.h"
#include "globals.h"

// This is a pointer to the groups list
// The list itseld must be allocated
GroupList *gList;

// ECE244 Student: you may want to add the prototype of
// helper functions you write here
bool invalidShapeName(string name);
bool shapeNameExist(string name);
// ShapeNode*newShapeNode(string name, string type, int xloc, int yloc, int
// xsize, int ysize);
GroupNode *moveShapeNode(string name);
GroupNode *moveGroupNode(string name);
GroupNode *deleteShapeNode(string name);
GroupNode *deleteGroupNode(string name);

int main() {
  // Create the groups list
  gList = new GroupList();

  // Create the poo group and add it to the group list
  GroupNode *poolGroup = new GroupNode(keyWordsList[NUM_KEYWORDS - 1]);
  gList->insert(poolGroup);

  string line;
  string command;

  cout << "> ";       // Prompt for input
  getline(cin, line); // Get a line from standard input

  while (!cin.eof()) {
    // Put the line in a linestream for parsing
    // Making a new sstream for each line so flags etc. are cleared
    stringstream lineStream(line);

    // Read from string stream into the command
    // The only way this can fail is if the eof is encountered
    lineStream >> command;

    if (command == "shape") {
      string name;
      lineStream >> name;
      if ((!invalidShapeName(name)) && (!shapeNameExist(name))) {
        // cout<<"helo0"<<endl;
        string type;
        lineStream >> type;
        int xloc, yloc, xsize, ysize;
        lineStream >> xloc;
        lineStream >> yloc;
        lineStream >> xsize;
        lineStream >> ysize;
        // cout<<"hel"<<endl;
        Shape *newshape = new Shape(name, type, xloc, yloc, xsize, ysize);
        ShapeNode *newNode = new ShapeNode();
        newNode->setShape(newshape);
        ShapeNode *tempnode = newNode;
        tempnode->print();
        // cout<<"helloo"<<endl;
        GroupNode *current = gList->getHead();
        // cout<<"okkk"<<endl;
        current->getShapeList()->insert(tempnode); //有segmentation fault
        // cout<<"dhfjfh"<<endl;
      }
    }

    else if (command == "group") {
      string name;
      lineStream >> name;
      if ((!invalidShapeName(name)) && (!shapeNameExist(name))) {
        GroupNode *tempnode = new GroupNode(name);
        gList->insert(tempnode);
        cout << name << ": "
             << "group" << endl;
      }

    }

    else if (command == "draw") {
      cout << "drawing:" << endl;
      gList->print();

    }

    else if (command == "move") {
      string nodename;
      string groupname;
      lineStream >> nodename;
      lineStream >> groupname;
      // check whether they are valid
      if ((!invalidShapeName(nodename)) && (!invalidShapeName(groupname))) {
        GroupNode *tempnode1 = moveShapeNode(nodename);
        GroupNode *tempnode2 = moveGroupNode(groupname);
        if (tempnode1 != NULL && tempnode2 != NULL) {
          ShapeNode *newshape = tempnode1->getShapeList()->remove(nodename);
          tempnode2->getShapeList()->insert(newshape);
          cout << "moved " << nodename << " to " << groupname << endl;
        }
      }
    }

     else if (command == "delete") {
      string name;
      lineStream >> name;
      if (!invalidShapeName(name)){
        GroupNode *tempnode1 = deleteShapeNode(name);
        GroupNode *tempnode2 = deleteGroupNode(name);
        // GroupNode *tempnode1 = deleteShapeNode(name);
        if (tempnode1 != NULL) {
          delete tempnode1->getShapeList()->remove(name);
          cout << name<< ": "<<"deleted " << endl;
        }
        // GroupNode*tempnode2=onlyGroupNode(name);
        else if (tempnode2 != NULL) {
          ShapeList *list1 = tempnode2->getShapeList();
          ShapeList *list2 = gList->getHead()->getShapeList();
          while (list1->getHead() != NULL) {
            ShapeNode *current = list1->getHead();
            string shapes = current->getShape()->getName();
            // delete list1->remove(shapes);
            ShapeNode *newshapenodes = list1->remove(shapes);
            list2->insert(newshapenodes);//add
          }
          gList->remove(name);
          cout << name<< ": "<<"deleted " << endl;
        }
        else{
          cout<<"error: shape "<<name<<" not found"<<endl;
        }
      }
    }
    // Check for the command and act accordingly
    // ECE244 Student: Insert your code here

    // Once the command has been processed, prompt for the
    // next command
    cout << "> "; // Prompt for input
    getline(cin, line);

  } // End input loop until EOF.

  return 0;
}

bool invalidShapeName(string name) {
  if ((name == "shape") || (name == "group") || (name == "draw") ||
      (name == "move") || (name == "delete") || (name == "pool") ||
      (name == "ellipse") || (name == "rectangle") || (name == "triangle")) {
    cout << "error: invalid name" << endl;
    return true;
  }
  return false;
}

bool shapeNameExist(string name) {
  GroupNode *tempnode = gList->getHead();
  while (tempnode != NULL) {
    if ((tempnode->getName()) == name) {
      cout << "error: name " << name << " exists" << endl;
      return true;
    }
    if ((tempnode->getShapeList()) == NULL) {
      return false;
    }
    if (((tempnode->getShapeList())->find(name)) != NULL) {
      cout << "error: name " << name << " exists" << endl;
      return true;
    }
    tempnode = tempnode->getNext();
  }
  return false;
}

// create a new shape node with shape
// ShapeNode*newShapeNode(string name, string type, int xloc, int yloc, int
// xsize, int ysize){
//   Shape*newshape= new Shape(name,type,xloc,yloc,xsize,ysize);
//   ShapeNode*newNode=new ShapeNode();
//   newNode->setShape(newshape);
//   return newNode;
// }

// create a groupnode with shape list(shapenode in it)
GroupNode *moveShapeNode(string name) {
  GroupNode *tempnode1 = gList->getHead();
  while (tempnode1 != NULL) {
    ShapeNode *tempnode2 = tempnode1->getShapeList()->find(name);
    if (tempnode2 != NULL) {
      return tempnode1;
    }
    tempnode1 = tempnode1->getNext();
  }
  tempnode1 = NULL;

  if (tempnode1 == NULL) {
    cout << "shape " << name << " not found" << endl;
  }
}

// a groupnode with name, check for whether we have
GroupNode *moveGroupNode(string name) {
  GroupNode *tempnode = gList->getHead();
  while (tempnode != NULL) {
    if (tempnode->getName() == name) {
      return tempnode;
    }
    tempnode = tempnode->getNext();
  }
  tempnode = NULL;

  if (tempnode == NULL) {
    cout << "group " << name << " not found" << endl;
  }
}

GroupNode *deleteShapeNode(string name) {
  GroupNode *tempnode1 = gList->getHead();
  while (tempnode1 != NULL) {
    ShapeNode *tempnode2 = tempnode1->getShapeList()->find(name);
    if (tempnode2 != NULL) {
      return tempnode1;
    }
    tempnode1 = tempnode1->getNext();
  }
  return NULL;
}

GroupNode *deleteGroupNode(string name) {
  GroupNode *tempnode = gList->getHead();
  while (tempnode != NULL) {
    if (tempnode->getName() == name) {
      return tempnode;
    }
    tempnode = tempnode->getNext();
  }
  return NULL;
}

