#include "player.h"
#include "types.h"
#include <random>
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
            if(!sqs[val-1].getIsEmpty()){
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
    sq[input-1].setValue(false);
    sq[input-1].setIsEmpty(false);
}
bool getWin(Square *sq,pType type){
    bool logic = true;
    if(type == OPPONENT){
        logic = false;
    }else{
        logic = true;
    }
    int indexH = 0;
    int indexV = 0;
    for(int i=0; i<3; i++){
        if(sq[0+indexH].getIsEmpty() == false && sq[1+indexH].getIsEmpty()==false && sq[2+indexH].getIsEmpty() == false){
        if(sq[0+indexH].getValue() == logic && sq[1+indexH].getValue()==logic && sq[2+indexH].getValue() == logic){
            return true;
        }
    }
    if(sq[0+indexV].getIsEmpty() == false && sq[3+indexV].getIsEmpty()== false && sq[6+indexV].getIsEmpty() == false){
        if(sq[0+indexV].getValue() == logic && sq[3+indexV].getValue()==logic && sq[6+indexV].getValue() == logic){
            return true;
        }
    }
        
        indexH +=3;
        indexV += 1;
        
    }
    if(sq[0].getIsEmpty() == false && sq[4].getIsEmpty()==false && sq[8].getIsEmpty() == false){
    if(sq[0].getValue() == logic && sq[4].getValue()==logic && sq[8].getValue() == logic){
        return true;
    }

}
    if(sq[2].getIsEmpty() == false && sq[4].getIsEmpty()== false && sq[6].getIsEmpty() == false){
    if(sq[2].getValue() == logic && sq[4].getValue()==logic && sq[6].getValue() == logic){
        return true;
    }
   }
}
void Player :: incPoints(Square *sq,pType type){
    win = getWin(sq,type);
}
void Player :: playPC(Square (&sq)[9]){
    Square tempSqs[9];
    std::copy(std::begin(sq),std::end(sq),std::begin(tempSqs));
    int index = 0;
    std::vector<int> frees;
    bool makeMove = false;
    for(Square slot : tempSqs){
        
        if(slot.getIsEmpty()){
            frees.push_back(index);
            tempSqs[index].setValue(true);
            tempSqs[index].setIsEmpty(false);
            bool isWin = getWin(tempSqs,PC);
            if(isWin){
                sq[index].setValue(true);
                sq[index].setIsEmpty(false);
                makeMove = true;
                win = true;
                break;
            }else{
                tempSqs[index].setValue(false);
                tempSqs[index].setIsEmpty(true);
            }
        }
        index++;
    }
    if(!makeMove){
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<>dis(0,frees.size()-1);
        int rand = dis(gen);
        sq[frees.at(rand)].setValue(true);
        sq[frees.at(rand)].setIsEmpty(false);
    }
}