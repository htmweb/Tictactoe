#include<iostream>
#include "player.h"
#include "types.h"
using namespace std;

void display(Square sqs[]){
    int id = 0;
    for(int i=0; i<9; i++){
        if(id>2){
            id = 0;
            cout << endl;
        }
        if(sqs[i].getValue()){
                cout<<"X"<<"\t";
        }else{
                cout<<"0"<<"\t";
        }
        id++;
    }
    std::cout<<std::endl;
}

void gameLoop(Square (&sqs)[9]){
    Player pc = {PC};
    OPP opp = {OPPONENT};
    Player players[2] = {pc,opp};
    int rounds = 1;
    std::cout<<std::endl<<"\t\t THE TIC TAC TOE"<<std::endl<<std::endl;

    while(!opp.getLost() && !pc.getLost() && rounds<20){
        auto p = players[rounds%2];
        p.logic(p.getType());
        if(p.getType() == OPPONENT){
            opp.getInput(sqs);
            opp.setInput(sqs);
            opp.incPoints(sqs);
        }else{
            pc.playPC(sqs);
            
        }
        display(sqs);

        if(pc.getLost()){
            cout << "PC is lost... Game end" << std::endl;
            std::exit(0);
        }else if(opp.getLost()){
            cout << "OPP is lost... Game end" << std::endl;
            std::exit(0);
        }
        cout<<endl;
        rounds++;
    }

}
int main(){
    Square squares[9];
    for(int i=0; i<sizeof(squares)/sizeof(squares[0]); i++){
        squares[i] = Square();
    } 
    gameLoop(squares);

    return 0;

}
