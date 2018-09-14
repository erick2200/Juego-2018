#include <iostream>

using namespace std;

int main()
{
    long a=0,b=1,c,acum=0;
    for(int i=1;i<1000;i++){
        c=b;b+=a;a=c;
        if(b>=4000000)break;
        if(b%2==0)acum+=b;

    }
    cout <<"..."<<acum;
    return 0;
}

