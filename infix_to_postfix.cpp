//infix to postfix using stack
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

bool isOperator(char x) {
    return (x == '+' || x == '-' || x == '*' || x == '/');
}

int main() {
    stack<char> s;
    string I = "8*6/(9-3*2)";
    string P = "";

    I = I + ")";
    s.push('(');

    for (int i = 0; i < I.length(); i++) {
        char x = I[i];

        if (x == ' ')
            continue;

        if (x == '(') {
            s.push(x);
        }

        else if (x == ')') {
            char y = s.top();
            s.pop();

            while (y != '(') {
                P = P + y;
                y = s.top();
                s.pop();
            }
        }

        else if (isOperator(x)) {
            char y = s.top();
            s.pop();

            while (isOperator(y) &&
                   precedence(y) >= precedence(x)) {
                P = P + y;
                y = s.top();
                s.pop();
            }

            s.push(y);
            s.push(x);
        }

        else {
            P = P + x;
        }
    }

    cout << "Postfix expression: " << P;

    return 0;
}
