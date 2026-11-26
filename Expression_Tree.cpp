
#include <iostream>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *left, *right;
};

// Check whether token is an operator
bool isOperator(string x)
{
    return (x == "+" || x == "-" ||
            x == "*" || x == "/");
}

// Create Expression Tree
Node* create(string P)
{
    stack<Node*> s;
    stringstream ss(P);
    string x;

    while (ss >> x)
    {
        Node *newNode = new Node;

        if (isOperator(x))
        {
            Node *t1 = s.top();
            s.pop();

            Node *t2 = s.top();
            s.pop();

            newNode->data = 0;
            newNode->left = t2;
            newNode->right = t1;
        }
        else
        {
            newNode->data = stoi(x);
            newNode->left = NULL;
            newNode->right = NULL;
        }

        s.push(newNode);
    }

    return s.top();
}

// Evaluate Expression Tree
int evaluate(Node *r)
{
    if (r == NULL)
        return 0;

    // If operand, return its value
    if (r->left == NULL && r->right == NULL)
        return r->data;

    int leftOperand = evaluate(r->left);
    int rightOperand = evaluate(r->right);

    // Apply operator
    // Store operator separately in the node
    return 0;
}

// Main function
int main()
{
    string P = "12 2 - 7 5 - /";

    Node *root = create(P);

    cout << "Result = " << evaluate(root);

    return 0;
}
