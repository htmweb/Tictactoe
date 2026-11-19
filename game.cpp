#include "game.h"
#include <iostream>
using namespace std;
#include "player.h"
#include "types.h"

Square Game::squares[9];
void Game :: display(Square sqs[]){
    int id = 0;
    for(int i=0; i<9; i++){
        if(id>2){
            id = 0;
            std::cout << std::endl;
        }
        if((sqs[i].getIsEmpty())){
                std::cout<<"[]"<<"\t";
        }else if((sqs[i].getValue()) && !(sqs[i].getIsEmpty())){
                std::cout<<"X"<<"\t";
        }else if(!(sqs[i].getValue()) && !(sqs[i].getIsEmpty())){
            std::cout<<"0"<<"\t";
        }
        id++;
    }
    std::cout<<std::endl;
}
void Game :: gameLoop(Square (&sqs)[9]){
    Player pc = {PC};
    OPP opp = {OPPONENT};
    Player players[2] = {pc,opp};
    int rounds = 1;
    std::cout<<std::endl<<"\t\t THE TIC TAC TOE"<<std::endl<<std::endl;
    std::cout<<std::endl<<"\t-------0 is you and X is pc--------"<<std::endl<<std::endl;

    while(!opp.getLost() && !pc.getLost() && rounds<20){
        auto p = players[rounds%2];
        p.logic(p.getType());
        if(p.getType() == OPPONENT){
            opp.getInput(sqs);
            opp.setInput(sqs);
            opp.incPoints(sqs,OPPONENT);
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