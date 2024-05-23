#ifndef FASAD_H
#define FASAD_H
#include "d_algorithm.h"
#include <QMessageBox>

class Temp
{
private:
    std::string expression = "";

public:
    Temp(){}
    void addSymbols(std::string add){
        expression += add;
    }
    std::string getInfix(){
        return expression;
    }
    void Clear(){
     expression = "";
    }

    void newValue(std::string value){
        expression = value;
    }
};

#endif // FASAD_H
