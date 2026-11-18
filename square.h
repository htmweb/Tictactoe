#ifndef SQUARE_H
#define SQUARE_H
class Square{
    int id;
    bool value;
    
    public:
    Square(){
        value = false;
    }
    void setValue(bool v){
        value = v;
    }
    bool getValue(){
        return value;
    }
};
#endif