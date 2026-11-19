#pragma once
class Square{
    int id;
    bool value;
    bool isEmpty;

    public:
    Square(){
        value = false;
        isEmpty = true;
    }
    void setValue(bool v){
        value = v;
    }
    bool getValue(){
        return value;
    }
    bool getIsEmpty(){
        return isEmpty;
    }
    void setIsEmpty(bool v){
        isEmpty = v;
    }
};
