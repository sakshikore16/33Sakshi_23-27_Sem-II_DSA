// 3. Convert an Infix expression to Postfix expression 
// using stack ADT.

// Theory:
// This code converts an infix expression to a postfix expression 
// using a stack. It reads an infix expression from the user, iterates 
// through each character, and based on the precedence of operators 
// and parentheses, constructs the corresponding postfix expression.

#include <iostream>
#include <stack>
using namespace std;

int main() 
{
    stack<char> s;
    string infix, postfix;

    cout << "enter an infix expression: ";
    getline(cin, infix);

    for (char c : infix) 
    {
        if (isalnum(c)) 
        {
            postfix += c;
        }

        else if (c == '(') 
        {
            s.push(c);
        }

        else if (c == ')') 
        {
            while (s.top() != '(') 
            { 
                postfix += s.top(); s.pop(); 
            }
            s.pop(); 
        } 
        else 
        {
            while (!s.empty() && s.top() != '(' && ((c == '+' || c == '-') ? 1 : 2) <= ((s.top() == '+' || s.top() == '-') ? 1 : 2)) 
            { 
                postfix += s.top(); s.pop(); 
            }
            s.push(c);
        }
    }

    while (!s.empty()) 
    { 
        postfix += s.top(); s.pop(); 
    }

    cout << "postfix expression: " << postfix << endl;

    return 0;
}

// Conclusion:
// The code efficiently converts infix expressions to postfix 
// expressions using a stack-based approach, handling operands, 
// operators, and parentheses while maintaining operator precedence. 
// It provides a straightforward implementation for converting 
// expressions, useful in various parsing and evaluation algorithms.