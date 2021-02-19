#include <iostream>
#include "Calculator.h"
using namespace std;

int main()
{
    while (true)
    {
        string input;
        cout << "Infix notation: ";
        getline(cin, input);
        if (input == "")
            break;
        Calculator test(input);
        cout << "Reverse Polich notation: " << test.ToPostfix() << endl;
        float res = test.getResult();
        cout << "Result: " << res << endl;
    }
}

