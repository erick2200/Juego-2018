#include <iostream>

using namespace std;
bool primo(int n){
        for(int i=2;i<=(n/2);i++){
            if(n%i==0)return false;
         } return true;
}



int main()
{
    long long num=600851475143;
    for(long long i=1;i<=num;i++){
        if (num%i==0 && primo(i)==1)
        cout <<i<<endl;
        }
    return 0;
}
