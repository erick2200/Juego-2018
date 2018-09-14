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
    long long b=0;
    for (int i=2;i<2000000;i++){
        if (primo(i)==1){b+=i;
        cout<<i<<" ";}
    }
    cout<<"\n<<b;
    return 0;
}

