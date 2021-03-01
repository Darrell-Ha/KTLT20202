#include <iostream>
#include <math.h>
#include <complex>
using namespace std;

int main(){
    complex<double> C2[6];
    complex<double> zeRo(0,0);
    /////// RUN //////////
    cout<<"Chuong trinh giai phuong trinh az2+bz+c=0 tren khong gian C"<<"\n";
    cout<<"Nhap lan luot he so viet trong khong gian C: "<<"\n";
    for(int ind=0;ind<3;ind++){
        double a,b;
        cout<<"Nhap he so z^"<<2-ind<<"\n";   
        cout<<"phan thuc: ";
        cin>>a;
        cout<<"phan ao: ";
        cin>>b;
        complex<double> x(a,b);
        C2[ind]=x;
    }
    if(C2[0]==zeRo){
        if(C2[1]==zeRo){
            if(C2[2]==zeRo){
                cout<<"Phuong trinh vo so nghiem";
            }else{
                cout<<"Phuong trinh vo nghiem";
            }
        }else{
            complex<double> z1(0,0);
            //z1=-C2[2];
            z1=-C2[2]/C2[1];
            cout<<"z="<<real(z1)<<"+"<<imag(z1)<<"i";
        }
    }else{
        complex<double> delta(0,0);
        complex<double> num4(4,0);
        complex<double> num2(2,0);
        complex<double> ac;
        complex<double> bb;
        bb=C2[1]*C2[1];
        ac=C2[2]*C2[0];
        delta=sqrt(bb-num4*ac);
        C2[3]=(-C2[1]+delta)/(num2*C2[0]);
        C2[4]=(-C2[1]-delta)/(num2*C2[0]);
        cout<<"z1= "<<real(C2[3])<<"+"<<imag(C2[3])<<"i";
        cout<<"\nz2= "<<real(C2[4])<<"+"<<imag(C2[4])<<"i";
    }
    return 0;
}