#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int priority(string& op) {
        if (op == "+" || op == "-") {
            return 1;
        }
        else if (op == "*" || op == "/") {
            return 2;
        }
        else if (op == "^") {
            return 3;
        }

        return 0;
    }

    int operation(int a, int b, string& op) {
        if (op == "+") {
            return a + b;
        }
        else if (op == "-") {
            return a - b;
        }
        else if (op == "*") {
            return a * b;
        }
        else if (op == "^") {
            return (int)pow(a, b);
        }
        else {  // Division
            return (int)floor((double)a / b);
        }
    }

    void solve(stack<int>& numbers, stack<string>& operators) {
        string op = operators.top();
        operators.pop();

        int b = numbers.top();
        numbers.pop();

        int a = numbers.top();
        numbers.pop();

        numbers.push(operation(a, b, op));
    }

    int evaluateInfix(vector<string>& arr) {
        stack<int> numbers;
        stack<string> operators;

        for (string s : arr) {

            // Operand
            if (s != "+" && s != "-" && s != "*" &&
                s != "/" && s != "^" && s != "(" && s != ")") {
                numbers.push(stoi(s));
            }

            // Opening parenthesis
            else if (s == "(") {
                operators.push(s);
            }

            // Closing parenthesis
            else if (s == ")") {
                while (!operators.empty() && operators.top() != "(") {
                    solve(numbers, operators);
                }

                operators.pop(); // Remove '('
            }

            // Operator
            else {
                while (!operators.empty() && operators.top() != "(" &&
                       (priority(operators.top()) > priority(s) ||
                       (priority(operators.top()) == priority(s) && s != "^"))) {
                    solve(numbers, operators);
                }

                operators.push(s);
            }
        }

        // Process remaining operators
        while (!operators.empty()) {
            solve(numbers, operators);
        }

        return numbers.top();
    }
};