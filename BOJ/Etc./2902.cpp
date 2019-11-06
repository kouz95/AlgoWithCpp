#include <iostream>
#include <string>
using namespace std;
int main()
{
    string input;
    cin >> input;
    cout << input[0];
    for (int i = 1 ; i < input.size() -1 ; i++)
    {
        if (input[i]=='-')
            cout<< input[i+1];
    }
}
