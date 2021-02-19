#include "Calculator.h"
#include <iostream>

Calculator::Calculator(string in)
{
    output = "";
    input = in;
}

string Calculator::ToPostfix()
{
    int  pos = 0;
    for (pos;  pos < input.length(); pos++) {
       char el = input[pos];
        switch (el)
        {
        case '+':
            setPreor(el, 1);
            break;
        case '-':
            setPreor(el, 1);
            break;
        case '*':
            setPreor(el, 2);
            break;
        case '/':
            setPreor(el, 2);
            break;
        case '%':
            setPreor(el, 2);
            break;
        case '^':
            setPreor(el, 3);
            break;
        case '(':
            operands.push(el);
            break;
        case ')':
            gotBracket(el);
            break;
        default:
            //output += el;
            if (el <= '9' && el >= '0') {
                string temp = "";
                do {
                    temp += el;
                    pos++;
                    if (pos >= input.length())
                        break;
                    el = input[pos];
                } while (el <= '9' && el >= '0' || el == '.');
                output += temp + " ";
                pos--;
            }
            else
            {
                if (el != ' ') {
                    cout << "Error : " << el;
                    return "";
                }
                pos++;
            }
            
            break;
        }
    }
    while (!operands.empty())
    {
        output += operands.top();
        output += " ";
        operands.pop();
    }
    if (output[output.length() - 1] == '(') {
        cout << "Error : " << output[output.length() - 1] << endl;
        return "";
    }
    return output;
}

float Calculator::getResult()
{
    int pos;
    char ch;
    float num_1;
    float num_2; 
    float result;
    size_t count = 0;

    for (pos = 0; pos < output.length(); pos++) {
        ch = output[pos];
        if (ch == ' ')
            ch == output[++pos];

        if (ch <= '9' && ch >= '0') {
            count++;
            string temp = "";
            do {
                temp += ch;
                pos++;
                if (pos >= output.length() || ch == ' ')
                    break;
                ch = output[pos];
            } while (ch <= '9' && ch >= '0' || ch == '.');
            numbers.push(stof(temp));
        }
        else
        {

            count--;
            switch (ch)
            {
            case '+':
                num_2 = numbers.top();
                numbers.pop();
                if (numbers.empty()) {
                    cout << "Error" << endl;
                    return 0;
                } 
                else
                {
                    num_1 = numbers.top();
                    numbers.pop();
                    result = num_1 + num_2;
                }
                break;
            case '-':
                num_2 = numbers.top();
                numbers.pop();
                if (numbers.empty()) {
                    cout << "Error" << endl;
                    return 0;
                }
                else
                {
                    num_1 = numbers.top();
                    numbers.pop();
                    result = num_1 - num_2;
                }
                break;
            case '*':
                num_2 = numbers.top();
                numbers.pop();
                if (numbers.empty()) {
                    cout << "Error" << endl;
                    return 0;
                }
                else
                {
                    num_1 = numbers.top();
                    numbers.pop();
                    result = num_1 * num_2;
                }
                break;
            case '%':
                num_2 = numbers.top();
                numbers.pop();
                if (numbers.empty()) {
                    cout << "Error" << endl;
                    return 0;
                }
                else
                {
                    num_1 = numbers.top();
                    numbers.pop();
                    result = (int)num_1 % (int)num_2;
                }
                break;
            case '^':
                num_2 = numbers.top();
                numbers.pop();
                if (numbers.empty()) {
                    cout << "Error" << endl;
                    return 0;
                }
                else
                {
                    num_1 = numbers.top();
                    numbers.pop();
                    result = pow(num_1, num_2);
                }
                break;
            case '/':
                num_2 = numbers.top();
                numbers.pop();
                if (num_2 == 0) {
                    cout << "Error /0 " << endl;
                    return 0;
                }
                else
                {
                    if (numbers.empty()) {
                        cout << "Error" << endl;
                        return 0;
                    }
                    else
                    {
                        num_1 = numbers.top();
                        numbers.pop();
                        result = num_1 / num_2;
                    }
                }
                break;
            default:
                //result = 0;
                break;
            }
            pos++;
            numbers.push(result);
        }
    }
    result = numbers.top();
    numbers.pop();
    if (count == 1)
        return result;
    else
    {
        cout << "Error !" << endl;
    }
    return result;
}

void Calculator::setPreor(char thisEl, int preor)
{
    while (!operands.empty())
    {
        char topEl = operands.top();
        operands.pop();

        if (topEl == '(')
        {
            operands.push(topEl);
            break;
        }
        else
        {
            int nextPreor;
            if (topEl == '+' || topEl == '-')
                nextPreor = 1;
            else
                nextPreor = 2;
            if (nextPreor < preor)
            {
                operands.push(topEl);
                break;
            }
            else
            {
                output += topEl;
                output += " ";
            }
                
        }
    }
    operands.push(thisEl);
}

void Calculator::gotBracket(char thisEl)
{
    while (!operands.empty())
    {
        char temp = operands.top();
        operands.pop();

        if (temp == '(')
            break;
        else
        {
            output += temp;
            output += " ";
        }
            
    }
}

void Calculator::printStack()
{
    stack<char> temp = operands;
    while (!temp.empty())
    {
        cout << temp.top() << " " << endl;
        temp.pop();
    }
}
