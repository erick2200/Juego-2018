#include <iostream>

using namespace std;

int main()
{
    int result=0,num=1000 ;
    for(int i=1;i<num;i++){
        if(i%3==0 ||i%5==0)
            result+=i;
        }
    cout << result;
    return 0;
}
