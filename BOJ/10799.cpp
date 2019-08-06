#include<iostream>
#include <string>
using namespace std;

string input;
int res = 0;

void in()
{
    cin >> input;
}
void func()
{
    int stack = 0;
    for (int i = 0 ; i < input.size(); i++)
    {
        if (input[i] == '(' && input[i+1] == ')'){
            res += stack;
            i++;
        }
        else if (input[i]=='(') stack ++;
            
        
        else {
            stack--;
            res++;
        }
        
    }
}
void out()
{
    cout << res <<endl;
}
int main()
{
    in();
    func();
    out();
}
