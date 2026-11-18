#include "player.h"
#include<iostream>
void Player :: logic(pType player){
    if(player == OPPONENT){
        std::cout<<"Opponent is playing"<<std::endl;
    }else{
        std::cout<<"PC is playing"<<std::endl;
    }
}
void OPP :: getInput(Square (&sqs)[9]){
    int val = 0;
    std::cout<<"Cross the square: ";
    
    if(std::cin>>val){
        if(val>9 || val<0){
        std::cout<<"Enter valid slot number"<<std::endl;
        getInput(sqs);
        }
        else{
            if(sqs[val-1].getValue()){
                std::cout<<"Enter valid slot number"<<std::endl;
                getInput(sqs);
            }else{
            input = val;
            }
        }
    }else{
        std::cin.clear();
        std::cin.ignore();
        std::cout<<"Enter valid slot number"<<std::endl;
        getInput(sqs);
    }
    
}
void OPP :: setInput(Square *sq){
    sq[input-1].setValue(true);
}
bool getLostAllAxis(Square *sq){
    int indexH = 0;
    int indexV = 0;
    for(int i=0; i<3; i++){
        
        if(sq[0+indexH].getValue() == true && sq[1+indexH].getValue()==true && sq[2+indexH].getValue() == true){
            return true;
        }
        if(sq[0+indexV].getValue() == true && sq[3+indexV].getValue()==true && sq[6+indexV].getValue() == true){
            return true;
        }
        
        indexH +=3;
        indexV += 1;
        
    }
    if(sq[0].getValue() == true && sq[4].getValue()==true && sq[8].getValue() == true){
        return true;
    }
    if(sq[2].getValue() == true && sq[4].getValue()==true && sq[6].getValue() == true){
        return true;
    }
}
void Player :: incPoints(Square *sq){
    lost = getLostAllAxis(sq);
}
void Player :: playPC(Square (&sq)[9]){
    Square tempSqs[9];
    std::copy(std::begin(sq),std::end(sq),std::begin(tempSqs));
    int index = 0;
    bool makeMove = false;
    for(Square slot : tempSqs){
        if(!slot.getValue()){
            tempSqs[index].setValue(true);
            bool isLost = getLostAllAxis(tempSqs);
            if(!isLost){
                sq[index].setValue(true);
                makeMove = true;
                break;
            }else{
                tempSqs[index].setValue(false);
            }
        }
        index++;
    }
    if(!makeMove){
        lost = true;
        std::cout << "Player withdraws and OPP has won..."<<std::endl;
    }
}