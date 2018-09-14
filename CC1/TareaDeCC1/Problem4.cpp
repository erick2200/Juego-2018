#include <iostream>
using namespace std;

bool palindromo(int a){
    int b1,b2,b3,c2,c3;
    b1=a%10;a/=10;
    b2=a%10;a/=10;
    b3=a%10;a/=10;
    c3=a%10;a/=10;
    c2=a%10;a/=10;
    if(b1==a && b2==c2 && b3==c3)
        return true;
    return false;
}

int main(){
    for(int i=700;i<1000;i++){
        for(int j=700;j<1000;j++){
            if (palindromo(i*j)==1){
                cout <<i<<" "<<j<<" "<<i*j<<"\n";}

        }
    }

    return 0;
}
