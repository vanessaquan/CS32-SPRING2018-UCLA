////
////  eval.cpp
////  mazestack
////
////  Created by XiaoJia Quan on 4/27/18.
////


#include <string>
#include <stack>
#include <iostream>
#include <cassert>
using namespace std;
//
//declarations of any additional functions you might have written
//to help you evaluate an expression
bool isValid(string infixS);
string convertToPostfix(string i, string &postfix);
int precedence(char ch);

int evaluate(string infix, string& postfix, bool& result)
{
   
    if(isValid(infix))
    {
        stack<bool> operandstack;
        convertToPostfix(infix, postfix);
        cout<<postfix<<endl;
        if (postfix.empty()) {
            return 1;
        }
       
        for (int k = 0; k < postfix.size(); k++) {
            if(postfix[k] == 'T')
                operandstack.push(true);
            else if (postfix[k] == 'F')
                operandstack.push(false);
            else if (postfix[k] == '!')
            {
                bool tmp = operandstack.top();
                operandstack.pop();
                operandstack.push(!tmp);
            }
            else
            {
                bool operand1 = operandstack.top();
                operandstack.pop();
                if (operandstack.empty()) {
                    return 1;
                }
                bool operand2 = operandstack.top();
                operandstack.pop();
                if (postfix[k] == '|') {
                    if (operand1 || operand2) {
                        operandstack.push(true);
                    }
                    else
                        operandstack.push(false);
                }
                else if(postfix[k] ==  '&')
                {
                    if (operand1 && operand2)
                        operandstack.push(true);
                    else
                        operandstack.push(false);
                }
            }

        }
        result = operandstack.top();
        return 0;
    }
    return 1;
}

string convertToPostfix(string i, string &postfix)
{
    postfix = "";
    stack <char> operatorstack;
    char ch;
    char addtop;
    for (int j = 0; j < i.size(); j++) {
        ch = i[j];
        switch (ch)
        {
            case 'T':
            case 'F':
                postfix += ch;
                break;
            case '(':
                operatorstack.push(ch);
                break;
            case ')':
                while (operatorstack.top()!='(') {
                    addtop = operatorstack.top();
                    operatorstack.pop();
                    postfix += addtop;
                }
                operatorstack.pop();
                break;
            case '!':
            case '&':
            case '|':
                while (!operatorstack.empty() && operatorstack.top()!='('
                       && precedence(ch) <= precedence(operatorstack.top()))
                {
                    if(ch == '!')
                        break;
                    postfix += operatorstack.top();
                    operatorstack.pop();
                }
                operatorstack.push(ch);
                break;

            default:
                break;
        }
    }
    while (!operatorstack.empty()) {
        postfix += operatorstack.top();
        operatorstack.pop();
    }
    return postfix;
}

int precedence(char ch)
{
    switch (ch) {
        case '!':
            return 2;
        case '&':
            return 1;
        case '|':
            return 0;
        default:
            return -1;
    }
}

bool isValid(string infixS)
{
    string tmpinfix = "";
    int countObraket = 0;
    int countCbraket = 0;
    for (int k = 0; k <infixS.size(); k++) {
        if (infixS[k] !=' ') {
            tmpinfix += infixS[k];
        }
    }
    infixS = tmpinfix;
    
    string ch;
    ch = infixS;

    if (infixS.length() == 1 && (ch[0] == 'T' || ch[0] == 'F') ){
        return true;
    }
    
    if (ch[0] == '|' || ch[0] == '&' || ch[0] == ')' ||ch[infixS.length()-1] == '|'
        || ch[infixS.length()-1] == '&' || ch[infixS.length()-1] == '!'|| ch[infixS.length()-1] == '(')
      return false;

    for (int j = 0; j < infixS.length(); j++)
    {
      
        if (((ch[j] == 'T') || ch[j] == 'F') && ((ch[j+1] == '|')||(ch[j+1] == '!') || (ch[j+1] == '&')))
        {
            return true;
        }
        
        if(ch[j] == '(')
        {
            countObraket++;
            if (ch[j+1] == '&' || ch[j+1] == '|'||ch[j+1] == ')') {
                return false;
            }
        }
        
        if(ch[j] == ')')
        {
            countCbraket++;
        }
        
        if((ch[j] =='T' || ch[j] == 'F' )&&(ch[j+1] == 'T' || ch[j+1] == 'F' || ch[j+1] == '(')) {
            return false;
        }
    }
    if(countCbraket == countObraket)
    {
        return true;
    }
    
    return false;
}

int main()
{
    string pf;
    bool answer;
    assert(evaluate("T| F", pf, answer) == 0  &&  pf == "TF|"  &&  answer);
    assert(evaluate("T|", pf, answer) == 1);
    assert(evaluate("F F", pf, answer) == 1);
    assert(evaluate("TF", pf, answer) == 1);
    assert(evaluate("()", pf, answer) == 1);
    assert(evaluate("T(F|T)", pf, answer) == 1);
    assert(evaluate("T(&T)", pf, answer) == 1);
    assert(evaluate("(T&(F|F)", pf, answer) == 1);
    assert(evaluate("", pf, answer) == 1);
    assert(evaluate("F  |  !F & (T&F) ", pf, answer) == 0
           &&  pf == "FF!TF&&|"  &&  !answer);
    assert(evaluate(" F  ", pf, answer) == 0 &&  pf == "F"  &&  !answer);
    assert(evaluate("((T))", pf, answer) == 0 &&  pf == "T"  &&  answer);
    cout << "Passed all tests" << endl;
}
