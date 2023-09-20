

#include "globals.h"
#include "GameState.h"

void playMove(GameState& game_state) {
    
    int playerrow=game_state.get_selectedRow();
    int playercol=game_state.get_selectedColumn();
    int player;
    
    
    
    if(game_state.get_turn()){
        player=1;
    }else if(!game_state.get_turn()){
        player=-1;
    }
  
    if(game_state.get_gameBoard(playerrow, playercol)!=0){
        game_state.set_moveValid(false);
        return;
    }else{
        game_state.set_moveValid(true);
        game_state.set_gameBoard(playerrow,playercol,player);
        
    }
  
    if(player==1){
        game_state.set_turn(false);
    }
    else{
        game_state.set_turn(true);
    }
    
    
  
    int xdir[]={ 1, -1, 0, 0, 1, -1, 1, -1 };
    int ydir[]={ 0, 0, 1, -1, 1, -1, -1, 1 };
    int playerrow2;
    int playercol2;

    for(int i=0,j=0;i<8&&j<8;i++,j++){
        if(game_state.get_gameBoard(playerrow+xdir[i],playercol+ydir[j])==(game_state.get_gameBoard(playerrow,playercol))){
          if(playerrow+2*xdir[i]>2||playerrow+2*xdir[i]<0||playercol+2*ydir[j]<0||playercol+2*ydir[j]>2){
            playerrow2=playerrow-xdir[i];
            playercol2=playercol-ydir[i];
          }else{
                playerrow2=playerrow+xdir[i]*2;
                playercol2=playercol+ydir[j]*2;
            }
          if(game_state.get_gameBoard(playerrow2,playercol2)==(game_state.get_gameBoard(playerrow,playercol))){
                game_state.set_gameOver(true);
            
              if(xdir[i]==0&&ydir[j]!=0){
                if(playerrow==0){
                  game_state.set_winCode(1);
                  return;
                }
                if(playerrow==1){
                  game_state.set_winCode(2);
                  return;
                }
                if(playerrow==2){
                  game_state.set_winCode(3);
                  return;
                }
              }
                if(xdir[i]!=0&&ydir[j]==0){
                if(playercol==0){
                  game_state.set_winCode(4);
                  return;
                }
                else if(playercol==1){
                  game_state.set_winCode(5);
                  return;
                }
                else if(playercol==2){
                  game_state.set_winCode(6);
                  return;
                }
              }
                if(xdir[i]!=0&&ydir[j]!=0){
                if(xdir[i]==ydir[j]){
                  game_state.set_winCode(7);
                  return;
                }
                else{
                  game_state.set_winCode(8);
                  return;
                }
              }  
            }
            }else{
                game_state.set_gameOver(false);
        }
      bool draw=true;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(game_state.get_gameBoard(i,j)==0){
        draw=false;
      }
    }
  }
  if(draw==true){
      game_state.set_gameOver(true);
    game_state.set_winCode(0);
    return;
  }
    }
  
  
  }
