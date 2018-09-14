#include <iostream>

using namespace std;

int main(){
    int acum1=0,acum2=0;
    for(int i=1;i<=100;i++){
        acum1+=i*i;
        acum2+=i;
    }
    acum2*=acum2;
    cout<<acum2<<" "<<acum1<<" "<<acum2-acum1;

    return 0;
}
