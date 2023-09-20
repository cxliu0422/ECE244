//
//  parser.cpp
//  lab3
//
//  Modified by Tarek Abdelrahman on 2020-10-04.
//  Created by Tarek Abdelrahman on 2018-08-25.
//  Copyright ? 2018-2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.


#include <iostream>
#include <sstream>
#include <string>
#include <valarray>

using namespace std;

#include "globals.h"
#include "Shape.h"

bool tooFewArguements(stringstream&stream);
bool invalidShapeName(string name, stringstream&stream);
bool shapeNameExist(string name, stringstream&stream);
bool invalidShapeType(string type, stringstream&stream);
bool invalidValue(int value, stringstream&stream);
bool invalidAngle(int angle, stringstream&stream);
bool shapeNameNotFound(string name, stringstream&stream);
//bool checkFloat(stringstream&stream);
bool circleValueCheck(string type,int xsize,int ysize);

// This is the shape array, to be dynamically allocated
Shape** shapesArray;

// The number of shapes in the database, to be incremented 
int shapeCount = 0;

// The value of the argument to the maxShapes command
int max_shapes;

// ECE244 Student: you may want to add the prototype of
// helper functions you write here

int main() {

    string line;
    string command;
    
    cout << "> ";         // Prompt for input
    getline(cin, line);    // Get a line from standard input

    while ( !cin.eof () ) {
        // Put the line in a linestream for parsing
        // Making a new sstream for each line so flags etc. are cleared
        stringstream lineStream (line);
        
        // Read from string stream into the command
        // The only way this can fail is if the eof is encountered
        lineStream >> command;

        // Check for the command and act accordingly
        // ECE244 Student: Insert your code here
      if(lineStream.fail()){
        cout<<"Error:invalid command"<<endl;
        lineStream.clear();
        lineStream.ignore(10000,'\n');
      }
        //command is maxShapes;
        else if(command=="maxShapes"){
            
          lineStream>>max_shapes;
          // if fail input, two cases.
          if(lineStream.fail()){
              // no input for number
             if(lineStream.eof()){
              cout<<"Error: too few arguments"<<endl;
            }else {
                 //incorrect type
              cout<<"Error: invalid arguments"<<endl;
               lineStream.clear();
               lineStream.ignore(10000,'\n');
            }
          }
          // if there are more than one input
          else if(!lineStream.eof()){
            cout<<"Error: too many argument"<<endl;
          }else{
            if(shapeCount!=0){
              for(int i=0;i<shapeCount;i++){
                delete shapesArray[i];
                shapesArray[i]=NULL;
                shapeCount=0;
                
              }cout<<"New database: max shapes is "<<max_shapes<<endl;
            }
            else{
            shapesArray= new Shape*[max_shapes];
            for(int i=0;i<max_shapes;i++){
              shapesArray[i]=NULL;
              
              
            }cout<<"New database: max shapes is "<<max_shapes<<endl;
            }
          }
          
        }
        
        //command is create
        else if(command=="create"){
//            cout<<"hello"<<endl;
            if(lineStream.fail()){
               
                if(lineStream.eof()){
                    cout<<"Error: too few arguments"<<endl;
                }
                else{
                    cout<<"Error: invalid arguments"<<endl;
                    lineStream.clear();
                    //lineStream.ignore(10000,'\n');
                }
                
          // decide if array is full
//          if(max_shapes==shapeCount){
//            cout<<"Error: shape array is full"<<endl;
//          }else if(lineStream.eof()){
//            cout<<"Error: too few arguments"<<endl;
            }
            else{
//                cout<<"ok"<<endl;
              string name;
              lineStream>>name;
            // if(lineStream.fail()){
            //   cout<<"Error: invalid command"<<endl;
            //   lineStream.clear();
            // }if(lineStream.eof()){
            //   cout<<"Error: too few argument"<<endl;
            // }else{
              
              if(!(invalidShapeName(name, lineStream))&& (!shapeNameExist(name, lineStream))&&(!tooFewArguements(lineStream))){
                string type;
//                cout<<"yes"<<endl;
                lineStream>>type;
                if(!(invalidShapeType(type, lineStream))&&(!tooFewArguements(lineStream))){
                  int xloc;
//                  cout<<"no"<<endl;
                  lineStream>> xloc;
//                  cout<<"bo"<<endl;
                  if((!invalidValue(xloc,lineStream))&&(!tooFewArguements(lineStream))){
                    int yloc;
                    lineStream>>yloc;
//                    cout<<"ok"<<endl;
                 
                    if((!invalidValue(yloc,lineStream))&&(!tooFewArguements(lineStream))){
//                        cout<<"fine"<<endl;
                      int xsize;
                      lineStream>> xsize;
                      if((!invalidAngle(xsize,lineStream))&&(!tooFewArguements(lineStream))){
                        int ysize;
                        lineStream>> ysize;
//         
//                        cout<<"good"<<endl;
                        if((!invalidAngle(ysize,lineStream))){
//                            cout<<"hello"<<endl;
                          if((!circleValueCheck(type,xsize,ysize))){
                   
                              cout<<"Error: invalid value"<<endl;
                          }
                              
                          
                           else if(!lineStream.eof()){
                               cout<<"Error: too many arguments"<<endl;
                          }
                           else if(max_shapes==shapeCount){
                               cout<<"Error: shape array is full"<<endl;
            
                            }
                          // else if(max_shapes==shapeCount){
                          //     cout<<"Error: shape array is full"<<endl;
                          // }
                          
                          else{
//                            for(int i=0;i<max_shapes;i++){
//                              if(shapesArray[i]==NULL){
                                shapesArray[shapeCount]=new Shape(name,type,xloc,xsize,yloc,ysize);
                                cout<<"Created ";
                                (*shapesArray[shapeCount]).draw();
                                shapeCount++;
//                            }
//                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }

        //command is move  
        else if(command=="move"){

          if(lineStream.eof()){
            cout<<"Error: too few arguments"<<endl;
          }else{
            string name;
            lineStream>>name;
            if((!invalidShapeName(name,lineStream))&&(!shapeNameNotFound(name, lineStream))&&(!tooFewArguements(lineStream))){
              int xloc;
              lineStream>>xloc;
//              if(lineStream.fail()){
//                  cout<<"Error: invalid command"<<endl;
//              }else{
                if((!invalidValue(xloc,lineStream))&&(!tooFewArguements(lineStream))){
                    int yloc;
                    lineStream>>yloc;
//                    if(lineStream.fail()){
//                        cout<<"Error: invalid command"<<endl;
//                    }else{
                        if((!invalidValue(yloc,lineStream))){
                            if(!lineStream.eof()){
                                cout<<"Error:too many arguments"<<endl;
                            }
                            else{
                                for(int i=0;i<max_shapes;i++){
                                if((shapesArray[i]!=NULL)&&((*shapesArray[i]).getName()==name)){
                                    (*shapesArray[i]).setXlocation(xloc);
                                    (*shapesArray[i]).setYlocation(yloc);
                                    cout <<"Moved "<< name <<" to "<<xloc<<" "<<yloc<<endl;
                                    }
                                }
                            }
                        }
                    } 
                }
            } 
//        }
//        }
       }
      //command is rotate    
      else if(command=="rotate"){
         if(lineStream.eof()){
           cout<<"Error: too few arguments"<<endl;
         }else{
             string name;
             lineStream>>name;
             if((!invalidShapeName(name,lineStream))&&(!shapeNameNotFound(name, lineStream))&&(!tooFewArguements(lineStream))){
              int angle;
              lineStream>>angle;
              if(!invalidAngle(angle,lineStream)){
                if(!lineStream.eof()){
                  cout<<"Error: too many arguments"<<endl;
                }
                else{
                  for(int i=0;i<max_shapes;i++){
                    if((shapesArray[i]!=NULL)&&((*shapesArray[i]).getName()==name)){
                      ((*shapesArray[i]).setRotate(angle));
                      cout<<"Rotated"<<name<<"by"<<angle<<"degrees"<<endl;
                }
              }
            }
          }
        }
      }
    }

     //command is draw   
    else if(command=="draw"){
      if(lineStream.eof()){

        cout<<"Error: too few arguments"<<endl;
      }else{
        string name;
        lineStream>>name;
        if(lineStream.fail()){
          cout<<"Error: invalid argument"<<endl;
        }
        else{
          if(name=="all"){
            if(!lineStream.eof()){
              cout<<"Error: too many arguments"<<endl;
            }else{
              cout<<"Drew all shapes"<<endl;
              for(int i=0;i<shapeCount;i++){
                if(shapesArray[i]!=NULL){
                  (*shapesArray[i]).draw();
                }
              }
            }
          }
          else if((!invalidShapeName(name,lineStream))&&(!shapeNameNotFound(name,lineStream))){
            if(!lineStream.eof()){
              cout<<"Error: too many arguments"<<endl;
            }else{
              for(int i=0;i<shapeCount;i++){
                if((shapesArray[i]!=NULL)&&(*shapesArray[i]).getName()==name){
                  cout<<"Drew ";
                  (*shapesArray[i]).draw();
                }
              }
            }
          } 
        }
      }
    }

      // command is delete
    else if(command=="delete"){
      if(lineStream.eof()){
        cout<<"Error: too few arguments"<<endl;
      }else{
        string name;
        lineStream>>name;
        if(lineStream.fail()){
          cout<<"Error: invalid arguments"<<endl;
        }
        else{
          if(name=="all"){
            if(!lineStream.eof()){
              cout<<"Error: too many arguments"<<endl;
            }else{
              cout<<"Deleted: all shapes"<<endl;
              for(int i=0;i<shapeCount;i++){
                delete shapesArray[i];
                shapesArray[i]=NULL;
//                shapeCount=0;
                }
            }
          }
          else if((!invalidShapeName(name,lineStream))&&(!shapeNameNotFound(name,lineStream))){
            if(!lineStream.eof()){
              cout<<"Error: too many arguments"<<endl;
            }else{
              for(int i=0;i<shapeCount;i++){
                if((shapesArray[i]!=NULL)&&(*shapesArray[i]).getName()==name){
                  delete shapesArray[i];
                  shapesArray[i]=NULL;
                  cout<<"Deleted shape"<<name<<endl;
//                  shapeCount--;
              }
                }
          }
        }
      }
    }
  }

  else{
    cout<<"Error: invalid command"<<endl;
    lineStream.clear();
    lineStream.ignore(10000,'\n');
  }
      

      
        
        
        
        // Once the command has been processed, prompt for the
        // next command
        cout << "> ";          // Prompt for input
        getline(cin, line);
        
    }  // End input loop until EOF.
    
    return 0;
}

bool tooFewArguements(stringstream&stream){
    if(stream.eof()){
        cout<<"Error: too few arguments"<<endl;
        return true;
    }
    return false;
}

bool invalidShapeName(string name, stringstream &stream){
//  if(stream.eof()){
//    cout<<"Error: too few arguments"<<endl;
//    return true;
//  }
  if(stream.fail()){
      if(stream.eof()){
          cout<<"Error: too few arguments"<<endl;
          return true;
      }else{
          cout<<"Error: invalid argument"<<endl;
          return true;
      }
    }  
  
  if((name=="maxShapes")||(name=="create")||(name=="move")||(name=="rotate")||(name=="draw")||(name=="delete")||(name=="all")||(name=="ellipse")||(name=="circle")||(name=="rectangle")||(name=="triangle")){
      cout<<"Error: invalid shape name"<<endl;
      return true;
  }
  return false;
  }

bool shapeNameExist(string name, stringstream &stream){
//  if(stream.eof()){
//    cout<<"Error: too few arguments"<<endl;
//    return true;
//  }
    if(stream.fail()){
      if(stream.eof()){
          cout<<"Error: too few arguments"<<endl;
          return true;
      }else{
          cout<<"Error: invalid argument"<<endl;
          return true;
      }
    }  
  
  for(int i=0;i<shapeCount;i++){
    if(shapesArray[i]!=NULL){
      if(name==(*shapesArray[i]).getName()){
        cout<<"Error: shape "<<name<<" exists"<<endl;
        return true;
      }
    }
  }
  return false;
}

bool invalidShapeType(string type, stringstream &stream){
//  if(stream.eof()){
//    cout<<"Error: too few arguments"<<endl;
//    return true;
//  }
  if(stream.fail()){
      if(stream.eof()){
          cout<<"Error: too few arguments"<<endl;
          return true;
      }else{
          cout<<"Error: invalid argument"<<endl;
          return true;
      }
    }    
  
  if((type!="ellipse")&&(type!="circle")&&(type!="rectangle")&&(type!="triangle")){
      cout<<"Error: invalid shape type"<<endl;
    return true;
  }
  return false;
}

bool invalidValue(int value, stringstream &stream){
//  if(stream.eof()){
//      cout<<"hello"<<endl;
//    cout<<"Error: too few arguments"<<endl;
//    return true;
//  }
    if(stream.fail()){
      if(stream.eof()){
          cout<<"Error: too few arguments"<<endl;
          return true;
      }else{
          cout<<"Error: invalid argument"<<endl;
          return true;
      }
    }
    
    if((stream.peek()!= ' ')&&(stream.peek()!=-1)){
    
        cout<<"Error: invalid argument"<<endl;
        return true;
    }
      
    if(value<0){
        cout<<"Error: invalid value"<<endl;
        return true;
    }
  // if(stream.fail()){
  //   cout<<"Error: invalid argument"<<endl;
  //   return true;
  // }
  return false;
}

//bool checkFloat(stringstream &stream){
//  if((stream.peek()!= ' ')&&(stream.peek()!=-1)){
//    
//    cout<<"Error: invalid argument"<<endl;
//    return true;
//  }
//  return false;
//}

bool invalidAngle(int angle, stringstream &stream){
//  if(stream.eof()){
//    cout<<"Error: too few arguments"<<endl;
//    return true;
//  }
  if(stream.fail()){
      if(stream.eof()){
          cout<<"Error: too few arguments "<<endl;
          return true;
      }else{
          cout<<"Error: invalid argument"<<endl;
          return true;
      }
  }

   if((stream.peek()!= ' ')&&(stream.peek()!=-1)){
    
    cout<<"Error: invalid argument"<<endl;
    return true;
  }
    
  if((angle<0)||(angle>360)){
    cout<<"Error: invalid value"<<endl;
    return true;
  }
//  if(stream.fail()){
//    cout<<"Error: invalid argument"<<endl;
//    return true;
//  }
  return false;
}

bool shapeNameNotFound(string name, stringstream &stream){
//  if(stream.eof()){
//    cout<<"Error: too few arguments"<<endl;
//    return true;
//  }
  if(stream.fail()){
      
      if(stream.eof()){
          cout<<"Error: too few arguments"<<endl;
          return true;
      }else{
          cout<<"Error: invalid argument"<<endl;
          return true;
      }
    }    
  
  for(int i=0;i<shapeCount;i++){
      if(shapesArray[i]!=NULL){
        if(name==(*shapesArray[i]).getName()){
        return false;
        }
    }
  }
  cout<<"Error: shape "<<name<<" not found"<<endl;
  return true;
}

bool circleValueCheck(string type, int xsize,int ysize){
    if(type=="circle"){
        if(xsize!=ysize){
            return false;
        }
    }
    return true;
}
