#include <iostream>
using namespace std;


char upper(char x);

int main(){
    char alp;
    do{
        cout<<"Nhap mot ki tu chu cai: ";
        cin>>alp;
        cout<<"Chu duoc viet hoa: "<<upper(alp)<<"\n";
    }while(alp<65||alp>122);
    return 0;
}

char upper(char x){
    if (x>96){
        x-=32;
    }else if (x<65 || x >122 || (x<97 && x>90)){
        cout<<"\nYeu cau nhap lai!";
    }
    return x;
}