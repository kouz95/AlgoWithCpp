#include <iostream>
using namespace std;

int a, b, c;
int res[10] = {0,};
void in()
{
    cin >> a >> b >> c;
}
void func(int a, int b, int c)
{
    int num = a * b * c ;
    
    while(num >= 1){
        switch(num%10){
            case 0 : res[0]++;
                num /= 10;
                break;
            case 1 : res[1]++;
                num/=10;
                break;
            case 2 : res[2]++;
                num/=10;
                break;
            case 3 : res[3]++;
                num/=10;
                break;
            case 4 : res[4]++;
                num/=10;
                break;
            case 5 : res[5]++;
                num/=10;
                break;
            case 6 : res[6]++;
                num/=10;
                break;
            case 7 : res[7]++;
                num/=10;
                break;
            case 8 : res[8]++;
                num/=10;
                break;
            case 9 : res[9]++;
                num/=10;
                break;

        }
    }
}
void out()
{
    for(int i = 0 ; i < 10 ; i ++)
    {
        cout << res[i] <<endl;
    }
}

int main()
{
    in();
    func(a,b,c);
    out();
    return 0;
}
