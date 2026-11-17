//Postfix evaluate
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<int> s;
    string P = "8 6 * 9 3 2 * - /";

    int x, y, val;
    char op;

    for (int i = 0; i < P.length(); i++) {

        if (P[i] == ' ')
            continue;

        if (P[i] >= '0' && P[i] <= '9') {
            s.push(P[i] - '0');
        }
        else {
            op = P[i];

            y = s.top();
            s.pop();

            x = s.top();
            s.pop();

            if (op == '+')
                val = x + y;
            else if (op == '-')
                val = x - y;
            else if (op == '*')
                val = x * y;
            else if (op == '/')
                val = x / y;

            s.push(val);
        }
    }

    cout << "Result = " << s.top();

    return 0;
}
