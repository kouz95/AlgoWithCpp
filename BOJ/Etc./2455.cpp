#include <iostream>
using namespace std;

int main()
{
    int max = 0;
    int in , out ;
    int num = 0;
    for (int i = 0 ; i < 4 ; i++)
    {
        cin >> out >> in;
        num += in - out;
        if (max < num)
            max = num;
    }
    
    cout << max <<endl;
    return 0;
}
