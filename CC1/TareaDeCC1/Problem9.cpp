#include <iostream>

using namespace std;

int main()
{
    for(int i=1;i<700;i++){
        for(int j=1;j<700;j++){
            for (int k=1;k<1000;k++){
                if ((i*i)+(j*j)==k*k && i+j+k==1000){
                cout<<i*j*k<<endl;
                cout<<i<<"\n"<<j<<"\n"<<k;
}
            }
        }
        }
    cout<<"resultado: "<<375*200*425;
    return 0;
}
