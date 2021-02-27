#include <iostream>
#include <math.h>
using namespace std;
int main(){
    float a,b,c;
    float x1,x2,delta;      
    ////------Run------////
    cout<<"Chuong trinh giai phuong trinh az2+bz+c=0 tren khong gian C"<<"\n";
    do{
        cout<<"Nhap lan luot he so a, b, c: "<<"\n";
        cin>>a>>b>>c;
    }while(a*a+b*b+c*c==0);
    if(a==0){
        if(b==0){
            cout<<"Phuong trinh vo nghiem"<<"\n";
        }else{
            x1=-c/b;
            cout<<"Phuong trinh co mot nghiem: "<<x1;
        }
    }else{
        delta=b*b-4*a*c;
        if(delta>0){
            x1=(-b+sqrt(delta))/(2*a);
            x2=(-b-sqrt(delta))/(2*a);
            cout<<"Phuong trinh co hai nghiem"<<"\n";
            cout<<"z1="<<x1<<"\n"<<"z2="<<x2;
        }else if(delta==0){
            x1=-b/(2*a);
            cout<<"Phuong trinh co nghiem kep x1=x2="<<x1;
        }else{
            x1=-b/(2*a);                   /// coi vai trò x1 là thành phần thực 
            x2=sqrt(-delta/(4*a*a));        /// coi vai trò x2 là thành phần ảo 
            cout<<"Phuong trinh chi co nghiem phuc la: "<<"\n";
            cout<<"z1= "<<x1<<"+i*"<<x2<<"\n";
            cout<<"z2= "<<x1<<"-i*"<<x2;       
        }
    }
    return 0;
    
}