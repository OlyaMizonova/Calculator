#include"TStack.h"
#include "Calculator.h"

bool TCalculator::isCorrect() {
    if (!operators.is_empty()) {
        operators.clear();
    }
    int res = 0;
    for (int i = 0; i < inf.size(); i++) {
        if (inf[i] == '(') {
            operators.push(inf[i]);
        }
        if (inf[i] == ')') {
            if (!operators.is_empty()) {
                operators.pop();
            }
            else {
                res = 1;
            }

        }
    }
    if (!operators.is_empty()) {
        res = 1;
    }
    return !res;
}

void TCalculator::set_infix(std::string str) {
    inf = str;
}

std::string TCalculator::get_postfix() {
    return postf;
}

std::string TCalculator::get_infix() {
    return inf;
}

double TCalculator::CalcPostfix() {
    if (!operands.is_empty()) {
        operands.clear();
    }
    for (int i = 0; i < postf.length(); i++) {
        if (postf[i] >= '0' && postf[i] <= '9')
        {
            operands.push(postf[i] - '0');
        }
        if ((postf[i] == '+') || (postf[i] == '-') ||
            (postf[i] == '*') || (postf[i] == '/') ||
            (postf[i] == '^')) {
            double x1 = 0, x2 = 0, y = 0;
            if (!operands.is_empty()) {
                x2 = operands.pop();
            }
            if (!operands.is_empty()) {
                x1 = operands.pop();
            }
            if (postf[i] == '+')
                y = x1 + x2;
            if (postf[i] == '-')
                y = x1 - x2;
            if (postf[i] == '*')
                y = x1 * x2;
            if (postf[i] == '/')
                y = x1 / x2;
            if (postf[i] == '^')
                y = pow(x1, x2);
            operands.push(y);
        }
    }
    double res;
    if (!operands.is_empty()) {
        res = operands.pop();
    }
    else {
        throw "stack is empty";
    }
    if (!operands.is_empty()) {
        throw "wrong result";
    }
    return res;
}

void TCalculator::ToPostfix() {
    if (!operators.is_empty()) {
        operators.clear();
    }
    std::string str = '(' + inf + ')';
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            operators.push('(');
        }
        if (str[i] >= '0' && str[i] <= '9'){
            postf += str[i];
        }
        if (str[i] == ')') {
            char opelement = operators.pop();
            while (opelement != '(')
            {
                postf += opelement;
                opelement = operators.pop();
            }
        }
        if ((str[i] == '+') || (str[i] == '-') ||
            (str[i] == '*') || (str[i] == '/') ||
            (str[i] == '^')) {
            char opelement = operators.pop();
            while (priority(opelement) >= priority(str[i])) {
                postf += opelement;
                opelement = operators.pop();
            }
            operators.push(opelement);
            operators.push(str[i]);
        }
    }

}

double TCalculator::calc() {
    double res = 0;
    operators.clear(); operands.clear();
    std::string s = '(' + inf + ')';
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            operators.push('(');
        }
        else if (s[i] == ')') {
            char el = operators.pop();
            while (el != '(') {
                double x2 = operands.pop(), x1 = operands.pop(), cur_res = 0;
                if (el == '+') {
                    cur_res = x1 + x2;
                }
                if (el == '*') {
                    cur_res = x1 * x2;
                }
                if (el == '-') {
                    cur_res = x1 - x2;
                }
                if (el == '^') {
                    cur_res = pow(x1, x2);
                }
                if (el == '/') {
                    cur_res = x1 / x2;
                }
                operands.push(cur_res);
                el = operators.pop();
            }
        }
        else if (s[i]>='0'&&s[i]<='9') {
            size_t pos = 0;
            double operand = std::stod(&s[i], &pos);
            operands.push(operand);
            i += pos - 1;  //because i++
        }
        else if ((s[i] == '+') || (s[i] == '-') ||
            (s[i] == '*') || (s[i] == '/') ||
            (s[i] == '^')) {
            char el = operators.pop(); double cur_res = 0;
            while (priority(el) > priority(s[i])) {
                double x2 = operands.pop(), x1 = operands.pop();
                if (el == '+') {
                    cur_res = x1 + x2;
                }
                if (el == '*') {
                    cur_res = x1 * x2;
                }
                if (el == '-') {
                    cur_res = x1 - x2;
                }
                if (el == '^') {
                    cur_res = pow(x1, x2);
                }
                if (el == '/') {
                    cur_res = x1 / x2;
                }
                operands.push(cur_res);
                el = operators.pop();
            }
            operators.push(el);
            operators.push(s[i]);
        }
    }
    if (!operators.is_empty()) {
        throw "extra operation";
    }
    if (!operands.is_empty()) {
        res = operands.pop();
    }
    if (!operands.is_empty()) {
        throw "extra operand";
    }
    return res;
}

/* 
func from std converts 3.232311323 to double
stod - string to double
double stod (string, size_t* pos_of_non_numeric_symb)
stod(&str[i]);
*/