#include <iostream>

using namespace std;

int UCLN(int num1, int num2);

int main(){
    int num1, num2;
    cout << "Nhap 2 so can tim UCLN: ";
    cin >> num1 >>num2;
    cout << UCLN(num1,num2);
    return 0;
}

int UCLN(int num1, int num2){
    if(num2==0){
        return num1;
    }else{
        return UCLN(num2,num1%num2);
    }
}