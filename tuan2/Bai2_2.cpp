#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int number;
    cout<<"Hay nhap so nguyen duong can xet: "<<"\n";
    cin>>number;
    for(int i=2;i<sqrt(number);i++){
        if(number%i==0){
            cout<<"Khong phai la so nguyen to";
            return 0;
        }
    }
    cout<<"La so nguyen to";
    return 0;
}