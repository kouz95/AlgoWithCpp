#include <iostream>

using namespace std;

int main()
{

    int t;
    int a, b;
    cin >> t;
    int count = 1;
    for (int i = 0 ; i < t ; i++)
    {
        cin >> a >> b ;
        cout << "Case #" << count << ": " << a << " + " << b << " = " << a+b << endl;
        count++;
    }
    
    return 0;
}
