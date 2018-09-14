#include <iostream>

using namespace std;

bool primo(int a){
    for(int i=2;i<=a/2;i++){
    if (a%i==0)return false;
    }
    return true;
}

int main()
{
    int a=2,b=0;
    while (true){
    if (primo(a)==1)b++;
    if(b==10001)break;
    a++;
    }
    cout<<a<<"  "<<b;
    return 0;
}
