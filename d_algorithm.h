#ifndef D_ALGORITHM_H
#define D_ALGORITHM_H
#include <string>
#include <map>
#include <stack>
#include <math.h>
#include <QString>
#include <QMessageBox>

class D_Algorithm
{
private:
    std::string postfixExpr; std::string infixExpr = "";
    std::map<char, int> operationPriority = {
    {'(', 0},
    {'+', 1},
    {'-', 1},
    {'*', 2},
    {'/', 2},
    {'^', 3},
    {'~', 4} //унарный минус
};


public:
    D_Algorithm(std::string expression);
    std::string Calc();
    void Clear(){
     infixExpr = "";
    }


private:
    std::string GetStringNumber(std::string expr, int &pos);
    std::string ToPostfix(std::string infixExpr);
    double Execute(char op, double first, double second);

};

#endif // D_ALGORITHM_H
