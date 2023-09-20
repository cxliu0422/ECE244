
#include <iostream>
#include <string>
using namespace std;

#include "Shape.h"

Shape::Shape(string n, string t, int x_loc, int y_loc, int x_sz, int y_sz){
  name=n;
  type=t;
  x_location=x_loc;
  y_location=y_loc;
  x_size=x_sz;
  y_size=y_sz;
}

string Shape::getType(){
  return type;
}

string Shape::getName(){
  return name;
}

int Shape::getXlocation(){
  return x_location;
}

int Shape::getYlocation(){
  return y_location;
}

int Shape::getXsize(){
  return x_size;
}

int Shape::getYsize(){
  return y_size;
}


void Shape::setType(string t){
  type=t;
  return;
}

void Shape::setName(string n){
  name=n;
  return;
}

void Shape::setXlocation(int x_loc){
  x_location=x_loc;
  return;
}

void Shape::setYlocation(int y_loc){
  y_location=y_loc;
  return;
}

void Shape::setXsize(int x_sz){
  x_size=x_sz;
  return;
}

void Shape::setYsize(int y_sz){
  y_size=y_sz;
  return;
}


void Shape::draw(){
  cout<<name<<": "<<type<<" "<<x_location<<" "<<y_location<<" "<<x_size<<" "<<y_size<<endl;
  return;
}
