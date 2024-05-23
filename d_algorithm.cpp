#include "d_algorithm.h"

D_Algorithm::D_Algorithm(std::string expression)
{
    infixExpr = expression;
    postfixExpr = ToPostfix(expression);
}


std::string D_Algorithm::GetStringNumber(std::string expr, int &pos){
    std::string strNumber = "";
        for (; pos < expr.length(); pos++) {
            char num = expr[pos];
            if (std::isdigit(num) || num == '.')
                strNumber += num;
            else {
                pos--;
                break;
            }
        }
        return strNumber;
}

std::string D_Algorithm::ToPostfix(std::string infixExpr){
    std::string postfixExpr = "";
    std::stack<char> stack;
    for (int i = 0; i < infixExpr.length(); i++) {
        char c = infixExpr[i];
        if (std::isdigit(c) || c == '.') {
            postfixExpr += GetStringNumber(infixExpr, i) + " ";
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (!stack.empty() && stack.top() != '(') {
                postfixExpr += stack.top();
                stack.pop();
            }
            if (!stack.empty())
                stack.pop();
            } else if (operationPriority.count(c)) {
                char op = c;
                if (op == '-' && (i == 0 || operationPriority.count(infixExpr[i - 1])))
                    op = '~';
                while (!stack.empty() && operationPriority[stack.top()] >= operationPriority[op]) {
                    postfixExpr += stack.top();
                    stack.pop();
                    }
                    stack.push(op);
            }
        }
        while (!stack.empty()) {
            postfixExpr += stack.top();
            stack.pop();
    }
    return postfixExpr;
}

double D_Algorithm::Execute(char op, double first, double second){
    switch (op) {
        case '+':
            return first + second;
        case '-':
            return first - second;
        case '*':
            return first * second;
        case '/':
            return first / second;
        case '^':
            return std::pow(first, second);
        default:
            return 0;
    }
}


std::string D_Algorithm::Calc() {
    std::stack<double> locals;
    int counter = 0;
    for (int i = 0; i < postfixExpr.length(); i++) {
        char c = postfixExpr[i];
        if (std::isdigit(c) || c == '.') {
            std::string number = GetStringNumber(postfixExpr, i);
            try {
                size_t pos;
                double value = std::stod(number, &pos);
                if (pos != number.size()) {
                    QMessageBox::warning(nullptr, "Ошибка ввода", "Проверьте правильность ввода чисел");
                    return infixExpr;
                }
                if (value > std::numeric_limits<double>::max() || value < -std::numeric_limits<double>::max()) {
                    QMessageBox::warning(nullptr, "Ошибка ввода", "Введено слишком большое число");
                    return infixExpr;
                }
                locals.push(value);
            } catch (const std::out_of_range&) {
                QMessageBox::warning(nullptr, "Ошибка ввода", "Введено слишком большое число");
                return infixExpr;
            } catch (const std::invalid_argument&) {
                QMessageBox::warning(nullptr, "Ошибка ввода", "Проверьте правильность ввода чисел");
                return infixExpr;
            }
        } else if (operationPriority.count(c)) {
            counter++;
            if (c == '~') {
                if (locals.empty()) {
                    QMessageBox::warning(nullptr, "Ошибка ввода", "Стек пуст при использовании унарного минуса");
                    return infixExpr;
                }
                double last = locals.top();
                locals.pop();
                locals.push(Execute('-', 0, last));
                continue;
            }
            if (locals.size() < 2) {
                QMessageBox::warning(nullptr, "Ошибка ввода", "Недостаточно операндов для выполнения операции");
                return infixExpr;
            }
            double second = locals.top();
            locals.pop();
            double first = locals.top();
            locals.pop();
            locals.push(Execute(c, first, second));
        } else if (!std::isspace(c)) {
            QMessageBox::warning(nullptr, "Ошибка ввода", "Обнаружен недопустимый символ");
            return infixExpr;
        }
    }
    if (locals.size() != 1) {
        QMessageBox::warning(nullptr, "Ошибка ввода", "Проверьте правильность ввода выражения");
        return infixExpr;
    }
    return std::to_string(locals.top());
}
